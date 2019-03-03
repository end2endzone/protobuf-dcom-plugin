#include "AddServerImpl.h"

namespace testadd {

//Global objects
// TODO: Rename or copy this template to a new file (ie: AddServerImpl.cpp)
//       to prevent overwriting the file on new generation of TestAdd.proto
static long g_FirstNumber = 0;
static long g_SecondNumber = 0;

AddServerImpl::AddServerImpl()
{
}

AddServerImpl::~AddServerImpl()
{
}

//ICalculatorService:
bool AddServerImpl::SetFirstNumber(const testadd::InputNumberRequest & requestMessage, testadd::VoidResponse & responseMessage)
{
  g_FirstNumber = requestMessage.value();
  return true; //success
}

bool AddServerImpl::SetSecondNumber(const testadd::InputNumberRequest & requestMessage, testadd::VoidResponse & responseMessage)
{
  g_SecondNumber = requestMessage.value();
  return true; //success
}

bool AddServerImpl::DoTheAddition(const testadd::VoidRequest & requestMessage, testadd::OutputNumberResponse & responseMessage)
{
  responseMessage.set_value(g_FirstNumber + g_SecondNumber);
  return true; //success
}


}  // namespace testadd
