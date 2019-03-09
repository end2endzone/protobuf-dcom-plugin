

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Nov 17 15:45:18 2017
 */
/* Compiler settings for DemoServer.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __DemoServer_h_h__
#define __DemoServer_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDemoServer_FWD_DEFINED__
#define __IDemoServer_FWD_DEFINED__
typedef interface IDemoServer IDemoServer;
#endif 	/* __IDemoServer_FWD_DEFINED__ */


#ifndef __CoDemoServer_FWD_DEFINED__
#define __CoDemoServer_FWD_DEFINED__

#ifdef __cplusplus
typedef class CoDemoServer CoDemoServer;
#else
typedef struct CoDemoServer CoDemoServer;
#endif /* __cplusplus */

#endif 	/* __CoDemoServer_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IDemoServer_INTERFACE_DEFINED__
#define __IDemoServer_INTERFACE_DEFINED__

/* interface IDemoServer */
/* [unique][dual][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDemoServer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7F24AABF-C822-4c18-9432-21433208F4DC")
    IDemoServer : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetSequentialNumber( 
            /* [in] */ VARIANT requestBuffer,
            /* [retval][out] */ VARIANT *responseBuffer) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Hello( 
            /* [in] */ VARIANT requestBuffer,
            /* [retval][out] */ VARIANT *responseBuffer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDemoServerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDemoServer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDemoServer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDemoServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDemoServer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDemoServer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDemoServer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDemoServer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetSequentialNumber )( 
            IDemoServer * This,
            /* [in] */ VARIANT requestBuffer,
            /* [retval][out] */ VARIANT *responseBuffer);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Hello )( 
            IDemoServer * This,
            /* [in] */ VARIANT requestBuffer,
            /* [retval][out] */ VARIANT *responseBuffer);
        
        END_INTERFACE
    } IDemoServerVtbl;

    interface IDemoServer
    {
        CONST_VTBL struct IDemoServerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDemoServer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDemoServer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDemoServer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDemoServer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDemoServer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDemoServer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDemoServer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDemoServer_GetSequentialNumber(This,requestBuffer,responseBuffer)	\
    ( (This)->lpVtbl -> GetSequentialNumber(This,requestBuffer,responseBuffer) ) 

#define IDemoServer_Hello(This,requestBuffer,responseBuffer)	\
    ( (This)->lpVtbl -> Hello(This,requestBuffer,responseBuffer) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDemoServer_INTERFACE_DEFINED__ */



#ifndef __LibDemoServer_LIBRARY_DEFINED__
#define __LibDemoServer_LIBRARY_DEFINED__

/* library LibDemoServer */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_LibDemoServer;

EXTERN_C const CLSID CLSID_CoDemoServer;

#ifdef __cplusplus

class DECLSPEC_UUID("6AE24C34-1466-482e-9407-90B98798A712")
CoDemoServer;
#endif
#endif /* __LibDemoServer_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


