@echo off
:: %1 is $(ProjectDir)
:: %2 is $(OutDir)
:: %3 is %(Identity)
:: %4 is %(Filename)
::

echo Copying %3 to output directory...
copy /v "%1%3" "%2"
echo done
echo.
