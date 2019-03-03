@echo off
attrib -h -r -s *.suo 1>NUL 2>NUL
del *.ncb 1>NUL 2>NUL
del *.suo 1>NUL 2>NUL
del "COM Server Registry Dump\*.user" 1>NUL 2>NUL
del "RegistryManipulatorLib\*.user" 1>NUL 2>NUL

rmdir /q /s "TestResults" 1>NUL 2>NUL
rmdir /q /s "COM Server Registry Dump\bin" 1>NUL 2>NUL
rmdir /q /s "COM Server Registry Dump\obj" 1>NUL 2>NUL
rmdir /q /s "RegistryManipulatorLib\bin" 1>NUL 2>NUL
rmdir /q /s "RegistryManipulatorLib\obj" 1>NUL 2>NUL
rmdir /q /s "RegistryManipulatorTests\bin" 1>NUL 2>NUL
rmdir /q /s "RegistryManipulatorTests\obj" 1>NUL 2>NUL

pause
