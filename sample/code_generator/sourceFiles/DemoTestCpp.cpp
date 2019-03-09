// DemoTestCpp.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <limits>

#ifdef max
#undef max
#endif

#include "DemoClient.h"

int main(int argc, char* argv[])
{
  testdemo::DemoClient client;
  if (!client.isConnected() || client.GetLastComErrorCode() != 0)
  {
    printf("*** ERROR! Initializing of DemoServer failed. Code:%lu Description:%s\n", client.GetLastComErrorCode(), client.GetLastComErrorStr().c_str());
    return 1;
  }

  for(int call = 0; call<3; call++)
  {
    //ICounterService
    {
      testdemo::VoidMessage request;
      testdemo::SequentialNumber response;
      bool success = client.GetSequentialNumber(request, response);
      if (success)
        printf("Call %d to GetSequentialNumber() returned %d\n", call, response.value());
      else
        printf("*** ERROR! Call %d to GetSequentialNumber() failed. Code:%lu Description:%s\n", call, client.GetLastComErrorCode(), client.GetLastComErrorStr().c_str());

      system("PAUSE");
    }
  }

  //ITextService
  {
    testdemo::HelloRequest request;
    request.set_name("Antoine");
    testdemo::HelloResponse response;
    bool success = client.Hello(request, response);
    if (success)
      printf("Calling Hello(%s) returned '%s'\n", request.name().c_str(), response.greetings().c_str());
    else
      printf("*** ERROR! Call Hello(%s) failed. Code:%lu Description:%s\n", request.name().c_str(), client.GetLastComErrorCode(), client.GetLastComErrorStr().c_str());

    system("PAUSE");
  }

  return 0;
}
