// ecparms.h : Declaration of the Cecparms

#pragma once

// code generated on 2014年6月11日, 下午 04:50

class CecparmsAccessor : public CEtroAccessor
{
public:
	LONG m_parmid;
	SHORT m_userid;
	TCHAR m_user_name[11];
	TCHAR m_parm_type[11];
	TCHAR m_parm_name[51];
	TCHAR m_parm_value[257];

	// The following wizard-generated data members contain status
	// values for the corresponding fields in the column map. You
	// can use these values to hold NULL values that the database
	// returns or to hold error information when the compiler returns
	// errors. See Field Status Data Members in Wizard-Generated
	// Accessors in the Visual C++ documentation for more information
	// on using these fields.
	// NOTE: You must initialize these fields before setting/inserting data!

	DBSTATUS m_dwparmidStatus;
	DBSTATUS m_dwuseridStatus;
	DBSTATUS m_dwuser_nameStatus;
	DBSTATUS m_dwparm_typeStatus;
	DBSTATUS m_dwparm_nameStatus;
	DBSTATUS m_dwparm_valueStatus;

	// The following wizard-generated data members contain length
	// values for the corresponding fields in the column map.
	// NOTE: For variable-length columns, you must initialize these
	//       fields before setting/inserting data!

	DBLENGTH m_dwparmidLength;
	DBLENGTH m_dwuseridLength;
	DBLENGTH m_dwuser_nameLength;
	DBLENGTH m_dwparm_typeLength;
	DBLENGTH m_dwparm_nameLength;
	DBLENGTH m_dwparm_valueLength;


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

	DEFINE_COMMAND_EX(CecparmsAccessor, L" \
	SELECT \
		parmid, \
		userid, \
		user_name, \
		parm_type, \
		parm_name, \
		parm_value \
		FROM dbo.ecparms")


	// In order to fix several issues with some providers, the code below may bind
	// columns in a different order than reported by the provider

	BEGIN_COLUMN_MAP(CecparmsAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_parmid, m_dwparmidLength, m_dwparmidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_userid, m_dwuseridLength, m_dwuseridStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_user_name, m_dwuser_nameLength, m_dwuser_nameStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_parm_type, m_dwparm_typeLength, m_dwparm_typeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_parm_name, m_dwparm_nameLength, m_dwparm_nameStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_parm_value, m_dwparm_valueLength, m_dwparm_valueStatus)
	END_COLUMN_MAP()
};

class Cecparms : public CCommand<CAccessor<CecparmsAccessor> >
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


