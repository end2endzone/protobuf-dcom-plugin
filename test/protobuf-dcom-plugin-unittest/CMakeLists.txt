# Manually get the location of include directories for libprotobuf
get_target_property(PROTOBUF_INCLUDE_DIRS libprotobuf INTERFACE_INCLUDE_DIRECTORIES)

# Manually get the location of protoc
get_property(PROTOC_LOCATION TARGET protoc PROPERTY LOCATION)

# Configure protobuf locator
set(PROTOBUF_LOCATOR_SOURCE ${CMAKE_CURRENT_BINARY_DIR}/protobuf_locator.cpp)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/protobuf_locator.cpp.in ${PROTOBUF_LOCATOR_SOURCE} @ONLY)

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
  ${PROTOBUF_LOCATOR_SOURCE}
  protobuf_locator.cpp.in
  protobuf_locator.h
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

# Define the proto files to process before building `protobuf-dcom-plugin_unittest`
set(OUTPUT_PROTO_FILES
  ${EXECUTABLE_OUTPUT_PATH}/TestBuildFull.proto
  ${EXECUTABLE_OUTPUT_PATH}/TestVoidMessages.proto
  ${EXECUTABLE_OUTPUT_PATH}/TestPluginRun.proto
  ${EXECUTABLE_OUTPUT_PATH}/TestDemo.proto
  ${EXECUTABLE_OUTPUT_PATH}/TestCalculator.proto
  ${EXECUTABLE_OUTPUT_PATH}/TestBuildQuick.proto
)
if (WIN32)
  # On Windows, we need to duplicate the output files for `Debug` and `Release` directories
  set(OUTPUT_PROTO_FILES_DEBUG)
  set(OUTPUT_PROTO_FILES_RELEASE)
  foreach(tmpfile ${OUTPUT_PROTO_FILES})
    string(REPLACE "${EXECUTABLE_OUTPUT_PATH}" "${EXECUTABLE_OUTPUT_PATH}/Debug"   tmp_debug   ${tmpfile})
    string(REPLACE "${EXECUTABLE_OUTPUT_PATH}" "${EXECUTABLE_OUTPUT_PATH}/Release" tmp_release ${tmpfile})
    set(OUTPUT_PROTO_FILES_DEBUG   ${OUTPUT_PROTO_FILES_DEBUG}   ${tmp_debug})
    set(OUTPUT_PROTO_FILES_RELEASE ${OUTPUT_PROTO_FILES_RELEASE} ${tmp_release})
  endforeach()
  set(OUTPUT_PROTO_FILES ${OUTPUT_PROTO_FILES_DEBUG} ${OUTPUT_PROTO_FILES_RELEASE})
endif()
foreach(output_file ${OUTPUT_PROTO_FILES})
  get_filename_component(filename ${output_file} NAME)
  #get_filename_component(filename_we ${output_file} NAME_WE)
  #get_filename_component(output_dir ${output_file} DIRECTORY)

  #Compute the input file's path
  set(input_file "${CMAKE_CURRENT_SOURCE_DIR}/${filename}")

  # message("Processing proto file: " ${filename})

  # Step 1: copy the file to the output directory
  add_custom_command(
    OUTPUT ${output_file}
    COMMAND ${CMAKE_COMMAND} -E copy
            ${input_file}
            ${output_file}
  )
endforeach()
add_custom_target(unittest-prebuild DEPENDS ${OUTPUT_PROTO_FILES})
add_dependencies(protobuf-dcom-plugin_unittest unittest-prebuild)


# Force Visual Studio to execute code in $(OutDir) when debugging from the IDE.
if (WIN32)
  file( WRITE "${CMAKE_CURRENT_BINARY_DIR}/protobuf-dcom-plugin_unittest.vcxproj.user" 
      "<?xml version=\"1.0\" encoding=\"utf-8\"?>     \
      <Project ToolsVersion=\"4.0\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">
      <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\">
          <LocalDebuggerWorkingDirectory>$(OutDir)</LocalDebuggerWorkingDirectory>
          <DebuggerFlavor>WindowsLocalDebugger</DebuggerFlavor>
      </PropertyGroup>
      <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|Win32'\">
          <LocalDebuggerWorkingDirectory>$(OutDir)</LocalDebuggerWorkingDirectory>
          <DebuggerFlavor>WindowsLocalDebugger</DebuggerFlavor>
      </PropertyGroup>
      <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|x64'\">
          <LocalDebuggerWorkingDirectory>$(OutDir)</LocalDebuggerWorkingDirectory>
          <DebuggerFlavor>WindowsLocalDebugger</DebuggerFlavor>
      </PropertyGroup>
      <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|x64'\">
          <LocalDebuggerWorkingDirectory>$(OutDir)</LocalDebuggerWorkingDirectory>
          <DebuggerFlavor>WindowsLocalDebugger</DebuggerFlavor>
      </PropertyGroup>
      </Project>"
  )
endif()

install(TARGETS protobuf-dcom-plugin_unittest
        EXPORT protobufdcomplugin-targets
        ARCHIVE DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_LIB_DIR}
        LIBRARY DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_LIB_DIR}
        RUNTIME DESTINATION ${PROTOBUFDCOMPLUGIN_INSTALL_BIN_DIR}
)
