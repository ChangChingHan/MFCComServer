// ec_storage.h : Declaration of the Cec_storage

#pragma once

// code generated on 2014年6月11日, 下午 04:37

class Cec_storageAccessor : public CEtroAccessor
{
public:
	LONG m_storageid;
	TCHAR m_storage_type[11];
	TCHAR m_all_cam_flag[2];
	LONG m_streamid;
	TCHAR m_store_location[257];
	TCHAR m_archive_location[101];
	LONG m_buffer_size;
	SHORT m_sort_order;
	TCHAR m_server_user[65];
	TCHAR m_server_password[65];
	TCHAR m_camera_ids[129];

	// The following wizard-generated data members contain status
	// values for the corresponding fields in the column map. You
	// can use these values to hold NULL values that the database
	// returns or to hold error information when the compiler returns
	// errors. See Field Status Data Members in Wizard-Generated
	// Accessors in the Visual C++ documentation for more information
	// on using these fields.
	// NOTE: You must initialize these fields before setting/inserting data!

	DBSTATUS m_dwstorageidStatus;
	DBSTATUS m_dwstorage_typeStatus;
	DBSTATUS m_dwall_cam_flagStatus;
	DBSTATUS m_dwstreamidStatus;
	DBSTATUS m_dwstore_locationStatus;
	DBSTATUS m_dwarchive_locationStatus;
	DBSTATUS m_dwbuffer_sizeStatus;
	DBSTATUS m_dwsort_orderStatus;
	DBSTATUS m_dwserver_userStatus;
	DBSTATUS m_dwserver_passwordStatus;
	DBSTATUS m_dwcamera_idsStatus;

	// The following wizard-generated data members contain length
	// values for the corresponding fields in the column map.
	// NOTE: For variable-length columns, you must initialize these
	//       fields before setting/inserting data!

	DBLENGTH m_dwstorageidLength;
	DBLENGTH m_dwstorage_typeLength;
	DBLENGTH m_dwall_cam_flagLength;
	DBLENGTH m_dwstreamidLength;
	DBLENGTH m_dwstore_locationLength;
	DBLENGTH m_dwarchive_locationLength;
	DBLENGTH m_dwbuffer_sizeLength;
	DBLENGTH m_dwsort_orderLength;
	DBLENGTH m_dwserver_userLength;
	DBLENGTH m_dwserver_passwordLength;
	DBLENGTH m_dwcamera_idsLength;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_IRowsetChange, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);
	}

	virtual HRESULT OpenDataSource()
	{
		CDataSource _db;
		HRESULT hr;
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
		IniDatabaseAuth();
		hr = _db.OpenFromInitializationString(m_strDatabaseAuth);
		if (FAILED(hr))
		{
#ifdef _DEBUG
			AtlTraceErrorRecords(hr);
#endif
			return hr;
		}
		return m_session.Open(_db);
	}

	void CloseDataSource()
	{
		m_session.Close();
	}

	operator const CSession&()
	{
		return m_session;
	}

	CSession m_session;

	DEFINE_COMMAND_EX(Cec_storageAccessor, L" \
	SELECT \
		storageid, \
		storage_type, \
		all_cam_flag, \
		streamid, \
		store_location, \
		archive_location, \
		buffer_size, \
		sort_order, \
		server_user, \
		server_password, \
		camera_ids \
		FROM dbo.ec_storage")


	// In order to fix several issues with some providers, the code below may bind
	// columns in a different order than reported by the provider

	BEGIN_COLUMN_MAP(Cec_storageAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_storageid, m_dwstorageidLength, m_dwstorageidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_storage_type, m_dwstorage_typeLength, m_dwstorage_typeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_all_cam_flag, m_dwall_cam_flagLength, m_dwall_cam_flagStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_streamid, m_dwstreamidLength, m_dwstreamidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_store_location, m_dwstore_locationLength, m_dwstore_locationStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_archive_location, m_dwarchive_locationLength, m_dwarchive_locationStatus)
		COLUMN_ENTRY_LENGTH_STATUS(7, m_buffer_size, m_dwbuffer_sizeLength, m_dwbuffer_sizeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(8, m_sort_order, m_dwsort_orderLength, m_dwsort_orderStatus)
		COLUMN_ENTRY_LENGTH_STATUS(9, m_server_user, m_dwserver_userLength, m_dwserver_userStatus)
		COLUMN_ENTRY_LENGTH_STATUS(10, m_server_password, m_dwserver_passwordLength, m_dwserver_passwordStatus)
		COLUMN_ENTRY_LENGTH_STATUS(11, m_camera_ids, m_dwcamera_idsLength, m_dwcamera_idsStatus)
	END_COLUMN_MAP()
};

class Cec_storage : public CCommand<CAccessor<Cec_storageAccessor> >
{
public:
	virtual HRESULT ModifyDatabase(const CString& strSQL )
	{
		HRESULT hr;
		::CoInitialize(NULL);
		hr = OpenDataSource();
		if (FAILED(hr))
			return hr;
		LPCWSTR wszCommand = (LPCWSTR)strSQL;
		if (wszCommand == NULL)
		{
			hr = _CommandClass::GetDefaultCommand(&wszCommand);
			if (FAILED(hr))
				return hr;
		}
		hr = Create(m_session, wszCommand, DBGUID_DEFAULT);
		if (FAILED(hr))
			return hr;

		hr = Execute((IUnknown**)GetInterfacePtr(), 0, 0, 
			0, 0);
		CoUninitialize();
		return hr;
	}
	virtual HRESULT OpenTbl( const CString& strSQL )
	{
		HRESULT hr;
		hr = Open( m_session, strSQL );
		if (FAILED(hr))
			return hr;
		return hr;
	}

	HRESULT OpenAll()
	{
		HRESULT hr;
		::CoInitialize(NULL);
		hr = OpenDataSource();
		if (FAILED(hr))
			return hr;
		__if_exists(GetRowsetProperties)
		{
			CDBPropSet propset(DBPROPSET_ROWSET);
			__if_exists(HasBookmark)
			{
				if( HasBookmark() )
					propset.AddProperty(DBPROP_IRowsetLocate, true);
			}
			GetRowsetProperties(&propset);
			CoUninitialize();
			return OpenRowset(&propset);
		}
		__if_not_exists(GetRowsetProperties)
		{
			__if_exists(HasBookmark)
			{
				if( HasBookmark() )
				{
					CDBPropSet propset(DBPROPSET_ROWSET);
					propset.AddProperty(DBPROP_IRowsetLocate, true);
					CoUninitialize();
					return OpenRowset(&propset);
				}
			}
		}
		CoUninitialize();
		return OpenRowset();
	}

	HRESULT OpenRowset(DBPROPSET *pPropSet = NULL)
	{
		HRESULT hr = Open(m_session, NULL, pPropSet);
#ifdef _DEBUG
		if(FAILED(hr))
			AtlTraceErrorRecords(hr);
#endif
		return hr;
	}

	void CloseAll()
	{
		Close();
		ReleaseCommand();
		CloseDataSource();
	}
};


