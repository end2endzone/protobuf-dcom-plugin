add_executable(protobuf-dcom-plugin_unittest
  ${PROTOBUFDCOMPLUGIN_EXPORT_HEADER}
  ${PROTOBUFDCOMPLUGIN_VERSION_HEADER}
  ${PROTOBUFDCOMPLUGIN_CONFIG_HEADER}
  TestVoidMessages.proto
  gtesthelper.cpp
  gtesthelper.h
  main.cpp
  postbuild.bat
  proto_postbuild.bat
  targetver.h
  TestBuildFull.bat
  TestBuildFull.cpp
  TestBuildFull.h
  TestBuildFull.proto
  TestBuildQuick.bat
  TestBuildQuick.cpp
  TestBuildQuick.h
  TestBuildQuick.proto
  TestCalculator.bat
  TestCalculator.cpp
  TestCalculator.h
  TestCalculator.proto
  TestDcomFunctions.cpp
  TestDcomFunctions.h
  TestDemo.bat
  TestDemo.cpp
  TestDemo.h
  TestDemo.proto
  TestMd5GuidGenerator.cpp
  TestMd5GuidGenerator.h
  TestPath.cpp
  TestPath.h
  TestPluginRun.bat
  TestPluginRun.cpp
  TestPluginRun.h
  TestPluginRun.proto
  TestProtoFunctions.cpp
  TestProtoFunctions.h
  TestStringFunctions.cpp
  TestStringFunctions.h
  testutils.cpp
  testutils.h
  TestVoidMessages.bat
  TestVoidMessages.cpp
  TestVoidMessages.h
)

# Unit test projects requires to link with pthread if also linking with gtest
if(NOT WIN32)
  set(PTHREAD_LIBRARIES -pthread)
endif()

# Force CMAKE_DEBUG_POSTFIX for executables
set_target_properties(protobuf-dcom-plugin_unittest PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

# Manually get the location of include directories for libprotobuf
get_target_property(PROTOBUF_INCLUDE_DIRS libprotobuf INTERFACE_INCLUDE_DIRECTORIES)

target_include_directories(protobuf-dcom-plugin_unittest 
  PRIVATE 
    ${GTEST_INCLUDE_DIR}
    ${PROTOBUF_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/src/libDCOM # for stringfunc.h
)
add_dependencies(protobuf-dcom-plugin_unittest protobuf-dcom-plugin)
target_link_libraries(protobuf-dcom-plugin_unittest PRIVATE libDCOM ${PTHREAD_LIBRARIES} ${GTEST_LIBRARIES} )

install(TARGETS protobuf-dcom-plugin_unittest
        EXPORT protobufdcomplugin-targets
        ARCHIVE DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_LIB_DIR}
        LIBRARY DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_LIB_DIR}
        RUNTIME DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_BIN_DIR}
)
