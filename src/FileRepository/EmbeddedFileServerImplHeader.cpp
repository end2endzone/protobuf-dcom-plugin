/**
 * This file was generated by bin2cpp v2.2.0
 * Copyright (C) 2013-2019 end2endzone.com. All rights reserved.
 * bin2cpp is open source software, see http://github.com/end2endzone/bin2cpp
 * Source code for file 'DCOMPLUGIN_COMPONENT_NAMEServerImpl.h', last modified 1552247129.
 * Do not modify this file.
 */
#include "EmbeddedFileServerImplHeader.h"
#include <stdio.h> //for FILE
#include <string> //for memcpy
namespace bin2cpp
{
  class ServerImplHeaderFile : public virtual bin2cpp::File
  {
  public:
    ServerImplHeaderFile() { build(); }
    virtual ~ServerImplHeaderFile() {}
    virtual size_t getSize() const { return 652; }
    virtual const char * getFilename() const { return "DCOMPLUGIN_COMPONENT_NAMEServerImpl.h"; }
    virtual const char * getBuffer() const { return mBuffer.c_str(); }
    void build()
    {
      mBuffer.clear();
      mBuffer.reserve(getSize()); //allocate all required memory at once to prevent reallocations
      mBuffer.append("#pragma once\r\n\r\nDCOMPLUGIN_ALL_SERVICES_INCLUDE_LIST\r\n\r\nnamespace DCOMPLUGIN_PACKAGE_NAME {\r\n\r\n///<summary>Actual implementation of DCOMPLUGIN_PACKAGE_NAME services.</summary>\r\n///<returns>Returns a s", 200);
      mBuffer.append("tring containing the file name of the current executable. ie: MyProcessName.exe</returns>\r\nclass DCOMPLUGIN_COMPONENT_NAMEServerImpl :\t\r\n                                DCOMPLUGIN_ALL_SERVICES_VIRTUAL", 200);
      mBuffer.append("_IMPL\r\n{\r\npublic:\r\n  DCOMPLUGIN_COMPONENT_NAMEServerImpl();\r\n  virtual ~DCOMPLUGIN_COMPONENT_NAMEServerImpl();\r\n\r\n  //DCOMPLUGIN_COMPONENT_NAMEProtoLib interfaces\r\n\r\n  DCOMPLUGIN_ALL_SERVICES_DECLARAT", 200);
      mBuffer.append("ION\r\n};\r\n\r\n}  // namespace DCOMPLUGIN_PACKAGE_NAME\r\n", 52);
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
  const File & getServerImplHeaderFile() { static ServerImplHeaderFile _instance; return _instance; }
}; //bin2cpp
