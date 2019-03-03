/**
 * This file was generated by
 * bin2cpp v1.3.
 * Copyright (C) 2013-2014 end2endzone.com. All rights reserved.
 * Do not modify this file.
 */
#include ".\EmbeddedFileServerImplHeader.h"
#include <stdio.h> //for FILE
#include <string> //for memcpy
namespace bin2cpp
{
  class ServerImplHeaderFile : public virtual bin2cpp::File
  {
  public:
    ServerImplHeaderFile() {}
    ~ServerImplHeaderFile() {}
    virtual size_t getSize() { return 652; }
    virtual size_t getSegmentSize() { return 200; }
    virtual size_t getNumSegments() { return 4; }
    virtual const char * getFilename() { return "DCOMPLUGIN_COMPONENT_NAMEServerImpl.h"; }
    virtual const char * getSegment(size_t iIndex, size_t & oLength)
    {
      oLength = 0;
      if (iIndex >= getNumSegments())
        return NULL;
      const char * buffer = NULL;
      size_t index = 0;
      oLength = getSegmentSize();
      buffer = "#pragma once\x0d\x0a\x0d\012DCOMPLUGIN_ALL_SERVICES_INCLUDE_LIST\x0d\x0a\x0d\012namespace DCOMPLUGIN_PACKAGE_NAME {\x0d\x0a\x0d\012///<summary>Actual implementation of DCOMPLUGIN_PACKAGE_NAME services.</summary>\x0d\012///<returns>Returns a s"; if (iIndex == index) return buffer; index++;
      buffer = "tring containing the file name of the current executable. ie: MyProcessName.exe</returns>\x0d\012class DCOMPLUGIN_COMPONENT_NAMEServerImpl :\t\x0d\012                                DCOMPLUGIN_ALL_SERVICES_VIRTUAL"; if (iIndex == index) return buffer; index++;
      buffer = "_IMPL\x0d\012{\x0d\012public:\x0d\012  DCOMPLUGIN_COMPONENT_NAMEServerImpl();\x0d\012  virtual ~DCOMPLUGIN_COMPONENT_NAMEServerImpl();\x0d\x0a\x0d\012  //DCOMPLUGIN_COMPONENT_NAMEProtoLib interfaces\x0d\x0a\x0d\012  DCOMPLUGIN_ALL_SERVICES_DECLARAT"; if (iIndex == index) return buffer; index++;
      oLength = 52;
      buffer = "ION\x0d\012};\x0d\x0a\x0d\012}  // namespace DCOMPLUGIN_PACKAGE_NAME\x0d\x0a"; if (iIndex == index) return buffer; index++;
      oLength = 0;
      return NULL;
    }
    virtual const char * getMd5() { return "536c5bc113ff0e9f9911319747f1a5f9"; }
    virtual char * newBuffer()
    {
      size_t size = getSize();
      char * buffer = new char[size];
      if (buffer == NULL)
        return NULL;
      size_t numSegments = getNumSegments();
      size_t segmentLength = 0;
      size_t index = 0;
      for(size_t i=0; i<numSegments; i++)
      {
        const char * segmentBuffer = getSegment(i, segmentLength);
        memcpy(&buffer[index], segmentBuffer, segmentLength);
        index += segmentLength;
      }
      return buffer;
    }
    virtual bool save(const char * iFilename)
    {
      FILE * f = fopen(iFilename, "wb");
      if (!f) return false;
      size_t numSegments = getNumSegments();
      size_t segmentLength = 0;
      const char * buffer = NULL;
      for(size_t i=0; i<numSegments; i++)
      {
        buffer = getSegment(i, segmentLength);
        fwrite(buffer, 1, segmentLength, f);
      }
      fclose(f);
      return true;
    }
  };
  File & getServerImplHeaderFile() { static ServerImplHeaderFile _instance; return _instance; }
}; //bin2cpp
