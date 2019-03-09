#define WIN32_LEAN_AND_MEAN    // Exclude rarely-used stuff from Windows headers
#include <windows.h>

#include "DemoClient.h"

#include <comdef.h> //for CoInitialize and CoUninitialize
#include "DemoServer_h.h" // interface declaration
#include "DemoServer_i.c" // IID, CLSID

#include "MessageSerializer.h"
#include "ErrorHandlers.h"

namespace testdemo {

#define mServer ((IDemoServer *)mInstance)

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

DemoClient::DemoClient() :
  mInstance(NULL),
  mLastError(0)
{
  //note: multiple calls to CoInitialize() is safe.
  //An internal counter is used to actually initialize on first call only.
  ::CoInitialize(NULL);

  // create an instance
  HRESULT hr = CoCreateInstance(CLSID_CoDemoServer, NULL, /*CLSCTX_ALL*/ CLSCTX_SERVER, /*IID_IDemoServer*/ __uuidof(IDemoServer), (void **)&mInstance);
  if (FAILED(hr))
  {
    mLastError = hr;
  }
}

DemoClient::~DemoClient()
{
  if (mServer)
  {
    mServer->Release();
    mInstance = NULL;
  }

  //note: the number of calls to CoUninitialize() must match the number of calls to CoInitialize(NULL)
  ::CoUninitialize();
}

bool DemoClient::isConnected()
{
  if (mServer)
  {
    return true;
  }
  return false;
}

//DemoProtoLib interfaces
unsigned int DemoClient::GetLastComErrorCode()
{
  return mLastError;
}

std::string DemoClient::GetLastComErrorStr()
{
  std::string description = GetComErrorDescription(mLastError);
  return description;
}

///<DCOMPLUGIN_CLIENT_DEFINITION>
bool DemoClient::GetSequentialNumber(const testdemo::VoidMessage & requestMessage, testdemo::SequentialNumber & responseMessage)
{
  if (mServer == NULL)
  {
    if (mLastError == S_OK)
    {
      mLastError = E_NOINTERFACE;
    }
    return false;
  }

  //serialise input (prepare input VARIANT buffer)
  VARIANT requestBuffer;
  VariantInit(&requestBuffer);
  HRESULT hr = SerializeMessageToVariant(requestMessage, testdemo::CPLUSPLUS, requestBuffer);
  if (FAILED(hr))
  {
    //Serialization failed. Cleanup..
    VariantClear(&requestBuffer);

    mLastError = hr;
    return false;
  }

  //make the RPC call
  VARIANT responseBuffer;
  VariantInit(&responseBuffer);
  hr = mServer->GetSequentialNumber(requestBuffer, &responseBuffer);
  if (FAILED(hr))
  {
    //cleanup local allocations
    SafeArrayDestroy(requestBuffer.parray);
    VariantClear(&requestBuffer);

    mLastError = hr;
    return false;
  }

  //COM call succeeded

  //deserialize data into the output message
  testdemo::VariantFlavor tmpFlavor;
  hr = DeserializeVariantToMessage(responseBuffer, responseMessage, tmpFlavor);
  if (FAILED(hr))
  {
    //cleanup memory allocation of client
    SafeArrayDestroy(responseBuffer.parray);
    VariantClear(&responseBuffer);

    mLastError = hr;
    return false;
  }

  //cleanup memory allocation of client
  SafeArrayDestroy(responseBuffer.parray);
  VariantClear(&responseBuffer);

  return true;
}

bool DemoClient::Hello(const testdemo::HelloRequest & requestMessage, testdemo::HelloResponse & responseMessage)
{
  if (mServer == NULL)
  {
    if (mLastError == S_OK)
    {
      mLastError = E_NOINTERFACE;
    }
    return false;
  }

  //serialise input (prepare input VARIANT buffer)
  VARIANT requestBuffer;
  VariantInit(&requestBuffer);
  HRESULT hr = SerializeMessageToVariant(requestMessage, testdemo::CPLUSPLUS, requestBuffer);
  if (FAILED(hr))
  {
    //Serialization failed. Cleanup..
    VariantClear(&requestBuffer);

    mLastError = hr;
    return false;
  }

  //make the RPC call
  VARIANT responseBuffer;
  VariantInit(&responseBuffer);
  hr = mServer->Hello(requestBuffer, &responseBuffer);
  if (FAILED(hr))
  {
    //cleanup local allocations
    SafeArrayDestroy(requestBuffer.parray);
    VariantClear(&requestBuffer);

    mLastError = hr;
    return false;
  }

  //COM call succeeded

  //deserialize data into the output message
  testdemo::VariantFlavor tmpFlavor;
  hr = DeserializeVariantToMessage(responseBuffer, responseMessage, tmpFlavor);
  if (FAILED(hr))
  {
    //cleanup memory allocation of client
    SafeArrayDestroy(responseBuffer.parray);
    VariantClear(&responseBuffer);

    mLastError = hr;
    return false;
  }

  //cleanup memory allocation of client
  SafeArrayDestroy(responseBuffer.parray);
  VariantClear(&responseBuffer);

  return true;
}
///</DCOMPLUGIN_CLIENT_DEFINITION>

}  // namespace testdemo
