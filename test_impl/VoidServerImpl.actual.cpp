#include "VoidServerImpl.h"

#include <Windows.h>


namespace testvoidmessages {

//Global objects
// TODO: Rename or copy this template to a new file (ie: VoidServerImpl.cpp)
//       to prevent overwriting the file on new generation of TestVoidMessages.proto


VoidServerImpl::VoidServerImpl()
{
}

VoidServerImpl::~VoidServerImpl()
{
}

//IPhoneBookService:
bool VoidServerImpl::Method1(const testvoidmessages::FooRequest & requestMessage, testvoidmessages::FooResponse & responseMessage)
{
  // TODO: build responseMessage based on requestMessage
  MessageBox(NULL, __FUNCTION__ "()", "VoidServerImpl", MB_OK | MB_ICONEXCLAMATION);
  return true; //success
}

bool VoidServerImpl::Method2(const testvoidmessages::FooRequest & requestMessage)
{
  // TODO: process requestMessage
  MessageBox(NULL, __FUNCTION__ "()", "VoidServerImpl", MB_OK | MB_ICONEXCLAMATION);
  return true; //success
}

bool VoidServerImpl::Method3(testvoidmessages::FooResponse & responseMessage)
{
  // TODO: build responseMessage
  MessageBox(NULL, __FUNCTION__ "()", "VoidServerImpl", MB_OK | MB_ICONEXCLAMATION);
  return true; //success
}

bool VoidServerImpl::Method4()
{
  // TODO: implement service method
  MessageBox(NULL, __FUNCTION__ "()", "VoidServerImpl", MB_OK | MB_ICONEXCLAMATION);
  return true; //success
}


}  // namespace testvoidmessages
