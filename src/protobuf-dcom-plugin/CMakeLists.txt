add_executable(protobuf-dcom-plugin
  ${PROTOBUFDCOMPLUGIN_VERSION_HEADER}
  ${PROTOBUFDCOMPLUGIN_CONFIG_HEADER}
  MacroManager.cpp
  MacroManager.h
  main.cpp
  PluginCodeGenerator.cpp
  PluginCodeGenerator.h
  postbuild.bat
  targetver.h
)

# Force CMAKE_DEBUG_POSTFIX for executables
set_target_properties(protobuf-dcom-plugin PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

# Manually get the location of include directories for libprotobuf
get_target_property(PROTOBUF_INCLUDE_DIRS libprotobuf INTERFACE_INCLUDE_DIRECTORIES)

# Define include directories for exported code.
target_include_directories(protobuf-dcom-plugin
  PUBLIC
    $<INSTALL_INTERFACE:${PROTOBUFDCOMPLUGIN_INSTALL_INCLUDE_DIR}>  # for clients using the installed library.
  PRIVATE
    ${PROTOBUF_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/src/libDCOM # for stringfunc.h
    ${CMAKE_CURRENT_BINARY_DIR}/../libDCOM   # for dcomplugin.pb.h
    ${CMAKE_SOURCE_DIR}/src/FileRepository # for ResourceFiles.h
)

add_dependencies(protobuf-dcom-plugin libDCOM FileRepository)

target_link_libraries(protobuf-dcom-plugin PUBLIC libDCOM FileRepository libprotobuf libprotoc)

install(TARGETS protobuf-dcom-plugin
        EXPORT protobufdcomplugin-targets
        ARCHIVE DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_LIB_DIR}
        LIBRARY DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_LIB_DIR}
        RUNTIME DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_BIN_DIR}
)
