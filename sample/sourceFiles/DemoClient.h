#pragma once

#include "IComErrorProvider.h"
///<DCOMPLUGIN_ALL_SERVICES_INCLUDE_LIST>
#include "ICounterService.h"
#include "ITextService.h"
///</DCOMPLUGIN_ALL_SERVICES_INCLUDE_LIST>

namespace testdemo {

#ifdef Demo_CLIENT_EXPORTS
#define Demo_DLL_API __declspec(dllexport)
#else
#define Demo_DLL_API __declspec(dllimport)
#endif

///<summary>Client class for connection to DemoServer.</summary>
class Demo_DLL_API DemoClient : public virtual IComErrorProvider, 
///<DCOMPLUGIN_ALL_SERVICES_VIRTUAL_IMPL>
                                public virtual ICounterService,
                                public virtual ITextService
///</DCOMPLUGIN_ALL_SERVICES_VIRTUAL_IMPL>

{
public:
  DemoClient();
  virtual ~DemoClient();

  ///<summary>Defines if the DemoServer is available.</summary>
  ///<returns>Returns true if the client is connected with the DemoServer server. Returns false otherwise.</returns>
  bool isConnected();

  //DemoProtoLib interfaces

  //IComErrorProvider
  virtual unsigned int GetLastComErrorCode();
  virtual std::string GetLastComErrorStr();
  
  ///<DCOMPLUGIN_ALL_SERVICES_DECLARATION>
  //ICounterService
  ///<summary>Process the GetSequentialNumber rpc of the ICounterService service.</summary>
  ///<param name="requestMessage">A valid request message of type testdemo::VoidMessage.</param>
  ///<param name="responseMessage">The response message of type testdemo::SequentialNumber for the GetSequentialNumber() rpc.</param>
  ///<returns>Returns true if the call is successful. Returns false otherwise.</returns>
  virtual bool GetSequentialNumber(const testdemo::VoidMessage & requestMessage, testdemo::SequentialNumber & responseMessage);

  //ITextService
  ///<summary>Process the Hello rpc of the ITextService service.</summary>
  ///<param name="requestMessage">A valid request message of type testdemo::HelloRequest.</param>
  ///<param name="responseMessage">The response message of type testdemo::HelloResponse for the Hello() rpc.</param>
  ///<returns>Returns true if the call is successful. Returns false otherwise.</returns>
  virtual bool Hello(const testdemo::HelloRequest & requestMessage, testdemo::HelloResponse & responseMessage);
  ///</DCOMPLUGIN_ALL_SERVICES_DECLARATION>

protected:
  ///<summary>Error code returned by the last internal call to the server.</summary>
  unsigned long mLastError;

  ///<summary>DemoClient private implementation pointer.</summary>
  void * mInstance;
};

}  // namespace testdemo
