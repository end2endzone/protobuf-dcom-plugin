/**
 * This file was generated by bin2cpp v2.2.0
 * Copyright (C) 2013-2019 end2endzone.com. All rights reserved.
 * bin2cpp is open source software, see http://github.com/end2endzone/bin2cpp
 * Source code for file 'DCOMPLUGIN_COMPONENT_NAMEServer.vcxproj.filters', last modified 1552247129.
 * Do not modify this file.
 */
#ifndef EMBEDDEDFILESERVERFILTERS_H
#define EMBEDDEDFILESERVERFILTERS_H

#include <stddef.h>

namespace bin2cpp
{
  #ifndef BIN2CPP_EMBEDDEDFILE_CLASS
  #define BIN2CPP_EMBEDDEDFILE_CLASS
  class File
  {
  public:
    virtual size_t getSize() const = 0;
    virtual const char * getFilename() const = 0;
    virtual const char * getBuffer() const = 0;
    virtual bool save(const char * iFilename) const = 0;
  };
  #endif //BIN2CPP_EMBEDDEDFILE_CLASS
  const File & getServerFiltersFile();
}; //bin2cpp

#endif //EMBEDDEDFILESERVERFILTERS_H
