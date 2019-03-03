/**
 * This file was generated by
 * bin2cpp v1.3.
 * Copyright (C) 2013-2014 end2endzone.com. All rights reserved.
 * Do not modify this file.
 */
#include ".\EmbeddedFileServerImplCpp.h"
#include <stdio.h> //for FILE
#include <string> //for memcpy
namespace bin2cpp
{
  class ServerImplCppFile : public virtual bin2cpp::File
  {
  public:
    ServerImplCppFile() {}
    ~ServerImplCppFile() {}
    virtual size_t getSize() { return 407; }
    virtual size_t getSegmentSize() { return 200; }
    virtual size_t getNumSegments() { return 3; }
    virtual const char * getFilename() { return "DCOMPLUGIN_COMPONENT_NAMEServerImpl.template.cpp"; }
    virtual const char * getSegment(size_t iIndex, size_t & oLength)
    {
      oLength = 0;
      if (iIndex >= getNumSegments())
        return NULL;
      const char * buffer = NULL;
      size_t index = 0;
      oLength = getSegmentSize();
      buffer = "#include \"DCOMPLUGIN_COMPONENT_NAMEServerImpl.h\"\x0d\x0a\x0d\012namespace DCOMPLUGIN_PACKAGE_NAME {\x0d\x0a\x0d\012//Global objects\x0d\012DCOMPLUGIN_SERVER_IMPL_TEMPLATE_GLOBAL\x0d\x0a\x0d\012DCOMPLUGIN_COMPONENT_NAMEServerImpl::DCOMPLUGIN_C"; if (iIndex == index) return buffer; index++;
      buffer = "OMPONENT_NAMEServerImpl()\x0d\012{\x0d\012}\x0d\x0a\x0d\012DCOMPLUGIN_COMPONENT_NAMEServerImpl::~DCOMPLUGIN_COMPONENT_NAMEServerImpl()\x0d\012{\x0d\012}\x0d\x0a\x0d\012DCOMPLUGIN_SERVER_IMPL_TEMPLATE_DEFINITION\x0d\x0a\x0d\012}  // namespace DCOMPLUGIN_PACKAGE"; if (iIndex == index) return buffer; index++;
      oLength = 7;
      buffer = "_NAME\x0d\x0a"; if (iIndex == index) return buffer; index++;
      oLength = 0;
      return NULL;
    }
    virtual const char * getMd5() { return "86b6461906aee649471bfd095db8846f"; }
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
  File & getServerImplCppFile() { static ServerImplCppFile _instance; return _instance; }
}; //bin2cpp
