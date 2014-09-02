

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Aug 28 15:20:29 2014
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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IDataMgr,0x8F7DDF6B,0x4907,0x45D9,0x87,0x69,0x70,0x6F,0x80,0x0D,0x92,0x4C);


MIDL_DEFINE_GUID(IID, LIBID_ComServerLib,0x25C35E63,0x4ED5,0x485D,0x89,0x2C,0x83,0x23,0x6F,0x7F,0x60,0x39);


MIDL_DEFINE_GUID(IID, DIID__IDataMgrEvents,0xEC42CE68,0xE7A6,0x45AC,0xB6,0xE5,0x36,0x2E,0x7D,0x5B,0x3F,0x6A);


MIDL_DEFINE_GUID(CLSID, CLSID_DataMgr,0xBCCB259A,0x648C,0x46D8,0x80,0xEC,0xF3,0x54,0xDF,0xE7,0xB5,0x5B);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



