#define WIN32_LEAN_AND_MEAN    // Exclude rarely-used stuff from Windows headers
#include <windows.h>

#include "DCOMPLUGIN_COMPONENT_NAMEClient.h"

#include <comdef.h> //for CoInitialize and CoUninitialize
#include "DCOMPLUGIN_COMPONENT_NAMEServer_h.h" // interface declaration
#include "DCOMPLUGIN_COMPONENT_NAMEServer_i.c" // IID, CLSID

#include "MessageSerializer.h"
#include "ErrorHandlers.h"

namespace DCOMPLUGIN_PACKAGE_NAME {

#define mServer ((DCOMPLUGIN_IDL_INTERFACE_NAMEServer *)mInstance)

BOOL APIENTRY DllMain( HANDLE hModule,
                      DWORD  ul_reason_for_call,
                      LPVOID lpReserved
                      )
{
  switch (ul_reason_for_call)
  {
  case DLL_PROCESS_ATTACH:
  case DLL_THREAD_ATTACH:
  case DLL_THREAD_DETACH:
  case DLL_PROCESS_DETACH:
    break;
  }
  return TRUE;
}

DCOMPLUGIN_COMPONENT_NAMEClient::DCOMPLUGIN_COMPONENT_NAMEClient() :
  mInstance(NULL),
  mLastError(0)
{
  //note: multiple calls to CoInitialize() is safe.
  //An internal counter is used to actually initialize on first call only.
  ::CoInitialize(NULL);

  // create an instance
  HRESULT hr = CoCreateInstance(CLSID_CoDCOMPLUGIN_COMPONENT_NAMEServer, NULL, /*CLSCTX_ALL*/ CLSCTX_SERVER, /*IID_DCOMPLUGIN_IDL_INTERFACE_NAMEServer*/ __uuidof(DCOMPLUGIN_IDL_INTERFACE_NAMEServer), (void **)&mInstance);
  if (FAILED(hr))
  {
    mLastError = hr;
  }
}

DCOMPLUGIN_COMPONENT_NAMEClient::~DCOMPLUGIN_COMPONENT_NAMEClient()
{
  if (mServer)
  {
    mServer->Release();
    mInstance = NULL;
  }

  //note: the number of calls to CoUninitialize() must match the number of calls to CoInitialize(NULL)
  ::CoUninitialize();
}

bool DCOMPLUGIN_COMPONENT_NAMEClient::isConnected()
{
  if (mServer)
  {
    return true;
  }
  return false;
}

//DCOMPLUGIN_COMPONENT_NAMEProtoLib interfaces
unsigned int DCOMPLUGIN_COMPONENT_NAMEClient::GetLastComErrorCode()
{
  return mLastError;
}

std::string DCOMPLUGIN_COMPONENT_NAMEClient::GetLastComErrorStr()
{
  std::string description = GetComErrorDescription(mLastError);
  return description;
}

DCOMPLUGIN_CLIENT_DEFINITION

}  // namespace DCOMPLUGIN_PACKAGE_NAME
