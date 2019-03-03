#include <objbase.h> // 
#include "DemoServer_h.h"
#include "DemoServer_i.c"
#include <comdef.h>
#include "Registry.h"
#include "DemoServer.h"
#include "DemoServerImpl.h"
#include "TestDemo.pb.h"
#include "stdio.h"
#include "stdlib.h"

#pragma comment(lib, "rpcrt4" )
#pragma comment(lib, "ole32" ) 

#include "MessageSerializer.h"
#include "ErrorHandlers.h"

#include "WinError.h"

// Count of active components
static long g_cComponents = 0 ;

// Count of locks
static long g_cServerLocks = 0 ;

// DLL module handle
static HMODULE g_hModule = NULL ;

// Friendly name of component
const char g_szFriendlyName[] = "DemoServer object";

// Version-independent ProgID of component
const char g_szVerIndProgID[] = "DemoServer.object";

// ProgID of component
const char g_szProgID[] = "DemoServer.object.1";

// AppID
const char g_szAppID[] = "{BD4F1636-820F-4499-9878-69B055547BE5}";


// Actual server implementation
testdemo::DemoServerImpl g_objDemoServerImpl;

//
// Constructor
//
CoDemoServer::CoDemoServer() : m_cRef(1)
{ 
  InterlockedIncrement(&g_cComponents) ; 

  m_ptinfo = NULL;
  LoadTypeInfo(&m_ptinfo, LIBID_LibDemoServer, IID_IDemoServer, 0);
}

//
// Destructor
//
CoDemoServer::~CoDemoServer() 
{ 
  InterlockedDecrement(&g_cComponents) ; 
}

//
// IUnknown implementation
//
HRESULT __stdcall CoDemoServer::QueryInterface(const IID& iid, void** ppv)
{    
  if (iid == IID_IUnknown || iid == IID_IDemoServer || iid == IID_IDispatch)
  {
    *ppv = static_cast<IDemoServer*>(this) ; 
  }
  else
  {
    *ppv = NULL ;
    return E_NOINTERFACE ;
  }
  reinterpret_cast<IUnknown*>(*ppv)->AddRef() ;
  return S_OK ;
}

ULONG __stdcall CoDemoServer::AddRef()
{
  return InterlockedIncrement(&m_cRef) ;
}

ULONG __stdcall CoDemoServer::Release() 
{
  if (InterlockedDecrement(&m_cRef) == 0)
  {
    delete this ;
    ::PostMessage(NULL,WM_QUIT,0,0);
    return 0 ;
  }
  return m_cRef ;
}

///<DCOMPLUGIN_COCLASS_DEFINITION>
STDMETHODIMP CoDemoServer::GetSequentialNumber(VARIANT requestBuffer, VARIANT* responseBuffer)
{
  testdemo::VariantFlavor flavor;
  testdemo::VoidMessage requestMessage;

  //deserialize requestMessage
  HRESULT hr = DeserializeVariantToMessage(requestBuffer, requestMessage, flavor);
  if (FAILED(hr))
  {
    //COM call failed. Show error
    testdemo::MessageBoxLastComError(hr);
    return hr;
  }

  //call server implementation
  testdemo::SequentialNumber responseMessage;
  g_objDemoServerImpl.GetSequentialNumber(requestMessage, responseMessage);

  //serialize response
  hr = SerializeMessageToVariant(responseMessage, flavor, *responseBuffer);
  if (FAILED(hr))
  {
    //COM call failed. Show error
    testdemo::MessageBoxLastComError(hr);
    return hr;
  }

  return S_OK;
}

STDMETHODIMP CoDemoServer::Hello(VARIANT requestBuffer, VARIANT* responseBuffer)
{
  testdemo::VariantFlavor flavor;
  testdemo::HelloRequest requestMessage;

  //deserialize requestMessage
  HRESULT hr = DeserializeVariantToMessage(requestBuffer, requestMessage, flavor);
  if (FAILED(hr))
  {
    //COM call failed. Show error
    testdemo::MessageBoxLastComError(hr);
    return hr;
  }

  //call server implementation
  testdemo::HelloResponse responseMessage;
  g_objDemoServerImpl.Hello(requestMessage, responseMessage);

  //serialize response
  hr = SerializeMessageToVariant(responseMessage, flavor, *responseBuffer);
  if (FAILED(hr))
  {
    //COM call failed. Show error
    testdemo::MessageBoxLastComError(hr);
    return hr;
  }

  return S_OK;
}
///</DCOMPLUGIN_COCLASS_DEFINITION>

HRESULT CoDemoServer::LoadTypeInfo(ITypeInfo ** pptinfo, const CLSID &libid, const CLSID &iid, LCID lcid)
{
   HRESULT hr;
   LPTYPELIB ptlib = NULL;
   LPTYPEINFO ptinfo = NULL;

   *pptinfo = NULL;

   // Load type library.
   hr = LoadRegTypeLib(libid, 1, 0, lcid, &ptlib);
   if (FAILED(hr))
      return hr;

   // Get type information for interface of the object.
   hr = ptlib->GetTypeInfoOfGuid(iid, &ptinfo);
   if (FAILED(hr))
   {
      ptlib->Release();
      return hr;
   }

   ptlib->Release();
   *pptinfo = ptinfo;
   return NOERROR;
}


HRESULT __stdcall CoDemoServer::GetTypeInfoCount(UINT* pctinfo)
{
  *pctinfo = 1;
  return S_OK;
}
HRESULT __stdcall CoDemoServer::GetTypeInfo(UINT itinfo, LCID lcid, ITypeInfo** pptinfo)
{
  *pptinfo = NULL;

  if(itinfo != 0)
    return ResultFromScode(DISP_E_BADINDEX);

  m_ptinfo->AddRef();      // AddRef and return pointer to cached
                           // typeinfo for this object.
  *pptinfo = m_ptinfo;

  return NOERROR;
}
HRESULT __stdcall CoDemoServer::GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames,
    LCID lcid, DISPID* rgdispid)
{
  return DispGetIDsOfNames(m_ptinfo, rgszNames, cNames, rgdispid);
}
HRESULT __stdcall CoDemoServer::Invoke(DISPID dispidMember, REFIID riid,
    LCID lcid, WORD wFlags, DISPPARAMS* pdispparams, VARIANT* pvarResult,
    EXCEPINFO* pexcepinfo, UINT* puArgErr)
{
  return DispInvoke(
        this, m_ptinfo,
        dispidMember, wFlags, pdispparams,
        pvarResult, pexcepinfo, puArgErr); 
}


//
// Class factory IUnknown implementation
//
HRESULT __stdcall CFactory::QueryInterface(const IID& iid, void** ppv)
{    
  if ((iid == IID_IUnknown) || (iid == IID_IClassFactory))
  {
    *ppv = static_cast<IClassFactory*>(this) ; 
  }
  else
  {
    *ppv = NULL ;
    return E_NOINTERFACE ;
  }
  reinterpret_cast<IUnknown*>(*ppv)->AddRef() ;
  return S_OK ;
}

ULONG __stdcall CFactory::AddRef()
{
  return InterlockedIncrement(&m_cRef) ;
}

ULONG __stdcall CFactory::Release() 
{
  if (InterlockedDecrement(&m_cRef) == 0)
  {
    delete this ;
    return 0 ;
  }
  return m_cRef ;
}

//
// IClassFactory implementation
//
HRESULT __stdcall CFactory::CreateInstance(IUnknown* pUnknownOuter,
                                           const IID& iid,
                                           void** ppv) 
{
  // Cannot aggregate.
  if (pUnknownOuter != NULL)
  {
    return CLASS_E_NOAGGREGATION ;
  }

  // Create component.
  CoDemoServer* pA = new CoDemoServer ;
  if (pA == NULL)
  {
    return E_OUTOFMEMORY ;
  }

  // Get the requested interface.
  HRESULT hr = pA->QueryInterface(iid, ppv) ;

  // Release the IUnknown pointer.
  // (If QueryInterface failed, component will delete itself.)
  pA->Release() ;
  return hr ;
}

// LockServer
HRESULT __stdcall CFactory::LockServer(BOOL bLock) 
{
  if (bLock)
  {
    InterlockedIncrement(&g_cServerLocks) ; 
  }
  else
  {
    InterlockedDecrement(&g_cServerLocks) ;
  }
  return S_OK ;
}







///////////////////////////////////////////////////////////
//
// Exported functions
//

//
// Can DLL unload now?
//
STDAPI DllCanUnloadNow()
{
  if ((g_cComponents == 0) && (g_cServerLocks == 0))
  {
    return S_OK ;
  }
  else
  {
    return S_FALSE ;
  }
}

//
// Get class factory
//
STDAPI DllGetClassObject(const CLSID& clsid,
                         const IID& iid,
                         void** ppv)
{
  // Can we create this component?
  if (clsid != CLSID_CoDemoServer)
  {
    return CLASS_E_CLASSNOTAVAILABLE ;
  }

  // Create class factory.
  CFactory* pFactory = new CFactory ;  // Reference count set to 1
                                       // in constructor
  if (pFactory == NULL)
  {
    return E_OUTOFMEMORY ;
  }

  // Get requested interface.
  HRESULT hr = pFactory->QueryInterface(iid, ppv) ;
  pFactory->Release() ;

  return hr ;
}




CFactory gClassFactory;



DWORD CoEXEInitialize()
{
  DWORD nReturn;

  HRESULT hr=::CoRegisterClassObject(CLSID_CoDemoServer,
    &gClassFactory,
    CLSCTX_SERVER, 
    REGCLS_MULTIPLEUSE, 
    &nReturn);

  return nReturn;
}

void CoEXEUninitialize(DWORD nToken)
{
  ::CoRevokeClassObject(nToken);
}










//
// Server registration
//
STDAPI DllRegisterServer()
{

  g_hModule = ::GetModuleHandle(NULL);

  HRESULT hr= RegisterServer(g_hModule,
                             g_szAppID,
                             CLSID_CoDemoServer,
                             g_szFriendlyName,
                             g_szVerIndProgID,
                             g_szProgID,
                             LIBID_LibDemoServer);
  if (SUCCEEDED(hr))
  {
    hr = RegisterTypeLib( g_hModule, NULL);
  }
  return hr;
}


//
// Server unregistration
//
STDAPI DllUnregisterServer()
{

  g_hModule = ::GetModuleHandle(NULL);

  HRESULT hr= UnregisterServer(g_hModule,
                               g_szAppID,
                               CLSID_CoDemoServer,
                               g_szVerIndProgID,
                               g_szProgID,
                               LIBID_LibDemoServer);
  if (SUCCEEDED(hr))
  {
    UnRegisterTypeLib( g_hModule, NULL);
  }
  return hr;
}



///////////////////////////////////////////////////////////
//
// DLL module information
//
BOOL APIENTRY DllMain(HANDLE hModule,
                      DWORD dwReason,
                      void* lpReserved)
{
  if (dwReason == DLL_PROCESS_ATTACH)
  {
    g_hModule = (HMODULE)hModule ;
  }

  return TRUE ;
}
