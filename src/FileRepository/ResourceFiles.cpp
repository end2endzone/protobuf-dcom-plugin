#include "ResourceFiles.h"

FileList getResourceFiles()
{
  FileList files;

  files.push_back(&bin2cpp::getClientCppFile());
  files.push_back(&bin2cpp::getClientFiltersFile());
  files.push_back(&bin2cpp::getClientHeaderFile());
  files.push_back(&bin2cpp::getClientProjectFile());
  files.push_back(&bin2cpp::getCMakeListsFile());
  files.push_back(&bin2cpp::getErrorHandlersCppFile());
  files.push_back(&bin2cpp::getErrorHandlersHeaderFile());
  files.push_back(&bin2cpp::getIComErrorProviderFile());
  files.push_back(&bin2cpp::getIServiceFile());
  files.push_back(&bin2cpp::getMessageSerializerCppFile());
  files.push_back(&bin2cpp::getMessageSerializerHeaderFile());
  files.push_back(&bin2cpp::getProtoLibFiltersFile());
  files.push_back(&bin2cpp::getProtoLibProjectFile());
  files.push_back(&bin2cpp::getRegisterServerDebugFile());
  files.push_back(&bin2cpp::getRegisterServerReleaseFile());
  files.push_back(&bin2cpp::getRegistryCppFile());
  files.push_back(&bin2cpp::getRegistryHeaderFile());
  files.push_back(&bin2cpp::getServerCppFile());
  files.push_back(&bin2cpp::getServerFiltersFile());
  files.push_back(&bin2cpp::getServerHeaderFile());
  files.push_back(&bin2cpp::getServerIdlFile());
  files.push_back(&bin2cpp::getServerImplCppFile());
  files.push_back(&bin2cpp::getServerImplFiltersFile());
  files.push_back(&bin2cpp::getServerImplHeaderFile());
  files.push_back(&bin2cpp::getServerImplProjectFile());
  files.push_back(&bin2cpp::getServerMainFile());
  files.push_back(&bin2cpp::getServerProjectFile());
  files.push_back(&bin2cpp::getSmartPointersFile());
  files.push_back(&bin2cpp::getSolutionFile());
  files.push_back(&bin2cpp::getUnregisterServerDebugFile());
  files.push_back(&bin2cpp::getUnregisterServerReleaseFile());

  return files;
}
