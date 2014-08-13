// ec_camera.h : Declaration of the Cec_camera

#pragma once
// code generated on 2014年6月10日, 下午 02:11

class Cec_cameraAccessor : public CEtroAccessor
{
public:
	LONG m_cameraid;
	LONG m_camera_idx;
	TCHAR m_cameraname[201];
	TCHAR m_connect_type_code[11];
	TCHAR m_ipaddress[31];
	SHORT m_httpport;
	TCHAR m_gateway[31];
	TCHAR m_name_server[31];
	TCHAR m_mac_address[13];
	TCHAR m_mac_idx[31];
	SHORT m_userid;
	TCHAR m_username[21];
	TCHAR m_password[31];
	TCHAR m_brand_code[51];
	TCHAR m_model_code[51];
	TCHAR m_channelid[11];
	TCHAR m_ptz_support[2];
	TCHAR m_ptz_protocol[21];
	TCHAR m_digital_in1[2];
	TCHAR m_digital_in2[2];
	TCHAR m_digital_out[2];
	TCHAR m_videoid[11];
	TCHAR m_video_format[11];
	TCHAR m_video_res[21];
	TCHAR m_video_sizew[11];
	TCHAR m_video_sizeh[11];
	TCHAR m_rtspport[11];
	TCHAR m_speaker_support[2];
	TCHAR m_mic_support[2];
	BYTE m_subnet_mask1;
	BYTE m_subnet_mask2;
	BYTE m_subnet_mask3;
	BYTE m_subnet_mask4;
	TCHAR m_H264[2];
	TCHAR m_MPEG4[2];
	SHORT m_ftpid;
	SHORT m_emailid;
	SHORT m_total_stream;
	TCHAR m_active_[2];
	SHORT m_sort_order;
	TCHAR m_pppoe_id[21];
	TCHAR m_pppoe_password[21];
	LONG m_pppoe_mtu;
	TCHAR m_pppoe_dns_type[2];
	TCHAR m_stream_url[65];

	DBSTATUS m_dwcameraidStatus;
	DBSTATUS m_dwcamera_idxStatus;
	DBSTATUS m_dwcameranameStatus;
	DBSTATUS m_dwconnect_type_codeStatus;
	DBSTATUS m_dwipaddressStatus;
	DBSTATUS m_dwhttpportStatus;
	DBSTATUS m_dwgatewayStatus;
	DBSTATUS m_dwname_serverStatus;
	DBSTATUS m_dwmac_addressStatus;
	DBSTATUS m_dwmac_idxStatus;
	DBSTATUS m_dwuseridStatus;
	DBSTATUS m_dwusernameStatus;
	DBSTATUS m_dwpasswordStatus;
	DBSTATUS m_dwbrand_codeStatus;
	DBSTATUS m_dwmodel_codeStatus;
	DBSTATUS m_dwchannelidStatus;
	DBSTATUS m_dwptz_supportStatus;
	DBSTATUS m_dwptz_protocolStatus;
	DBSTATUS m_dwdigital_in1Status;
	DBSTATUS m_dwdigital_in2Status;
	DBSTATUS m_dwdigital_outStatus;
	DBSTATUS m_dwvideoidStatus;
	DBSTATUS m_dwvideo_formatStatus;
	DBSTATUS m_dwvideo_resStatus;
	DBSTATUS m_dwvideo_sizewStatus;
	DBSTATUS m_dwvideo_sizehStatus;
	DBSTATUS m_dwrtspportStatus;
	DBSTATUS m_dwspeaker_supportStatus;
	DBSTATUS m_dwmic_supportStatus;
	DBSTATUS m_dwsubnet_mask1Status;
	DBSTATUS m_dwsubnet_mask2Status;
	DBSTATUS m_dwsubnet_mask3Status;
	DBSTATUS m_dwsubnet_mask4Status;
	DBSTATUS m_dwH264Status;
	DBSTATUS m_dwMPEG4Status;
	DBSTATUS m_dwftpidStatus;
	DBSTATUS m_dwemailidStatus;
	DBSTATUS m_dwtotal_streamStatus;
	DBSTATUS m_dwactive_Status;
	DBSTATUS m_dwsort_orderStatus;
	DBSTATUS m_dwpppoe_idStatus;
	DBSTATUS m_dwpppoe_passwordStatus;
	DBSTATUS m_dwpppoe_mtuStatus;
	DBSTATUS m_dwpppoe_dns_typeStatus;
	DBSTATUS m_dwstream_urlStatus;

	DBLENGTH m_dwcameraidLength;
	DBLENGTH m_dwcamera_idxLength;
	DBLENGTH m_dwcameranameLength;
	DBLENGTH m_dwconnect_type_codeLength;
	DBLENGTH m_dwipaddressLength;
	DBLENGTH m_dwhttpportLength;
	DBLENGTH m_dwgatewayLength;
	DBLENGTH m_dwname_serverLength;
	DBLENGTH m_dwmac_addressLength;
	DBLENGTH m_dwmac_idxLength;
	DBLENGTH m_dwuseridLength;
	DBLENGTH m_dwusernameLength;
	DBLENGTH m_dwpasswordLength;
	DBLENGTH m_dwbrand_codeLength;
	DBLENGTH m_dwmodel_codeLength;
	DBLENGTH m_dwchannelidLength;
	DBLENGTH m_dwptz_supportLength;
	DBLENGTH m_dwptz_protocolLength;
	DBLENGTH m_dwdigital_in1Length;
	DBLENGTH m_dwdigital_in2Length;
	DBLENGTH m_dwdigital_outLength;
	DBLENGTH m_dwvideoidLength;
	DBLENGTH m_dwvideo_formatLength;
	DBLENGTH m_dwvideo_resLength;
	DBLENGTH m_dwvideo_sizewLength;
	DBLENGTH m_dwvideo_sizehLength;
	DBLENGTH m_dwrtspportLength;
	DBLENGTH m_dwspeaker_supportLength;
	DBLENGTH m_dwmic_supportLength;
	DBLENGTH m_dwsubnet_mask1Length;
	DBLENGTH m_dwsubnet_mask2Length;
	DBLENGTH m_dwsubnet_mask3Length;
	DBLENGTH m_dwsubnet_mask4Length;
	DBLENGTH m_dwH264Length;
	DBLENGTH m_dwMPEG4Length;
	DBLENGTH m_dwftpidLength;
	DBLENGTH m_dwemailidLength;
	DBLENGTH m_dwtotal_streamLength;
	DBLENGTH m_dwactive_Length;
	DBLENGTH m_dwsort_orderLength;
	DBLENGTH m_dwpppoe_idLength;
	DBLENGTH m_dwpppoe_passwordLength;
	DBLENGTH m_dwpppoe_mtuLength;
	DBLENGTH m_dwpppoe_dns_typeLength;
	DBLENGTH m_dwstream_urlLength;

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
		//hr = _db.OpenFromInitializationString(L"Provider=MSDASQL.1;Persist Security Info=False;Extended Properties=\"DSN=EtroCenter;UID=;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae 2008;WSID=LYNN-PC;DATABASE=Etrocenter;Network=DBNMPNTW\"");

		hr = _db.OpenFromInitializationString(L"Provider=MSDASQL.1;Persist Security Info=False;Extended Properties=\"DSN=EtroCenter;UID=;Trusted_Connection=Yes;DATABASE=Etrocenter;Network=DBNMPNTW\"");
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

	DEFINE_COMMAND_EX(Cec_cameraAccessor, L" \
	SELECT \
		cameraid, \
		camera_idx, \
		cameraname, \
		connect_type_code, \
		ipaddress, \
		httpport, \
		gateway, \
		name_server, \
		mac_address, \
		mac_idx, \
		userid, \
		username, \
		password, \
		brand_code, \
		model_code, \
		channelid, \
		ptz_support, \
		ptz_protocol, \
		digital_in1, \
		digital_in2, \
		digital_out, \
		videoid, \
		video_format, \
		video_res, \
		video_sizew, \
		video_sizeh, \
		rtspport, \
		speaker_support, \
		mic_support, \
		subnet_mask1, \
		subnet_mask2, \
		subnet_mask3, \
		subnet_mask4, \
		H264, \
		MPEG4, \
		ftpid, \
		emailid, \
		total_stream, \
		active_, \
		sort_order, \
		pppoe_id, \
		pppoe_password, \
		pppoe_mtu, \
		pppoe_dns_type, \
		stream_url \
		FROM dbo.ec_camera")


	// In order to fix several issues with some providers, the code below may bind
	// columns in a different order than reported by the provider

	BEGIN_COLUMN_MAP(Cec_cameraAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_cameraid, m_dwcameraidLength, m_dwcameraidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_camera_idx, m_dwcamera_idxLength, m_dwcamera_idxStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_cameraname, m_dwcameranameLength, m_dwcameranameStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_connect_type_code, m_dwconnect_type_codeLength, m_dwconnect_type_codeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_ipaddress, m_dwipaddressLength, m_dwipaddressStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_httpport, m_dwhttpportLength, m_dwhttpportStatus)
		COLUMN_ENTRY_LENGTH_STATUS(7, m_gateway, m_dwgatewayLength, m_dwgatewayStatus)
		COLUMN_ENTRY_LENGTH_STATUS(8, m_name_server, m_dwname_serverLength, m_dwname_serverStatus)
		COLUMN_ENTRY_LENGTH_STATUS(9, m_mac_address, m_dwmac_addressLength, m_dwmac_addressStatus)
		COLUMN_ENTRY_LENGTH_STATUS(10, m_mac_idx, m_dwmac_idxLength, m_dwmac_idxStatus)
		COLUMN_ENTRY_LENGTH_STATUS(11, m_userid, m_dwuseridLength, m_dwuseridStatus)
		COLUMN_ENTRY_LENGTH_STATUS(12, m_username, m_dwusernameLength, m_dwusernameStatus)
		COLUMN_ENTRY_LENGTH_STATUS(13, m_password, m_dwpasswordLength, m_dwpasswordStatus)
		COLUMN_ENTRY_LENGTH_STATUS(14, m_brand_code, m_dwbrand_codeLength, m_dwbrand_codeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(15, m_model_code, m_dwmodel_codeLength, m_dwmodel_codeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(16, m_channelid, m_dwchannelidLength, m_dwchannelidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(17, m_ptz_support, m_dwptz_supportLength, m_dwptz_supportStatus)
		COLUMN_ENTRY_LENGTH_STATUS(18, m_ptz_protocol, m_dwptz_protocolLength, m_dwptz_protocolStatus)
		COLUMN_ENTRY_LENGTH_STATUS(19, m_digital_in1, m_dwdigital_in1Length, m_dwdigital_in1Status)
		COLUMN_ENTRY_LENGTH_STATUS(20, m_digital_in2, m_dwdigital_in2Length, m_dwdigital_in2Status)
		COLUMN_ENTRY_LENGTH_STATUS(21, m_digital_out, m_dwdigital_outLength, m_dwdigital_outStatus)
		COLUMN_ENTRY_LENGTH_STATUS(22, m_videoid, m_dwvideoidLength, m_dwvideoidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(23, m_video_format, m_dwvideo_formatLength, m_dwvideo_formatStatus)
		COLUMN_ENTRY_LENGTH_STATUS(24, m_video_res, m_dwvideo_resLength, m_dwvideo_resStatus)
		COLUMN_ENTRY_LENGTH_STATUS(25, m_video_sizew, m_dwvideo_sizewLength, m_dwvideo_sizewStatus)
		COLUMN_ENTRY_LENGTH_STATUS(26, m_video_sizeh, m_dwvideo_sizehLength, m_dwvideo_sizehStatus)
		COLUMN_ENTRY_LENGTH_STATUS(27, m_rtspport, m_dwrtspportLength, m_dwrtspportStatus)
		COLUMN_ENTRY_LENGTH_STATUS(28, m_speaker_support, m_dwspeaker_supportLength, m_dwspeaker_supportStatus)
		COLUMN_ENTRY_LENGTH_STATUS(29, m_mic_support, m_dwmic_supportLength, m_dwmic_supportStatus)
		COLUMN_ENTRY_LENGTH_STATUS(30, m_subnet_mask1, m_dwsubnet_mask1Length, m_dwsubnet_mask1Status)
		COLUMN_ENTRY_LENGTH_STATUS(31, m_subnet_mask2, m_dwsubnet_mask2Length, m_dwsubnet_mask2Status)
		COLUMN_ENTRY_LENGTH_STATUS(32, m_subnet_mask3, m_dwsubnet_mask3Length, m_dwsubnet_mask3Status)
		COLUMN_ENTRY_LENGTH_STATUS(33, m_subnet_mask4, m_dwsubnet_mask4Length, m_dwsubnet_mask4Status)
		COLUMN_ENTRY_LENGTH_STATUS(34, m_H264, m_dwH264Length, m_dwH264Status)
		COLUMN_ENTRY_LENGTH_STATUS(35, m_MPEG4, m_dwMPEG4Length, m_dwMPEG4Status)
		COLUMN_ENTRY_LENGTH_STATUS(36, m_ftpid, m_dwftpidLength, m_dwftpidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(37, m_emailid, m_dwemailidLength, m_dwemailidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(38, m_total_stream, m_dwtotal_streamLength, m_dwtotal_streamStatus)
		COLUMN_ENTRY_LENGTH_STATUS(39, m_active_, m_dwactive_Length, m_dwactive_Status)
		COLUMN_ENTRY_LENGTH_STATUS(40, m_sort_order, m_dwsort_orderLength, m_dwsort_orderStatus)
		COLUMN_ENTRY_LENGTH_STATUS(41, m_pppoe_id, m_dwpppoe_idLength, m_dwpppoe_idStatus)
		COLUMN_ENTRY_LENGTH_STATUS(42, m_pppoe_password, m_dwpppoe_passwordLength, m_dwpppoe_passwordStatus)
		COLUMN_ENTRY_LENGTH_STATUS(43, m_pppoe_mtu, m_dwpppoe_mtuLength, m_dwpppoe_mtuStatus)
		COLUMN_ENTRY_LENGTH_STATUS(44, m_pppoe_dns_type, m_dwpppoe_dns_typeLength, m_dwpppoe_dns_typeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(45, m_stream_url, m_dwstream_urlLength, m_dwstream_urlStatus)
	END_COLUMN_MAP()
};

class Cec_camera : public CCommand<CAccessor<Cec_cameraAccessor> >
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


