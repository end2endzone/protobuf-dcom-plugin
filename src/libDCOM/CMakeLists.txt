add_library(libDCOM
  ${PROTOBUFDCOMPLUGIN_EXPORT_HEADER}
  ${PROTOBUFDCOMPLUGIN_VERSION_HEADER}
  ${PROTOBUFDCOMPLUGIN_CONFIG_HEADER}
  ComponentManager.cpp
  ComponentManager.h
  dcom.cpp
  dcom.h
  DComGenerator.cpp
  DComGenerator.h
  dcomplugin.bat
  dcomplugin.pb.cc
  dcomplugin.pb.h
  dcomplugin.proto
  DebugPrinter.cpp
  DebugPrinter.h
  FileDescriptorServiceRemover.cpp
  FileDescriptorServiceRemover.h
  IGuidGenerator.h
  md5.cpp
  md5.h
  md5Ex.cpp
  md5Ex.h
  Md5GuidGenerator.cpp
  Md5GuidGenerator.h
  path.cpp
  path.h
  protofunc.cpp
  protofunc.h
  StreamPrinter.cpp
  StreamPrinter.h
  stringfunc.cpp
  stringfunc.h
)

# Force CMAKE_DEBUG_POSTFIX for executables
set_target_properties(libDCOM PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

# Define include directories for exported code.
target_include_directories(libDCOM
  PUBLIC
    $<INSTALL_INTERFACE:${PROTOBUFDCOMPLUGIN_INSTALL_INCLUDE_DIR}>  # for clients using the installed library.
  PRIVATE
    ${CMAKE_SOURCE_DIR}/third_parties/
)
add_dependencies(libDCOM FileRepository)
target_link_libraries(libDCOM PRIVATE FileRepository protobuf )

install(TARGETS libDCOM
        EXPORT protobufdcomplugin-targets
        ARCHIVE DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_LIB_DIR}
        LIBRARY DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_LIB_DIR}
        RUNTIME DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_BIN_DIR}
)
