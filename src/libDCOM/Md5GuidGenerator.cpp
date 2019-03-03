#include "Md5GuidGenerator.h"
#include "md5.h"
#include "md5Ex.h"

Md5GuidGenerator::Md5GuidGenerator()
{
}

Md5GuidGenerator::~Md5GuidGenerator()
{
}

//IGuidGenerator
std::string Md5GuidGenerator::newGuid()
{
  MD5DIGEST digest;

  MD5_CTX context;
  MD5Init(&context);

  MD5Update(&context, this->mProtoFilename);
  MD5Update(&context, this->mPackage);
  MD5Update(&context, this->mComponentName);
  MD5Update(&context, this->mOutputFilename);

  MD5Final(digest.bytes, &context);

  std::string hex = toString(digest);

  //insert special characters
  hex.insert( 8, 1, '-');
  hex.insert(13, 1, '-');
  hex.insert(18, 1, '-');
  hex.insert(23, 1, '-');

  //simulate this guid as random
  hex[14] = '4';

  return hex;
}

void Md5GuidGenerator::setProtoFilename(const std::string & iProtoFilename)
{
  mProtoFilename = iProtoFilename;
}

void Md5GuidGenerator::setPackage(const std::string & iPackage)
{
  mPackage = iPackage;
}

void Md5GuidGenerator::setComponentName(const std::string & iComponentName)
{
  mComponentName = iComponentName;
}

void Md5GuidGenerator::setOutputFilename(const std::string & iOutputFilename)
{
  mOutputFilename = iOutputFilename;
}
