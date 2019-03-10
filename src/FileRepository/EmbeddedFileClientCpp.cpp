/**
 * This file was generated by bin2cpp v2.2.0
 * Copyright (C) 2013-2019 end2endzone.com. All rights reserved.
 * bin2cpp is open source software, see http://github.com/end2endzone/bin2cpp
 * Source code for file 'DCOMPLUGIN_COMPONENT_NAMEClient.cpp', last modified 1552228002.
 * Do not modify this file.
 */
#include "EmbeddedFileClientCpp.h"
#include <stdio.h> //for FILE
#include <string> //for memcpy
namespace bin2cpp
{
  class ClientCppFile : public virtual bin2cpp::File
  {
  public:
    ClientCppFile() { build(); }
    virtual ~ClientCppFile() {}
    virtual size_t getSize() const { return 2219; }
    virtual const char * getFilename() const { return "DCOMPLUGIN_COMPONENT_NAMEClient.cpp"; }
    virtual const char * getBuffer() const { return mBuffer.c_str(); }
    void build()
    {
      mBuffer.clear();
      mBuffer.reserve(getSize()); //allocate all required memory at once to prevent reallocations
      mBuffer.append("#define WIN32_LEAN_AND_MEAN    // Exclude rarely-used stuff from Windows headers\r\n#include <windows.h>\r\n\r\n#include \"DCOMPLUGIN_COMPONENT_NAMEClient.h\"\r\n\r\n#include <comdef.h> //for CoInitialize and CoU", 200);
      mBuffer.append("ninitialize\r\n#include \"DCOMPLUGIN_COMPONENT_NAMEServer_h.h\" // interface declaration\r\n#include \"DCOMPLUGIN_COMPONENT_NAMEServer_i.c\" // IID, CLSID\r\n\r\n#include \"MessageSerializer.h\"\r\n#include \"ErrorHan", 200);
      mBuffer.append("dlers.h\"\r\n\r\nnamespace DCOMPLUGIN_PACKAGE_NAME {\r\n\r\n#define mServer ((DCOMPLUGIN_IDL_INTERFACE_NAMEServer *)mInstance)\r\n\r\nBOOL APIENTRY DllMain( HANDLE hModule,\r\n                      DWORD  ul_reason_", 200);
      mBuffer.append("for_call,\r\n                      LPVOID lpReserved\r\n                      )\r\n{\r\n  switch (ul_reason_for_call)\r\n  {\r\n  case DLL_PROCESS_ATTACH:\r\n  case DLL_THREAD_ATTACH:\r\n  case DLL_THREAD_DETACH:\r\n  ", 200);
      mBuffer.append("case DLL_PROCESS_DETACH:\r\n    break;\r\n  }\r\n  return TRUE;\r\n}\r\n\r\nDCOMPLUGIN_COMPONENT_NAMEClient::DCOMPLUGIN_COMPONENT_NAMEClient() :\r\n  mInstance(NULL),\r\n  mLastError(0)\r\n{\r\n  //note: multiple calls t", 200);
      mBuffer.append("o CoInitialize() is safe.\r\n  //An internal counter is used to actually initialize on first call only.\r\n  ::CoInitialize(NULL);\r\n\r\n  // create an instance\r\n  HRESULT hr = CoCreateInstance(CLSID_CoDCOMP", 200);
      mBuffer.append("LUGIN_COMPONENT_NAMEServer, NULL, /*CLSCTX_ALL*/ CLSCTX_SERVER, /*IID_DCOMPLUGIN_IDL_INTERFACE_NAMEServer*/ __uuidof(DCOMPLUGIN_IDL_INTERFACE_NAMEServer), (void **)&mInstance);\r\n  if (FAILED(hr))\r\n  {", 200);
      mBuffer.append("\r\n    mLastError = hr;\r\n  }\r\n}\r\n\r\nDCOMPLUGIN_COMPONENT_NAMEClient::~DCOMPLUGIN_COMPONENT_NAMEClient()\r\n{\r\n  if (mServer)\r\n  {\r\n    mServer->Release();\r\n    mInstance = NULL;\r\n  }\r\n\r\n  //note: the numb", 200);
      mBuffer.append("er of calls to CoUninitialize() must match the number of calls to CoInitialize(NULL)\r\n  ::CoUninitialize();\r\n}\r\n\r\nbool DCOMPLUGIN_COMPONENT_NAMEClient::isConnected()\r\n{\r\n  if (mServer)\r\n  {\r\n    retur", 200);
      mBuffer.append("n true;\r\n  }\r\n  return false;\r\n}\r\n\r\n//DCOMPLUGIN_COMPONENT_NAMEProtoLib interfaces\r\nunsigned int DCOMPLUGIN_COMPONENT_NAMEClient::GetLastComErrorCode()\r\n{\r\n  return mLastError;\r\n}\r\n\r\nstd::string DCOMP", 200);
      mBuffer.append("LUGIN_COMPONENT_NAMEClient::GetLastComErrorStr()\r\n{\r\n  std::string description = GetComErrorDescription(mLastError);\r\n  return description;\r\n}\r\n\r\nDCOMPLUGIN_CLIENT_DEFINITION\r\n\r\n}  // namespace DCOMPL", 200);
      mBuffer.append("UGIN_PACKAGE_NAME\r\n", 19);
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
  const File & getClientCppFile() { static ClientCppFile _instance; return _instance; }
}; //bin2cpp
