# CMakeLists.txt
cmake_minimum_required(VERSION 3.4.3 FATAL_ERROR)
project(DCOMPLUGIN_COMPONENT_NAME)

##############################################################################################################################################
# Standard CMake variables
##############################################################################################################################################

# Set a default build type if none was specified.
# See https://blog.kitware.com/cmake-and-the-default-build-type/
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Release' as none was specified.")
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  mark_as_advanced(CMAKE_BUILD_TYPE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# Set the output folder where your program will be created
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(   LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

##############################################################################################################################################
# CMake properties
##############################################################################################################################################
MESSAGE( STATUS "PROJECT_NAME:             " ${PROJECT_NAME} )
MESSAGE( STATUS "CMAKE_BINARY_DIR:         " ${CMAKE_BINARY_DIR} )
MESSAGE( STATUS "CMAKE_CURRENT_BINARY_DIR: " ${CMAKE_CURRENT_BINARY_DIR} )
MESSAGE( STATUS "CMAKE_SOURCE_DIR:         " ${CMAKE_SOURCE_DIR} )
MESSAGE( STATUS "CMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR} )
MESSAGE( STATUS "PROJECT_BINARY_DIR:       " ${PROJECT_BINARY_DIR} )
MESSAGE( STATUS "PROJECT_SOURCE_DIR:       " ${PROJECT_SOURCE_DIR} )
MESSAGE( STATUS "EXECUTABLE_OUTPUT_PATH:   " ${EXECUTABLE_OUTPUT_PATH} )
MESSAGE( STATUS "LIBRARY_OUTPUT_PATH:      " ${LIBRARY_OUTPUT_PATH} )
MESSAGE( STATUS "CMAKE_MODULE_PATH:        " ${CMAKE_MODULE_PATH} )
MESSAGE( STATUS "CMAKE_COMMAND:            " ${CMAKE_COMMAND} )
MESSAGE( STATUS "CMAKE_ROOT:               " ${CMAKE_ROOT} )
MESSAGE( STATUS "CMAKE_CURRENT_LIST_FILE:  " ${CMAKE_CURRENT_LIST_FILE} )
MESSAGE( STATUS "CMAKE_CURRENT_LIST_LINE:  " ${CMAKE_CURRENT_LIST_LINE} )
MESSAGE( STATUS "CMAKE_INCLUDE_PATH:       " ${CMAKE_INCLUDE_PATH} )
MESSAGE( STATUS "CMAKE_LIBRARY_PATH:       " ${CMAKE_LIBRARY_PATH} )
MESSAGE( STATUS "CMAKE_SYSTEM:             " ${CMAKE_SYSTEM} )
MESSAGE( STATUS "CMAKE_SYSTEM_NAME:        " ${CMAKE_SYSTEM_NAME} )
MESSAGE( STATUS "CMAKE_SYSTEM_VERSION:     " ${CMAKE_SYSTEM_VERSION} )
MESSAGE( STATUS "CMAKE_SYSTEM_PROCESSOR:   " ${CMAKE_SYSTEM_PROCESSOR} )

##############################################################################################################################################
# Dependencies
##############################################################################################################################################
find_package(protobuf 2.5.0 REQUIRED NO_CMAKE_SYSTEM_PATH NO_CMAKE_PATH NO_CMAKE_SYSTEM_PACKAGE_REGISTRY )

# Manually get the location of include directories for libprotobuf
get_target_property(PROTOBUF_INCLUDE_DIRS libprotobuf INTERFACE_INCLUDE_DIRECTORIES)

##############################################################################################################################################
# Project settings
##############################################################################################################################################

# Force a debug postfix if none specified.
# This allows publishing both release and debug binaries to the same location
# and it helps to prevent linking with the wrong library on Windows.
if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX "-d")
endif()

# Prevents annoying warnings on MSVC
if (WIN32)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

add_library(DCOMPLUGIN_COMPONENT_NAMEClient SHARED
  DCOMPLUGIN_COMPONENT_NAMEClient.h
  DCOMPLUGIN_COMPONENT_NAMEClient.cpp
)
set_target_properties(DCOMPLUGIN_COMPONENT_NAMEClient PROPERTIES COMPILE_DEFINITIONS DCOMPLUGIN_COMPONENT_NAME_CLIENT_EXPORTS)

add_library(DCOMPLUGIN_COMPONENT_NAMEProtoLib
  ErrorHandlers.h
  IComErrorProvider.h
  MessageSerializer.h
  Registry.h
  
  ErrorHandlers.cpp
  MessageSerializer.cpp
  Registry.cpp
  
  # Proto Files
  dcomplugin.pb.cc
  dcomplugin.pb.h
  DCOMPLUGIN_COMPONENT_NAME.pb.cc
  DCOMPLUGIN_COMPONENT_NAME.pb.h
  DCOMPLUGIN_COMPONENT_NAME.proto
  
  # Services
  IPhoneBookService.h
)

add_executable(DCOMPLUGIN_COMPONENT_NAMEServer WIN32 
  SmartPointers.h
  DCOMPLUGIN_COMPONENT_NAMEServer.h
  DCOMPLUGIN_COMPONENT_NAMEServer.cpp
  DCOMPLUGIN_COMPONENT_NAMEServerMain.cpp

  # The current implementation adds the IDL file directly into the project source files.
  # This let CMake handle the MIDL compilation automatically and does not give us control on how to name the generated files (header, iid and proxy)
  # TODO: Investigate the use of invoking the MIDL compilor manually as described here: https://stackoverflow.com/questions/46878906/invoke-midl-compiler-from-cmake
  DCOMPLUGIN_COMPONENT_NAMEServer.idl
)

add_library(DCOMPLUGIN_COMPONENT_NAMEServerImpl
  DCOMPLUGIN_COMPONENT_NAMEServerImpl.h
  IPhoneBookService.h
  DCOMPLUGIN_COMPONENT_NAMEServerImpl.template.cpp
)

# Force CMAKE_DEBUG_POSTFIX for executables
set_target_properties(DCOMPLUGIN_COMPONENT_NAMEClient     PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
set_target_properties(DCOMPLUGIN_COMPONENT_NAMEProtoLib   PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
set_target_properties(DCOMPLUGIN_COMPONENT_NAMEServer     PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
set_target_properties(DCOMPLUGIN_COMPONENT_NAMEServerImpl PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

# Define include directories for exported code.
target_include_directories(DCOMPLUGIN_COMPONENT_NAMEClient     PRIVATE ${PROTOBUF_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(DCOMPLUGIN_COMPONENT_NAMEProtoLib   PRIVATE ${PROTOBUF_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(DCOMPLUGIN_COMPONENT_NAMEServer     PRIVATE ${PROTOBUF_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(DCOMPLUGIN_COMPONENT_NAMEServerImpl PRIVATE ${PROTOBUF_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})

add_dependencies(DCOMPLUGIN_COMPONENT_NAMEClient      DCOMPLUGIN_COMPONENT_NAMEProtoLib DCOMPLUGIN_COMPONENT_NAMEServer)
add_dependencies(DCOMPLUGIN_COMPONENT_NAMEServer      DCOMPLUGIN_COMPONENT_NAMEProtoLib DCOMPLUGIN_COMPONENT_NAMEServerImpl)
add_dependencies(DCOMPLUGIN_COMPONENT_NAMEServerImpl  DCOMPLUGIN_COMPONENT_NAMEProtoLib)

target_link_libraries(DCOMPLUGIN_COMPONENT_NAMEClient     PRIVATE DCOMPLUGIN_COMPONENT_NAMEProtoLib libprotobuf)
target_link_libraries(DCOMPLUGIN_COMPONENT_NAMEServer     PRIVATE DCOMPLUGIN_COMPONENT_NAMEProtoLib DCOMPLUGIN_COMPONENT_NAMEServerImpl libprotobuf)
target_link_libraries(DCOMPLUGIN_COMPONENT_NAMEServerImpl PRIVATE DCOMPLUGIN_COMPONENT_NAMEProtoLib)
