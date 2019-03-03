@echo off

call M:\Training\C++\new\comgen2\protobuf\trunk\2.5\temp_install.bat

REM set PROTOBUF_INCLUDE_DIR=
REM set PROTOBUF_LIB_DIR=
REM set PROTOBUF_DEBUG_LIBRARIES=
REM set PROTOBUF_RELEASE_LIBRARIES=
REM set GTEST_INCLUDE=
REM set GTEST_LIBRARY_DIR=

set BASEDIR=%cd%

cd /d %BASEDIR%\src\Debug

echo Deleting old proto file...
del %BASEDIR%\src\Debug\TestAddOut\TestAdd.proto
echo done.
echo.

echo Creating a temporary copy of patched proto file...
copy /Y "%BASEDIR%\src\Debug\TestAddOut\TestAdd_modified.proto" %TEMP%\TestAdd.proto
echo done.
echo.

echo Running plugin again...
protoc --protobuf-dcom-plugin_out=%BASEDIR%\src\Debug\TestAdd2 --proto_path=%BASEDIR%\src\Debug;%BASEDIR%\src\Debug\TestAddOut;%PROTOBUF_SRC_DIR%;%TEMP% %TEMP%\TestAdd.proto
echo done.
echo.

pause
