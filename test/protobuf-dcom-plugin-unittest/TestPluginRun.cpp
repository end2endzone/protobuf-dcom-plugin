#include "TestPluginRun.h"
#include "testutils.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
#endif
#include <Windows.h>

std::string path_backup;

void TestPluginRun::SetUp()
{
  //backup %PATH%
  path_backup = getEnvironementVariable("PATH");

  //PROTOBUF_BINARY_DIR
  std::string PROTOBUF_BINARY_DIR = getEnvironementVariable("PROTOBUF_BINARY_DIR");
  addApplicationPath(PROTOBUF_BINARY_DIR.c_str());
}

void TestPluginRun::TearDown()
{
  //restore %PATH%
  setApplicationPath(path_backup.c_str());
}

TEST_F(TestPluginRun, testShowProtocVersion)
{
  std::string cmdline;
  cmdline.append("protoc.exe --version");

  ASSERT_EXEC(cmdline.c_str());
}

TEST_F(TestPluginRun, testRunPluginAbsolutePath)
{
  //protoc --plugin=protoc-gen-NAME=path/to/mybinary.exe --NAME_out=OUT_DIR
  //protoc --plugin=protoc-gen-foobar=[...]\src\Debug\protobuf-dcom-plugin.exe --foobar_out=[...]\src\Debug\output --proto_path=[...]\src\Debug\proto_files [...]\src\Debug\proto_files\addressbookservice.proto

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

  //validate no macros in output
  std::vector<std::string> generatedFiles = get_all_files_names_within_folder( getTestOutDir() );
  ASSERT_TRUE( generatedFiles.size() > 0 );
  std::string errorDescription;
  bool hasMacros = hasMacroInFiles(generatedFiles, errorDescription);
  ASSERT_FALSE(hasMacros) << errorDescription;
}

TEST_F(TestPluginRun, testRunPluginAutoDetect)
{
  //protoc --NAME_out=%TEMP%
  //protoc.exe looks for protoc-gen-NAME.exe in %PATH%


  //add plugin dir to %PATH%
  addApplicationPath(getExecutableDir().c_str());

  //duplicate the plugin file adding the expected "protoc-gen-" prefix to the filename
  std::string cmdline;
  cmdline = "";
  cmdline.append("copy \"");
  cmdline.append(getPluginFilePath());
  cmdline.append("\" \"");
  cmdline.append(getExecutableDir());
  cmdline.append("\\protoc-gen-");
  cmdline.append(getPluginFileName());
  cmdline.append("\" >NUL 2>NUL");

  //run command line
  ASSERT_EXEC(cmdline.c_str());

  //build
  cmdline = "";
  cmdline.append("protoc.exe --");
  cmdline.append(getPluginName());
  cmdline.append("_out=");
  cmdline.append(getTestOutDir());
  cmdline.append(" --proto_path=");
  cmdline.append(getTestProtoPath());
  cmdline.append(" ");
  cmdline.append(getTestProtoFilePath());
  
  //run command line
  ASSERT_EXEC(cmdline.c_str());

  //validate no macros in output
  std::vector<std::string> generatedFiles = get_all_files_names_within_folder( getTestOutDir() );
  ASSERT_TRUE( generatedFiles.size() > 0 );
  std::string errorDescription;
  bool hasMacros = hasMacroInFiles(generatedFiles, errorDescription);
  ASSERT_FALSE(hasMacros) << errorDescription;
}
