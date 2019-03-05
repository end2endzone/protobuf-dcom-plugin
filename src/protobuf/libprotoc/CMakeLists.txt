project( libprotoc )

set(SOURCES
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/code_generator.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/command_line_interface.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/cpp/cpp_enum.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/cpp/cpp_enum_field.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/cpp/cpp_extension.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/cpp/cpp_field.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/cpp/cpp_file.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/cpp/cpp_generator.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/cpp/cpp_helpers.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/cpp/cpp_message.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/cpp/cpp_message_field.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/cpp/cpp_primitive_field.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/cpp/cpp_service.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/cpp/cpp_string_field.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/java/java_enum.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/java/java_enum_field.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/java/java_extension.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/java/java_field.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/java/java_file.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/java/java_generator.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/java/java_helpers.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/java/java_message.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/java/java_message_field.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/java/java_primitive_field.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/java/java_service.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/python/python_generator.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/zip_writer.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/plugin.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/plugin.pb.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/subprocess.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/java/java_string_field.cc
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/java/java_doc_comment.cc
  )

if(WIN32 AND BUILD_SHARED_LIBS AND MSVC)
  add_definitions("-DLIBPROTOC_EXPORTS")
endif()

add_library( libprotoc ${SOURCES} )

# Define include directories for exported code.
target_include_directories(libprotoc
  PUBLIC
    $<INSTALL_INTERFACE:${PROTOBUF_INSTALL_INCLUDE_DIR}>  # for clients using the installed library.
)

target_link_libraries( libprotoc libprotobuf )

install(TARGETS libprotoc
        EXPORT protobuf-targets
        ARCHIVE DESTINATION ${PROTOBUF_INSTALL_LIB_DIR}
        LIBRARY DESTINATION ${PROTOBUF_INSTALL_LIB_DIR}
        RUNTIME DESTINATION ${PROTOBUF_INSTALL_BIN_DIR}
)
