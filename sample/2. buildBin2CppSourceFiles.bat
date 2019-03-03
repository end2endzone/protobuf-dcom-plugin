@echo off

set path=%path%;"c:\Program Files\bin2cpp"
set path=%path%;"%cd%\..\..\bin2cpp"

echo Deleting existing files...
del ..\src\FileRepository\EmbeddedFile*.*
echo done
echo.

set SOURCE_FILES_DIR=%cd%\templateFiles
cd ..\src\FileRepository
set TARGET_FILES_DIR=%cd%

echo Creating C++ source files (bin2cpp)
echo.  source files = %SOURCE_FILES_DIR%
echo.  target files = %TARGET_FILES_DIR%
echo.
echo.

cd /d %TARGET_FILES_DIR%
bin2cpp %SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAME.sln                          . EmbeddedFileSolution.h                   Solution                -override
bin2cpp %SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEClient.cpp                    . EmbeddedFileClientCpp.h                  ClientCpp               -override
bin2cpp %SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEClient.h                      . EmbeddedFileClientHeader.h               ClientHeader            -override
bin2cpp %SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEClient.vcxproj                . EmbeddedFileClientProject.h              ClientProject           -override
bin2cpp %SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEClient.vcxproj.filters        . EmbeddedFileClientFilters.h              ClientFilters           -override
bin2cpp %SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEProtoLib.vcxproj              . EmbeddedFileProtoLibProject.h            ProtoLibProject         -override
bin2cpp %SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEProtoLib.vcxproj.filters      . EmbeddedFileProtoLibFilters.h            ProtoLibFilters         -override
bin2cpp %SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEServer.cpp                    . EmbeddedFileServerCpp.h                  ServerCpp               -override
bin2cpp %SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEServer.h                      . EmbeddedFileServerHeader.h               ServerHeader            -override
bin2cpp %SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEServer.idl                    . EmbeddedFileServerIdl.h                  ServerIdl               -override
bin2cpp %SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEServer.vcxproj                . EmbeddedFileServerProject.h              ServerProject           -override
bin2cpp %SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEServer.vcxproj.filters        . EmbeddedFileServerFilters.h              ServerFilters           -override
bin2cpp %SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEServerImpl.template.cpp       . EmbeddedFileServerImplCpp.h              ServerImplCpp           -override
bin2cpp %SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEServerImpl.h                  . EmbeddedFileServerImplHeader.h           ServerImplHeader        -override
bin2cpp %SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEServerImpl.vcxproj            . EmbeddedFileServerImplProject.h          ServerImplProject       -override
bin2cpp %SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEServerImpl.vcxproj.filters    . EmbeddedFileServerImplFilters.h          ServerImplFilters       -override
bin2cpp %SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEServerMain.cpp                . EmbeddedFileServerMain.h                 ServerMain              -override
bin2cpp %SOURCE_FILES_DIR%\ErrorHandlers.cpp                                      . EmbeddedFileErrorHandlersCpp.h           ErrorHandlersCpp        -override
bin2cpp %SOURCE_FILES_DIR%\ErrorHandlers.h                                        . EmbeddedFileErrorHandlersHeader.h        ErrorHandlersHeader     -override
bin2cpp %SOURCE_FILES_DIR%\IComErrorProvider.h                                    . EmbeddedFileIComErrorProvider.h          IComErrorProvider       -override
bin2cpp %SOURCE_FILES_DIR%\IService.h                                             . EmbeddedFileIService.h                   IService                -override
bin2cpp %SOURCE_FILES_DIR%\MessageSerializer.cpp                                  . EmbeddedFileMessageSerializerCpp.h       MessageSerializerCpp    -override
bin2cpp %SOURCE_FILES_DIR%\MessageSerializer.h                                    . EmbeddedFileMessageSerializerHeader.h    MessageSerializerHeader -override
bin2cpp %SOURCE_FILES_DIR%\RegisterServerDebug.bat                                . EmbeddedFileRegisterServerDebug.h        RegisterServerDebug     -override
bin2cpp %SOURCE_FILES_DIR%\RegisterServerRelease.bat                              . EmbeddedFileRegisterServerRelease.h      RegisterServerRelease   -override
bin2cpp %SOURCE_FILES_DIR%\Registry.cpp                                           . EmbeddedFileRegistryCpp.h                RegistryCpp             -override
bin2cpp %SOURCE_FILES_DIR%\Registry.h                                             . EmbeddedFileRegistryHeader.h             RegistryHeader          -override
bin2cpp %SOURCE_FILES_DIR%\SmartPointers.h                                        . EmbeddedFileSmartPointers.h              SmartPointers           -override
bin2cpp %SOURCE_FILES_DIR%\UnregisterServerDebug.bat                              . EmbeddedFileUnregisterServerDebug.h      UnregisterServerDebug   -override
bin2cpp %SOURCE_FILES_DIR%\UnregisterServerRelease.bat                            . EmbeddedFileUnregisterServerRelease.h    UnregisterServerRelease -override

echo done
echo.

pause
goto :EOF
