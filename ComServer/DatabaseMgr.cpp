#include "StdAfx.h"
#include "DatabaseMgr.h"

CDatabaseMgr::CDatabaseMgr(void)
{
	m_CameraArray.RemoveAll();
	m_GroupCamArray.RemoveAll();
	m_GroupArray.RemoveAll();

	m_DeviceGroupArray.RemoveAll();
	m_LayoutGroupArray.RemoveAll();
}

CDatabaseMgr::~CDatabaseMgr(void)
{
}

void CDatabaseMgr::QueryGroupTable(CSimpleArray <group> *pArray, BYTE bOperation, BOOL bUpdate)
{
	group tblData;
	
	CSimpleArray<group> *pCacheArray = NULL;

	switch(bOperation)
	{
	case GET_GROUP:
		{
			int n = m_GroupArray.GetSize();
			CString str;
			str.Format(_T("myname is lynn size = %d"),n);
			::OutputDebugString(str);

			HANDLE hCameraRecording = CreateEvent(NULL, false, false, _T("Global\\LYNN"));
			if (hCameraRecording != NULL)
				SetEvent( hCameraRecording );
			CloseHandle(hCameraRecording);

			if (m_GroupArray.GetSize())
			{
				*pArray = m_GroupArray;
				return;
			}
			m_ecGroup.OpenAll();
		}
		break;
	case GET_GROUP_BY_DEVICE:
		{
			if (m_DeviceGroupArray.GetSize())
			{
				*pArray = m_DeviceGroupArray;
				return;
			}
			m_ecGroup.Query(_T("select * from ec_camera_group where category_code = 1 order by cameragroupid"));
		}
		break;
	case GET_GROUP_BY_LAYOUT:
		{
			if (m_LayoutGroupArray.GetSize())
			{
				*pArray = m_LayoutGroupArray;
				return;
			}
			m_ecGroup.Query(_T("select * from ec_camera_group where category_code = 2 order by cameragroupid"));
		}
		break;
	default:
		return;
	}

	while(m_ecGroup.MoveNext() == S_OK)
	{
		tblData.cameragroupid		= m_ecGroup.m_cameragroupid;
		tblData.camera_group_desc	= m_ecGroup.m_camera_group_desc;
		tblData.default_			= m_ecGroup.m_default_;
		tblData.category_code		= m_ecGroup.m_category_code;
		tblData.module_code			= m_ecGroup.m_module_code;
		tblData.map_file			= m_ecGroup.m_map_file;
		tblData.acmap_file			= m_ecGroup.m_acmap_file;

		if (!bUpdate)
		{
			if(bOperation == GET_GROUP)
				m_GroupArray.Add(tblData);
			else if (bOperation == GET_GROUP_BY_DEVICE)
				m_DeviceGroupArray.Add(tblData);
			else if (bOperation == GET_GROUP_BY_LAYOUT)
				m_LayoutGroupArray.Add(tblData);
		}
		pArray->Add(tblData);
	}
	m_ecGroup.CloseAll();
}

void CDatabaseMgr::QueryGroupCamTable(CSimpleArray <group_camera> *pArray, BYTE bOperation, BOOL bUpdate)
{
	group_camera tblData;

	switch(bOperation)
	{
	case GET_GROUP_CAM:
		{
			if (m_GroupCamArray.GetSize())
			{
				*pArray = m_GroupCamArray;
				return;
			}
			m_ecGroup_Camera.OpenAll();
		}
		break;
	case GET_LAST_GROUP_CAM:
		{
			if (m_GroupCamArray.GetSize())
			{
				pArray->Add(m_GroupCamArray[m_GroupCamArray.GetSize()-1]);
				return;
			}
			m_ecGroup_Camera.Query(_T("select top 1 *from ec_camera_group_camera order by cameragroupcameraid desc"));
		}
		break;
	case GET_GROUP_CAM_BY_STATION:
		{
			m_ecGroup_Camera.Query(_T("SELECT *FROM ec_camera_group_camera ORDER BY numb_"));
		}
	default:
		return;
	}

	while(m_ecGroup_Camera.MoveNext() == S_OK)
	{
		tblData.cameragroupcameraid	= m_ecGroup_Camera.m_cameragroupcameraid;
		tblData.cameragroupid		= m_ecGroup_Camera.m_cameragroupid;
		tblData.cameraid			= m_ecGroup_Camera.m_cameraid;
		tblData.camera_idx			= m_ecGroup_Camera.m_camera_idx;
		tblData.streamid			= m_ecGroup_Camera.m_streamid;
		tblData.numb_				= m_ecGroup_Camera.m_numb_;
		tblData.emap_x				= m_ecGroup_Camera.m_emap_x;
		tblData.emap_y				= m_ecGroup_Camera.m_emap_y;
		tblData.acmap_x				= m_ecGroup_Camera.m_acmap_x;
		tblData.acmap_y				= m_ecGroup_Camera.m_acmap_y;

		if (!bUpdate)
		{
			if(bOperation == GET_GROUP_CAM)
				m_GroupCamArray.Add(tblData);
		}
		pArray->Add(tblData);
	}

	m_ecGroup_Camera.CloseAll();
}

void CDatabaseMgr::QueryStreamTable(CSimpleArray <video_stream> *pArray, BYTE bOperation)
{
	video_stream tblData;

	switch(bOperation)
	{
	case GET_STREAM:
		{
			m_ecStream.OpenAll();
		}
		break;
	case GET_STREAM_BY_ID:
		{
			if (pArray->GetSize())
			{
				int nCameraid = (*pArray)[0].cameraid;
				CString str;
				str.Format(_T("select * from ec_stream where cameraid = '%d'"), nCameraid);
				m_ecStream.Query(str);
				pArray->RemoveAll();
			}
		}
		break;
	default:
		return;
	}

	while(m_ecStream.MoveNext() == S_OK)
	{
		tblData.stream_name		= m_ecStream.m_stream_name;
		tblData.stream_tag		= m_ecStream.m_stream_tag;
		tblData.cameraid		= m_ecStream.m_cameraid;
		tblData.stream_type		= m_ecStream.m_stream_type;
		tblData.stream_port		= m_ecStream.m_stream_port;
		tblData.stream_protocol	= m_ecStream.m_stream_protocol;
		tblData.video_cmpr_type	= m_ecStream.m_video_cmpr_type;
		tblData.video_res		= m_ecStream.m_video_res;

		pArray->Add(tblData);
	}

	m_ecStream.CloseAll();
}


void CDatabaseMgr::QueryCameraTable(CSimpleArray<camera> *pArray, BYTE bOperation, BOOL bUpdate)
{
	camera tblData;

	switch(bOperation)
	{
	case GET_CAM:
		{
			if (m_CameraArray.GetSize() != 0)
			{
				*pArray = m_CameraArray;
				return;
			}
			m_ecCamera.OpenAll();
		}
		break;
	case GET_CAM_BY_INDEX:
		{
			m_ecCamera.Query(_T("SELECT *FROM ec_camera ORDER BY camera_idx"));
		}
		break;
	default:
		return;
	}

	while(m_ecCamera.MoveNext() == S_OK)
	{
		if(m_ecCamera.m_H264 && _wtoi(m_ecCamera.m_H264) == 1)
			tblData.isURL = true;
		else
			tblData.isURL = false;

		tblData.cameraid			 = m_ecCamera.m_cameraid;
		tblData.camera_idx			 = m_ecCamera.m_camera_idx;
		tblData.cameraname			 = m_ecCamera.m_cameraname;
		tblData.connect_type_code	 = m_ecCamera.m_connect_type_code; 
		tblData.ipaddress			 = m_ecCamera.m_ipaddress;
		tblData.httpport			 = m_ecCamera.m_httpport;
		tblData.gateway				 = m_ecCamera.m_gateway;
		tblData.name_server			 = m_ecCamera.m_name_server;
		tblData.mac_address			 = m_ecCamera.m_mac_address;
		tblData.username			 = m_ecCamera.m_username;
		tblData.password			 = m_ecCamera.m_password;
		tblData.brand_code			 = m_ecCamera.m_brand_code;
		tblData.model_code			 = m_ecCamera.m_model_code;
		tblData.ptz_support			 = m_ecCamera.m_ptz_support;
		tblData.ptz_protocol		 = m_ecCamera.m_ptz_protocol;
		tblData.digital_in1			 = m_ecCamera.m_digital_in1;
		tblData.digital_in2			 = m_ecCamera.m_digital_in2;
		tblData.digital_out			 = m_ecCamera.m_digital_out;
		tblData.video_format		 = m_ecCamera.m_video_format;
		tblData.speaker_support		 = m_ecCamera.m_speaker_support;
		tblData.mic_support			 = m_ecCamera.m_mic_support;
		tblData.subnet_mask1		 = m_ecCamera.m_subnet_mask1;
		tblData.subnet_mask2		 = m_ecCamera.m_subnet_mask2;
		tblData.subnet_mask3		 = m_ecCamera.m_subnet_mask3;
		tblData.subnet_mask4		 = m_ecCamera.m_subnet_mask4;
		tblData.active_				 = m_ecCamera.m_active_;
		tblData.stream_url			 = m_ecCamera.m_stream_url;

		pArray->Add(tblData);

		if (!bUpdate)
		{
			if(bOperation == GET_CAM)
				m_CameraArray.Add(tblData);
		}		
	}

	m_ecCamera.CloseAll();
}

void CDatabaseMgr::QueryCameraRecordTable(CSimpleArray<video_record> *pArray)
{
	video_record tblData;
	m_ecRecording.OpenAll();
	int nIdx = 0, nCoun = 0;
	wchar_t buffer[3];

	while(m_ecRecording.MoveNext() == S_OK)
	{
		tblData.camera_idx			= m_ecRecording.m_camera_idx;
		tblData.recording_type		= m_ecRecording.m_recording_type;

		nCoun = sizeof(m_ecRecording.m_recording_time);
		for (nIdx=0; nIdx<nCoun; nIdx++)
		{
			wsprintf(buffer,_T("%02x"),m_ecRecording.m_recording_time[nIdx]);
			tblData.recording_time += buffer;
		}
		pArray->Add(tblData);
	}
	m_ecRecording.CloseAll();
}

void CDatabaseMgr::QueryStorageTable(CSimpleArray<storage> *pArray)
{
	storage tblData;

	if (pArray->GetSize())
	{
		CString str;
		str.Format(_T("SELECT * FROM ec_storage WHERE storage_type='%s'"), (*pArray)[0].storage_type.c_str());
		m_ecStorage.Query(str);
		pArray->RemoveAll();
	}

	while(m_ecStorage.MoveNext() == S_OK)
	{
		tblData.storage_type		= m_ecStorage.m_storage_type;
		tblData.store_location		= m_ecStorage.m_store_location;
		tblData.buffer_size			= m_ecStorage.m_buffer_size;
		tblData.server_user			= m_ecStorage.m_server_user;
		tblData.server_password		= m_ecStorage.m_server_password;
		
		pArray->Add(tblData);
	}

	m_ecStorage.CloseAll();
}

void CDatabaseMgr::QueryEventActionTable(CSimpleArray<eventaction> *pArray)
{
	HRESULT hr;
	eventaction tblData;
	hr = m_ecEventAction.OpenAll();

	while(hr == S_OK && m_ecEventAction.MoveNext() == S_OK)
	{
		tblData.actionid		= m_ecEventAction.m_actionid;
		tblData.event_type		= (EVENTTYPE)m_ecEventAction.m_event_type;
		tblData.action_type		= (EVENT_ACTION)m_ecEventAction.m_action_type;
		tblData.source_mac		= m_ecEventAction.m_camera_ip;
		tblData.target_mac		= m_ecEventAction.m_mail_target;

		pArray->Add(tblData);
	}
	m_ecEventAction.CloseAll();	
}

void CDatabaseMgr::QueryEventLogTable(CSimpleArray<eventlog> *pArray)
{
	HRESULT hr;
	eventlog tblData;
	if(pArray && pArray->GetSize())
		tblData = (*pArray)[0];

	if (pArray->GetSize())
	{
		CString str;
		if (tblData.logcount)
		{
			str.Format(_T("SELECT TOP %d *FROM ec_event_log"), tblData.logcount);
		}
		else
		{
			BOOL bAddSubStr = false;
			CString strTemp;
			str = (_T("SELECT *FROM ec_event_log where "));
			if (tblData.event_type != NULL_EVENT_TYPE)
			{
				strTemp.Format(_T("event_type_code = %d "),tblData.event_type);
				str += strTemp;
				bAddSubStr = TRUE;
			}

			if(tblData.device_mac.length())
			{
				strTemp.Format(_T("mac_address = '%s' "),tblData.device_mac.c_str());
				if (bAddSubStr)
				{
					str += _T("and ");
				}
				str += strTemp;
				bAddSubStr = TRUE;
			}

			if(tblData.start_time.year != 0)
			{
				CString strStartTime = DateTimeFormat(tblData.start_time);
				CString strEndTime = DateTimeFormat(tblData.end_time);
				strTemp.Format(_T("occur_time >= '%s' and end_time <= '%s'"),strStartTime,strEndTime);

				if (bAddSubStr)
				{
					str += _T("and ");
				}
				str += strTemp;
			}
		}
		
		hr = m_ecEventLog.Query(str);
		pArray->RemoveAll();
	}

	while(hr == S_OK && m_ecEventLog.MoveNext() == S_OK)
	{
		tblData.logid			= m_ecEventLog.m_event_key;
		tblData.event_type		= (EVENTTYPE)_wtoi(m_ecEventLog.m_event_type_code);
		tblData.start_time		= m_ecEventLog.m_occur_time;
		tblData.end_time		= m_ecEventLog.m_end_time;
		tblData.device_mac		= m_ecEventLog.m_mac_address;
		
		pArray->Add(tblData);
	}
	m_ecEventLog.CloseAll();
}

void CDatabaseMgr::QueryECparmsTable(CSimpleArray<parameter> *pArray)
{
	parameter tblData;

	if (pArray->GetSize())
	{
		CString str;
		str.Format(_T("SELECT *FROM ecparms WHERE parm_name = '%s'"), (*pArray)[0].parm_name.c_str());
		m_ecParam.Query(str);
		pArray->RemoveAll();
	}

	while(m_ecParam.MoveNext() == S_OK)
	{
		tblData.parm_name		= m_ecParam.m_parm_name;
		tblData.parm_value		= m_ecParam.m_parm_value;
		pArray->Add(tblData);
	}
	m_ecParam.CloseAll();
}


void CDatabaseMgr::InsertGroupTable(CSimpleArray <group> *pArray)
{
	int nIdx = 0, nCount = pArray->GetSize();
	CString str, strSql;
	for (nIdx = 0; nIdx < nCount; nIdx++)
	{
		str.Empty();
		str.Format( 
			_T(
			"Insert INTO ec_camera_group (cameragroupid, camera_group_desc, module_code, category_code, default_) VALUES ('%d', '%s', '%s', '%s', '%s')"),
			(*pArray)[nIdx].cameragroupid, (*pArray)[nIdx].camera_group_desc.c_str(), (*pArray)[nIdx].module_code.c_str(), (*pArray)[nIdx].category_code.c_str(), (*pArray)[nIdx].default_.c_str()
			);

		strSql += str;
	}

	m_ecGroup.ModifyDatabase(strSql);
	m_ecGroup.CloseAll();

	m_GroupArray.RemoveAll();
	m_DeviceGroupArray.RemoveAll();
	m_LayoutGroupArray.RemoveAll();
}

void CDatabaseMgr::InsertCameraTable(CSimpleArray<camera> *pArray)
{
	int nIdx = 0, nCount = pArray->GetSize();
	CString str, strSql;
	for (nIdx = 0; nIdx < nCount; nIdx++)
	{
		str.Empty();
		str.Format( 
			_T(
			"INSERT INTO ec_camera(camera_idx, cameraname, connect_type_code, ipaddress, httpport, gateway, name_server, mac_address, username, password, brand_code, model_code, ptz_support, ptz_protocol,digital_in1,digital_in2,digital_out,video_format,speaker_support,mic_support,subnet_mask1,subnet_mask2,subnet_mask3,subnet_mask4,H264,total_stream,active_,stream_url) VALUES ('%d', '%s', '%s', '%s', '%d', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%d','%d','%s','%s')"),
			(*pArray)[nIdx].camera_idx,
			(*pArray)[nIdx].cameraname.c_str(),
			(*pArray)[nIdx].connect_type_code.c_str(), 
			(*pArray)[nIdx].ipaddress.c_str(),
			(*pArray)[nIdx].httpport,
			(*pArray)[nIdx].gateway.c_str(),
			(*pArray)[nIdx].name_server.c_str(),
			(*pArray)[nIdx].mac_address.c_str(),
			(*pArray)[nIdx].username.c_str(),
			(*pArray)[nIdx].password.c_str(),
			(*pArray)[nIdx].brand_code.c_str(),
			(*pArray)[nIdx].model_code.c_str(),
			(*pArray)[nIdx].ptz_support.c_str(),
			(*pArray)[nIdx].ptz_protocol.c_str(),
			(*pArray)[nIdx].digital_in1.c_str(),
			(*pArray)[nIdx].digital_in2.c_str(),						
			(*pArray)[nIdx].digital_out.c_str(),
			(*pArray)[nIdx].video_format.c_str(),
			(*pArray)[nIdx].speaker_support.c_str(),
			(*pArray)[nIdx].mic_support.c_str(),
			(*pArray)[nIdx].subnet_mask1.c_str(),
			(*pArray)[nIdx].subnet_mask2.c_str(),
			(*pArray)[nIdx].subnet_mask3.c_str(),
			(*pArray)[nIdx].subnet_mask4.c_str(),
			(*pArray)[nIdx].isURL,
			0,
			(*pArray)[nIdx].active_.c_str(),
			(*pArray)[nIdx].stream_url.c_str()
			);

		strSql += str;
	}

	m_ecCamera.ModifyDatabase(strSql);
	m_ecCamera.CloseAll();
	m_CameraArray.RemoveAll();
}

void CDatabaseMgr::InsertCameraRecordTable(CSimpleArray<video_record> *pArray)
{
	int nIdx = 0, nCount = pArray->GetSize();
	CString str, strSql;
	for (nIdx = 0; nIdx < nCount; nIdx++)
	{
		str.Empty();
		str.Format( 
			_T(
			"INSERT INTO ec_camera_recording (camera_idx, recording_type) VALUES('%d', '%s')"),
			(*pArray)[nIdx].camera_idx,(*pArray)[nIdx].recording_type.c_str()
			);

		strSql += str;
	}
	m_ecRecording.ModifyDatabase(strSql);
	m_ecRecording.CloseAll();	
}

void CDatabaseMgr::InsertGroupCamTable(CSimpleArray<group_camera> *pArray)
{
	int nIdx = 0, nCount = pArray->GetSize();
	CString str, strSql;
	for (nIdx = 0; nIdx < nCount; nIdx++)
	{
		str.Empty();
		str.Format( 
			_T(
			"INSERT INTO ec_camera_group_camera (cameragroupid, cameraid, camera_idx, streamid, numb_) VALUES('%d', '%d', '%d', '%d', '%d')"),
			(*pArray)[nIdx].cameragroupid,
			(*pArray)[nIdx].cameraid,
			(*pArray)[nIdx].camera_idx,
			(*pArray)[nIdx].streamid,
			(*pArray)[nIdx].numb_
			);

		strSql += str;
	}
	m_ecGroup_Camera.ModifyDatabase(strSql);
	m_ecGroup_Camera.CloseAll();	
	m_GroupCamArray.RemoveAll();
}

void CDatabaseMgr::InsertEventActionTable(CSimpleArray<eventaction> *pArray)
{
	HRESULT hr;
	eventaction tblData;

	int nIdx = 0, nCount = pArray->GetSize();
	CString str, strSql;
	for (nIdx = 0; nIdx < nCount; nIdx++)
	{
		str.Empty();
		str.Format( 
			_T(
			"INSERT INTO ec_event_action(camera_ip,event_type,action_type,mail_target) values ('%s',%d,%d,'%s')"),
			(*pArray)[nIdx].source_mac.c_str(),
			(*pArray)[nIdx].event_type,
			(*pArray)[nIdx].action_type,
			(*pArray)[nIdx].target_mac.c_str()
			);

		strSql += str;
	}
	hr = m_ecEventAction.ModifyDatabase(strSql);
	m_ecEventAction.CloseAll();
}

void CDatabaseMgr::InsertStreamTable(CSimpleArray<video_stream> *pArray)
{
	int nIdx = 0, nCount = pArray->GetSize();
	CString str, strSql;
	for (nIdx = 0; nIdx < nCount; nIdx++)
	{
		str.Empty();
		str.Format( 
			_T(
			"INSERT INTO ec_stream (stream_name, stream_tag, cameraid, stream_type, stream_port, stream_protocol, video_cmpr_type, video_res) VALUES('%s', '%s', %d, '%s', '%d', '%s', '%s', '%s')"),
			(*pArray)[nIdx].stream_name.c_str(),
			(*pArray)[nIdx].stream_tag.c_str(),
			(*pArray)[nIdx].cameraid,
			(*pArray)[nIdx].stream_type.c_str(),
			(*pArray)[nIdx].stream_port,
			(*pArray)[nIdx].stream_protocol.c_str(), 
			(*pArray)[nIdx].video_cmpr_type.c_str(), 
			(*pArray)[nIdx].video_res.c_str()
			);

		strSql += str;
	}
	m_ecStream.ModifyDatabase(strSql);
	m_ecStream.CloseAll();
}

void CDatabaseMgr::DeleteGroupTable(CSimpleArray <group> *pArray, BYTE bOperation)
{
	bool bExecute = false;
	switch(bOperation)
	{
	case DELETE_GROUP_BY_DEVICE:
		{
			m_ecGroup.ModifyDatabase(_T("DELETE FROM ec_camera_group WHERE category_code = 1"));
			bExecute = true;
		}
		break;
	case DELETE_GROUP_BY_LAYOUT:
		{
			m_ecGroup.ModifyDatabase(_T("DELETE FROM ec_camera_group WHERE category_code = 2"));
			bExecute = true;
		}
		break;
	case DELETE_GROUP_BY_ID:
		{
			if (pArray->GetSize())
			{
				CString strSql;
				strSql.Format(_T("DELETE FROM ec_camera_group WHERE cameragroupid = %d"), (*pArray)[pArray->GetSize()-1].cameragroupid);
				m_ecGroup.ModifyDatabase(strSql);
				bExecute = true;
			}
		}
		break;
	default:
		return;
	}

	if (bExecute)
	{
		m_ecGroup.CloseAll();
		m_GroupArray.RemoveAll();
		m_DeviceGroupArray.RemoveAll();
		m_LayoutGroupArray.RemoveAll();
	}
}

void CDatabaseMgr::DeleteGroupCamTable(CSimpleArray <group_camera> *pArray, BYTE bOperation)
{
	bool bExecute = false;
	switch(bOperation)
	{
	case DELETE_GROUP_CAM_BY_GRPID:
		{
			if (pArray->GetSize())
			{
				CString strSql;
				strSql.Format(_T("DELETE FROM ec_camera_group_camera WHERE cameragroupid = %d"), 
					(*pArray)[pArray->GetSize()-1].cameragroupid);
				m_ecGroup_Camera.ModifyDatabase(strSql);
				bExecute = true;
			}
		}
		break;
	case DELETE_GROUP_CAM_BY_CAMID:
		{
			if (pArray->GetSize())
			{
				CString strSql;
				strSql.Format(_T("DELETE FROM ec_camera_group_camera WHERE cameraid = %d"), 
					(*pArray)[pArray->GetSize()-1].cameraid);
				m_ecGroup_Camera.ModifyDatabase(strSql);
				bExecute = true;
			}
		}
		break;
	case DELETE_GROUP_CAM_BY_CAMID_GRPID:
		{
			if (pArray->GetSize())
			{
				CString strSql;
				strSql.Format(_T("DELETE FROM ec_camera_group_camera WHERE cameraid = %d and cameragroupid = %d"), 
					(*pArray)[pArray->GetSize()-1].cameraid,
					(*pArray)[pArray->GetSize()-1].cameragroupid);
				m_ecGroup_Camera.ModifyDatabase(strSql);
				bExecute = true;
			}
		}
		break;
	case DELETE_GROUP_CAM_BY_PRIM:
		{
			if (pArray->GetSize())
			{
				CString strSql;
				strSql.Format(_T("DELETE FROM ec_camera_group_camera WHERE cameragroupcameraid = %d"), 
					(*pArray)[pArray->GetSize()-1].cameragroupcameraid);
				m_ecGroup_Camera.ModifyDatabase(strSql);
				bExecute = true;
			}
		}
		break;
	default:
		return;
	}

	if (bExecute)
	{
		m_ecGroup_Camera.CloseAll();
		m_GroupCamArray.RemoveAll();
	}
}
void CDatabaseMgr::DeleteCameraRecordTable(CSimpleArray <video_record> *pArray, BYTE bOperation)
{	
	switch(bOperation)
	{
	case DELETE_RECORD_TIME_BY_ID:
		{
			if (pArray->GetSize())
			{
				CString strSql;
				strSql.Format(_T("DECLARE @REC_ID int; SELECT @REC_ID = camera_recordingid FROM ec_camera_recording WHERE camera_idx = %d; DELETE FROM ec_camera_recording_time WHERE camera_recordingid = @REC_ID"), 
					(*pArray)[pArray->GetSize()-1].camera_idx);
				m_ecRecordingTime.ModifyDatabase(strSql);
				m_ecRecordingTime.CloseAll();
			}
		}
		break;
	case DELETE_RECORD_BY_ID:
		{
			if (pArray->GetSize())
			{
				CString strSql;
				strSql.Format(_T("DELETE FROM ec_camera_recording WHERE camera_idx = %d"), 
					(*pArray)[pArray->GetSize()-1].camera_idx);
				m_ecRecording.ModifyDatabase(strSql);
				m_ecRecording.CloseAll();
			}
		}
		break;
	default:
		return;
	}
}

void CDatabaseMgr::DeleteCameraTable(CSimpleArray <camera> *pArray, BYTE bOperation)
{
	bool bExecute = false;
	switch(bOperation)
	{
	case DELETE_CAM:
		{
			if (pArray->GetSize())
			{
				CString strSql;
				strSql.Format(_T("DELETE FROM ec_camera WHERE cameraid = %d"), 
					(*pArray)[pArray->GetSize()-1].cameraid);
				m_ecCamera.ModifyDatabase(strSql);
				bExecute = true;
			}
		}
		break;
	default:
		return;
	}

	if (bExecute)
	{
		m_ecCamera.CloseAll();
		m_CameraArray.RemoveAll();
	}
}

void CDatabaseMgr::DeleteEventActionTable(CSimpleArray<eventaction> *pArray)
{
	if (pArray->GetSize())
	{
		CString strSql;
		strSql.Format(_T("DELETE FROM ec_event_action WHERE actionid = %d"), 
			(*pArray)[0].actionid);

		m_ecEventAction.ModifyDatabase(strSql);
		m_ecEventAction.CloseAll();	
	}
}

void CDatabaseMgr::DeleteStreamTable(CSimpleArray <video_stream> *pArray, BYTE bOperation)
{
	bool bExecute = false;
	switch(bOperation)
	{
	case DELETE_STREAM:
		{
			if (pArray->GetSize())
			{
				CString strSql;
				strSql.Format(_T("DELETE FROM ec_stream WHERE cameraid = %d"), 
					(*pArray)[pArray->GetSize()-1].cameraid);
				m_ecStream.ModifyDatabase(strSql);
				m_ecStream.CloseAll();
			}
		}
		break;
	default:
		return;
	}
}

void CDatabaseMgr::UpdateGroupTable(CSimpleArray <group> *pArray,BYTE bOperation)
{
	bool bExecute = false;
	switch(bOperation)
	{
	case UPDATE_GROUP_BY_ID:
		{
			if (pArray->GetSize() == 2)
			{
				CString strSql, str(_T(""));

				int nNewGroup = (*pArray)[1].cameragroupid;
				int	OldGroup = (*pArray)[0].cameragroupid;

				str = _T("UPDATE ec_camera_group SET cameragroupid='%d', camera_group_code='GROUP%d' WHERE cameragroupid = '%d'");
				str += _T(";UPDATE ec_camera_group_camera SET cameragroupid='%d' WHERE cameragroupid='%d'");

				strSql.Format(str, 
					nNewGroup, nNewGroup, OldGroup, nNewGroup, OldGroup);
				
				m_ecGroup.ModifyDatabase(strSql);
				bExecute = true;
			}
		}
		break;
	case UPDATE_GROUP_BY_NAME:
		{
			if (pArray->GetSize())
			{
				CString strSql;

				strSql.Format(_T("UPDATE ec_camera_group SET camera_group_desc='%s' WHERE cameragroupid= %d"), 
					(*pArray)[0].camera_group_desc.c_str(), 
					(*pArray)[0].cameragroupid);

				m_ecGroup.ModifyDatabase(strSql);
				bExecute = true;
			}
		}
		break;
	case UPDATE_DEFAULT_GROUP:
		{
			CString strSql;
			strSql.Format(_T("UPDATE ec_camera_group SET default_ = 'Y' WHERE cameragroupid = 1"));
			m_ecGroup.ModifyDatabase(strSql);
			bExecute = true;
		}
		break;
	case UPDATE_GROUP_BY_TYPE:
		{
			if (pArray->GetSize())
			{
				CString strSql;

				strSql.Format(_T("UPDATE ec_camera_group SET category_code = '%s' WHERE cameragroupid = %d"), 
					(*pArray)[0].category_code.c_str(), 
					(*pArray)[0].cameragroupid);

				m_ecGroup.ModifyDatabase(strSql);
				bExecute = true;
			}
		}
		break;
	default:
		return;
	}

	if (bExecute)
	{
		m_ecGroup.CloseAll();
		m_GroupArray.RemoveAll();
		m_DeviceGroupArray.RemoveAll();
		m_LayoutGroupArray.RemoveAll();
		if(bOperation == UPDATE_GROUP_BY_ID)
			m_GroupCamArray.RemoveAll();
	}
}

void CDatabaseMgr::UpdateGroupCamTable(CSimpleArray <group_camera> *pArray,BYTE bOperation)
{
	bool bExecute = false;
	switch(bOperation)
	{
	case UPDATE_GROUP_CAM_BY_CAMID:
		{
			if (pArray->GetSize() == 2)
			{
				CString strSql;

				int nNewGroup = (*pArray)[1].cameragroupid;
				int	nOldGroup = (*pArray)[0].cameragroupid;
				int nCameraid = (*pArray)[0].cameraid;

				strSql.Format(_T("UPDATE  ec_camera_group_camera SET cameragroupid = %d , emap_x=0,emap_y=0 WHERE cameraid = %d and cameragroupid = %d"), 
					nNewGroup, nCameraid, nOldGroup);

				m_ecGroup_Camera.ModifyDatabase(strSql);
				bExecute = true;
			}
		}
		break;
	case UPDATE_GROUP_CAM:
		{
			if (pArray->GetSize())
			{
				CString strSql;

				strSql.Format(_T("UPDATE ec_camera_group_camera set cameragroupid='%d',cameraid='%d',camera_idx='%d',streamid='%d',numb_='%d',emap_x='%d',emap_y='%d',acmap_x='%d',acmap_y='%d' where cameragroupcameraid='%d'"),
					(*pArray)[0].cameragroupid,
					(*pArray)[0].cameraid,
					(*pArray)[0].camera_idx, 
					(*pArray)[0].streamid,
					(*pArray)[0].numb_,
					(*pArray)[0].emap_x,
					(*pArray)[0].emap_y,
					(*pArray)[0].acmap_x,
					(*pArray)[0].acmap_y,
					(*pArray)[0].cameragroupcameraid);

				m_ecGroup_Camera.ModifyDatabase(strSql);
				bExecute = true;
			}
		}
		break;
	default:
		return;
	}

	if (bExecute)
	{
		m_ecGroup_Camera.CloseAll();
		m_GroupCamArray.RemoveAll();
	}
}

void CDatabaseMgr::UpdateCameraTable(CSimpleArray <camera> *pArray, BYTE bOperation)
{
	bool bExecute = false;
	switch(bOperation)
	{
	case UPDATE_CAM:
		{
			if (pArray->GetSize())
			{
				CString strSql;

				strSql.Format(_T("UPDATE ec_camera set camera_idx='%d',cameraname='%s',connect_type_code='%s',ipaddress='%s',httpport='%d',gateway='%s',name_server='%s',mac_address='%s',username='%s',password='%s',brand_code='%s',model_code='%s',ptz_support='%s',ptz_protocol='%s',digital_in1='%s',digital_in2='%s',digital_out='%s',video_format='%s',speaker_support='%s',mic_support='%s',subnet_mask1='%s',subnet_mask2='%s',subnet_mask3='%s',subnet_mask4='%s',total_stream='%d',active_='%s',stream_url='%s' where cameraid='%d'"),
					(*pArray)[0].camera_idx,
					(*pArray)[0].cameraname.c_str(),
					(*pArray)[0].connect_type_code.c_str(), 
					(*pArray)[0].ipaddress.c_str(),
					(*pArray)[0].httpport,
					(*pArray)[0].gateway.c_str(),
					(*pArray)[0].name_server.c_str(),
					(*pArray)[0].mac_address.c_str(),
					(*pArray)[0].username.c_str(),
					(*pArray)[0].password.c_str(),
					(*pArray)[0].brand_code.c_str(),
					(*pArray)[0].model_code.c_str(),
					(*pArray)[0].ptz_support.c_str(),
					(*pArray)[0].ptz_protocol.c_str(),
					(*pArray)[0].digital_in1.c_str(),
					(*pArray)[0].digital_in2.c_str(),						
					(*pArray)[0].digital_out.c_str(),
					(*pArray)[0].video_format.c_str(),
					(*pArray)[0].speaker_support.c_str(),
					(*pArray)[0].mic_support.c_str(),
					(*pArray)[0].subnet_mask1.c_str(),
					(*pArray)[0].subnet_mask2.c_str(),
					(*pArray)[0].subnet_mask3.c_str(),
					(*pArray)[0].subnet_mask4.c_str(),
					0,
					(*pArray)[0].active_.c_str(),
					(*pArray)[0].stream_url.c_str(),
					(*pArray)[0].cameraid);

				m_ecCamera.ModifyDatabase(strSql);
			}
		}
		break;
	default:
		return;
	}

	if (bExecute)
	{
		m_ecCamera.CloseAll();
		m_CameraArray.RemoveAll();
	}
}

void CDatabaseMgr::UpdateEventActionTable(CSimpleArray<eventaction> *pArray)
{
	if (pArray->GetSize())
	{
		CString strSql;
		strSql.Format(_T("UPDATE ec_event_action SET camera_ip='%s',event_type=%d,action_type=%d,mail_target='%s' WHERE actionid= %d"), 
			(*pArray)[0].source_mac,(*pArray)[0].event_type,(*pArray)[0].action_type,(*pArray)[0].target_mac,(*pArray)[0].actionid);

		m_ecEventAction.ModifyDatabase(strSql);
		m_ecEventAction.CloseAll();	
	}
}

void CDatabaseMgr::UpdateStreamTable(CSimpleArray <video_stream> *pArray,BYTE bOperation)
{
	bool bExecute = false;
	switch(bOperation)
	{
	case UPDATE_STREAM:
		{

		}
		break;
	default:
		return;
	}

	if (bExecute)
	{

	}
}

CString CDatabaseMgr::DateTimeFormat(const DBTIMESTAMP& dbTime)
{
	CString str;
	str.Format(_T("%d%02d%02d %d:%d:%d"),
		dbTime.year,
		dbTime.month,
		dbTime.day,
		dbTime.hour,
		dbTime.minute,
		dbTime.second);

	return str;
}