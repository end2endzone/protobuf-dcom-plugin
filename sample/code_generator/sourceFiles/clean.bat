@echo off
attrib -h -r -s *.suo 1>NUL 2>NUL
del *.ncb 1>NUL 2>NUL
del *.suo 1>NUL 2>NUL
del *.user 1>NUL 2>NUL
rmdir /q /s Debug 1>NUL 2>NUL
rmdir /q /s Release 1>NUL 2>NUL
rmdir /q /s bin 1>NUL 2>NUL
rmdir /q /s obj 1>NUL 2>NUL
rmdir /q /s Properties 1>NUL 2>NUL

pause
