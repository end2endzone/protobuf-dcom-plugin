#pragma once

#include <google/protobuf/descriptor.h>
#include "dcomplugin.pb.h"

class ComponentManager
{
public:
  ComponentManager();
  virtual ~ComponentManager();

  static bool validate(const dcomplugin::Component & c, std::string & oError);
  static bool validate(const dcomplugin::Component & c, const std::string & iMessagePrefix, std::string & oError);
  static bool validate(const dcomplugin::TypeLib & typelib, const std::string & iMessagePrefix, std::string & oError);
  static bool validate(const dcomplugin::CoClass & coclass, const std::string & iMessagePrefix, std::string & oError);
  static bool validate(const dcomplugin::CoInterface & cointerface, const std::string & iMessagePrefix, std::string & oError);
  static bool validate(const dcomplugin::Identifier & id, const std::string & iMessagePrefix, std::string & oError);
  static bool isValid(const dcomplugin::Component & c);

  static void build(dcomplugin::Component & c);
  static void build(dcomplugin::Component & c, const google::protobuf::FileDescriptor & iFileDescriptor);
  static void build(dcomplugin::TypeLib & typelib, const std::string & iComponentName);
  static void build(dcomplugin::CoClass & coclass, const std::string & iComponentName);
  static void build(dcomplugin::CoInterface & cointerface, const std::string & iComponentName);
  static void build(dcomplugin::Identifier & id);

private:
  //methods
  static void setDefaultHelpstring(dcomplugin::Identifier & id, const std::string & iValue);

  //attributes
};
