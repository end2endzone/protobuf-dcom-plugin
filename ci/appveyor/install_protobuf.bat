@echo off

:: Validate appveyor's environment
if "%APPVEYOR_BUILD_FOLDER%"=="" (
  echo Please define 'APPVEYOR_BUILD_FOLDER' environment variable.
  exit /B 1
)

set INSTALL_LOCATION=%APPVEYOR_BUILD_FOLDER%\third_parties\protobuf\install

echo ============================================================================
echo Cloning protobuf into %APPVEYOR_BUILD_FOLDER%\third_parties\protobuf
echo ============================================================================
mkdir %APPVEYOR_BUILD_FOLDER%\third_parties >NUL 2>NUL
cd %APPVEYOR_BUILD_FOLDER%\third_parties
git clone "https://github.com/protocolbuffers/protobuf.git"
cd protobuf
echo.

echo Checking out version v2.5.0...
git checkout v2.5.0
echo.

echo ============================================================================
echo Compiling...
echo ============================================================================
mkdir build >NUL 2>NUL
cd build
cmake -DCMAKE_INSTALL_PREFIX=%INSTALL_LOCATION% -DPROTOBUF_ROOT=%APPVEYOR_BUILD_FOLDER%/third_parties/protobuf %APPVEYOR_BUILD_FOLDER%\src\protobuf
if %errorlevel% neq 0 exit /b %errorlevel%
cmake --build . --config %Configuration%
if %errorlevel% neq 0 exit /b %errorlevel%
echo.

echo ============================================================================
echo Installing into %INSTALL_LOCATION%
echo ============================================================================
cmake --build . --config %Configuration% --target INSTALL
if %errorlevel% neq 0 exit /b %errorlevel%
echo.
