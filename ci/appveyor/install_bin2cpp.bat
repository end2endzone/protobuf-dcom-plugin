@echo off

:: Validate appveyor's environment
if "%APPVEYOR_BUILD_FOLDER%"=="" (
  echo Please define 'APPVEYOR_BUILD_FOLDER' environment variable.
  exit /B 1
)

set GTEST_ROOT=%APPVEYOR_BUILD_FOLDER%\third_parties\googletest\install
set rapidassist_DIR=%APPVEYOR_BUILD_FOLDER%\third_parties\RapidAssist\install
set INSTALL_LOCATION=%APPVEYOR_BUILD_FOLDER%\third_parties\bin2cpp\install

echo ============================================================================
echo Cloning bin2cpp into %APPVEYOR_BUILD_FOLDER%\third_parties\bin2cpp
echo ============================================================================
mkdir %APPVEYOR_BUILD_FOLDER%\third_parties >NUL 2>NUL
cd %APPVEYOR_BUILD_FOLDER%\third_parties
git clone "https://github.com/end2endzone/bin2cpp.git"
cd bin2cpp
echo.

echo Checking out version v2.2.0...
git checkout 2.2.0
echo.

echo ============================================================================
echo Compiling...
echo ============================================================================
mkdir build >NUL 2>NUL
cd build
cmake -DCMAKE_INSTALL_PREFIX=%INSTALL_LOCATION% ..
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
