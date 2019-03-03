#pragma once

#include <google/protobuf/descriptor.h>
#include "dcomplugin.pb.h"

class DComGenerator
{
public:
  DComGenerator();
  virtual ~DComGenerator();

  void init(const google::protobuf::FileDescriptor * iFile, const dcomplugin::Component & iComponent);

  const google::protobuf::FileDescriptor * getFileDescriptor() const;
  const dcomplugin::Component & getComponent() const;

  //code generation methods
  std::string getClientDefinition() const;
  std::string getAllServicesDeclaration() const;
  std::string getAllServicesIncludeList() const;
  std::string getAllServicesVirtualImplementationString() const;
  std::string getAllServicesVcxprojInjection() const;
  std::string getAllServicesFiltersInjection() const;
  std::string getCoClassDefinition() const;
  std::string getCoClassDeclaration() const;
  std::string getIdlServicesDeclaration() const;
  std::string getServerImplTemplateGlobalSection() const;
  std::string getServerImplTemplateDefinition() const;

  //service based generation methods
  std::string getMethodDocumentation(const char * iIndentation, bool isPureVirtual, const int iServiceIndex, const int iMethodIndex) const;
  std::string getMethodDocumentation(const char * iIndentation, bool isPureVirtual, const std::string & methodName, const std::string & interfaceName, const std::string & inputTypeName, const std::string & outputTypeName) const;
  std::string getServiceInterfaceDeclaration(int iServiceIndex) const;

private:
  //methods
  bool isEmptyMessage(const std::string & iTypeName) const;
  const ::google::protobuf::Descriptor * findMessageDescriptor(const google::protobuf::FileDescriptor * file, const std::string & iTypeName) const;

  //attributes
  //const google::protobuf::DescriptorPool * mPool;
  const google::protobuf::FileDescriptor * mFile;
  dcomplugin::Component mComponent;
};
