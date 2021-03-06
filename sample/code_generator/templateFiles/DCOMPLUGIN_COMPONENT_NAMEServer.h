#pragma once

///<summary>
///DCOMPLUGIN_IDL_INTERFACE_NAMEServer interface declaration.
///Implements all the required code for the COM server.
///</summary>
class CoDCOMPLUGIN_COMPONENT_NAMEServer : public DCOMPLUGIN_IDL_INTERFACE_NAMEServer
{

  // Construction
public:
  CoDCOMPLUGIN_COMPONENT_NAMEServer();
  ~CoDCOMPLUGIN_COMPONENT_NAMEServer();

  // IUnknown interface
  virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv) ;
  virtual ULONG __stdcall AddRef() ;
  virtual ULONG __stdcall Release() ;

  // IDispatch interface
  virtual HRESULT __stdcall GetTypeInfoCount(UINT* pctinfo);
  virtual HRESULT __stdcall GetTypeInfo(UINT itinfo, LCID lcid, ITypeInfo** pptinfo);
  virtual HRESULT __stdcall GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgdispid);
  virtual HRESULT __stdcall Invoke(DISPID dispidMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS* pdispparams, VARIANT* pvarResult, EXCEPINFO* pexcepinfo, UINT* puArgErr);

  // DCOMPLUGIN_IDL_INTERFACE_NAMEServer interface
  DCOMPLUGIN_COCLASS_DECLARATION

private:

  // IDispatch private methods
  HRESULT LoadTypeInfo(ITypeInfo ** pptinfo, const CLSID& libid, const CLSID& iid, LCID lcid);

  long m_cRef;          // Reference count
  LPTYPEINFO m_ptinfo;  // pointer to type-library
};

///<summary>Class factory for CoDCOMPLUGIN_COMPONENT_NAMEServer.</summary>
class CFactory : public IClassFactory
{
public:
  // IUnknown
  virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv) ;         
  virtual ULONG   __stdcall AddRef() ;
  virtual ULONG   __stdcall Release() ;

  // Interface IClassFactory
  virtual HRESULT __stdcall CreateInstance(IUnknown* pUnknownOuter,
                                           const IID& iid,
                                           void** ppv) ;
  virtual HRESULT __stdcall LockServer(BOOL bLock) ; 

  // Constructor
  CFactory() : m_cRef(1) {}

  // Destructor
  ~CFactory() {;}

private:
  long m_cRef ;
} ;


 
///<summary>
///Registers the CoDCOMPLUGIN_COMPONENT_NAMEServer class object with OLE (the internal COM table) so other applications can connect to it.
///Note that this operation has nothing to do with the registry.
///</summary>
DWORD CoEXEInitialize();

///<summary>
///Informs OLE that CoDCOMPLUGIN_COMPONENT_NAMEServer class object is no longer available for use.
///Unregister the CoDCOMPLUGIN_COMPONENT_NAMEServer class object registered through CoEXEInitialize from the known table of class objects.
///</summary>
void CoEXEUninitialize(DWORD nToken);

///<summary>
///Instructs the application to create its registry entries for all classes supported in this server module.
///Called when execuging "DCOMPLUGIN_COMPONENT_NAMEServer.exe /regserver"
///</summary>
STDAPI DllRegisterServer();

///<summary>
///Instructs the application to remove the entries created through DllRegisterServer.
///Called when execuging "DCOMPLUGIN_COMPONENT_NAMEServer.exe /unregserver"
///</summary>
STDAPI DllUnregisterServer();

///<summary>
///Instructs the application to create its registry entries for all classes supported in this server module.
///Called when execuging "DCOMPLUGIN_COMPONENT_NAMEServer.exe /regserver"
///</summary>
STDAPI RegisterApplicationId();

///<summary>
///Instructs the application to remove the entries created through DllRegisterServer.
///Called when execuging "DCOMPLUGIN_COMPONENT_NAMEServer.exe /unregserver"
///</summary>
STDAPI UnregisterApplicationId();
