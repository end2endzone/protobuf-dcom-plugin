#include "TestCalculator.h"
#include "testutils.h"

void TestCalculator::SetUp()
{
}

void TestCalculator::TearDown()
{
}

TEST_F(TestCalculator, testRun)
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
