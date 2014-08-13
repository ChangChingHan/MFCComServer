// ec_camera_recording.h : Declaration of the Cec_camera_recording

#pragma once

// code generated on 2014年6月11日, 下午 01:58

class Cec_camera_recordingAccessor : public CEtroAccessor
{
public:
	LONG m_camera_recordingid;
	LONG m_camera_idx;
	LONG m_streamid;
	LONG m_numb_;
	TCHAR m_recording_type[11];
	BYTE m_recording_time[43];
	TCHAR m_trigger_type[11];
	TCHAR m_record_period_code[11];
	TCHAR m_active_[2];

	// The following wizard-generated data members contain status
	// values for the corresponding fields in the column map. You
	// can use these values to hold NULL values that the database
	// returns or to hold error information when the compiler returns
	// errors. See Field Status Data Members in Wizard-Generated
	// Accessors in the Visual C++ documentation for more information
	// on using these fields.
	// NOTE: You must initialize these fields before setting/inserting data!

	DBSTATUS m_dwcamera_recordingidStatus;
	DBSTATUS m_dwcamera_idxStatus;
	DBSTATUS m_dwstreamidStatus;
	DBSTATUS m_dwnumb_Status;
	DBSTATUS m_dwrecording_typeStatus;
	DBSTATUS m_dwrecording_timeStatus;
	DBSTATUS m_dwtrigger_typeStatus;
	DBSTATUS m_dwrecord_period_codeStatus;
	DBSTATUS m_dwactive_Status;

	// The following wizard-generated data members contain length
	// values for the corresponding fields in the column map.
	// NOTE: For variable-length columns, you must initialize these
	//       fields before setting/inserting data!

	DBLENGTH m_dwcamera_recordingidLength;
	DBLENGTH m_dwcamera_idxLength;
	DBLENGTH m_dwstreamidLength;
	DBLENGTH m_dwnumb_Length;
	DBLENGTH m_dwrecording_typeLength;
	DBLENGTH m_dwrecording_timeLength;
	DBLENGTH m_dwtrigger_typeLength;
	DBLENGTH m_dwrecord_period_codeLength;
	DBLENGTH m_dwactive_Length;


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
		hr = _db.OpenFromInitializationString(L"Provider=MSDASQL.1;Persist Security Info=False;Extended Properties=\"DSN=EtroCenter;UID=;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae 2008;WSID=LYNN-PC;DATABASE=Etrocenter;Network=DBMSLPCN\"");
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

	DEFINE_COMMAND_EX(Cec_camera_recordingAccessor, L" \
	SELECT \
		camera_recordingid, \
		camera_idx, \
		streamid, \
		numb_, \
		recording_type, \
		recording_time, \
		trigger_type, \
		record_period_code, \
		active_ \
		FROM dbo.ec_camera_recording")


	// In order to fix several issues with some providers, the code below may bind
	// columns in a different order than reported by the provider

	BEGIN_COLUMN_MAP(Cec_camera_recordingAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_camera_recordingid, m_dwcamera_recordingidLength, m_dwcamera_recordingidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_camera_idx, m_dwcamera_idxLength, m_dwcamera_idxStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_streamid, m_dwstreamidLength, m_dwstreamidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_numb_, m_dwnumb_Length, m_dwnumb_Status)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_recording_type, m_dwrecording_typeLength, m_dwrecording_typeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_recording_time, m_dwrecording_timeLength, m_dwrecording_timeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(7, m_trigger_type, m_dwtrigger_typeLength, m_dwtrigger_typeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(8, m_record_period_code, m_dwrecord_period_codeLength, m_dwrecord_period_codeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(9, m_active_, m_dwactive_Length, m_dwactive_Status)
	END_COLUMN_MAP()
};

class Cec_camera_recording : public CCommand<CAccessor<Cec_camera_recordingAccessor> >
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


