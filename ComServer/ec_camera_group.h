// ec_camera_group.h : Declaration of the Cec_camera_group

#pragma once

// code generated on 2014年6月10日, 下午 04:56

class Cec_camera_groupAccessor : public CEtroAccessor
{
public:
	CBookmark<4>   bookmark;
	SHORT m_cameragroupid;
	TCHAR m_user_name[11];
	TCHAR m_camera_group_code[11];
	TCHAR m_camera_group_desc[201];
	TCHAR m_module_code[11];
	TCHAR m_category_code[11];
	TCHAR m_matrix_code[11];
	TCHAR m_map_file[101];
	TCHAR m_acmap_file[101];
	TCHAR m_map_align[2];
	TCHAR m_map_size[2];
	TCHAR m_map_videoon[21];
	TCHAR m_sequence_view[2];
	TCHAR m_sequence_all_channel[2];
	SHORT m_sequence_all_interval;
	TCHAR m_default_[2];
	TCHAR m_first_cell_event[2];
	SHORT m_sort_order;

	// The following wizard-generated data members contain status
	// values for the corresponding fields in the column map. You
	// can use these values to hold NULL values that the database
	// returns or to hold error information when the compiler returns
	// errors. See Field Status Data Members in Wizard-Generated
	// Accessors in the Visual C++ documentation for more information
	// on using these fields.
	// NOTE: You must initialize these fields before setting/inserting data!

	DBSTATUS m_dwcameragroupidStatus;
	DBSTATUS m_dwuser_nameStatus;
	DBSTATUS m_dwcamera_group_codeStatus;
	DBSTATUS m_dwcamera_group_descStatus;
	DBSTATUS m_dwmodule_codeStatus;
	DBSTATUS m_dwcategory_codeStatus;
	DBSTATUS m_dwmatrix_codeStatus;
	DBSTATUS m_dwmap_fileStatus;
	DBSTATUS m_dwacmap_fileStatus;
	DBSTATUS m_dwmap_alignStatus;
	DBSTATUS m_dwmap_sizeStatus;
	DBSTATUS m_dwmap_videoonStatus;
	DBSTATUS m_dwsequence_viewStatus;
	DBSTATUS m_dwsequence_all_channelStatus;
	DBSTATUS m_dwsequence_all_intervalStatus;
	DBSTATUS m_dwdefault_Status;
	DBSTATUS m_dwfirst_cell_eventStatus;
	DBSTATUS m_dwsort_orderStatus;

	// The following wizard-generated data members contain length
	// values for the corresponding fields in the column map.
	// NOTE: For variable-length columns, you must initialize these
	//       fields before setting/inserting data!

	DBLENGTH m_dwcameragroupidLength;
	DBLENGTH m_dwuser_nameLength;
	DBLENGTH m_dwcamera_group_codeLength;
	DBLENGTH m_dwcamera_group_descLength;
	DBLENGTH m_dwmodule_codeLength;
	DBLENGTH m_dwcategory_codeLength;
	DBLENGTH m_dwmatrix_codeLength;
	DBLENGTH m_dwmap_fileLength;
	DBLENGTH m_dwacmap_fileLength;
	DBLENGTH m_dwmap_alignLength;
	DBLENGTH m_dwmap_sizeLength;
	DBLENGTH m_dwmap_videoonLength;
	DBLENGTH m_dwsequence_viewLength;
	DBLENGTH m_dwsequence_all_channelLength;
	DBLENGTH m_dwsequence_all_intervalLength;
	DBLENGTH m_dwdefault_Length;
	DBLENGTH m_dwfirst_cell_eventLength;
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
		hr = _db.OpenFromInitializationString(L"Provider=MSDASQL.1;Persist Security Info=False;Extended Properties=\"DSN=EtroCenter;UID=;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae 2008;WSID=LYNN-PC;DATABASE=Etrocenter;Network=DBNMPNTW\"");
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

	DEFINE_COMMAND_EX(Cec_camera_groupAccessor, L" \
	SELECT \
		cameragroupid, \
		user_name, \
		camera_group_code, \
		camera_group_desc, \
		module_code, \
		category_code, \
		matrix_code, \
		map_file, \
		acmap_file, \
		map_align, \
		map_size, \
		map_videoon, \
		sequence_view, \
		sequence_all_channel, \
		sequence_all_interval, \
		default_, \
		first_cell_event, \
		sort_order \
		FROM dbo.ec_camera_group")


	// In order to fix several issues with some providers, the code below may bind
	// columns in a different order than reported by the provider

	BEGIN_COLUMN_MAP(Cec_camera_groupAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_cameragroupid, m_dwcameragroupidLength, m_dwcameragroupidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_user_name, m_dwuser_nameLength, m_dwuser_nameStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_camera_group_code, m_dwcamera_group_codeLength, m_dwcamera_group_codeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_camera_group_desc, m_dwcamera_group_descLength, m_dwcamera_group_descStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_module_code, m_dwmodule_codeLength, m_dwmodule_codeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_category_code, m_dwcategory_codeLength, m_dwcategory_codeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(7, m_matrix_code, m_dwmatrix_codeLength, m_dwmatrix_codeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(8, m_map_file, m_dwmap_fileLength, m_dwmap_fileStatus)
		COLUMN_ENTRY_LENGTH_STATUS(9, m_acmap_file, m_dwacmap_fileLength, m_dwacmap_fileStatus)
		COLUMN_ENTRY_LENGTH_STATUS(10, m_map_align, m_dwmap_alignLength, m_dwmap_alignStatus)
		COLUMN_ENTRY_LENGTH_STATUS(11, m_map_size, m_dwmap_sizeLength, m_dwmap_sizeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(12, m_map_videoon, m_dwmap_videoonLength, m_dwmap_videoonStatus)
		COLUMN_ENTRY_LENGTH_STATUS(13, m_sequence_view, m_dwsequence_viewLength, m_dwsequence_viewStatus)
		COLUMN_ENTRY_LENGTH_STATUS(14, m_sequence_all_channel, m_dwsequence_all_channelLength, m_dwsequence_all_channelStatus)
		COLUMN_ENTRY_LENGTH_STATUS(15, m_sequence_all_interval, m_dwsequence_all_intervalLength, m_dwsequence_all_intervalStatus)
		COLUMN_ENTRY_LENGTH_STATUS(16, m_default_, m_dwdefault_Length, m_dwdefault_Status)
		COLUMN_ENTRY_LENGTH_STATUS(17, m_first_cell_event, m_dwfirst_cell_eventLength, m_dwfirst_cell_eventStatus)
		COLUMN_ENTRY_LENGTH_STATUS(18, m_sort_order, m_dwsort_orderLength, m_dwsort_orderStatus)
	END_COLUMN_MAP()
};

class Cec_camera_group : public CCommand<CAccessor<Cec_camera_groupAccessor> >
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


