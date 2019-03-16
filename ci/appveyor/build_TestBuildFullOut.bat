@echo off

:: Validate appveyor's environment
if "%APPVEYOR_BUILD_FOLDER%"=="" (
  echo Please define 'APPVEYOR_BUILD_FOLDER' environment variable.
  exit /B 1
)

set GTEST_ROOT=%APPVEYOR_BUILD_FOLDER%\third_parties\googletest\install
set rapidassist_DIR=%APPVEYOR_BUILD_FOLDER%\third_parties\RapidAssist\install
set bin2cpp_DIR=%APPVEYOR_BUILD_FOLDER%\third_parties\bin2cpp\install
set protobuf_DIR=%APPVEYOR_BUILD_FOLDER%\third_parties\protobuf\install
set INSTALL_LOCATION=%APPVEYOR_BUILD_FOLDER%\install

echo ============================================================================
echo Generating...
echo ============================================================================
cd /d %APPVEYOR_BUILD_FOLDER%/build/bin/%Configuration%/TestBuildFullOut
mkdir build >NUL 2>NUL
cd build
cmake -DBUILD_SHARED_LIBS=OFF ..
if %errorlevel% neq 0 exit /b %errorlevel%

echo ============================================================================
echo Compiling...
echo ============================================================================
cmake --build . --config %Configuration%
if %errorlevel% neq 0 exit /b %errorlevel%
echo.

::Delete all temporary environment variable created
set GTEST_ROOT=
set rapidassist_DIR=
set bin2cpp_DIR_DIR=
set protobuf_DIR=
set INSTALL_LOCATION=

::Return to launch folder
cd /d %~dp0
