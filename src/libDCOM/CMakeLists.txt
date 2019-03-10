# Manually get the location of include directories for libprotobuf
get_target_property(PROTOBUF_INCLUDE_DIRS libprotobuf INTERFACE_INCLUDE_DIRECTORIES)

# Copy the 'dcomplugin.proto' file to executable directory
if (WIN32)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/dcomplugin.proto ${EXECUTABLE_OUTPUT_PATH}/Debug/dcomplugin.proto   @ONLY)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/dcomplugin.proto ${EXECUTABLE_OUTPUT_PATH}/Release/dcomplugin.proto @ONLY)
else()
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/dcomplugin.proto ${EXECUTABLE_OUTPUT_PATH}/dcomplugin.proto @ONLY)
endif()

# Execute 'dcomplugin.proto' and output to CMAKE_CURRENT_BINARY_DIR
set(PROTO_FILE "dcomplugin.proto")
set(GENERATED_FILES
  ${CMAKE_CURRENT_BINARY_DIR}/dcomplugin.pb.cc
  ${CMAKE_CURRENT_BINARY_DIR}/dcomplugin.pb.h
)
add_custom_command(
  OUTPUT ${GENERATED_FILES}
  # Warning: CMake treats ; character differently. They must be escaped to prevent issues
  COMMAND echo protoc --cpp_out=${CMAKE_CURRENT_BINARY_DIR} --proto_path=.\;${PROTOBUF_INCLUDE_DIRS}\;${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/${PROTO_FILE}
  COMMAND      protoc --cpp_out=${CMAKE_CURRENT_BINARY_DIR} --proto_path=.\;${PROTOBUF_INCLUDE_DIRS}\;${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/${PROTO_FILE}
  COMMAND echo done
)


if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/path2.cpp")
  set(FILE_TEMPLATE path2.cpp)
else()
  set(FILE_TEMPLATE path.cpp)
endif()

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
  ${FILE_TEMPLATE}
  path.h
  protofunc.cpp
  protofunc.h
  StreamPrinter.cpp
  StreamPrinter.h
  stringfunc.cpp
  stringfunc.h
  ${GENERATED_FILES}
)

# Force CMAKE_DEBUG_POSTFIX for executables
set_target_properties(libDCOM PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

# Define include directories for exported code.
target_include_directories(libDCOM
  PUBLIC
    $<INSTALL_INTERFACE:${PROTOBUFDCOMPLUGIN_INSTALL_INCLUDE_DIR}>  # for clients using the installed library.
  PRIVATE
    ${PROTOBUF_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}   # for dcomplugin.pb.h
)
add_dependencies(libDCOM FileRepository)
target_link_libraries(libDCOM PRIVATE FileRepository libprotobuf )


install(TARGETS libDCOM
        EXPORT protobufdcomplugin-targets
        ARCHIVE DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_LIB_DIR}
        LIBRARY DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_LIB_DIR}
        RUNTIME DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_BIN_DIR}
)
