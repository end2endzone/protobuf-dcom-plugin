@echo off

::Add protoc.exe to PATH env var
echo Using
protoc.exe --version

protoc --cpp_out=%cd% --proto_path=.;..\protobuf-dcom-plugin;%PROTOBUF_SRC_DIR% ./TestBuildFull.proto

pause
