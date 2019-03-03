#pragma once

#include <google/protobuf/descriptor.h>
#include <google/protobuf/compiler/code_generator.h>
#include <google/protobuf/io/zero_copy_stream.h>

#include "dcomplugin.pb.h"

using namespace google::protobuf;
using namespace google::protobuf::compiler;
using namespace google::protobuf::io;

class PluginCodeGenerator : public google::protobuf::compiler::CodeGenerator
{
public:
  PluginCodeGenerator();
  virtual ~PluginCodeGenerator();

  virtual bool Generate(const FileDescriptor * file, const std::string & parameter, GeneratorContext * generator_context, string * error) const;

private:
  void registerPropertiesMacros(const FileDescriptor * file, const dcomplugin::Component & component) const;
  void registerCodeGenerationMacros(const FileDescriptor * file, const dcomplugin::Component & component) const;
  void registerServiceBasedMacros(int iServiceIndex, const FileDescriptor * file, const dcomplugin::Component & component) const;
};
