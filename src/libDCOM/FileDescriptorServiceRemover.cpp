#include "FileDescriptorServiceRemover.h"
#include "protofunc.h"

FileDescriptorServiceRemover::FileDescriptorServiceRemover()
{
}

FileDescriptorServiceRemover::~FileDescriptorServiceRemover()
{
}

const FileDescriptor * FileDescriptorServiceRemover::removeServicesFrom(const FileDescriptor * iFile)
{
  //copy everything from the file except the file itself to the pool
  addFileDescriptorToPool(mPool, *iFile, false);

  //copy the file (without its services)
  google::protobuf::FileDescriptorProto tmpProto;
  iFile->CopyTo(&tmpProto);
  tmpProto.clear_service();

  //retrieve the modified FileDescriptor *
  return mPool.BuildFile(tmpProto);
}
