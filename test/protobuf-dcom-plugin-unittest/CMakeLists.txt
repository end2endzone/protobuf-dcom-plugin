add_executable(protobufdcomplugin_unittest
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
set_target_properties(protobufdcomplugin_unittest PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

target_include_directories(protobufdcomplugin_unittest 
  PRIVATE 
    ${GTEST_INCLUDE_DIR}
)
add_dependencies(protobufdcomplugin_unittest protobufdcomplugin)
target_link_libraries(protobufdcomplugin_unittest PRIVATE ${PTHREAD_LIBRARIES} ${GTEST_LIBRARIES} )

install(TARGETS protobufdcomplugin_unittest
        EXPORT protobufdcomplugin-targets
        ARCHIVE DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_LIB_DIR}
        LIBRARY DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_LIB_DIR}
        RUNTIME DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_BIN_DIR}
)
