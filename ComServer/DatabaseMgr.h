#pragma once

#include "ec_camera.h"
#include "ec_camera_group.h"
#include "ec_camera_group_camera.h"
#include "ec_stream.h"
#include "ec_camera_recording.h"
#include "ec_storage.h"
#include "ecparms.h"
#include "ec_camera_recording_time.h"
#include "ec_event_log.h"
#include "ec_event_action.h"

class CDatabaseMgr
{
public:
	CDatabaseMgr(void);
	~CDatabaseMgr(void);

public:
	CRITICAL_SECTION					m_criSec;

public:
	void QueryGroupTable(CSimpleArray <group> *pArray, BYTE bOperation, BOOL bUpdate = FALSE);
	void QueryGroupCamTable(CSimpleArray <group_camera> *pArray, BYTE bOperation, BOOL bUpdate = FALSE);
	void QueryStreamTable(CSimpleArray <video_stream> *pArray, BYTE bOperation);
	void QueryCameraTable(CSimpleArray<camera> *pArray, BYTE bOperation, BOOL bUpdate = FALSE);
	void QueryCameraRecordTable(CSimpleArray<video_record> *pArray);
	void QueryStorageTable(CSimpleArray<storage> *pArray);
	void QueryECparmsTable(CSimpleArray<parameter> *pArray);
	void QueryEventLogTable(CSimpleArray<eventlog> *pArray, BYTE bOperation);
	void QueryEventActionTable(CSimpleArray<eventaction> *pArray, BYTE bOperation);

	void InsertGroupTable(CSimpleArray <group> *pArray);
	void InsertCameraTable(CSimpleArray<camera> *pArray);
	void InsertCameraRecordTable(CSimpleArray<video_record> *pArray);
	void InsertGroupCamTable(CSimpleArray<group_camera> *pArray);
	void InsertStreamTable(CSimpleArray<video_stream> *pArray);
	void InsertEventLogTable(CSimpleArray<eventlog> *pArray);
	void InsertEventActionTable(CSimpleArray<eventaction> *pArray);

	void DeleteGroupTable(CSimpleArray <group> *pArray, BYTE bOperation);
	void DeleteGroupCamTable(CSimpleArray <group_camera> *pArray, BYTE bOperation);
	void DeleteCameraRecordTable(CSimpleArray <video_record> *pArray, BYTE bOperation);
	void DeleteCameraTable(CSimpleArray <camera> *pArray, BYTE bOperation);
	void DeleteStreamTable(CSimpleArray <video_stream> *pArray, BYTE bOperation);
	void DeleteEventActionTable(CSimpleArray<eventaction> *pArray);

	void UpdateGroupTable(CSimpleArray <group> *pArray,BYTE bOperation);
	void UpdateGroupCamTable(CSimpleArray <group_camera> *pArray,BYTE bOperation);
	void UpdateCameraTable(CSimpleArray <camera> *pArray, BYTE bOperation);
	void UpdateStreamTable(CSimpleArray <video_stream> *pArray,BYTE bOperation);
	void UpdateEventActionTable(CSimpleArray<eventaction> *pArray);

	void FlushData();
	DWORD TransIP2DWORD(wstring strIP);
	CString DateTimeFormat(const DBTIMESTAMP& dbTime);
	Cec_event_log* GetEventLogHandle(){return &m_ecEventLog;};

private:
	vector<eventlog>				m_eventLogArray;
	CSimpleArray<camera> m_CameraArray;
	CSimpleArray<group_camera> m_GroupCamArray;
	CSimpleArray<group> m_GroupArray;
	CSimpleArray<group> m_DeviceGroupArray;
	CSimpleArray<group> m_LayoutGroupArray;
	wstring TransDWORD2IP(DWORD dwIP);
	
private:
	Cec_camera					m_ecCamera;
	Cec_camera_group			m_ecGroup;
	Cec_camera_group_camera		m_ecGroup_Camera;
	Cec_stream					m_ecStream;
	Cec_camera_recording		m_ecRecording;
	Cec_storage					m_ecStorage;
	Cecparms					m_ecParam;
	Cec_camera_recording_time	m_ecRecordingTime;
	Cec_event_log				m_ecEventLog;
	Cec_event_action			m_ecEventAction;
};
