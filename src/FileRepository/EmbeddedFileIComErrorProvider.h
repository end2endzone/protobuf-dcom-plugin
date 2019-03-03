/**
 * This file was generated by
 * bin2cpp v1.3.
 * Copyright (C) 2013-2014 end2endzone.com. All rights reserved.
 * Do not modify this file.
 */
#pragma once
#include <stddef.h>
namespace bin2cpp
{
  #ifndef BIN2CPP_EMBEDEDFILE_CLASS
  #define BIN2CPP_EMBEDEDFILE_CLASS
  class File
  {
  public:
    virtual size_t getSize() = 0;
    virtual size_t getSegmentSize() = 0;
    virtual size_t getNumSegments() = 0;
    virtual const char * getFilename() = 0;
    virtual const char * getSegment(size_t iIndex, size_t & oLength) = 0;
    virtual const char * getMd5() = 0;
    virtual char * newBuffer() = 0;
    virtual bool save(const char * iFilename) = 0;
  };
  #endif
  File & getIComErrorProviderFile();
}; //bin2cpp
