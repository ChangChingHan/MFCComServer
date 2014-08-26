// ec_event_action.h : Declaration of the Cec_event_action

#pragma once

// code generated on 2014年8月18日, 下午 05:17

class Cec_event_actionAccessor : public CEtroAccessor
{
public:
	LONG m_actionid;
	TCHAR m_camera_ip[21];
	SHORT m_event_type;
	SHORT m_action_type;
	SHORT m_after_action_type;
	SHORT m_smtp_secure;
	TCHAR m_smtp_server[51];
	TCHAR m_smtp_account[51];
	TCHAR m_smtp_password[51];
	TCHAR m_mail_target[51];
	SHORT m_rec_duration_time;
	TCHAR m_cam_user[51];
	TCHAR m_cam_pwd[101];
	LONG m_cam_port;
	SHORT m_DO_out1;
	TCHAR m_snap_path[51];
	SHORT m_ptz_p;
	SHORT m_ptz_t;
	SHORT m_ptz_z;

	// The following wizard-generated data members contain status
	// values for the corresponding fields in the column map. You
	// can use these values to hold NULL values that the database
	// returns or to hold error information when the compiler returns
	// errors. See Field Status Data Members in Wizard-Generated
	// Accessors in the Visual C++ documentation for more information
	// on using these fields.
	// NOTE: You must initialize these fields before setting/inserting data!

	DBSTATUS m_dwactionidStatus;
	DBSTATUS m_dwcamera_ipStatus;
	DBSTATUS m_dwevent_typeStatus;
	DBSTATUS m_dwaction_typeStatus;
	DBSTATUS m_dwafter_action_typeStatus;
	DBSTATUS m_dwsmtp_secureStatus;
	DBSTATUS m_dwsmtp_serverStatus;
	DBSTATUS m_dwsmtp_accountStatus;
	DBSTATUS m_dwsmtp_passwordStatus;
	DBSTATUS m_dwmail_targetStatus;
	DBSTATUS m_dwrec_duration_timeStatus;
	DBSTATUS m_dwcam_userStatus;
	DBSTATUS m_dwcam_pwdStatus;
	DBSTATUS m_dwcam_portStatus;
	DBSTATUS m_dwDO_out1Status;
	DBSTATUS m_dwsnap_pathStatus;
	DBSTATUS m_dwptz_pStatus;
	DBSTATUS m_dwptz_tStatus;
	DBSTATUS m_dwptz_zStatus;

	// The following wizard-generated data members contain length
	// values for the corresponding fields in the column map.
	// NOTE: For variable-length columns, you must initialize these
	//       fields before setting/inserting data!

	DBLENGTH m_dwactionidLength;
	DBLENGTH m_dwcamera_ipLength;
	DBLENGTH m_dwevent_typeLength;
	DBLENGTH m_dwaction_typeLength;
	DBLENGTH m_dwafter_action_typeLength;
	DBLENGTH m_dwsmtp_secureLength;
	DBLENGTH m_dwsmtp_serverLength;
	DBLENGTH m_dwsmtp_accountLength;
	DBLENGTH m_dwsmtp_passwordLength;
	DBLENGTH m_dwmail_targetLength;
	DBLENGTH m_dwrec_duration_timeLength;
	DBLENGTH m_dwcam_userLength;
	DBLENGTH m_dwcam_pwdLength;
	DBLENGTH m_dwcam_portLength;
	DBLENGTH m_dwDO_out1Length;
	DBLENGTH m_dwsnap_pathLength;
	DBLENGTH m_dwptz_pLength;
	DBLENGTH m_dwptz_tLength;
	DBLENGTH m_dwptz_zLength;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, VARIANT_TRUE , DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, VARIANT_TRUE , DBPROPOPTIONS_OPTIONAL);
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

	DEFINE_COMMAND_EX(Cec_event_actionAccessor, L" \
	SELECT \
		actionid, \
		camera_ip, \
		event_type, \
		action_type, \
		after_action_type, \
		smtp_secure, \
		smtp_server, \
		smtp_account, \
		smtp_password, \
		mail_target, \
		rec_duration_time, \
		cam_user, \
		cam_pwd, \
		cam_port, \
		DO_out1, \
		snap_path, \
		ptz_p, \
		ptz_t, \
		ptz_z \
		FROM dbo.ec_event_action")


	// In order to fix several issues with some providers, the code below may bind
	// columns in a different order than reported by the provider

	BEGIN_COLUMN_MAP(Cec_event_actionAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_actionid, m_dwactionidLength, m_dwactionidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_camera_ip, m_dwcamera_ipLength, m_dwcamera_ipStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_event_type, m_dwevent_typeLength, m_dwevent_typeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_action_type, m_dwaction_typeLength, m_dwaction_typeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_after_action_type, m_dwafter_action_typeLength, m_dwafter_action_typeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_smtp_secure, m_dwsmtp_secureLength, m_dwsmtp_secureStatus)
		COLUMN_ENTRY_LENGTH_STATUS(7, m_smtp_server, m_dwsmtp_serverLength, m_dwsmtp_serverStatus)
		COLUMN_ENTRY_LENGTH_STATUS(8, m_smtp_account, m_dwsmtp_accountLength, m_dwsmtp_accountStatus)
		COLUMN_ENTRY_LENGTH_STATUS(9, m_smtp_password, m_dwsmtp_passwordLength, m_dwsmtp_passwordStatus)
		COLUMN_ENTRY_LENGTH_STATUS(10, m_mail_target, m_dwmail_targetLength, m_dwmail_targetStatus)
		COLUMN_ENTRY_LENGTH_STATUS(11, m_rec_duration_time, m_dwrec_duration_timeLength, m_dwrec_duration_timeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(12, m_cam_user, m_dwcam_userLength, m_dwcam_userStatus)
		COLUMN_ENTRY_LENGTH_STATUS(13, m_cam_pwd, m_dwcam_pwdLength, m_dwcam_pwdStatus)
		COLUMN_ENTRY_LENGTH_STATUS(14, m_cam_port, m_dwcam_portLength, m_dwcam_portStatus)
		COLUMN_ENTRY_LENGTH_STATUS(15, m_DO_out1, m_dwDO_out1Length, m_dwDO_out1Status)
		COLUMN_ENTRY_LENGTH_STATUS(16, m_snap_path, m_dwsnap_pathLength, m_dwsnap_pathStatus)
		COLUMN_ENTRY_LENGTH_STATUS(17, m_ptz_p, m_dwptz_pLength, m_dwptz_pStatus)
		COLUMN_ENTRY_LENGTH_STATUS(18, m_ptz_t, m_dwptz_tLength, m_dwptz_tStatus)
		COLUMN_ENTRY_LENGTH_STATUS(19, m_ptz_z, m_dwptz_zLength, m_dwptz_zStatus)
	END_COLUMN_MAP()
};

class Cec_event_action : public CCommand<CAccessor<Cec_event_actionAccessor> >
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


