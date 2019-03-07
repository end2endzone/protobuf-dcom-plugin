// protobuf-dcom-plugin.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>

#include <google/protobuf/compiler/plugin.h>
#include "PluginCodeGenerator.h"

int main(int argc, char** argv)
{
  PluginCodeGenerator generator;
  return google::protobuf::compiler::PluginMain(argc, argv, &generator);
}
