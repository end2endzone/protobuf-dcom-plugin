// VoidServerCppTest.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>

#include "VoidClient.h"

int _tmain(int argc, _TCHAR* argv[])
{
  //create client
  testvoidmessages::VoidClient client;

  //verify connection
  if (!client.isConnected() || client.GetLastComErrorCode() != 0)
  {
    printf("*** ERROR! Initializing of VoidClient failed. Code:%lu Description:%s\n", client.GetLastComErrorCode(), client.GetLastComErrorStr().c_str());
    return 1;
  }

  //Method1
  {
    testvoidmessages::FooRequest request;
    request.set_value(5);
    testvoidmessages::FooResponse response;
    client.Method1(request, response);
  }

  //Method2
  {
    testvoidmessages::FooRequest request;
    request.set_value(6);
    client.Method2(request);
  }

  //Method3
  {
    testvoidmessages::FooResponse response;
    client.Method3(response);
  }

  //Method4
  {
    client.Method4();
  }

  return 0;
}
