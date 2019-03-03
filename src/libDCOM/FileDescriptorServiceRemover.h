#pragma once

#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>

using namespace google::protobuf;

class FileDescriptorServiceRemover
{
public:
  FileDescriptorServiceRemover();
  ~FileDescriptorServiceRemover();

  const FileDescriptor * removeServicesFrom(const FileDescriptor * iFile);

private:
  google::protobuf::DescriptorPool mPool;
};
