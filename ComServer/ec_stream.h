// ec_stream.h : Declaration of the Cec_stream

#pragma once

// code generated on 2014年6月11日, 下午 12:07

class Cec_streamAccessor : public CEtroAccessor
{
public:
	LONG m_streamid;
	TCHAR m_stream_name[51];
	TCHAR m_stream_tag[101];
	LONG m_cameraid;
	SHORT m_camera_numb;
	TCHAR m_stream_type[11];
	SHORT m_stream_port;
	TCHAR m_stream_protocol[11];
	TCHAR m_audio_typecode[11];
	TCHAR m_video_cmpr_type[11];
	TCHAR m_video_res[21];
	TCHAR m_liveview_enable[2];
	TCHAR m_record_enable[2];
	SHORT m_sort_order;

	// The following wizard-generated data members contain status
	// values for the corresponding fields in the column map. You
	// can use these values to hold NULL values that the database
	// returns or to hold error information when the compiler returns
	// errors. See Field Status Data Members in Wizard-Generated
	// Accessors in the Visual C++ documentation for more information
	// on using these fields.
	// NOTE: You must initialize these fields before setting/inserting data!

	DBSTATUS m_dwstreamidStatus;
	DBSTATUS m_dwstream_nameStatus;
	DBSTATUS m_dwstream_tagStatus;
	DBSTATUS m_dwcameraidStatus;
	DBSTATUS m_dwcamera_numbStatus;
	DBSTATUS m_dwstream_typeStatus;
	DBSTATUS m_dwstream_portStatus;
	DBSTATUS m_dwstream_protocolStatus;
	DBSTATUS m_dwaudio_typecodeStatus;
	DBSTATUS m_dwvideo_cmpr_typeStatus;
	DBSTATUS m_dwvideo_resStatus;
	DBSTATUS m_dwliveview_enableStatus;
	DBSTATUS m_dwrecord_enableStatus;
	DBSTATUS m_dwsort_orderStatus;

	// The following wizard-generated data members contain length
	// values for the corresponding fields in the column map.
	// NOTE: For variable-length columns, you must initialize these
	//       fields before setting/inserting data!

	DBLENGTH m_dwstreamidLength;
	DBLENGTH m_dwstream_nameLength;
	DBLENGTH m_dwstream_tagLength;
	DBLENGTH m_dwcameraidLength;
	DBLENGTH m_dwcamera_numbLength;
	DBLENGTH m_dwstream_typeLength;
	DBLENGTH m_dwstream_portLength;
	DBLENGTH m_dwstream_protocolLength;
	DBLENGTH m_dwaudio_typecodeLength;
	DBLENGTH m_dwvideo_cmpr_typeLength;
	DBLENGTH m_dwvideo_resLength;
	DBLENGTH m_dwliveview_enableLength;
	DBLENGTH m_dwrecord_enableLength;
	DBLENGTH m_dwsort_orderLength;


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

	DEFINE_COMMAND_EX(Cec_streamAccessor, L" \
	SELECT \
		streamid, \
		stream_name, \
		stream_tag, \
		cameraid, \
		camera_numb, \
		stream_type, \
		stream_port, \
		stream_protocol, \
		audio_typecode, \
		video_cmpr_type, \
		video_res, \
		liveview_enable, \
		record_enable, \
		sort_order \
		FROM dbo.ec_stream")


	// In order to fix several issues with some providers, the code below may bind
	// columns in a different order than reported by the provider

	BEGIN_COLUMN_MAP(Cec_streamAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_streamid, m_dwstreamidLength, m_dwstreamidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_stream_name, m_dwstream_nameLength, m_dwstream_nameStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_stream_tag, m_dwstream_tagLength, m_dwstream_tagStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_cameraid, m_dwcameraidLength, m_dwcameraidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_camera_numb, m_dwcamera_numbLength, m_dwcamera_numbStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_stream_type, m_dwstream_typeLength, m_dwstream_typeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(7, m_stream_port, m_dwstream_portLength, m_dwstream_portStatus)
		COLUMN_ENTRY_LENGTH_STATUS(8, m_stream_protocol, m_dwstream_protocolLength, m_dwstream_protocolStatus)
		COLUMN_ENTRY_LENGTH_STATUS(9, m_audio_typecode, m_dwaudio_typecodeLength, m_dwaudio_typecodeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(10, m_video_cmpr_type, m_dwvideo_cmpr_typeLength, m_dwvideo_cmpr_typeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(11, m_video_res, m_dwvideo_resLength, m_dwvideo_resStatus)
		COLUMN_ENTRY_LENGTH_STATUS(12, m_liveview_enable, m_dwliveview_enableLength, m_dwliveview_enableStatus)
		COLUMN_ENTRY_LENGTH_STATUS(13, m_record_enable, m_dwrecord_enableLength, m_dwrecord_enableStatus)
		COLUMN_ENTRY_LENGTH_STATUS(14, m_sort_order, m_dwsort_orderLength, m_dwsort_orderStatus)
	END_COLUMN_MAP()
};

class Cec_stream : public CCommand<CAccessor<Cec_streamAccessor> >
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


