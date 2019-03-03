#pragma once

#include "IGuidGenerator.h"

class Md5GuidGenerator : public virtual IGuidGenerator
{
public:
  Md5GuidGenerator();
  virtual ~Md5GuidGenerator();

  //IGuidGenerator
  virtual std::string newGuid();

  void setProtoFilename(const std::string & iProtoFilename);
  void setPackage(const std::string & iPackage);
  void setComponentName(const std::string & iComponentName);
  void setOutputFilename(const std::string & iOutputFilename);

private:
  std::string mProtoFilename;
  std::string mPackage;
  std::string mComponentName;
  std::string mOutputFilename;
};
