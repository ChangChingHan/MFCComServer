

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Wed Oct 29 16:16:33 2014
 */
/* Compiler settings for .\ComServer.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

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

#ifndef __ComServer_i_h__
#define __ComServer_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDataMgr_FWD_DEFINED__
#define __IDataMgr_FWD_DEFINED__
typedef interface IDataMgr IDataMgr;
#endif 	/* __IDataMgr_FWD_DEFINED__ */


#ifndef ___IDataMgrEvents_FWD_DEFINED__
#define ___IDataMgrEvents_FWD_DEFINED__
typedef interface _IDataMgrEvents _IDataMgrEvents;
#endif 	/* ___IDataMgrEvents_FWD_DEFINED__ */


#ifndef __DataMgr_FWD_DEFINED__
#define __DataMgr_FWD_DEFINED__

#ifdef __cplusplus
typedef class DataMgr DataMgr;
#else
typedef struct DataMgr DataMgr;
#endif /* __cplusplus */

#endif 	/* __DataMgr_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IDataMgr_INTERFACE_DEFINED__
#define __IDataMgr_INTERFACE_DEFINED__

/* interface IDataMgr */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDataMgr;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8F7DDF6B-4907-45D9-8769-706F800D924C")
    IDataMgr : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE QueryFromDC( 
            /* [in] */ BYTE bDataType,
            /* [in] */ BYTE bOperation,
            /* [out][in] */ VARIANT *VarData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDataMgrVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDataMgr * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDataMgr * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDataMgr * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDataMgr * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDataMgr * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDataMgr * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDataMgr * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *QueryFromDC )( 
            IDataMgr * This,
            /* [in] */ BYTE bDataType,
            /* [in] */ BYTE bOperation,
            /* [out][in] */ VARIANT *VarData);
        
        END_INTERFACE
    } IDataMgrVtbl;

    interface IDataMgr
    {
        CONST_VTBL struct IDataMgrVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDataMgr_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDataMgr_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDataMgr_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDataMgr_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDataMgr_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDataMgr_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDataMgr_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDataMgr_QueryFromDC(This,bDataType,bOperation,VarData)	\
    ( (This)->lpVtbl -> QueryFromDC(This,bDataType,bOperation,VarData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDataMgr_INTERFACE_DEFINED__ */



#ifndef __ComServerLib_LIBRARY_DEFINED__
#define __ComServerLib_LIBRARY_DEFINED__

/* library ComServerLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ComServerLib;

#ifndef ___IDataMgrEvents_DISPINTERFACE_DEFINED__
#define ___IDataMgrEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IDataMgrEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IDataMgrEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EC42CE68-E7A6-45AC-B6E5-362E7D5B3F6A")
    _IDataMgrEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IDataMgrEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IDataMgrEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IDataMgrEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IDataMgrEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IDataMgrEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IDataMgrEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IDataMgrEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IDataMgrEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IDataMgrEventsVtbl;

    interface _IDataMgrEvents
    {
        CONST_VTBL struct _IDataMgrEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IDataMgrEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IDataMgrEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IDataMgrEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IDataMgrEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IDataMgrEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IDataMgrEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IDataMgrEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IDataMgrEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_DataMgr;

#ifdef __cplusplus

class DECLSPEC_UUID("BCCB259A-648C-46D8-80EC-F354DFE7B55B")
DataMgr;
#endif
#endif /* __ComServerLib_LIBRARY_DEFINED__ */

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


