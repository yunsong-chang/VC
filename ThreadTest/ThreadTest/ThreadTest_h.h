

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sun Apr 29 10:09:49 2018
 */
/* Compiler settings for ThreadTest.idl:
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


#ifndef __ThreadTest_h_h__
#define __ThreadTest_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IThreadTest_FWD_DEFINED__
#define __IThreadTest_FWD_DEFINED__
typedef interface IThreadTest IThreadTest;
#endif 	/* __IThreadTest_FWD_DEFINED__ */


#ifndef __ThreadTest_FWD_DEFINED__
#define __ThreadTest_FWD_DEFINED__

#ifdef __cplusplus
typedef class ThreadTest ThreadTest;
#else
typedef struct ThreadTest ThreadTest;
#endif /* __cplusplus */

#endif 	/* __ThreadTest_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __ThreadTest_LIBRARY_DEFINED__
#define __ThreadTest_LIBRARY_DEFINED__

/* library ThreadTest */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ThreadTest;

#ifndef __IThreadTest_DISPINTERFACE_DEFINED__
#define __IThreadTest_DISPINTERFACE_DEFINED__

/* dispinterface IThreadTest */
/* [uuid] */ 


EXTERN_C const IID DIID_IThreadTest;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00766A2F-1623-4D44-964D-9A885F70057B")
    IThreadTest : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IThreadTestVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IThreadTest * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IThreadTest * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IThreadTest * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IThreadTest * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IThreadTest * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IThreadTest * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IThreadTest * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IThreadTestVtbl;

    interface IThreadTest
    {
        CONST_VTBL struct IThreadTestVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IThreadTest_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IThreadTest_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IThreadTest_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IThreadTest_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IThreadTest_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IThreadTest_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IThreadTest_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IThreadTest_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ThreadTest;

#ifdef __cplusplus

class DECLSPEC_UUID("A3EA9976-1C41-43F7-B793-FD5953D9BECB")
ThreadTest;
#endif
#endif /* __ThreadTest_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


