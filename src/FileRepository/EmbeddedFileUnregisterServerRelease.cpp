/**
 * This file was generated by bin2cpp v2.2.0
 * Copyright (C) 2013-2019 end2endzone.com. All rights reserved.
 * bin2cpp is open source software, see http://github.com/end2endzone/bin2cpp
 * Source code for file 'UnregisterServerRelease.bat', last modified 1552228003.
 * Do not modify this file.
 */
#include "EmbeddedFileUnregisterServerRelease.h"
#include <stdio.h> //for FILE
#include <string> //for memcpy
namespace bin2cpp
{
  class UnregisterServerReleaseFile : public virtual bin2cpp::File
  {
  public:
    UnregisterServerReleaseFile() { build(); }
    virtual ~UnregisterServerReleaseFile() {}
    virtual size_t getSize() const { return 80; }
    virtual const char * getFilename() const { return "UnregisterServerRelease.bat"; }
    virtual const char * getBuffer() const { return mBuffer.c_str(); }
    void build()
    {
      mBuffer.clear();
      mBuffer.reserve(getSize()); //allocate all required memory at once to prevent reallocations
      mBuffer.append("@echo off\r\n\".\\Release\\DCOMPLUGIN_COMPONENT_NAMEServer.exe\" /unregserver\r\npause\r\n", 80);
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
  const File & getUnregisterServerReleaseFile() { static UnregisterServerReleaseFile _instance; return _instance; }
}; //bin2cpp
