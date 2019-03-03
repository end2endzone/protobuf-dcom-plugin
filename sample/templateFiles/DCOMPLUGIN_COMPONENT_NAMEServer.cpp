#include <objbase.h> // 
#include "DCOMPLUGIN_COMPONENT_NAMEServer_h.h"
#include "DCOMPLUGIN_COMPONENT_NAMEServer_i.c"
#include <comdef.h>
#include "Registry.h"
#include "DCOMPLUGIN_COMPONENT_NAMEServer.h"
#include "DCOMPLUGIN_COMPONENT_NAMEServerImpl.h"
#include "DCOMPLUGIN_PROTO_FILE_NAME.pb.h"
#include "stdio.h"
#include "stdlib.h"

#pragma comment(lib, "rpcrt4" )
#pragma comment(lib, "ole32" ) 

#include "MessageSerializer.h"
#include "ErrorHandlers.h"

#include "WinError.h"

// Count of active components
static long g_cComponents = 0 ;

// Count of locks
static long g_cServerLocks = 0 ;

// DLL module handle
static HMODULE g_hModule = NULL ;

// Friendly name of component
const char g_szFriendlyName[] = "DCOMPLUGIN_OBJECT_FRIENDLYNAME";

// Version-independent ProgID of component
const char g_szVerIndProgID[] = "DCOMPLUGIN_OBJECT_NAME";

// ProgID of component
const char g_szProgID[] = "DCOMPLUGIN_OBJECT_NAME.1";

// AppID
const char g_szAppID[] = "{DCOMPLUGIN_APPID_GUID}";


// Actual server implementation
DCOMPLUGIN_PACKAGE_NAME::DCOMPLUGIN_COMPONENT_NAMEServerImpl g_objDCOMPLUGIN_COMPONENT_NAMEServerImpl;

//
// Constructor
//
CoDCOMPLUGIN_COMPONENT_NAMEServer::CoDCOMPLUGIN_COMPONENT_NAMEServer() : m_cRef(1)
{ 
  InterlockedIncrement(&g_cComponents) ; 

  m_ptinfo = NULL;
  LoadTypeInfo(&m_ptinfo, LIBID_DCOMPLUGIN_LIBRARY_NAME, IID_DCOMPLUGIN_IDL_INTERFACE_NAMEServer, 0);
}

//
// Destructor
//
CoDCOMPLUGIN_COMPONENT_NAMEServer::~CoDCOMPLUGIN_COMPONENT_NAMEServer() 
{ 
  InterlockedDecrement(&g_cComponents) ; 
}

//
// IUnknown implementation
//
HRESULT __stdcall CoDCOMPLUGIN_COMPONENT_NAMEServer::QueryInterface(const IID& iid, void** ppv)
{    
  if (iid == IID_IUnknown || iid == IID_DCOMPLUGIN_IDL_INTERFACE_NAMEServer || iid == IID_IDispatch)
  {
    *ppv = static_cast<DCOMPLUGIN_IDL_INTERFACE_NAMEServer*>(this) ; 
  }
  else
  {
    *ppv = NULL ;
    return E_NOINTERFACE ;
  }
  reinterpret_cast<IUnknown*>(*ppv)->AddRef() ;
  return S_OK ;
}

ULONG __stdcall CoDCOMPLUGIN_COMPONENT_NAMEServer::AddRef()
{
  return InterlockedIncrement(&m_cRef) ;
}

ULONG __stdcall CoDCOMPLUGIN_COMPONENT_NAMEServer::Release() 
{
  if (InterlockedDecrement(&m_cRef) == 0)
  {
    delete this ;
    ::PostMessage(NULL,WM_QUIT,0,0);
    return 0 ;
  }
  return m_cRef ;
}

DCOMPLUGIN_COCLASS_DEFINITION

HRESULT CoDCOMPLUGIN_COMPONENT_NAMEServer::LoadTypeInfo(ITypeInfo ** pptinfo, const CLSID &libid, const CLSID &iid, LCID lcid)
{
   HRESULT hr;
   LPTYPELIB ptlib = NULL;
   LPTYPEINFO ptinfo = NULL;

   *pptinfo = NULL;

   // Load type library.
   hr = LoadRegTypeLib(libid, 1, 0, lcid, &ptlib);
   if (FAILED(hr))
      return hr;

   // Get type information for interface of the object.
   hr = ptlib->GetTypeInfoOfGuid(iid, &ptinfo);
   if (FAILED(hr))
   {
      ptlib->Release();
      return hr;
   }

   ptlib->Release();
   *pptinfo = ptinfo;
   return NOERROR;
}


HRESULT __stdcall CoDCOMPLUGIN_COMPONENT_NAMEServer::GetTypeInfoCount(UINT* pctinfo)
{
  *pctinfo = 1;
  return S_OK;
}
HRESULT __stdcall CoDCOMPLUGIN_COMPONENT_NAMEServer::GetTypeInfo(UINT itinfo, LCID lcid, ITypeInfo** pptinfo)
{
  *pptinfo = NULL;

  if(itinfo != 0)
    return ResultFromScode(DISP_E_BADINDEX);

  m_ptinfo->AddRef();      // AddRef and return pointer to cached
                           // typeinfo for this object.
  *pptinfo = m_ptinfo;

  return NOERROR;
}
HRESULT __stdcall CoDCOMPLUGIN_COMPONENT_NAMEServer::GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames,
    LCID lcid, DISPID* rgdispid)
{
  return DispGetIDsOfNames(m_ptinfo, rgszNames, cNames, rgdispid);
}
HRESULT __stdcall CoDCOMPLUGIN_COMPONENT_NAMEServer::Invoke(DISPID dispidMember, REFIID riid,
    LCID lcid, WORD wFlags, DISPPARAMS* pdispparams, VARIANT* pvarResult,
    EXCEPINFO* pexcepinfo, UINT* puArgErr)
{
  return DispInvoke(
        this, m_ptinfo,
        dispidMember, wFlags, pdispparams,
        pvarResult, pexcepinfo, puArgErr); 
}


//
// Class factory IUnknown implementation
//
HRESULT __stdcall CFactory::QueryInterface(const IID& iid, void** ppv)
{    
  if ((iid == IID_IUnknown) || (iid == IID_IClassFactory))
  {
    *ppv = static_cast<IClassFactory*>(this) ; 
  }
  else
  {
    *ppv = NULL ;
    return E_NOINTERFACE ;
  }
  reinterpret_cast<IUnknown*>(*ppv)->AddRef() ;
  return S_OK ;
}

ULONG __stdcall CFactory::AddRef()
{
  return InterlockedIncrement(&m_cRef) ;
}

ULONG __stdcall CFactory::Release() 
{
  if (InterlockedDecrement(&m_cRef) == 0)
  {
    delete this ;
    return 0 ;
  }
  return m_cRef ;
}

//
// IClassFactory implementation
//
HRESULT __stdcall CFactory::CreateInstance(IUnknown* pUnknownOuter,
                                           const IID& iid,
                                           void** ppv) 
{
  // Cannot aggregate.
  if (pUnknownOuter != NULL)
  {
    return CLASS_E_NOAGGREGATION ;
  }

  // Create component.
  CoDCOMPLUGIN_COMPONENT_NAMEServer* pA = new CoDCOMPLUGIN_COMPONENT_NAMEServer ;
  if (pA == NULL)
  {
    return E_OUTOFMEMORY ;
  }

  // Get the requested interface.
  HRESULT hr = pA->QueryInterface(iid, ppv) ;

  // Release the IUnknown pointer.
  // (If QueryInterface failed, component will delete itself.)
  pA->Release() ;
  return hr ;
}

// LockServer
HRESULT __stdcall CFactory::LockServer(BOOL bLock) 
{
  if (bLock)
  {
    InterlockedIncrement(&g_cServerLocks) ; 
  }
  else
  {
    InterlockedDecrement(&g_cServerLocks) ;
  }
  return S_OK ;
}







///////////////////////////////////////////////////////////
//
// Exported functions
//

//
// Can DLL unload now?
//
STDAPI DllCanUnloadNow()
{
  if ((g_cComponents == 0) && (g_cServerLocks == 0))
  {
    return S_OK ;
  }
  else
  {
    return S_FALSE ;
  }
}

//
// Get class factory
//
STDAPI DllGetClassObject(const CLSID& clsid,
                         const IID& iid,
                         void** ppv)
{
  // Can we create this component?
  if (clsid != CLSID_CoDCOMPLUGIN_COMPONENT_NAMEServer)
  {
    return CLASS_E_CLASSNOTAVAILABLE ;
  }

  // Create class factory.
  CFactory* pFactory = new CFactory ;  // Reference count set to 1
                                       // in constructor
  if (pFactory == NULL)
  {
    return E_OUTOFMEMORY ;
  }

  // Get requested interface.
  HRESULT hr = pFactory->QueryInterface(iid, ppv) ;
  pFactory->Release() ;

  return hr ;
}




CFactory gClassFactory;



DWORD CoEXEInitialize()
{
  DWORD nReturn;

  HRESULT hr=::CoRegisterClassObject(CLSID_CoDCOMPLUGIN_COMPONENT_NAMEServer,
    &gClassFactory,
    CLSCTX_SERVER, 
    REGCLS_MULTIPLEUSE, 
    &nReturn);

  return nReturn;
}

void CoEXEUninitialize(DWORD nToken)
{
  ::CoRevokeClassObject(nToken);
}










//
// Server registration
//
STDAPI DllRegisterServer()
{

  g_hModule = ::GetModuleHandle(NULL);

  HRESULT hr= RegisterServer(g_hModule,
                             g_szAppID,
                             CLSID_CoDCOMPLUGIN_COMPONENT_NAMEServer,
                             g_szFriendlyName,
                             g_szVerIndProgID,
                             g_szProgID,
                             LIBID_DCOMPLUGIN_LIBRARY_NAME);
  if (SUCCEEDED(hr))
  {
    hr = RegisterTypeLib( g_hModule, NULL);
  }
  return hr;
}


//
// Server unregistration
//
STDAPI DllUnregisterServer()
{

  g_hModule = ::GetModuleHandle(NULL);

  HRESULT hr= UnregisterServer(g_hModule,
                               g_szAppID,
                               CLSID_CoDCOMPLUGIN_COMPONENT_NAMEServer,
                               g_szVerIndProgID,
                               g_szProgID,
                               LIBID_DCOMPLUGIN_LIBRARY_NAME);
  if (SUCCEEDED(hr))
  {
    UnRegisterTypeLib( g_hModule, NULL);
  }
  return hr;
}



///////////////////////////////////////////////////////////
//
// DLL module information
//
BOOL APIENTRY DllMain(HANDLE hModule,
                      DWORD dwReason,
                      void* lpReserved)
{
  if (dwReason == DLL_PROCESS_ATTACH)
  {
    g_hModule = (HMODULE)hModule ;
  }

  return TRUE ;
}
