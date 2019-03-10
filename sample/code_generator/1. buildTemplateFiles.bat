@echo off
echo Deleting old files...
del /Q .\templateFiles\*.*
echo done
echo.

echo Copying source files to templates...
copy /v .\sourceFiles\demo.sln                                     .\templateFiles\DCOMPLUGIN_COMPONENT_NAME.sln                      
copy /v .\sourceFiles\DemoClient.cpp                               .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEClient.cpp                
copy /v .\sourceFiles\DemoClient.h                                 .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEClient.h                  
copy /v .\sourceFiles\DemoClient.vcxproj                           .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEClient.vcxproj            
copy /v .\sourceFiles\DemoClient.vcxproj.filters                   .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEClient.vcxproj.filters    
copy /v .\sourceFiles\DemoProtoLib.vcxproj                         .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEProtoLib.vcxproj          
copy /v .\sourceFiles\DemoProtoLib.vcxproj.filters                 .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEProtoLib.vcxproj.filters  
copy /v .\sourceFiles\DemoServer.cpp                               .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEServer.cpp                
copy /v .\sourceFiles\DemoServer.h                                 .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEServer.h                  
copy /v .\sourceFiles\DemoServer.idl                               .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEServer.idl                
copy /v .\sourceFiles\DemoServer.vcxproj                           .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEServer.vcxproj            
copy /v .\sourceFiles\DemoServer.vcxproj.filters                   .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEServer.vcxproj.filters    
copy /v .\sourceFiles\DemoServerImpl.cpp                           .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEServerImpl.template.cpp   
copy /v .\sourceFiles\DemoServerImpl.h                             .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEServerImpl.h              
copy /v .\sourceFiles\DemoServerImpl.vcxproj                       .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEServerImpl.vcxproj        
copy /v .\sourceFiles\DemoServerImpl.vcxproj.filters               .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEServerImpl.vcxproj.filters
copy /v .\sourceFiles\DemoServerMain.cpp                           .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEServerMain.cpp            
copy /v .\sourceFiles\ErrorHandlers.cpp                            .\templateFiles\ErrorHandlers.cpp             
copy /v .\sourceFiles\ErrorHandlers.h                              .\templateFiles\ErrorHandlers.h               
copy /v .\sourceFiles\IComErrorProvider.h                          .\templateFiles\IComErrorProvider.h           
copy /v .\sourceFiles\ICounterService.h                            .\templateFiles\IService.h             
copy /v .\sourceFiles\MessageSerializer.cpp                        .\templateFiles\MessageSerializer.cpp         
copy /v .\sourceFiles\MessageSerializer.h                          .\templateFiles\MessageSerializer.h           
copy /v .\sourceFiles\RegisterServerDebug.bat                      .\templateFiles\RegisterServerDebug.bat       
copy /v .\sourceFiles\RegisterServerRelease.bat                    .\templateFiles\RegisterServerRelease.bat       
copy /v .\sourceFiles\Registry.cpp                                 .\templateFiles\Registry.cpp                  
copy /v .\sourceFiles\Registry.h                                   .\templateFiles\Registry.h                    
copy /v .\sourceFiles\SmartPointers.h                              .\templateFiles\SmartPointers.h               
copy /v .\sourceFiles\UnregisterServerDebug.bat                    .\templateFiles\UnregisterServerDebug.bat     
copy /v .\sourceFiles\UnregisterServerRelease.bat                  .\templateFiles\UnregisterServerRelease.bat     

REM copy /v .\sourceFiles\DemoTestCpp.cpp                              .\templateFiles
REM copy /v .\sourceFiles\DemoTestCpp.vcxproj                          .\templateFiles
REM copy /v .\sourceFiles\DemoTestCpp.vcxproj.filters                  .\templateFiles

echo done
echo.

echo Processing search and replace values...
call :PROCESS_REPLACEMENT .\templateFiles\DCOMPLUGIN_COMPONENT_NAME.sln                      
call :PROCESS_REPLACEMENT .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEClient.cpp                
call :PROCESS_REPLACEMENT .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEClient.h                  
call :PROCESS_REPLACEMENT .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEClient.vcxproj            
call :PROCESS_REPLACEMENT .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEClient.vcxproj.filters    
call :PROCESS_REPLACEMENT .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEProtoLib.vcxproj          
call :PROCESS_REPLACEMENT .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEProtoLib.vcxproj.filters  
call :PROCESS_REPLACEMENT .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEServer.cpp                
call :PROCESS_REPLACEMENT .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEServer.h                  
call :PROCESS_REPLACEMENT .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEServer.idl                
call :PROCESS_REPLACEMENT .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEServer.vcxproj            
call :PROCESS_REPLACEMENT .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEServer.vcxproj.filters    
call :PROCESS_REPLACEMENT .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEServerImpl.template.cpp            
call :PROCESS_REPLACEMENT .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEServerImpl.h              
call :PROCESS_REPLACEMENT .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEServerImpl.vcxproj        
call :PROCESS_REPLACEMENT .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEServerImpl.vcxproj.filters
call :PROCESS_REPLACEMENT .\templateFiles\DCOMPLUGIN_COMPONENT_NAMEServerMain.cpp            
call :PROCESS_REPLACEMENT .\templateFiles\ErrorHandlers.cpp             
call :PROCESS_REPLACEMENT .\templateFiles\ErrorHandlers.h               
call :PROCESS_REPLACEMENT .\templateFiles\IComErrorProvider.h           
call :PROCESS_REPLACEMENT .\templateFiles\IService.h             
call :PROCESS_REPLACEMENT .\templateFiles\MessageSerializer.cpp         
call :PROCESS_REPLACEMENT .\templateFiles\MessageSerializer.h           
call :PROCESS_REPLACEMENT .\templateFiles\RegisterServerDebug.bat       
call :PROCESS_REPLACEMENT .\templateFiles\RegisterServerRelease.bat       
call :PROCESS_REPLACEMENT .\templateFiles\Registry.cpp                  
call :PROCESS_REPLACEMENT .\templateFiles\Registry.h                    
call :PROCESS_REPLACEMENT .\templateFiles\SmartPointers.h               
call :PROCESS_REPLACEMENT .\templateFiles\UnregisterServerDebug.bat     
call :PROCESS_REPLACEMENT .\templateFiles\UnregisterServerRelease.bat     

echo done
echo.


pause
goto :EOF

:PROCESS_REPLACEMENT
echo %1...
call cscript //nologo %~dp0process_replacement.wsf %1
goto :EOF
