/**
 * This file was generated by bin2cpp v2.2.0
 * Copyright (C) 2013-2019 end2endzone.com. All rights reserved.
 * bin2cpp is open source software, see http://github.com/end2endzone/bin2cpp
 * Source code for file 'DCOMPLUGIN_COMPONENT_NAMEClient.h', last modified 1552247129.
 * Do not modify this file.
 */
#include "EmbeddedFileClientHeader.h"
#include <stdio.h> //for FILE
#include <string> //for memcpy
namespace bin2cpp
{
  class ClientHeaderFile : public virtual bin2cpp::File
  {
  public:
    ClientHeaderFile() { build(); }
    virtual ~ClientHeaderFile() {}
    virtual size_t getSize() const { return 1407; }
    virtual const char * getFilename() const { return "DCOMPLUGIN_COMPONENT_NAMEClient.h"; }
    virtual const char * getBuffer() const { return mBuffer.c_str(); }
    void build()
    {
      mBuffer.clear();
      mBuffer.reserve(getSize()); //allocate all required memory at once to prevent reallocations
      mBuffer.append("#pragma once\r\n\r\n#include \"IComErrorProvider.h\"\r\nDCOMPLUGIN_ALL_SERVICES_INCLUDE_LIST\r\n\r\nnamespace DCOMPLUGIN_PACKAGE_NAME {\r\n\r\n#ifdef DCOMPLUGIN_COMPONENT_NAME_CLIENT_EXPORTS\r\n#define DCOMPLUGIN_COMPO", 200);
      mBuffer.append("NENT_NAME_DLL_API __declspec(dllexport)\r\n#else\r\n#define DCOMPLUGIN_COMPONENT_NAME_DLL_API __declspec(dllimport)\r\n#endif\r\n\r\n///<summary>Client class for connection to DCOMPLUGIN_COMPONENT_NAMEServer.</", 200);
      mBuffer.append("summary>\r\nclass DCOMPLUGIN_COMPONENT_NAME_DLL_API DCOMPLUGIN_COMPONENT_NAMEClient : public virtual IComErrorProvider, \r\nDCOMPLUGIN_ALL_SERVICES_VIRTUAL_IMPL\r\n\r\n{\r\npublic:\r\n  DCOMPLUGIN_COMPONENT_NAMEC", 200);
      mBuffer.append("lient();\r\n  virtual ~DCOMPLUGIN_COMPONENT_NAMEClient();\r\n\r\n  ///<summary>Defines if the DCOMPLUGIN_COMPONENT_NAMEServer is available.</summary>\r\n  ///<returns>Returns true if the client is connected w", 200);
      mBuffer.append("ith the DCOMPLUGIN_COMPONENT_NAMEServer server. Returns false otherwise.</returns>\r\n  bool isConnected();\r\n\r\n  //DCOMPLUGIN_COMPONENT_NAMEProtoLib interfaces\r\n\r\n  //IComErrorProvider\r\n  virtual unsign", 200);
      mBuffer.append("ed int GetLastComErrorCode();\r\n  virtual std::string GetLastComErrorStr();\r\n  \r\n  DCOMPLUGIN_ALL_SERVICES_DECLARATION\r\n\r\nprotected:\r\n  ///<summary>Error code returned by the last internal call to the ", 200);
      mBuffer.append("server.</summary>\r\n  unsigned long mLastError;\r\n\r\n  ///<summary>DCOMPLUGIN_COMPONENT_NAMEClient private implementation pointer.</summary>\r\n  void * mInstance;\r\n};\r\n\r\n}  // namespace DCOMPLUGIN_PACKAGE", 200);
      mBuffer.append("_NAME\r\n", 7);
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
  const File & getClientHeaderFile() { static ClientHeaderFile _instance; return _instance; }
}; //bin2cpp
