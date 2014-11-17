// stdafx.cpp : source file that includes just the standard includes
// ComServer.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
wstring g_strDSN = _T("");
wstring g_strDBName = _T("");
#define EC_INI					_T("\\ec.ini")


extern bool GetDSNnDBNAME(wstring& strDSN, wstring& strDBName)
{
	if (g_strDSN.length() && g_strDBName.length())
	{
		strDSN = g_strDSN;
		strDBName = g_strDBName;
		return true;
	}
	else
	{
		USES_CONVERSION;
		wchar_t buffer[125];
		GetModuleFileName(NULL,buffer,125);
		int pos = wstring( buffer ).find_last_of( _T("\\/") );
		wstring str = wstring( buffer ).substr( 0, pos);
		str.append(EC_INI);
		
		CString cpDns,csDbName;
		GetPrivateProfileString(_T("database"), _T("DSN"),_T(""),(LPWSTR)(LPCTSTR)cpDns.GetBuffer(255),255,str.c_str());
		GetPrivateProfileString(_T("database"), _T("DBNAME"),_T(""),(LPWSTR)(LPCTSTR)csDbName.GetBuffer(255),255,str.c_str());

		g_strDSN = cpDns;
		g_strDBName = csDbName;
		cpDns.ReleaseBuffer();
		csDbName.ReleaseBuffer();
		return true;
	}
	return false;
}

