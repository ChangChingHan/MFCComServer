#define EC_INI					_T("\\ec.ini")

class CEtroAccessor
{
protected:
	CString m_strDatabaseAuth;

	void IniDatabaseAuth()
	{
		if (m_strDatabaseAuth.IsEmpty())
		{
			USES_CONVERSION;
			wchar_t buffer[125];
			GetModuleFileName(NULL,buffer,125);
			int pos = wstring( buffer ).find_last_of( _T("\\/") );
			wstring str = wstring( buffer ).substr( 0, pos);
			str.append(EC_INI);
			
			CString strDSN, strDBName;
			GetPrivateProfileString(_T("database"), _T("DSN"),_T(""),(LPWSTR)(LPCTSTR)strDSN.GetBuffer(255),255,str.c_str());
			GetPrivateProfileString(_T("database"), _T("DBNAME"),_T(""),(LPWSTR)(LPCTSTR)strDBName.GetBuffer(255),255,str.c_str());

			m_strDatabaseAuth.Format(
				_T("Provider=MSDASQL.1;Persist Security Info=False;Extended Properties=\"DSN=%s;UID=;Trusted_Connection=Yes;DATABASE=%s;Network=DBMSLPCN\""),
				strDSN, strDBName);

			strDSN.ReleaseBuffer();
			strDBName.ReleaseBuffer();
		}
	}

public:
	virtual HRESULT OpenTbl(const CString& strSQL ) = 0;
	virtual HRESULT OpenDataSource() = 0;
	virtual HRESULT ModifyDatabase(const CString& strSQL ) = 0;
	virtual HRESULT Query(const CString& strSQL )
	{
		HRESULT hr;
		::CoInitialize(NULL);
		hr = OpenDataSource();
		if (FAILED(hr))
			return hr;

		hr = OpenTbl( strSQL );
		CoUninitialize();
		return hr;
	};

};