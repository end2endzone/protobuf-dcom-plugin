@echo off
attrib -h -r -s *.suo 1>NUL 2>NUL
del *.ncb 1>NUL 2>NUL
del *.suo 1>NUL 2>NUL
del FileRepository\*.user 1>NUL 2>NUL
del libDCOM\*.user 1>NUL 2>NUL
del protobuf-dcom-plugin\*.user 1>NUL 2>NUL
del protobuf-dcom-plugin-tests\*.user 1>NUL 2>NUL
del protobuf-debug-plugin\*.user 1>NUL 2>NUL
rmdir /q /s Debug 1>NUL 2>NUL
rmdir /q /s Release 1>NUL 2>NUL
rmdir /q /s FileRepository\Debug 1>NUL 2>NUL
rmdir /q /s FileRepository\Release 1>NUL 2>NUL
rmdir /q /s libDCOM\Debug 1>NUL 2>NUL
rmdir /q /s libDCOM\Release 1>NUL 2>NUL
rmdir /q /s protobuf-dcom-plugin\Debug 1>NUL 2>NUL
rmdir /q /s protobuf-dcom-plugin\Release 1>NUL 2>NUL
rmdir /q /s protobuf-dcom-plugin-tests\Debug 1>NUL 2>NUL
rmdir /q /s protobuf-dcom-plugin-tests\Release 1>NUL 2>NUL
rmdir /q /s protobuf-debug-plugin\Debug 1>NUL 2>NUL
rmdir /q /s protobuf-debug-plugin\Release 1>NUL 2>NUL

pause
