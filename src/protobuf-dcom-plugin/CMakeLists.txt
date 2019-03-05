add_executable(protobufdcomplugin
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
set_target_properties(protobufdcomplugin PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

# Define include directories for exported code.
target_include_directories(protobufdcomplugin
  PUBLIC
    $<INSTALL_INTERFACE:${PROTOBUFDCOMPLUGIN_INSTALL_INCLUDE_DIR}>  # for clients using the installed library.
)

add_dependencies(protobufdcomplugin libDCOM)
add_dependencies(protobufdcomplugin FileRepository)

target_link_libraries(protobufdcomplugin PUBLIC libDCOM)
target_link_libraries(protobufdcomplugin PUBLIC FileRepository)

install(TARGETS protobufdcomplugin
        EXPORT protobufdcomplugin-targets
        ARCHIVE DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_LIB_DIR}
        LIBRARY DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_LIB_DIR}
        RUNTIME DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_BIN_DIR}
)
