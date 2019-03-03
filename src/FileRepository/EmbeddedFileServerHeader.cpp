/**
 * This file was generated by
 * bin2cpp v1.3.
 * Copyright (C) 2013-2014 end2endzone.com. All rights reserved.
 * Do not modify this file.
 */
#include ".\EmbeddedFileServerHeader.h"
#include <stdio.h> //for FILE
#include <string> //for memcpy
namespace bin2cpp
{
  class ServerHeaderFile : public virtual bin2cpp::File
  {
  public:
    ServerHeaderFile() {}
    ~ServerHeaderFile() {}
    virtual size_t getSize() { return 3583; }
    virtual size_t getSegmentSize() { return 200; }
    virtual size_t getNumSegments() { return 18; }
    virtual const char * getFilename() { return "DCOMPLUGIN_COMPONENT_NAMEServer.h"; }
    virtual const char * getSegment(size_t iIndex, size_t & oLength)
    {
      oLength = 0;
      if (iIndex >= getNumSegments())
        return NULL;
      const char * buffer = NULL;
      size_t index = 0;
      oLength = getSegmentSize();
      buffer = "#pragma once\x0d\x0a\x0d\012///<summary>\x0d\012///DCOMPLUGIN_IDL_INTERFACE_NAMEServer interface declaration.\x0d\012///Implements all the required code for the COM server.\x0d\012///</summary>\x0d\012class CoDCOMPLUGIN_COMPONENT_NAMESe"; if (iIndex == index) return buffer; index++;
      buffer = "rver : public DCOMPLUGIN_IDL_INTERFACE_NAMEServer\x0d\012{\x0d\x0a\x0d\012  // Construction\x0d\012public:\x0d\012  CoDCOMPLUGIN_COMPONENT_NAMEServer();\x0d\012  ~CoDCOMPLUGIN_COMPONENT_NAMEServer();\x0d\x0a\x0d\012  // IUnknown interface\x0d\012  virtua"; if (iIndex == index) return buffer; index++;
      buffer = "l HRESULT __stdcall QueryInterface(const IID& iid, void** ppv) ;\x0d\012  virtual ULONG __stdcall AddRef() ;\x0d\012  virtual ULONG __stdcall Release() ;\x0d\x0a\x0d\012  // IDispatch interface\x0d\012  virtual HRESULT __stdcall G"; if (iIndex == index) return buffer; index++;
      buffer = "etTypeInfoCount(UINT* pctinfo);\x0d\012  virtual HRESULT __stdcall GetTypeInfo(UINT itinfo, LCID lcid, ITypeInfo** pptinfo);\x0d\012  virtual HRESULT __stdcall GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT"; if (iIndex == index) return buffer; index++;
      buffer = " cNames, LCID lcid, DISPID* rgdispid);\x0d\012  virtual HRESULT __stdcall Invoke(DISPID dispidMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS* pdispparams, VARIANT* pvarResult, EXCEPINFO* pexcepinfo"; if (iIndex == index) return buffer; index++;
      buffer = ", UINT* puArgErr);\x0d\x0a\x0d\012  // DCOMPLUGIN_IDL_INTERFACE_NAMEServer interface\x0d\012  DCOMPLUGIN_COCLASS_DECLARATION\x0d\x0a\x0d\012private:\x0d\x0a\x0d\012  // IDispatch private methods\x0d\012  HRESULT LoadTypeInfo(ITypeInfo ** pptinfo, c"; if (iIndex == index) return buffer; index++;
      buffer = "onst CLSID& libid, const CLSID& iid, LCID lcid);\x0d\x0a\x0d\012  long m_cRef;          // Reference count\x0d\012  LPTYPEINFO m_ptinfo;  // pointer to type-library\x0d\012};\x0d\x0a\x0d\012///<summary>Class factory for CoDCOMPLUGIN_COM"; if (iIndex == index) return buffer; index++;
      buffer = "PONENT_NAMEServer.</summary>\x0d\012class CFactory : public IClassFactory\x0d\012{\x0d\012public:\x0d\012  // IUnknown\x0d\012  virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv) ;         \x0d\012  virtual ULONG   __s"; if (iIndex == index) return buffer; index++;
      buffer = "tdcall AddRef() ;\x0d\012  virtual ULONG   __stdcall Release() ;\x0d\x0a\x0d\012  // Interface IClassFactory\x0d\012  virtual HRESULT __stdcall CreateInstance(IUnknown* pUnknownOuter,\x0d\012                                       "; if (iIndex == index) return buffer; index++;
      buffer = "    const IID& iid,\x0d\012                                           void** ppv) ;\x0d\012  virtual HRESULT __stdcall LockServer(BOOL bLock) ; \x0d\x0a\x0d\012  // Constructor\x0d\012  CFactory() : m_cRef(1) {}\x0d\x0a\x0d\012  // Destructor"; if (iIndex == index) return buffer; index++;
      buffer = "\x0d\012  ~CFactory() {;}\x0d\x0a\x0d\012private:\x0d\012  long m_cRef ;\x0d\012} ;\x0d\x0a\x0d\x0a\x0d\012 \x0d\012///<summary>\x0d\012///Registers the CoDCOMPLUGIN_COMPONENT_NAMEServer class object with OLE (the internal COM table) so other applications can "; if (iIndex == index) return buffer; index++;
      buffer = "connect to it.\x0d\012///Note that this operation has nothing to do with the registry.\x0d\012///</summary>\x0d\012DWORD CoEXEInitialize();\x0d\x0a\x0d\012///<summary>\x0d\012///Informs OLE that CoDCOMPLUGIN_COMPONENT_NAMEServer class o"; if (iIndex == index) return buffer; index++;
      buffer = "bject is no longer available for use.\x0d\012///Unregister the CoDCOMPLUGIN_COMPONENT_NAMEServer class object registered through CoEXEInitialize from the known table of class objects.\x0d\012///</summary>\x0d\012void C"; if (iIndex == index) return buffer; index++;
      buffer = "oEXEUninitialize(DWORD nToken);\x0d\x0a\x0d\012///<summary>\x0d\012///Instructs the application to create its registry entries for all classes supported in this server module.\x0d\012///Called when execuging \"DCOMPLUGIN_COMP"; if (iIndex == index) return buffer; index++;
      buffer = "ONENT_NAMEServer.exe /regserver\"\x0d\012///</summary>\x0d\012STDAPI DllRegisterServer();\x0d\x0a\x0d\012///<summary>\x0d\012///Instructs the application to remove the entries created through DllRegisterServer.\x0d\012///Called when exec"; if (iIndex == index) return buffer; index++;
      buffer = "uging \"DCOMPLUGIN_COMPONENT_NAMEServer.exe /unregserver\"\x0d\012///</summary>\x0d\012STDAPI DllUnregisterServer();\x0d\x0a\x0d\012///<summary>\x0d\012///Instructs the application to create its registry entries for all classes supp"; if (iIndex == index) return buffer; index++;
      buffer = "orted in this server module.\x0d\012///Called when execuging \"DCOMPLUGIN_COMPONENT_NAMEServer.exe /regserver\"\x0d\012///</summary>\x0d\012STDAPI RegisterApplicationId();\x0d\x0a\x0d\012///<summary>\x0d\012///Instructs the application to"; if (iIndex == index) return buffer; index++;
      oLength = 183;
      buffer = " remove the entries created through DllRegisterServer.\x0d\012///Called when execuging \"DCOMPLUGIN_COMPONENT_NAMEServer.exe /unregserver\"\x0d\012///</summary>\x0d\012STDAPI UnregisterApplicationId();\x0d\x0a"; if (iIndex == index) return buffer; index++;
      oLength = 0;
      return NULL;
    }
    virtual const char * getMd5() { return "8172a812af69f7277092bc703925c4f5"; }
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
  File & getServerHeaderFile() { static ServerHeaderFile _instance; return _instance; }
}; //bin2cpp
