@echo off

set filename=dcomplugin.proto

echo Compiling %filename%...
protoc.exe --version
protoc --cpp_out=%cd% --proto_path=.;%PROTOBUF_SRC_DIR% ./%filename%
echo done
echo.

pause
