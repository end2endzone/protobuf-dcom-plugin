#pragma once

#include "TestDemo.pb.h"

namespace testdemo {

///<DCOMPLUGIN_CURRENT_SERVICE_INTERFACE_DECLARATION>
class ITextService
{
public:
  ///<summary>Process the Hello rpc of the ITextService service.</summary>
  ///<param name="requestMessage">A valid request message of type testdemo::HelloRequest.</param>
  ///<param name="responseMessage">The response message of type testdemo::HelloResponse for the Hello() rpc.</param>
  ///<returns>Returns true if the call is successful. Returns false otherwise.</returns>
  virtual bool Hello(const testdemo::HelloRequest & requestMessage, testdemo::HelloResponse & responseMessage) = 0;
};
///</DCOMPLUGIN_CURRENT_SERVICE_INTERFACE_DECLARATION>

}  // namespace testdemo
