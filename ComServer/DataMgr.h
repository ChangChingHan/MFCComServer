// DataMgr.h : Declaration of the CDataMgr

#pragma once
#include "resource.h"       // main symbols

#include "ComServer_i.h"
#include "_IDataMgrEvents_CP.h"
#include "DatabaseMgr.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CDataMgr

class ATL_NO_VTABLE CDataMgr :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDataMgr, &CLSID_DataMgr>,
	public IConnectionPointContainerImpl<CDataMgr>,
	public CProxy_IDataMgrEvents<CDataMgr>,
	public IDispatchImpl<IDataMgr, &IID_IDataMgr, &LIBID_ComServerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CDataMgr()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DATAMGR)


BEGIN_COM_MAP(CDataMgr)
	COM_INTERFACE_ENTRY(IDataMgr)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CDataMgr)
	CONNECTION_POINT_ENTRY(__uuidof(_IDataMgrEvents))
END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

private:
	CDatabaseMgr m_databaseMgr;

private:
	void DatabaseOperation(BYTE bOperation, VARIANT* VarData);

	void QueryDatabase(BYTE bOperation, VARIANT* VarData);
	void InsertDatabase(BYTE bOperation, VARIANT* VarData);
	void DeleteDatabase(BYTE bOperation, VARIANT* VarData);
	void UpdateDatabase(BYTE bOperation, VARIANT* VarData);

	void FlushData();
	
public:

	STDMETHOD(QueryFromDC)(BYTE bDataType, BYTE bOperation, VARIANT* VarData);
};

OBJECT_ENTRY_AUTO(__uuidof(DataMgr), CDataMgr)
