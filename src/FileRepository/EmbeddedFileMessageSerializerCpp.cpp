/**
 * This file was generated by bin2cpp v2.2.0
 * Copyright (C) 2013-2019 end2endzone.com. All rights reserved.
 * bin2cpp is open source software, see http://github.com/end2endzone/bin2cpp
 * Source code for file 'MessageSerializer.cpp', last modified 1552228002.
 * Do not modify this file.
 */
#include "EmbeddedFileMessageSerializerCpp.h"
#include <stdio.h> //for FILE
#include <string> //for memcpy
namespace bin2cpp
{
  class MessageSerializerCppFile : public virtual bin2cpp::File
  {
  public:
    MessageSerializerCppFile() { build(); }
    virtual ~MessageSerializerCppFile() {}
    virtual size_t getSize() const { return 6204; }
    virtual const char * getFilename() const { return "MessageSerializer.cpp"; }
    virtual const char * getBuffer() const { return mBuffer.c_str(); }
    void build()
    {
      mBuffer.clear();
      mBuffer.reserve(getSize()); //allocate all required memory at once to prevent reallocations
      mBuffer.append("#include \"MessageSerializer.h\"\r\n\r\n#include <vector>\r\n\r\nnamespace DCOMPLUGIN_PACKAGE_NAME {\r\n\r\nHRESULT Variant2ByteArray(VARIANT & iVar, DCOMPLUGIN_PACKAGE_NAME::VariantFlavor & oVariantFlavor, std::st", 200);
      mBuffer.append("ring & oData)\r\n{\r\n  static const VARTYPE IS_VARIANT       = (VT_BYREF | VT_VARIANT);\r\n  static const VARTYPE BYTE_ARRAY       = (VT_ARRAY | VT_UI1);\r\n  static const VARTYPE VARIANT_ARRAY    = (VT_ARRA", 200);
      mBuffer.append("Y | VT_VARIANT);\r\n\r\n  //Note that c++ serialize a \"byte array\" as a \"SAFEARRAY of bytes inside a VARIANT\". This structure \r\n  //store the bytes data in a consecutive buffer (all values are one after t", 200);
      mBuffer.append("he other) which makes the \r\n  //process of converting the data to a std::vector or std::string easy.\r\n  //However, weakly-typed languages (such as VBScript) does not serialize data the same way.\r\n  //", 200);
      mBuffer.append("VBScript serialize data as a VARIANT holding a SAFEARRAY of VARIANT, each VARIANT holding a single byte.\r\n  //To recover the data, one must read every VARIANT one by one and make sure it contains a by", 200);
      mBuffer.append("te before\r\n  //storing this byte within the output array.\r\n\r\n  if (iVar.vt == IS_VARIANT)\r\n  {\r\n    //this VARIANT contains another VARIANT\r\n    //it is expected that the inner VARIANT contains an ARR", 200);
      mBuffer.append("AY of VARIANT...\r\n    //this is typical of VBScript (weakly-typed languages)\r\n    VARIANT * v1 = iVar.pvarVal;\r\n    if (v1 == NULL)\r\n      return NULL;\r\n\r\n    HRESULT hr = Variant2ByteArray(*v1, oVari", 200);
      mBuffer.append("antFlavor, oData);\r\n    oVariantFlavor = VBSCRIPT;\r\n    return hr;\r\n  }\r\n  else if (iVar.vt == VARIANT_ARRAY)\r\n  {\r\n    //this variant contains an array of VARIANT\r\n    //this is typical of VBScript (", 200);
      mBuffer.append("weakly-typed languages)\r\n    SAFEARRAY * sa = iVar.parray;\r\n\r\n    VARIANT * values;\r\n    HRESULT hr = SafeArrayAccessData(sa, (void**)&values); // direct access to SA memory\r\n    if (FAILED(hr))\r\n    ", 200);
      mBuffer.append("  return NULL;\r\n\r\n    // get array bounds\r\n    long lowerBound = 0;\r\n    long upperBound = 0;\r\n    SafeArrayGetLBound(sa, 1, &lowerBound);\r\n    SafeArrayGetUBound(sa, 1, &upperBound);\r\n\r\n    long numE", 200);
      mBuffer.append("lements = upperBound - lowerBound + 1;\r\n    if (numElements == 0)\r\n    {\r\n      oData.clear();\r\n    }\r\n    else\r\n    {\r\n      //copy each VARIANT element one by one\r\n      for(long i=0; i<numElements;", 200);
      mBuffer.append(" i++)\r\n      {\r\n        VARIANT & var = values[i];\r\n\r\n        //does the VARIANT contains unsigned char data \?\r\n        if (var.vt == VT_UI1)\r\n        {\r\n          oData.append(1, var.bVal);\r\n        ", 200);
      mBuffer.append("}\r\n      }\r\n    }\r\n    SafeArrayUnaccessData(sa);\r\n\r\n    oVariantFlavor = VBSCRIPT;\r\n\r\n    return S_OK;\r\n  }\r\n  else if (iVar.vt == BYTE_ARRAY)\r\n  {\r\n    //this VARIANT is a SAFEARRAY that contains By", 200);
      mBuffer.append("tes (unsigned char)\r\n    //this is typical of C++ client calls\r\n    SAFEARRAY * sa = iVar.parray;\r\n\r\n    byte * values;\r\n    HRESULT hr = SafeArrayAccessData(sa, (void**)&values); // direct access to ", 200);
      mBuffer.append("SA memory\r\n    if (FAILED(hr))\r\n      return NULL;\r\n\r\n    // get array bounds\r\n    long lowerBound = 0;\r\n    long upperBound = 0;\r\n    SafeArrayGetLBound(sa, 1, &lowerBound);\r\n    SafeArrayGetUBound(s", 200);
      mBuffer.append("a, 1, &upperBound);\r\n\r\n    long numElements = upperBound - lowerBound + 1;\r\n    if (numElements == 0)\r\n    {\r\n      oData.clear();\r\n    }\r\n    else\r\n    {\r\n      //copy all continuous BYTE elements as", 200);
      mBuffer.append(" a single operation\r\n      oData.assign( (const char*)values, numElements);\r\n    }\r\n    SafeArrayUnaccessData(sa);\r\n    \r\n    oVariantFlavor = CPLUSPLUS;\r\n\r\n    return S_OK;\r\n  }\r\n  else\r\n    return E", 200);
      mBuffer.append("_INVALIDARG;\r\n}\r\n\r\nHRESULT ByteArray2Variant(const std::string & iData, const DCOMPLUGIN_PACKAGE_NAME::VariantFlavor & iVariantFlavor, VARIANT & oVar)\r\n{\r\n  switch(iVariantFlavor)\r\n  {\r\n  case DCOMPLU", 200);
      mBuffer.append("GIN_PACKAGE_NAME::CPLUSPLUS:\r\n    {\r\n      //https://stackoverflow.com/questions/10905043/c-sharp-marshal-byte-to-com-safearray-parameter-with-ref-object-signature\r\n      VariantInit (&oVar);\r\n      V", 200);
      mBuffer.append("ariantClear(&oVar);\r\n\r\n      SAFEARRAYBOUND bounds[1];\r\n      bounds[0].cElements = iData.size();\r\n      bounds[0].lLbound = 1;\r\n\r\n      SAFEARRAY* sa = SafeArrayCreate(VT_UI1, 1, bounds);\r\n      if(s", 200);
      mBuffer.append("a == NULL)\r\n        return E_OUTOFMEMORY;\r\n\r\n      //copy data to SAFEARRAY\r\n      SafeArrayLock(sa);\r\n      memcpy(sa->pvData, iData.c_str(), iData.size());\r\n      SafeArrayUnlock(sa);\r\n\r\n      oVar.", 200);
      mBuffer.append("parray = sa;\r\n      oVar.vt = VT_ARRAY | VT_UI1;\r\n      return S_OK;\r\n    };\r\n    break;\r\n  case DCOMPLUGIN_PACKAGE_NAME::VBSCRIPT:\r\n    {\r\n      //https://stackoverflow.com/questions/10905043/c-sharp", 200);
      mBuffer.append("-marshal-byte-to-com-safearray-parameter-with-ref-object-signature\r\n      VariantInit (&oVar);\r\n      VariantClear(&oVar);\r\n\r\n      SAFEARRAYBOUND bounds[1];\r\n      bounds[0].cElements = iData.size();", 200);
      mBuffer.append("\r\n      bounds[0].lLbound = 1;\r\n\r\n      SAFEARRAY* sa = SafeArrayCreate(VT_VARIANT, 1, bounds);\r\n      if(sa == NULL)\r\n        return E_OUTOFMEMORY;\r\n\r\n      //copy data to SAFEARRAY\r\n      VARIANT * ", 200);
      mBuffer.append("values = NULL;\r\n      HRESULT hr = SafeArrayAccessData(sa, (void **)&values);\r\n      if (SUCCEEDED(hr))\r\n      {\r\n        for(size_t i=0; i<iData.size(); i++)\r\n        {\r\n          VARIANT & tmp = val", 200);
      mBuffer.append("ues[i];\r\n          VariantInit (&tmp);\r\n          tmp.vt = VT_UI1;\r\n          tmp.bVal = (unsigned char)iData[i];\r\n        }\r\n        SafeArrayUnaccessData(sa);\r\n      }\r\n\r\n      oVar.parray = sa;\r\n  ", 200);
      mBuffer.append("    oVar.vt = VT_ARRAY | VT_VARIANT;\r\n      return S_OK;\r\n    };\r\n    break;\r\n  default:\r\n    return E_INVALIDARG;\r\n  };\r\n\r\n}\r\n\r\n///\r\nHRESULT SerializeMessageToVariant(const google::protobuf::MessageL", 200);
      mBuffer.append("ite & iMsg, const DCOMPLUGIN_PACKAGE_NAME::VariantFlavor & iVariantFlavor, VARIANT & oVar)\r\n{\r\n  std::string data;\r\n  bool success = iMsg.SerializeToString(&data);\r\n  if (!success)\r\n    return E_INVAL", 200);
      mBuffer.append("IDARG;\r\n\r\n  HRESULT hr = ByteArray2Variant(data, iVariantFlavor, oVar);\r\n  if (FAILED(hr))\r\n    return hr;\r\n  return S_OK;\r\n}\r\n\r\n///\r\nHRESULT DeserializeVariantToMessage(VARIANT & iVar, google::protob", 200);
      mBuffer.append("uf::MessageLite & oMsg, DCOMPLUGIN_PACKAGE_NAME::VariantFlavor & oVariantFlavor)\r\n{\r\n  std::string data;\r\n  HRESULT hr = Variant2ByteArray(iVar, oVariantFlavor, data);\r\n  if (FAILED(hr))\r\n    return h", 200);
      mBuffer.append("r;\r\n\r\n  //deserialize data into message\r\n  bool success = oMsg.ParseFromString(data);\r\n  if (!success)\r\n  {\r\n    return E_INVALIDARG;\r\n  }\r\n\r\n  return S_OK;\r\n}\r\n\r\n}  // namespace DCOMPLUGIN_PACKAGE_NA", 200);
      mBuffer.append("ME\r\n", 4);
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
  const File & getMessageSerializerCppFile() { static MessageSerializerCppFile _instance; return _instance; }
}; //bin2cpp
