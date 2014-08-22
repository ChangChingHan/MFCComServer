// ec_event_log.h : Declaration of the Cec_event_log

#pragma once

// code generated on 2014年8月18日, 下午 05:14

class Cec_event_logAccessor : public CEtroAccessor
{
public:
	LONG m_event_key;
	LONG m_eventid;
	TCHAR m_event_source_code[11];
	TCHAR m_event_type_code[11];
	SHORT m_alert_level;
	TCHAR m_device_id[11];
	TCHAR m_device_action_code[11];
	DBTIMESTAMP m_occur_time;
	LONG m_camera_idx;
	TCHAR m_mac_address[13];
	DBTIMESTAMP m_end_time;

	// The following wizard-generated data members contain status
	// values for the corresponding fields in the column map. You
	// can use these values to hold NULL values that the database
	// returns or to hold error information when the compiler returns
	// errors. See Field Status Data Members in Wizard-Generated
	// Accessors in the Visual C++ documentation for more information
	// on using these fields.
	// NOTE: You must initialize these fields before setting/inserting data!

	DBSTATUS m_dwevent_keyStatus;
	DBSTATUS m_dweventidStatus;
	DBSTATUS m_dwevent_source_codeStatus;
	DBSTATUS m_dwevent_type_codeStatus;
	DBSTATUS m_dwalert_levelStatus;
	DBSTATUS m_dwdevice_idStatus;
	DBSTATUS m_dwdevice_action_codeStatus;
	DBSTATUS m_dwoccur_timeStatus;
	DBSTATUS m_dwcamera_idxStatus;
	DBSTATUS m_dwmac_addressStatus;
	DBSTATUS m_dwend_timeStatus;

	// The following wizard-generated data members contain length
	// values for the corresponding fields in the column map.
	// NOTE: For variable-length columns, you must initialize these
	//       fields before setting/inserting data!

	DBLENGTH m_dwevent_keyLength;
	DBLENGTH m_dweventidLength;
	DBLENGTH m_dwevent_source_codeLength;
	DBLENGTH m_dwevent_type_codeLength;
	DBLENGTH m_dwalert_levelLength;
	DBLENGTH m_dwdevice_idLength;
	DBLENGTH m_dwdevice_action_codeLength;
	DBLENGTH m_dwoccur_timeLength;
	DBLENGTH m_dwcamera_idxLength;
	DBLENGTH m_dwmac_addressLength;
	DBLENGTH m_dwend_timeLength;


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
		hr = _db.OpenFromInitializationString(L"Provider=MSDASQL.1;Persist Security Info=False;Data Source=EtroCenter;Extended Properties=\"DSN=EtroCenter;UID=;Trusted_Connection=0;APP=Microsoft\x00ae Visual Studio\x00ae 2008;WSID=LYNN-PC;DATABASE=Etrocenter;Network=DBNMPNTW\"");
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

	DEFINE_COMMAND_EX(Cec_event_logAccessor, L" \
	SELECT \
		event_key, \
		eventid, \
		event_source_code, \
		event_type_code, \
		alert_level, \
		device_id, \
		device_action_code, \
		occur_time, \
		camera_idx, \
		mac_address, \
		end_time \
		FROM dbo.ec_event_log")


	// In order to fix several issues with some providers, the code below may bind
	// columns in a different order than reported by the provider

	BEGIN_COLUMN_MAP(Cec_event_logAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_event_key, m_dwevent_keyLength, m_dwevent_keyStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_eventid, m_dweventidLength, m_dweventidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_event_source_code, m_dwevent_source_codeLength, m_dwevent_source_codeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_event_type_code, m_dwevent_type_codeLength, m_dwevent_type_codeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_alert_level, m_dwalert_levelLength, m_dwalert_levelStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_device_id, m_dwdevice_idLength, m_dwdevice_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(7, m_device_action_code, m_dwdevice_action_codeLength, m_dwdevice_action_codeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(8, m_occur_time, m_dwoccur_timeLength, m_dwoccur_timeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(9, m_camera_idx, m_dwcamera_idxLength, m_dwcamera_idxStatus)
		COLUMN_ENTRY_LENGTH_STATUS(10, m_mac_address, m_dwmac_addressLength, m_dwmac_addressStatus)
		COLUMN_ENTRY_LENGTH_STATUS(11, m_end_time, m_dwend_timeLength, m_dwend_timeStatus)
	END_COLUMN_MAP()
};

class Cec_event_log : public CCommand<CAccessor<Cec_event_logAccessor> >
{
public:
	virtual HRESULT ModifyDatabase( const CString& strSQL )
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

		hr = Open( m_session, strSQL);
		if (FAILED(hr))
			return hr;
		return hr;
	}
	HRESULT OpenAll()
	{
		HRESULT hr;
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
					return OpenRowset(&propset);
				}
			}
		}
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


