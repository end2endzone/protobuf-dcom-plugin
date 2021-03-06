/**
 * This file was generated by bin2cpp v2.2.0
 * Copyright (C) 2013-2019 end2endzone.com. All rights reserved.
 * bin2cpp is open source software, see http://github.com/end2endzone/bin2cpp
 * Source code for file 'CMakeLists.txt', last modified 1552747336.
 * Do not modify this file.
 */
#include "EmbeddedFileCMakeLists.h"
#include <stdio.h> //for FILE
#include <string> //for memcpy
namespace bin2cpp
{
  class CMakeListsFile : public virtual bin2cpp::File
  {
  public:
    CMakeListsFile() { build(); }
    virtual ~CMakeListsFile() {}
    virtual size_t getSize() const { return 7320; }
    virtual const char * getFilename() const { return "CMakeLists.txt"; }
    virtual const char * getBuffer() const { return mBuffer.c_str(); }
    void build()
    {
      mBuffer.clear();
      mBuffer.reserve(getSize()); //allocate all required memory at once to prevent reallocations
      mBuffer.append("# CMakeLists.txt\r\ncmake_minimum_required(VERSION 3.4.3 FATAL_ERROR)\r\nproject(DCOMPLUGIN_COMPONENT_NAME)\r\n\r\n#############################################################################################", 200);
      mBuffer.append("#################################################\r\n# Standard CMake variables\r\n#########################################################################################################################", 200);
      mBuffer.append("#####################\r\n\r\n# Set a default build type if none was specified.\r\n# See https://blog.kitware.com/cmake-and-the-default-build-type/\r\nif(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)", 200);
      mBuffer.append("\r\n  message(STATUS \"Setting build type to \'Release\' as none was specified.\")\r\n  set(CMAKE_BUILD_TYPE Release CACHE STRING \"Choose the type of build.\" FORCE)\r\n  mark_as_advanced(CMAKE_BUILD_TYPE)\r\n  # ", 200);
      mBuffer.append("Set the possible values of build type for cmake-gui\r\n  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS \"Debug\" \"Release\" \"MinSizeRel\" \"RelWithDebInfo\")\r\nendif()\r\n\r\n# Set the output folder where y", 200);
      mBuffer.append("our program will be created\r\nset(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)\r\nset(   LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)\r\n\r\n###############################################################", 200);
      mBuffer.append("###############################################################################\r\n# CMake properties\r\n###################################################################################################", 200);
      mBuffer.append("###########################################\r\nMESSAGE( STATUS \"PROJECT_NAME:             \" ${PROJECT_NAME} )\r\nMESSAGE( STATUS \"CMAKE_BINARY_DIR:         \" ${CMAKE_BINARY_DIR} )\r\nMESSAGE( STATUS \"CMAKE_", 200);
      mBuffer.append("CURRENT_BINARY_DIR: \" ${CMAKE_CURRENT_BINARY_DIR} )\r\nMESSAGE( STATUS \"CMAKE_SOURCE_DIR:         \" ${CMAKE_SOURCE_DIR} )\r\nMESSAGE( STATUS \"CMAKE_CURRENT_SOURCE_DIR: \" ${CMAKE_CURRENT_SOURCE_DIR} )\r\nMES", 200);
      mBuffer.append("SAGE( STATUS \"PROJECT_BINARY_DIR:       \" ${PROJECT_BINARY_DIR} )\r\nMESSAGE( STATUS \"PROJECT_SOURCE_DIR:       \" ${PROJECT_SOURCE_DIR} )\r\nMESSAGE( STATUS \"EXECUTABLE_OUTPUT_PATH:   \" ${EXECUTABLE_OUTPU", 200);
      mBuffer.append("T_PATH} )\r\nMESSAGE( STATUS \"LIBRARY_OUTPUT_PATH:      \" ${LIBRARY_OUTPUT_PATH} )\r\nMESSAGE( STATUS \"CMAKE_MODULE_PATH:        \" ${CMAKE_MODULE_PATH} )\r\nMESSAGE( STATUS \"CMAKE_COMMAND:            \" ${CM", 200);
      mBuffer.append("AKE_COMMAND} )\r\nMESSAGE( STATUS \"CMAKE_ROOT:               \" ${CMAKE_ROOT} )\r\nMESSAGE( STATUS \"CMAKE_CURRENT_LIST_FILE:  \" ${CMAKE_CURRENT_LIST_FILE} )\r\nMESSAGE( STATUS \"CMAKE_CURRENT_LIST_LINE:  \" ${", 200);
      mBuffer.append("CMAKE_CURRENT_LIST_LINE} )\r\nMESSAGE( STATUS \"CMAKE_INCLUDE_PATH:       \" ${CMAKE_INCLUDE_PATH} )\r\nMESSAGE( STATUS \"CMAKE_LIBRARY_PATH:       \" ${CMAKE_LIBRARY_PATH} )\r\nMESSAGE( STATUS \"CMAKE_SYSTEM:  ", 200);
      mBuffer.append("           \" ${CMAKE_SYSTEM} )\r\nMESSAGE( STATUS \"CMAKE_SYSTEM_NAME:        \" ${CMAKE_SYSTEM_NAME} )\r\nMESSAGE( STATUS \"CMAKE_SYSTEM_VERSION:     \" ${CMAKE_SYSTEM_VERSION} )\r\nMESSAGE( STATUS \"CMAKE_SYST", 200);
      mBuffer.append("EM_PROCESSOR:   \" ${CMAKE_SYSTEM_PROCESSOR} )\r\n\r\n##############################################################################################################################################\r\n# Depen", 200);
      mBuffer.append("dencies\r\n##############################################################################################################################################\r\nfind_package(protobuf 2.5.0 REQUIRED NO_CMAKE_S", 200);
      mBuffer.append("YSTEM_PATH NO_CMAKE_PATH NO_CMAKE_SYSTEM_PACKAGE_REGISTRY )\r\n\r\n# Manually get the location of include directories for libprotobuf\r\nget_target_property(PROTOBUF_INCLUDE_DIRS libprotobuf INTERFACE_INCLU", 200);
      mBuffer.append("DE_DIRECTORIES)\r\n\r\n##############################################################################################################################################\r\n# Project settings\r\n#################", 200);
      mBuffer.append("#############################################################################################################################\r\n\r\n# Force a debug postfix if none specified.\r\n# This allows publishing bo", 200);
      mBuffer.append("th release and debug binaries to the same location\r\n# and it helps to prevent linking with the wrong library on Windows.\r\nif(NOT CMAKE_DEBUG_POSTFIX)\r\n  set(CMAKE_DEBUG_POSTFIX \"-d\")\r\nendif()\r\n\r\n# Pre", 200);
      mBuffer.append("vents annoying warnings on MSVC\r\nif (WIN32)\r\n  add_definitions(-D_CRT_SECURE_NO_WARNINGS)\r\nendif()\r\n\r\nadd_library(DCOMPLUGIN_COMPONENT_NAMEClient SHARED\r\n  DCOMPLUGIN_COMPONENT_NAMEClient.h\r\n  DCOMPLU", 200);
      mBuffer.append("GIN_COMPONENT_NAMEClient.cpp\r\n)\r\nset_target_properties(DCOMPLUGIN_COMPONENT_NAMEClient PROPERTIES COMPILE_DEFINITIONS DCOMPLUGIN_COMPONENT_NAME_CLIENT_EXPORTS)\r\n\r\nadd_library(DCOMPLUGIN_COMPONENT_NAME", 200);
      mBuffer.append("ProtoLib\r\n  ErrorHandlers.h\r\n  IComErrorProvider.h\r\n  MessageSerializer.h\r\n  Registry.h\r\n  \r\n  ErrorHandlers.cpp\r\n  MessageSerializer.cpp\r\n  Registry.cpp\r\n  \r\n  # Proto Files\r\n  dcomplugin.pb.cc\r\n  dc", 200);
      mBuffer.append("omplugin.pb.h\r\n  DCOMPLUGIN_COMPONENT_NAME.pb.cc\r\n  DCOMPLUGIN_COMPONENT_NAME.pb.h\r\n  DCOMPLUGIN_COMPONENT_NAME.proto\r\n  \r\n  # Services\r\n  IPhoneBookService.h\r\n)\r\n\r\nadd_executable(DCOMPLUGIN_COMPONENT", 200);
      mBuffer.append("_NAMEServer WIN32 \r\n  SmartPointers.h\r\n  DCOMPLUGIN_COMPONENT_NAMEServer.h\r\n  DCOMPLUGIN_COMPONENT_NAMEServer.cpp\r\n  DCOMPLUGIN_COMPONENT_NAMEServerMain.cpp\r\n\r\n  # The current implementation adds the ", 200);
      mBuffer.append("IDL file directly into the project source files.\r\n  # This let CMake handle the MIDL compilation automatically and does not give us control on how to name the generated files (header, iid and proxy)\r\n", 200);
      mBuffer.append("  # TODO: Investigate the use of invoking the MIDL compilor manually as described here: https://stackoverflow.com/questions/46878906/invoke-midl-compiler-from-cmake\r\n  DCOMPLUGIN_COMPONENT_NAMEServer.", 200);
      mBuffer.append("idl\r\n)\r\n\r\nadd_library(DCOMPLUGIN_COMPONENT_NAMEServerImpl\r\n  DCOMPLUGIN_COMPONENT_NAMEServerImpl.h\r\n  IPhoneBookService.h\r\n  DCOMPLUGIN_COMPONENT_NAMEServerImpl.template.cpp\r\n)\r\n\r\n# Force CMAKE_DEBUG_", 200);
      mBuffer.append("POSTFIX for executables\r\nset_target_properties(DCOMPLUGIN_COMPONENT_NAMEClient     PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})\r\nset_target_properties(DCOMPLUGIN_COMPONENT_NAMEProtoLib   PROPERTIE", 200);
      mBuffer.append("S DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})\r\nset_target_properties(DCOMPLUGIN_COMPONENT_NAMEServer     PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})\r\nset_target_properties(DCOMPLUGIN_COMPONENT_NAMEServ", 200);
      mBuffer.append("erImpl PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})\r\n\r\n# Define include directories for exported code.\r\ntarget_include_directories(DCOMPLUGIN_COMPONENT_NAMEClient     PRIVATE ${PROTOBUF_INCLUDE_DI", 200);
      mBuffer.append("RS} ${CMAKE_CURRENT_BINARY_DIR})\r\ntarget_include_directories(DCOMPLUGIN_COMPONENT_NAMEProtoLib   PRIVATE ${PROTOBUF_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})\r\ntarget_include_directories(DCOMPLUGIN_CO", 200);
      mBuffer.append("MPONENT_NAMEServer     PRIVATE ${PROTOBUF_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})\r\ntarget_include_directories(DCOMPLUGIN_COMPONENT_NAMEServerImpl PRIVATE ${PROTOBUF_INCLUDE_DIRS} ${CMAKE_CURRENT_BI", 200);
      mBuffer.append("NARY_DIR})\r\n\r\nadd_dependencies(DCOMPLUGIN_COMPONENT_NAMEClient      DCOMPLUGIN_COMPONENT_NAMEProtoLib DCOMPLUGIN_COMPONENT_NAMEServer)\r\nadd_dependencies(DCOMPLUGIN_COMPONENT_NAMEServer      DCOMPLUGIN", 200);
      mBuffer.append("_COMPONENT_NAMEProtoLib DCOMPLUGIN_COMPONENT_NAMEServerImpl)\r\nadd_dependencies(DCOMPLUGIN_COMPONENT_NAMEServerImpl  DCOMPLUGIN_COMPONENT_NAMEProtoLib)\r\n\r\ntarget_link_libraries(DCOMPLUGIN_COMPONENT_NAM", 200);
      mBuffer.append("EClient     PRIVATE DCOMPLUGIN_COMPONENT_NAMEProtoLib libprotobuf)\r\ntarget_link_libraries(DCOMPLUGIN_COMPONENT_NAMEServer     PRIVATE DCOMPLUGIN_COMPONENT_NAMEProtoLib DCOMPLUGIN_COMPONENT_NAMEServerI", 200);
      mBuffer.append("mpl libprotobuf)\r\ntarget_link_libraries(DCOMPLUGIN_COMPONENT_NAMEServerImpl PRIVATE DCOMPLUGIN_COMPONENT_NAMEProtoLib)\r\n", 120);
    }
    virtual bool save(const char * iFilename) const
    {
      FILE * f = fopen(iFilename, "wb");
      if (!f) return false;
      size_t fileSize = getSize();
      const char * buffer = getBuffer();
      fwrite(buffer, 1, fileSize, f);
      fclose(f);
      return true;
    }
  private:
    std::string mBuffer;
  };
  const File & getCMakeListsFile() { static CMakeListsFile _instance; return _instance; }
}; //bin2cpp
