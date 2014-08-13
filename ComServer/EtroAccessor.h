class CEtroAccessor
{
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