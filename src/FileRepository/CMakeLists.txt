add_library(FileRepository
  ${PROTOBUFDCOMPLUGIN_EXPORT_HEADER}
  ${PROTOBUFDCOMPLUGIN_VERSION_HEADER}
  ${PROTOBUFDCOMPLUGIN_CONFIG_HEADER}
  EmbeddedFileUnregisterServerRelease.h
  EmbeddedFileClientCpp.cpp
  EmbeddedFileClientCpp.h
  EmbeddedFileClientFilters.cpp
  EmbeddedFileClientFilters.h
  EmbeddedFileClientHeader.cpp
  EmbeddedFileClientHeader.h
  EmbeddedFileClientProject.cpp
  EmbeddedFileClientProject.h
  EmbeddedFileErrorHandlersCpp.cpp
  EmbeddedFileErrorHandlersCpp.h
  EmbeddedFileErrorHandlersHeader.cpp
  EmbeddedFileErrorHandlersHeader.h
  EmbeddedFileIComErrorProvider.cpp
  EmbeddedFileIComErrorProvider.h
  EmbeddedFileIService.cpp
  EmbeddedFileIService.h
  EmbeddedFileMessageSerializerCpp.cpp
  EmbeddedFileMessageSerializerCpp.h
  EmbeddedFileMessageSerializerHeader.cpp
  EmbeddedFileMessageSerializerHeader.h
  EmbeddedFileProtoLibFilters.cpp
  EmbeddedFileProtoLibFilters.h
  EmbeddedFileProtoLibProject.cpp
  EmbeddedFileProtoLibProject.h
  EmbeddedFileRegisterServerDebug.cpp
  EmbeddedFileRegisterServerDebug.h
  EmbeddedFileRegisterServerRelease.cpp
  EmbeddedFileRegisterServerRelease.h
  EmbeddedFileRegistryCpp.cpp
  EmbeddedFileRegistryCpp.h
  EmbeddedFileRegistryHeader.cpp
  EmbeddedFileRegistryHeader.h
  EmbeddedFileServerCpp.cpp
  EmbeddedFileServerCpp.h
  EmbeddedFileServerFilters.cpp
  EmbeddedFileServerFilters.h
  EmbeddedFileServerHeader.cpp
  EmbeddedFileServerHeader.h
  EmbeddedFileServerIdl.cpp
  EmbeddedFileServerIdl.h
  EmbeddedFileServerImplCpp.cpp
  EmbeddedFileServerImplCpp.h
  EmbeddedFileServerImplFilters.cpp
  EmbeddedFileServerImplFilters.h
  EmbeddedFileServerImplHeader.cpp
  EmbeddedFileServerImplHeader.h
  EmbeddedFileServerImplProject.cpp
  EmbeddedFileServerImplProject.h
  EmbeddedFileServerMain.cpp
  EmbeddedFileServerMain.h
  EmbeddedFileServerProject.cpp
  EmbeddedFileServerProject.h
  EmbeddedFileSmartPointers.cpp
  EmbeddedFileSmartPointers.h
  EmbeddedFileSolution.cpp
  EmbeddedFileSolution.h
  EmbeddedFileUnregisterServerDebug.cpp
  EmbeddedFileUnregisterServerDebug.h
  EmbeddedFileUnregisterServerRelease.cpp
  ResourceFiles.cpp
  ResourceFiles.h  
)

# Force CMAKE_DEBUG_POSTFIX for executables
set_target_properties(FileRepository PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

# Define include directories for exported code.
target_include_directories(FileRepository
  PUBLIC
    $<INSTALL_INTERFACE:${PROTOBUFDCOMPLUGIN_INSTALL_INCLUDE_DIR}>  # for clients using the installed library.
)

install(TARGETS FileRepository
        EXPORT protobufdcomplugin-targets
        ARCHIVE DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_LIB_DIR}
        LIBRARY DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_LIB_DIR}
        RUNTIME DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_BIN_DIR}
)
