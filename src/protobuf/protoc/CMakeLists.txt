project( protoc )

set(SOURCES
  ${PROTOBUF_ROOT}/src/google/protobuf/compiler/main.cc
)

add_definitions(
  -D_CONSOLE
)

add_executable( protoc ${SOURCES} )
target_link_libraries( protoc libprotoc )
if( UNIX )
  target_link_libraries( protoc -lpthread )
endif()

install(TARGETS protoc
        EXPORT protobuf-targets
        ARCHIVE DESTINATION ${PROTOBUF_INSTALL_LIB_DIR}
        LIBRARY DESTINATION ${PROTOBUF_INSTALL_LIB_DIR}
        RUNTIME DESTINATION ${PROTOBUF_INSTALL_BIN_DIR}
)
