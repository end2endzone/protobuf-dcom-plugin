#include "DemoServerImpl.h"

namespace testdemo {

//Global objects
///<DCOMPLUGIN_SERVER_IMPL_TEMPLATE_GLOBAL>
static long g_cCallCounter = 123;  // Count of GetSequentialNumber() calls
///</DCOMPLUGIN_SERVER_IMPL_TEMPLATE_GLOBAL>

DemoServerImpl::DemoServerImpl()
{
}

DemoServerImpl::~DemoServerImpl()
{
}

///<DCOMPLUGIN_SERVER_IMPL_TEMPLATE_DEFINITION>
//ICounterService
bool DemoServerImpl::GetSequentialNumber(const testdemo::VoidMessage & requestMessage, testdemo::SequentialNumber & responseMessage)
{
  g_cCallCounter++;

  responseMessage.Clear();
  responseMessage.set_value(g_cCallCounter);

  return true;
}

//ITextService
bool DemoServerImpl::Hello(const testdemo::HelloRequest & requestMessage, testdemo::HelloResponse & responseMessage)
{
  testdemo::HelloResponse response;

  std::string greetings;
  greetings.append("Hello ");
  if (requestMessage.has_name())
    greetings.append(requestMessage.name());
  else
    greetings.append("noname");
  greetings.append("!");

  responseMessage.Clear();
  responseMessage.set_greetings(greetings);

  return true;
}
///</DCOMPLUGIN_SERVER_IMPL_TEMPLATE_DEFINITION>

}  // namespace testdemo
