/**
 * This file was generated by bin2cpp v2.2.0
 * Copyright (C) 2013-2019 end2endzone.com. All rights reserved.
 * bin2cpp is open source software, see http://github.com/end2endzone/bin2cpp
 * Source code for file 'ErrorHandlers.h', last modified 1552228002.
 * Do not modify this file.
 */
#include "EmbeddedFileErrorHandlersHeader.h"
#include <stdio.h> //for FILE
#include <string> //for memcpy
namespace bin2cpp
{
  class ErrorHandlersHeaderFile : public virtual bin2cpp::File
  {
  public:
    ErrorHandlersHeaderFile() { build(); }
    virtual ~ErrorHandlersHeaderFile() {}
    virtual size_t getSize() const { return 1082; }
    virtual const char * getFilename() const { return "ErrorHandlers.h"; }
    virtual const char * getBuffer() const { return mBuffer.c_str(); }
    void build()
    {
      mBuffer.clear();
      mBuffer.reserve(getSize()); //allocate all required memory at once to prevent reallocations
      mBuffer.append("#pragma once\r\n\r\n#define WIN32_LEAN_AND_MEAN    // Exclude rarely-used stuff from Windows headers\r\n#include <windows.h>\r\n\r\n#include <string>\r\n\r\nnamespace DCOMPLUGIN_PACKAGE_NAME {\r\n\r\n///<summary>Provid", 200);
      mBuffer.append("e the file name of the current executable.</summary>\r\n///<returns>Returns a string containing the file name of the current executable. ie: MyProcessName.exe</returns>\r\nstd::string getProcessFilename()", 200);
      mBuffer.append(";\r\n\r\n///<summary>Display an error message box which shows the last error code and its description.</summary>\r\nvoid MessageBoxLastError();\r\n\r\n///<summary>Display an error message box which shows the la", 200);
      mBuffer.append("st error code and its description.</summary>\r\n///<param name=\"hr\">A return value of a call to a Win32 API.</param>\r\nvoid MessageBoxLastComError(HRESULT hr);\r\n\r\n///<summary>Returns a string representat", 200);
      mBuffer.append("ion of the given error code.</summary>\r\n///<param name=\"hr\">A return value of a call to a Win32 API.</param>\r\n///<returns>Returns a string representation of the given error code.</returns>\r\nstd::strin", 200);
      mBuffer.append("g GetComErrorDescription(HRESULT hr);\r\n\r\n}  // namespace DCOMPLUGIN_PACKAGE_NAME\r\n", 82);
    }
    virtual bool save(const char * iFilename) const
    {
      FILE * f = fopen(iFilename, "wb");
      if (!f) return false;
      size_t fileSize = getSize();
      const char * buffer = getBuffer();
      fwrite(buffer, 1, fileSize, f);
      fclose(f);
      return true;
    }
  private:
    std::string mBuffer;
  };
  const File & getErrorHandlersHeaderFile() { static ErrorHandlersHeaderFile _instance; return _instance; }
}; //bin2cpp
