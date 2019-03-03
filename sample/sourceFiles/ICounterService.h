#pragma once

#include "TestDemo.pb.h"

namespace testdemo {

///<DCOMPLUGIN_CURRENT_SERVICE_INTERFACE_DECLARATION>
class ICounterService
{
public:
  ///<summary>Process the GetSequentialNumber rpc of the ICounterService service.</summary>
  ///<param name="requestMessage">A valid request message of type testdemo::VoidMessage.</param>
  ///<param name="responseMessage">The response message of type testdemo::SequentialNumber for the GetSequentialNumber() rpc.</param>
  ///<returns>Returns true if the call is successful. Returns false otherwise.</returns>
  virtual bool GetSequentialNumber(const testdemo::VoidMessage & requestMessage, testdemo::SequentialNumber & responseMessage) = 0;
};
///</DCOMPLUGIN_CURRENT_SERVICE_INTERFACE_DECLARATION>

}  // namespace testdemo
