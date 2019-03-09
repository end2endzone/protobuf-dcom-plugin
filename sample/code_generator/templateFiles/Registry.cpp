//
// Registry.cpp
//

#include <shlwapi.h>
#pragma comment(lib, "shlwapi" )

//ATL includes are not supported by Visual Studio Express.
//Using the following include files as an alternative:
//#include <objbase.h> // ATL base
//#include <atlbase.h>
#include <assert.h>
#include "SmartPointers.h" //replacement for <objbase.h> and <atlbase.h>
#include <comdef.h>

#include "Registry.h"


////////////////////////////////////////////////////////
//
// Internal helper functions prototypes
//

// Set the given key and its value.
BOOL setKeyAndValue(const char* pszPath,
                    const char* szSubkey,
                    const char* szValue) ;


BOOL setValue(const char* szKey,
              const char* szEntry,
              const char* szValue);


// Convert a CLSID into a char string.
void CLSIDtochar(const CLSID& clsid, 
                 char* szCLSID,
                 int length) ;

// Delete szKeyChild and all of its descendents.
LONG recursiveDeleteKey(HKEY hKeyParent, const char* szKeyChild) ;

////////////////////////////////////////////////////////
//
// Constants
//

// Size of a CLSID as a string
const int CLSID_STRING_SIZE = 39 ;

/////////////////////////////////////////////////////////
//
// Public function implementation
//

//
// Register the component in the registry.
//
HRESULT RegisterServer(HMODULE hModule,            // DLL module handle
                       const CLSID& clsid,         // Class ID
                       const char* szFriendlyName, // Friendly Name
                       const char* szVerIndProgID, // Programmatic
                       const char* szProgID,
					             const CLSID &libid)         // Type lib ID
{
	// Get server location.
	char szModule[1024];
	DWORD dwResult =
		::GetModuleFileName(hModule, 
		                    szModule,
		                    sizeof(szModule)/sizeof(char)) ;
	assert(dwResult != 0) ;

	// Convert the CLSID into a char.
	char szCLSID[CLSID_STRING_SIZE] ;
	CLSIDtochar(clsid, szCLSID, sizeof(szCLSID)) ;
	char szLIBID[CLSID_STRING_SIZE] ;
	CLSIDtochar(libid, szLIBID, sizeof(szLIBID)) ;

	// Build the key CLSID\\{...}
	char szKey[64] ;
	strcpy(szKey, "CLSID\\") ;
	strcat(szKey, szCLSID) ;
  
	// Add the CLSID to the registry.
	setKeyAndValue(szKey, NULL, szFriendlyName) ;

	// Add the server filename subkey under the CLSID key.
	char szModuleExeOrDll[4];
	long nLength = strlen(szModule);
	strncpy(szModuleExeOrDll, szModule+nLength-3, 3);
	szModuleExeOrDll[3] = 0;
	if (_stricmp(szModuleExeOrDll,"exe")==0)
		setKeyAndValue(szKey, "LocalServer32", szModule) ;
	else
	{
		setKeyAndValue(szKey, "InProcServer32", szModule) ;
		char szKeyInProc[64];
		strcpy(szKeyInProc, szKey);
		strcat(szKeyInProc, "\\InProcServer32");
		setValue(szKeyInProc, "ThreadingModel", "Both") ;
	}

	// Add the ProgID subkey under the CLSID key.
	setKeyAndValue(szKey, "ProgID", szProgID) ;

	// Add the version-independent ProgID subkey under CLSID key.
	setKeyAndValue(szKey, "VersionIndependentProgID", szVerIndProgID) ;

	// Add the typelib
	setKeyAndValue(szKey, "TypeLib", szLIBID) ;


	// Add the version-independent ProgID subkey under HKEY_CLASSES_ROOT.
	setKeyAndValue(szVerIndProgID, NULL, szFriendlyName) ; 
	setKeyAndValue(szVerIndProgID, "CLSID", szCLSID) ;
	setKeyAndValue(szVerIndProgID, "CurVer", szProgID) ;

	// Add the versioned ProgID subkey under HKEY_CLASSES_ROOT.
	setKeyAndValue(szProgID, NULL, szFriendlyName) ; 
	setKeyAndValue(szProgID, "CLSID", szCLSID) ;

	// add TypeLib keys
	strcpy(szKey, "TypeLib\\") ;
	strcat(szKey, szLIBID) ;

	// Add the CLSID to the registry.
	setKeyAndValue(szKey, NULL, NULL) ;
	strcat(szKey, "\\1.0");
	setKeyAndValue(szKey, NULL, szFriendlyName) ;
	strcat(szKey, "\\0");
	setKeyAndValue(szKey, NULL, NULL) ;
	strcat(szKey, "\\win32");
	setKeyAndValue(szKey, NULL, szModule) ;


	return S_OK ;
}


void RegisterInterface(HMODULE hModule,            // DLL module handle
                       const CLSID& clsid,         // Class ID
                       const char* szFriendlyName, // Friendly Name
					             const CLSID &libid,
					             const IID &iid)
{
	// Get server location.
	char szModule[512] ;
	DWORD dwResult =
		::GetModuleFileName(hModule, 
		                    szModule,
		                    sizeof(szModule)/sizeof(char)) ;
	assert(dwResult != 0) ;

	// Convert the CLSID into a char.
	char szCLSID[CLSID_STRING_SIZE] ;
	CLSIDtochar(clsid, szCLSID, sizeof(szCLSID)) ;
	char szLIBID[CLSID_STRING_SIZE] ;
	CLSIDtochar(libid, szLIBID, sizeof(szCLSID)) ;
	char szIID[CLSID_STRING_SIZE] ;
	CLSIDtochar(iid, szIID, sizeof(szCLSID)) ;

	// Build the key Interface\\{...}
	char szKey[64] ;
	strcpy(szKey, "Interface\\") ;
	strcat(szKey, szIID) ;
  
	// Add the value to the registry.
	setKeyAndValue(szKey, NULL, szFriendlyName) ;

	char szKey2[MAX_PATH];
	strcpy(szKey2, szKey);
	strcat(szKey2, "\\ProxyStubClsID");
	// Add the server filename subkey under the IID key.
	setKeyAndValue(szKey2, NULL, "{00020424-0000-0000-C000-000000000046}"); //IUnknown

	strcpy(szKey2, szKey);
	strcat(szKey2, "\\ProxyStubClsID32");
	// Add the server filename subkey under the IID key.
	setKeyAndValue(szKey2, NULL, "{00020424-0000-0000-C000-000000000046}"); //IUnknown

	strcpy(szKey2, szKey);
	strcat(szKey2, "\\TypeLib");
	// Add the server filename subkey under the CLSID key.
	setKeyAndValue(szKey2, NULL, szLIBID) ;
	
	setValue(szKey2, "Version", "1.0") ;
}

void UnregisterInterface(const IID &iid)
{
	char szIID[CLSID_STRING_SIZE] ;
	CLSIDtochar(iid, szIID, sizeof(szIID)) ;

	// Build the key Interface\\{...}
	char szKey[64] ;
	strcpy(szKey, "Interface\\") ;
	strcat(szKey, szIID) ;

	LONG lResult = recursiveDeleteKey(HKEY_CLASSES_ROOT, szKey) ;
}

//
// Remove the component from the registry.
//
LONG UnregisterServer(const CLSID& clsid,         // Class ID
                      const char* szVerIndProgID, // Programmatic
                      const char* szProgID,
					            const CLSID &libid)         // Type lib ID
{
	// Convert the CLSID into a char.
	char szCLSID[CLSID_STRING_SIZE] ;
	CLSIDtochar(clsid, szCLSID, sizeof(szCLSID)) ;

	// Build the key CLSID\\{...}
	char szKey[64] ;
	strcpy(szKey, "CLSID\\") ;
	strcat(szKey, szCLSID) ;

	// Delete the CLSID Key - CLSID\{...}
	LONG lResult = recursiveDeleteKey(HKEY_CLASSES_ROOT, szKey) ;
	assert((lResult == ERROR_SUCCESS) ||
	       (lResult == ERROR_FILE_NOT_FOUND)) ; // Subkey may not exist.

	// Delete the version-independent ProgID Key.
	lResult = recursiveDeleteKey(HKEY_CLASSES_ROOT, szVerIndProgID) ;
	assert((lResult == ERROR_SUCCESS) ||
	       (lResult == ERROR_FILE_NOT_FOUND)) ; // Subkey may not exist.

	// Delete the ProgID key.
	lResult = recursiveDeleteKey(HKEY_CLASSES_ROOT, szProgID) ;
	assert((lResult == ERROR_SUCCESS) ||
	       (lResult == ERROR_FILE_NOT_FOUND)) ; // Subkey may not exist.

	char szLIBID[CLSID_STRING_SIZE] ;
	CLSIDtochar(libid, szLIBID, sizeof(szLIBID)) ;
	
	strcpy(szKey, "TypeLib\\") ;
	strcat(szKey, szLIBID) ;

	// Delete the TypeLib Key - LIBID\{...}
	lResult = recursiveDeleteKey(HKEY_CLASSES_ROOT, szKey) ;
	assert((lResult == ERROR_SUCCESS) ||
	       (lResult == ERROR_FILE_NOT_FOUND)) ; // Subkey may not exist.

	return S_OK ;
}

///////////////////////////////////////////////////////////
//
// Internal helper functions
//

// Convert a CLSID to a char string.
void CLSIDtochar(const CLSID& clsid,
                 char* szCLSID,
                 int length)
{
	assert(length >= CLSID_STRING_SIZE) ;
	// Get CLSID
	LPOLESTR wszCLSID = NULL ;
	HRESULT hr = StringFromCLSID(clsid, &wszCLSID) ;
	assert(SUCCEEDED(hr)) ;

	// Covert from wide characters to non-wide.
	wcstombs(szCLSID, wszCLSID, length) ;

	// Free memory.
	CoTaskMemFree(wszCLSID) ;
}

//
// Delete a key and all of its descendents.
//
LONG recursiveDeleteKey(HKEY hKeyParent,           // Parent of key to delete
                        const char* lpszKeyChild)  // Key to delete
{
	// Open the child.
	HKEY hKeyChild ;
	LONG lRes = RegOpenKeyEx(hKeyParent, lpszKeyChild, 0,
	                         KEY_ALL_ACCESS, &hKeyChild) ;
	if (lRes != ERROR_SUCCESS)
	{
		return lRes ;
	}

	// Enumerate all of the decendents of this child.
	FILETIME time ;
	char szBuffer[256] ;
	DWORD dwSize = 256 ;
	while (RegEnumKeyEx(hKeyChild, 0, szBuffer, &dwSize, NULL,
	                    NULL, NULL, &time) == S_OK)
	{
		// Delete the decendents of this child.
		lRes = recursiveDeleteKey(hKeyChild, szBuffer) ;
		if (lRes != ERROR_SUCCESS)
		{
			// Cleanup before exiting.
			RegCloseKey(hKeyChild) ;
			return lRes;
		}
		dwSize = 256 ;
	}

	// Close the child.
	RegCloseKey(hKeyChild) ;

	// Delete this child.
	return RegDeleteKey(hKeyParent, lpszKeyChild) ;
}

//
// Create a key and set its value.
//   - This helper function was borrowed and modifed from
//     Kraig Brockschmidt's book Inside OLE.
//
BOOL setKeyAndValue(const char* szKey,
                    const char* szSubkey,
                    const char* szValue)
{
	HKEY hKey;
	char szKeyBuf[1024] ;

	// Copy keyname into buffer.
	strcpy(szKeyBuf, szKey) ;

	// Add subkey name to buffer.
	if (szSubkey != NULL)
	{
		strcat(szKeyBuf, "\\") ;
		strcat(szKeyBuf, szSubkey ) ;
	}

	// Create and open key and subkey.
	long lResult = RegCreateKeyEx(HKEY_CLASSES_ROOT ,
	                              szKeyBuf, 
	                              0, NULL, REG_OPTION_NON_VOLATILE,
	                              KEY_ALL_ACCESS, NULL, 
	                              &hKey, NULL) ;
	if (lResult != ERROR_SUCCESS)
	{
		return FALSE ;
	}

	// Set the Value.
	if (szValue != NULL)
	{
		RegSetValueEx(hKey, NULL, 0, REG_SZ, 
		              (BYTE *)szValue, 
		              DWORD( 1+strlen(szValue) ) 
		) ;
	}

	RegCloseKey(hKey) ;
	return TRUE ;
}


BOOL setValue(const char* szKey,
              const char* szEntry,
              const char* szValue)
{
	HKEY hKey;

	// Create and open key and subkey.
	long lResult = RegOpenKeyEx(HKEY_CLASSES_ROOT ,
	                              szKey, 
	                              0, 
	                              KEY_ALL_ACCESS, 
								  &hKey) ;
	if (lResult != ERROR_SUCCESS)
	{
		return FALSE ;
	}

	// Set the Value.
	if (szValue != NULL)
	{
		RegSetValueEx(hKey, szEntry, 0, REG_SZ, 
		              (BYTE *)szValue, 
		              DWORD( 1+strlen(szValue) )
		) ;
	}

	RegCloseKey(hKey) ;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// TypeLib registration

HRESULT LoadTypeLib(HINSTANCE hInstTypeLib, LPCOLESTR lpszIndex, BSTR* pbstrPath, ITypeLib** ppTypeLib)
{
	ATLASSERT(pbstrPath != NULL && ppTypeLib != NULL);
	if (pbstrPath == NULL || ppTypeLib == NULL)
		return E_POINTER;

	*pbstrPath = NULL;
	*ppTypeLib = NULL;

	USES_CONVERSION;
	ATLASSERT(hInstTypeLib != NULL);
	TCHAR szModule[MAX_PATH+10];

	DWORD dwFLen = ::GetModuleFileName(hInstTypeLib, szModule, MAX_PATH);
	if( dwFLen == 0 )
		return HRESULT_FROM_WIN32(::GetLastError());
	else if( dwFLen == MAX_PATH )
		return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);

	// get the extension pointer in case of fail
	LPTSTR lpszExt = NULL;

	lpszExt = ::PathFindExtension(szModule);

	if (lpszIndex != NULL)
		lstrcat(szModule, OLE2CT(lpszIndex));
	LPOLESTR lpszModule = T2OLE(szModule);
	HRESULT hr = ::LoadTypeLib(lpszModule, ppTypeLib);
	if (!SUCCEEDED(hr))
	{
		// typelib not in module, try <module>.tlb instead
		lstrcpy(lpszExt, _T(".tlb"));
		lpszModule = T2OLE(szModule);
		hr = ::LoadTypeLib(lpszModule, ppTypeLib);
	}
	if (SUCCEEDED(hr))
	{
		*pbstrPath = ::SysAllocString(lpszModule);
		if (*pbstrPath == NULL)
			hr = E_OUTOFMEMORY;
	}
	return hr;
}

static inline UINT WINAPI GetDirLen(LPCOLESTR lpszPathName) throw()
{
	ATLASSERT(lpszPathName != NULL);

	// always capture the complete file name including extension (if present)
	LPCOLESTR lpszTemp = lpszPathName;
	for (LPCOLESTR lpsz = lpszPathName; *lpsz != NULL; )
	{
		LPCOLESTR lp = CharNextO(lpsz);
		// remember last directory/drive separator
		if (*lpsz == OLESTR('\\') || *lpsz == OLESTR('/') || *lpsz == OLESTR(':'))
			lpszTemp = lp;
		lpsz = lp;
	}

	return UINT( lpszTemp-lpszPathName );
}


HRESULT RegisterTypeLib(HINSTANCE hInstTypeLib, LPCOLESTR lpszIndex)
{
	CComBSTR bstrPath;
	CComPtr<ITypeLib> pTypeLib;
	HRESULT hr = LoadTypeLib(hInstTypeLib, lpszIndex, &bstrPath, &pTypeLib);
	if (SUCCEEDED(hr))
	{
		OLECHAR szDir[MAX_PATH];
		ocscpy(szDir, bstrPath);
		// If index is specified remove it from the path
		if (lpszIndex != NULL)
		{
			size_t nLenPath = ocslen(szDir);
			size_t nLenIndex = ocslen(lpszIndex);
			if (memcmp(szDir + nLenPath - nLenIndex, lpszIndex, nLenIndex) == 0)
				szDir[nLenPath - nLenIndex] = 0;
		}
		szDir[GetDirLen(szDir)] = 0;
		hr = ::RegisterTypeLib(pTypeLib, bstrPath, szDir);
	}
	return hr;
}

HRESULT UnRegisterTypeLib(HINSTANCE hInstTypeLib, LPCOLESTR lpszIndex)
{
	CComBSTR bstrPath;
	CComPtr<ITypeLib> pTypeLib;
	HRESULT hr = LoadTypeLib(hInstTypeLib, lpszIndex, &bstrPath, &pTypeLib);
	if (SUCCEEDED(hr))
	{
		TLIBATTR* ptla;
		hr = pTypeLib->GetLibAttr(&ptla);
		if (SUCCEEDED(hr))
		{
			hr = ::UnRegisterTypeLib(ptla->guid, ptla->wMajorVerNum, ptla->wMinorVerNum, ptla->lcid, ptla->syskind);
			pTypeLib->ReleaseTLibAttr(ptla);
		}
	}
	return hr;
}

char *rstrstr(char * _Str, char * _SubStr)
{
  size_t  s1len = strlen(_Str);
  size_t  s2len = strlen(_SubStr);
  char *s;

  if (s2len > s1len)
    return NULL;
  for (s = _Str + s1len - s2len; s >= _Str; --s)
    if (strncmp(s, _SubStr, s2len) == 0)
      return s;
  return NULL;
}

HRESULT RegisterServer(HMODULE hModule,
                       const char* szAppID,
                       const CLSID& clsid,
                       const char* szFriendlyName,
                       const char* szVerIndProgID,
                       const char* szProgID,
					             const CLSID& libid)
{
  // Get server location.
  char szModule[1024];
  DWORD dwResult =
	  ::GetModuleFileName(hModule, 
		                    szModule,
		                    sizeof(szModule)/sizeof(char)) ;
  assert(dwResult != 0) ;
  long nModuleLength = strlen(szModule);

  // Get server filename
  char * szModuleFilename = rstrstr(szModule, "\\");
  assert(szModuleFilename != 0) ;
  szModuleFilename++; //skip \ character
  long nFilenameLength = strlen(szModuleFilename);

  // Get server filename extension
  char * szExtension = rstrstr(szModule, ".");
  assert(szExtension != 0) ;
  long nExtensionLength = strlen(szExtension);

  // Get server filename (without extension)
  char szModuleFilenameOnly[64];
  strncpy(szModuleFilenameOnly, szModuleFilename, nFilenameLength-nExtensionLength);
  szModuleFilenameOnly[nFilenameLength-nExtensionLength] = 0;

  // Build the key AppID\\{filename.exe}
  char szKey[64] ;
  strcpy(szKey, "AppID\\") ;
  strcat(szKey, szModuleFilename) ;
  
  // Add the AppID to the registry.
  setKeyAndValue(szKey, NULL, NULL) ;
  setValue(szKey, "AppID", szAppID) ;

  // Build the key AppID\\{GUID}
  strcpy(szKey, "AppID\\") ;
  strcat(szKey, szAppID) ;
  
  // Add the AppID to the registry.
  setKeyAndValue(szKey, NULL, szModuleFilenameOnly) ;

  HRESULT hr = RegisterServer(hModule, clsid, szFriendlyName, szVerIndProgID, szProgID, libid);
  return hr;
}

HRESULT UnregisterServer(HMODULE hModule,
                         const char* szAppID,
                         const CLSID& clsid,
                         const char* szVerIndProgID,
                         const char* szProgID,
						             const CLSID& libid)
{
  // Get server location.
  char szModule[1024];
  DWORD dwResult =
	  ::GetModuleFileName(hModule, 
		                    szModule,
		                    sizeof(szModule)/sizeof(char)) ;
  assert(dwResult != 0) ;
  long nModuleLength = strlen(szModule);

  // Get server filename
  char * szModuleFilename = rstrstr(szModule, "\\");
  assert(szModuleFilename != 0) ;
  szModuleFilename++; //skip \ character
  long nFilenameLength = strlen(szModuleFilename);

  // Get server filename extension
  char * szExtension = rstrstr(szModule, ".");
  assert(szExtension != 0) ;
  long nExtensionLength = strlen(szExtension);

  // Build the key AppID\\{filename.exe}
  char szKey[64] ;
  strcpy(szKey, "AppID\\") ;
  strcat(szKey, szModuleFilename) ;
  
  // Delete the AppID Key - AppID\{filename.exe}
  LONG lResult = recursiveDeleteKey(HKEY_CLASSES_ROOT, szKey) ;
  assert((lResult == ERROR_SUCCESS) ||
	       (lResult == ERROR_FILE_NOT_FOUND)) ; // Subkey may not exist.

  // Build the key AppID\\{GUID}
  strcpy(szKey, "AppID\\") ;
  strcat(szKey, szAppID) ;
  
  // Delete the AppID Key - AppID\{GUID}
  lResult = recursiveDeleteKey(HKEY_CLASSES_ROOT, szKey) ;
  assert((lResult == ERROR_SUCCESS) ||
	       (lResult == ERROR_FILE_NOT_FOUND)) ; // Subkey may not exist.

  HRESULT hr = UnregisterServer(clsid, szVerIndProgID, szProgID, libid);
  return hr;
}
