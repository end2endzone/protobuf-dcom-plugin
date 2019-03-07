@echo off

cd /d %~dp0
cd ..\..
set APPVEYOR=True
set APPVEYOR_BUILD_FOLDER=%cd%
set Configuration=Debug
echo Emulating appveyor's environment.
echo APPVEYOR_BUILD_FOLDER set to '%APPVEYOR_BUILD_FOLDER%'

set PATH=%APPVEYOR_BUILD_FOLDER%\third_parties\bin2cpp\install\bin;%PATH%
set PATH=%APPVEYOR_BUILD_FOLDER%\third_parties\protobuf\install\bin;%PATH%

echo.

:: Return back to original folder
cd /d %~dp0

:: Leave the command prompt open
cmd.exe /k echo AppVeyor ready...
