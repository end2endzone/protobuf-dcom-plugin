@echo off

:: Setup bin2cpp
set LOCAL_DIR=%cd%
cd ..\..\third_parties\bin2cpp\install\bin
set BIN2CPP_HOME=%cd%
set path=%path%;%BIN2CPP_HOME%
cd /d %LOCAL_DIR%

echo Deleting existing files...
del ..\..\src\FileRepository\EmbeddedFile*.*
echo done
echo.

set SOURCE_FILES_DIR=%cd%\templateFiles
cd ..\..\src\FileRepository
set TARGET_FILES_DIR=%cd%

echo Creating C++ source files (bin2cpp)
echo.  source files = %SOURCE_FILES_DIR%
echo.  target files = %TARGET_FILES_DIR%
echo.
echo.

cd /d %TARGET_FILES_DIR%
bin2cpp --file=%SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAME.sln                          --output=. --headerfile=EmbeddedFileSolution.h                   --identifier=Solution                --override
bin2cpp --file=%SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEClient.cpp                    --output=. --headerfile=EmbeddedFileClientCpp.h                  --identifier=ClientCpp               --override
bin2cpp --file=%SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEClient.h                      --output=. --headerfile=EmbeddedFileClientHeader.h               --identifier=ClientHeader            --override
bin2cpp --file=%SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEClient.vcxproj                --output=. --headerfile=EmbeddedFileClientProject.h              --identifier=ClientProject           --override
bin2cpp --file=%SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEClient.vcxproj.filters        --output=. --headerfile=EmbeddedFileClientFilters.h              --identifier=ClientFilters           --override
bin2cpp --file=%SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEProtoLib.vcxproj              --output=. --headerfile=EmbeddedFileProtoLibProject.h            --identifier=ProtoLibProject         --override
bin2cpp --file=%SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEProtoLib.vcxproj.filters      --output=. --headerfile=EmbeddedFileProtoLibFilters.h            --identifier=ProtoLibFilters         --override
bin2cpp --file=%SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEServer.cpp                    --output=. --headerfile=EmbeddedFileServerCpp.h                  --identifier=ServerCpp               --override
bin2cpp --file=%SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEServer.h                      --output=. --headerfile=EmbeddedFileServerHeader.h               --identifier=ServerHeader            --override
bin2cpp --file=%SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEServer.idl                    --output=. --headerfile=EmbeddedFileServerIdl.h                  --identifier=ServerIdl               --override
bin2cpp --file=%SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEServer.vcxproj                --output=. --headerfile=EmbeddedFileServerProject.h              --identifier=ServerProject           --override
bin2cpp --file=%SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEServer.vcxproj.filters        --output=. --headerfile=EmbeddedFileServerFilters.h              --identifier=ServerFilters           --override
bin2cpp --file=%SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEServerImpl.template.cpp       --output=. --headerfile=EmbeddedFileServerImplCpp.h              --identifier=ServerImplCpp           --override
bin2cpp --file=%SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEServerImpl.h                  --output=. --headerfile=EmbeddedFileServerImplHeader.h           --identifier=ServerImplHeader        --override
bin2cpp --file=%SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEServerImpl.vcxproj            --output=. --headerfile=EmbeddedFileServerImplProject.h          --identifier=ServerImplProject       --override
bin2cpp --file=%SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEServerImpl.vcxproj.filters    --output=. --headerfile=EmbeddedFileServerImplFilters.h          --identifier=ServerImplFilters       --override
bin2cpp --file=%SOURCE_FILES_DIR%\DCOMPLUGIN_COMPONENT_NAMEServerMain.cpp                --output=. --headerfile=EmbeddedFileServerMain.h                 --identifier=ServerMain              --override
bin2cpp --file=%SOURCE_FILES_DIR%\ErrorHandlers.cpp                                      --output=. --headerfile=EmbeddedFileErrorHandlersCpp.h           --identifier=ErrorHandlersCpp        --override
bin2cpp --file=%SOURCE_FILES_DIR%\ErrorHandlers.h                                        --output=. --headerfile=EmbeddedFileErrorHandlersHeader.h        --identifier=ErrorHandlersHeader     --override
bin2cpp --file=%SOURCE_FILES_DIR%\IComErrorProvider.h                                    --output=. --headerfile=EmbeddedFileIComErrorProvider.h          --identifier=IComErrorProvider       --override
bin2cpp --file=%SOURCE_FILES_DIR%\IService.h                                             --output=. --headerfile=EmbeddedFileIService.h                   --identifier=IService                --override
bin2cpp --file=%SOURCE_FILES_DIR%\MessageSerializer.cpp                                  --output=. --headerfile=EmbeddedFileMessageSerializerCpp.h       --identifier=MessageSerializerCpp    --override
bin2cpp --file=%SOURCE_FILES_DIR%\MessageSerializer.h                                    --output=. --headerfile=EmbeddedFileMessageSerializerHeader.h    --identifier=MessageSerializerHeader --override
bin2cpp --file=%SOURCE_FILES_DIR%\RegisterServerDebug.bat                                --output=. --headerfile=EmbeddedFileRegisterServerDebug.h        --identifier=RegisterServerDebug     --override
bin2cpp --file=%SOURCE_FILES_DIR%\RegisterServerRelease.bat                              --output=. --headerfile=EmbeddedFileRegisterServerRelease.h      --identifier=RegisterServerRelease   --override
bin2cpp --file=%SOURCE_FILES_DIR%\Registry.cpp                                           --output=. --headerfile=EmbeddedFileRegistryCpp.h                --identifier=RegistryCpp             --override
bin2cpp --file=%SOURCE_FILES_DIR%\Registry.h                                             --output=. --headerfile=EmbeddedFileRegistryHeader.h             --identifier=RegistryHeader          --override
bin2cpp --file=%SOURCE_FILES_DIR%\SmartPointers.h                                        --output=. --headerfile=EmbeddedFileSmartPointers.h              --identifier=SmartPointers           --override
bin2cpp --file=%SOURCE_FILES_DIR%\UnregisterServerDebug.bat                              --output=. --headerfile=EmbeddedFileUnregisterServerDebug.h      --identifier=UnregisterServerDebug   --override
bin2cpp --file=%SOURCE_FILES_DIR%\UnregisterServerRelease.bat                            --output=. --headerfile=EmbeddedFileUnregisterServerRelease.h    --identifier=UnregisterServerRelease --override

echo done
echo.

pause
goto :EOF
