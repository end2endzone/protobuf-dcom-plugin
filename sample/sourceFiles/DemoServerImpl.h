#pragma once

///<DCOMPLUGIN_ALL_SERVICES_INCLUDE_LIST>
#include "ICounterService.h"
#include "ITextService.h"
///</DCOMPLUGIN_ALL_SERVICES_INCLUDE_LIST>

namespace testdemo {

///<summary>Actual implementation of testdemo services.</summary>
///<returns>Returns a string containing the file name of the current executable. ie: MyProcessName.exe</returns>
class DemoServerImpl :	
                                ///<DCOMPLUGIN_ALL_SERVICES_VIRTUAL_IMPL>
                                public virtual ICounterService, public virtual ITextService
                                ///</DCOMPLUGIN_ALL_SERVICES_VIRTUAL_IMPL>
{
public:
  DemoServerImpl();
  virtual ~DemoServerImpl();

  //DemoProtoLib interfaces

  ///<DCOMPLUGIN_ALL_SERVICES_DECLARATION>
  //ICounterService
  ///<summary>Process the GetSequentialNumber rpc of the ICounterService service</summary>
  ///<param name="requestMessage">A valid request message of type testdemo::VoidMessage.</param>
  ///<param name="responseMessage">The response message of type testdemo::SequentialNumber for the GetSequentialNumber() rpc.</param>
  ///<returns>Returns true if the call is successful. Returns false otherwise.</returns>
  virtual bool GetSequentialNumber(const testdemo::VoidMessage & requestMessage, testdemo::SequentialNumber & responseMessage);

  //ITextService
  ///<summary>Process the Hello rpc of the ITextService service</summary>
  ///<param name="requestMessage">A valid request message of type testdemo::HelloRequest.</param>
  ///<param name="responseMessage">The response message of type testdemo::HelloResponse for the Hello() rpc.</param>
  ///<returns>Returns true if the call is successful. Returns false otherwise.</returns>
  virtual bool Hello(const testdemo::HelloRequest & requestMessage, testdemo::HelloResponse & responseMessage);
  ///</DCOMPLUGIN_ALL_SERVICES_DECLARATION>
};

}  // namespace testdemo
