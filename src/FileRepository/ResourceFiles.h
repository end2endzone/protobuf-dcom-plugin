#pragma once
#include <vector>

#include "EmbeddedFileClientCpp.h"
#include "EmbeddedFileClientFilters.h"
#include "EmbeddedFileClientHeader.h"
#include "EmbeddedFileClientProject.h"
#include "EmbeddedFileErrorHandlersCpp.h"
#include "EmbeddedFileErrorHandlersHeader.h"
#include "EmbeddedFileIComErrorProvider.h"
#include "EmbeddedFileIService.h"
#include "EmbeddedFileMessageSerializerCpp.h"
#include "EmbeddedFileMessageSerializerHeader.h"
#include "EmbeddedFileProtoLibFilters.h"
#include "EmbeddedFileProtoLibProject.h"
#include "EmbeddedFileRegisterServerDebug.h"
#include "EmbeddedFileRegisterServerRelease.h"
#include "EmbeddedFileRegistryCpp.h"
#include "EmbeddedFileRegistryHeader.h"
#include "EmbeddedFileServerCpp.h"
#include "EmbeddedFileServerFilters.h"
#include "EmbeddedFileServerHeader.h"
#include "EmbeddedFileServerIdl.h"
#include "EmbeddedFileServerImplCpp.h"
#include "EmbeddedFileServerImplFilters.h"
#include "EmbeddedFileServerImplHeader.h"
#include "EmbeddedFileServerImplProject.h"
#include "EmbeddedFileServerMain.h"
#include "EmbeddedFileServerProject.h"
#include "EmbeddedFileSmartPointers.h"
#include "EmbeddedFileSolution.h"
#include "EmbeddedFileUnregisterServerDebug.h"
#include "EmbeddedFileUnregisterServerRelease.h"

typedef std::vector<const bin2cpp::File *> FileList;

FileList getResourceFiles();
