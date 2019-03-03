#include "TestVoidMessages.h"
#include "testutils.h"

void TestVoidMessages::SetUp()
{
}

void TestVoidMessages::TearDown()
{
}

TEST_F(TestVoidMessages, DISABLED_testRun) //requires protobuf version 3 (proto3)
{
  //build
  std::string cmdline;
  cmdline.append("protoc.exe --plugin=protoc-gen-");
  cmdline.append(getPluginName());
  cmdline.append("=");
  cmdline.append(getPluginFilePath());
  cmdline.append(" --");
  cmdline.append(getPluginName());
  cmdline.append("_out=");
  cmdline.append(getTestOutDir());
  cmdline.append(" --proto_path=");
  cmdline.append(getTestProtoPath());
  cmdline.append(" ");
  cmdline.append(getTestProtoFilePath());

  //run command line
  ASSERT_EXEC(cmdline.c_str());
}
