// ec_camera_group_camera.h : Declaration of the Cec_camera_group_camera

#pragma once

// code generated on 2014年6月11日, 上午 11:35

class Cec_camera_group_cameraAccessor : public CEtroAccessor
{
public:
	LONG m_cameragroupcameraid;
	SHORT m_cameragroupid;
	LONG m_cameraid;
	LONG m_camera_idx;
	LONG m_streamid;
	LONG m_numb_;
	TCHAR m_sequence_view[2];
	SHORT m_sequence_interval;
	LONG m_emap_x;
	LONG m_emap_y;
	LONG m_acmap_x;
	LONG m_acmap_y;
	LONG m_gtmap_x;
	LONG m_gtmap_y;
	LONG m_sort_order;

	// The following wizard-generated data members contain status
	// values for the corresponding fields in the column map. You
	// can use these values to hold NULL values that the database
	// returns or to hold error information when the compiler returns
	// errors. See Field Status Data Members in Wizard-Generated
	// Accessors in the Visual C++ documentation for more information
	// on using these fields.
	// NOTE: You must initialize these fields before setting/inserting data!

	DBSTATUS m_dwcameragroupcameraidStatus;
	DBSTATUS m_dwcameragroupidStatus;
	DBSTATUS m_dwcameraidStatus;
	DBSTATUS m_dwcamera_idxStatus;
	DBSTATUS m_dwstreamidStatus;
	DBSTATUS m_dwnumb_Status;
	DBSTATUS m_dwsequence_viewStatus;
	DBSTATUS m_dwsequence_intervalStatus;
	DBSTATUS m_dwemap_xStatus;
	DBSTATUS m_dwemap_yStatus;
	DBSTATUS m_dwacmap_xStatus;
	DBSTATUS m_dwacmap_yStatus;
	DBSTATUS m_dwgtmap_xStatus;
	DBSTATUS m_dwgtmap_yStatus;
	DBSTATUS m_dwsort_orderStatus;

	// The following wizard-generated data members contain length
	// values for the corresponding fields in the column map.
	// NOTE: For variable-length columns, you must initialize these
	//       fields before setting/inserting data!

	DBLENGTH m_dwcameragroupcameraidLength;
	DBLENGTH m_dwcameragroupidLength;
	DBLENGTH m_dwcameraidLength;
	DBLENGTH m_dwcamera_idxLength;
	DBLENGTH m_dwstreamidLength;
	DBLENGTH m_dwnumb_Length;
	DBLENGTH m_dwsequence_viewLength;
	DBLENGTH m_dwsequence_intervalLength;
	DBLENGTH m_dwemap_xLength;
	DBLENGTH m_dwemap_yLength;
	DBLENGTH m_dwacmap_xLength;
	DBLENGTH m_dwacmap_yLength;
	DBLENGTH m_dwgtmap_xLength;
	DBLENGTH m_dwgtmap_yLength;
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

	DEFINE_COMMAND_EX(Cec_camera_group_cameraAccessor, L" \
	SELECT \
		cameragroupcameraid, \
		cameragroupid, \
		cameraid, \
		camera_idx, \
		streamid, \
		numb_, \
		sequence_view, \
		sequence_interval, \
		emap_x, \
		emap_y, \
		acmap_x, \
		acmap_y, \
		gtmap_x, \
		gtmap_y, \
		sort_order \
		FROM dbo.ec_camera_group_camera")


	// In order to fix several issues with some providers, the code below may bind
	// columns in a different order than reported by the provider

	BEGIN_COLUMN_MAP(Cec_camera_group_cameraAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_cameragroupcameraid, m_dwcameragroupcameraidLength, m_dwcameragroupcameraidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_cameragroupid, m_dwcameragroupidLength, m_dwcameragroupidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_cameraid, m_dwcameraidLength, m_dwcameraidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_camera_idx, m_dwcamera_idxLength, m_dwcamera_idxStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_streamid, m_dwstreamidLength, m_dwstreamidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_numb_, m_dwnumb_Length, m_dwnumb_Status)
		COLUMN_ENTRY_LENGTH_STATUS(7, m_sequence_view, m_dwsequence_viewLength, m_dwsequence_viewStatus)
		COLUMN_ENTRY_LENGTH_STATUS(8, m_sequence_interval, m_dwsequence_intervalLength, m_dwsequence_intervalStatus)
		COLUMN_ENTRY_LENGTH_STATUS(9, m_emap_x, m_dwemap_xLength, m_dwemap_xStatus)
		COLUMN_ENTRY_LENGTH_STATUS(10, m_emap_y, m_dwemap_yLength, m_dwemap_yStatus)
		COLUMN_ENTRY_LENGTH_STATUS(11, m_acmap_x, m_dwacmap_xLength, m_dwacmap_xStatus)
		COLUMN_ENTRY_LENGTH_STATUS(12, m_acmap_y, m_dwacmap_yLength, m_dwacmap_yStatus)
		COLUMN_ENTRY_LENGTH_STATUS(13, m_gtmap_x, m_dwgtmap_xLength, m_dwgtmap_xStatus)
		COLUMN_ENTRY_LENGTH_STATUS(14, m_gtmap_y, m_dwgtmap_yLength, m_dwgtmap_yStatus)
		COLUMN_ENTRY_LENGTH_STATUS(15, m_sort_order, m_dwsort_orderLength, m_dwsort_orderStatus)
	END_COLUMN_MAP()
};

class Cec_camera_group_camera : public CCommand<CAccessor<Cec_camera_group_cameraAccessor> >
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


