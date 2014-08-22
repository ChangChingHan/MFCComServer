// DataMgr.cpp : Implementation of CDataMgr

#include "stdafx.h"
#include "DataMgr.h"

// CDataMgr

STDMETHODIMP CDataMgr::QueryFromDC(BYTE bDataType, BYTE bOperation, VARIANT* VarData)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	switch(bDataType)
	{
	case DATABASE:
		{
			DatabaseOperation(bOperation, VarData);
		}
		break;
	default:
		break;
	}
	return S_OK;
}

void CDataMgr::DatabaseOperation(BYTE bOperation, VARIANT* VarData)
{
	if (bOperation >= GET_GROUP && bOperation <= GET_EVENT_ACTION)
	{
		QueryDatabase(bOperation, VarData);
	}
	else if(bOperation >= INSERT_GROUP && bOperation <= INSERT_EVENT_ACTION)
	{
		InsertDatabase(bOperation, VarData);
	}
	else if(bOperation >= DELETE_GROUP_BY_DEVICE && bOperation <= DELETE_EVENT_ACTION)
	{
		DeleteDatabase(bOperation, VarData);
	}
	else if(bOperation >= UPDATE_GROUP_BY_ID && bOperation <= UPDATE_EVENT_ACTION)
	{
		UpdateDatabase(bOperation, VarData);
	}
}

void CDataMgr::QueryDatabase(BYTE bOperation, VARIANT* VarData)
{
	if (bOperation >= GET_GROUP && bOperation <= GET_GROUP_BY_LAYOUT)
	{
		CSimpleArray <group> *pArray = (CSimpleArray <group>*)VarData;
		m_databaseMgr.QueryGroupTable(pArray,bOperation);
	}
	else if (bOperation >= GET_GROUP_CAM && bOperation <= GET_GROUP_CAM_BY_STATION)
	{
		CSimpleArray<group_camera> *pArray = (CSimpleArray<group_camera>*)VarData;
		m_databaseMgr.QueryGroupCamTable(pArray,bOperation);
	}
	else if (bOperation >= GET_CAM && bOperation <= GET_CAM_BY_INDEX)
	{
		CSimpleArray<camera> *pArray = (CSimpleArray<camera>*)VarData;
		m_databaseMgr.QueryCameraTable(pArray, bOperation);
	}
	else if (bOperation >= GET_STREAM && bOperation <= GET_STREAM_BY_ID)
	{
		CSimpleArray<video_stream> *pArray = (CSimpleArray<video_stream>*)VarData;
		m_databaseMgr.QueryStreamTable(pArray,bOperation);
	}
	else if (bOperation >= GET_RECORD && bOperation <= GET_RECORD)
	{
		CSimpleArray<video_record> *pArray = (CSimpleArray<video_record>*)VarData;
		m_databaseMgr.QueryCameraRecordTable(pArray);
	}
	else if (bOperation >= GET_STORAGE && bOperation <= GET_STORAGE)
	{
		CSimpleArray<storage> *pArray = (CSimpleArray<storage>*)VarData;
		m_databaseMgr.QueryStorageTable(pArray);
	}
	else if (bOperation >= GET_PARAM && bOperation <= GET_PARAM)
	{
		CSimpleArray<parameter> *pArray = (CSimpleArray<parameter>*)VarData;
		m_databaseMgr.QueryECparmsTable(pArray);
	}
	else if (bOperation >= GET_EVENT_LOG && bOperation <= GET_EVENT_LOG)
	{
		CSimpleArray<eventlog> *pArray = (CSimpleArray<eventlog>*)VarData;
		m_databaseMgr.QueryEventLogTable(pArray);
	}
	else if (bOperation >= GET_EVENT_ACTION && bOperation <= GET_EVENT_ACTION)
	{
		CSimpleArray<ec_Event_Action> *pArray = (CSimpleArray<ec_Event_Action>*)VarData;
		m_databaseMgr.QueryEventActionTable(pArray);
	}
}
void CDataMgr::InsertDatabase(BYTE bOperation, VARIANT* VarData)
{
	if (bOperation == INSERT_GROUP)
	{
		CSimpleArray <group> *pArray = (CSimpleArray <group>*)VarData;
		m_databaseMgr.InsertGroupTable(pArray);
	}
	else if (bOperation == INSERT_CAM)
	{
		CSimpleArray <camera> *pArray = (CSimpleArray <camera>*)VarData;
		m_databaseMgr.InsertCameraTable(pArray);
	}
	else if (bOperation == INSERT_RECORD)
	{
		CSimpleArray <video_record> *pArray = (CSimpleArray <video_record>*)VarData;
		m_databaseMgr.InsertCameraRecordTable(pArray);
	}
	else if (bOperation == INSERT_GROUP_CAM)
	{
		CSimpleArray <group_camera> *pArray = (CSimpleArray <group_camera>*)VarData;
		m_databaseMgr.InsertGroupCamTable(pArray);
	}
	else if (bOperation == INSERT_STREAM)
	{
		CSimpleArray <video_stream> *pArray = (CSimpleArray <video_stream>*)VarData;
		m_databaseMgr.InsertStreamTable(pArray);
	}
	else if (bOperation == INSERT_EVENT_ACTION)
	{
		CSimpleArray <ec_Event_Action> *pArray = (CSimpleArray <ec_Event_Action>*)VarData;
		m_databaseMgr.InsertEventActionTable(pArray);
	}
}
void CDataMgr::DeleteDatabase(BYTE bOperation, VARIANT* VarData)
{
	if (bOperation >= DELETE_GROUP_BY_DEVICE && bOperation <= DELETE_GROUP_BY_ID)
	{
		CSimpleArray <group> *pArray = (CSimpleArray <group>*)VarData;
		m_databaseMgr.DeleteGroupTable(pArray,bOperation);
	}
	else if (bOperation >= DELETE_GROUP_CAM_BY_GRPID && bOperation <= DELETE_GROUP_CAM_BY_PRIM)
	{
		CSimpleArray<group_camera> *pArray = (CSimpleArray<group_camera>*)VarData;
		m_databaseMgr.DeleteGroupCamTable(pArray,bOperation);
	}
	else if (bOperation >= DELETE_CAM && bOperation <= DELETE_CAM)
	{
		CSimpleArray<camera> *pArray = (CSimpleArray<camera>*)VarData;
		m_databaseMgr.DeleteCameraTable(pArray, bOperation);
	}
	else if (bOperation >= DELETE_STREAM && bOperation <= DELETE_STREAM)
	{
		CSimpleArray<video_stream> *pArray = (CSimpleArray<video_stream>*)VarData;
		m_databaseMgr.DeleteStreamTable(pArray,bOperation);
	}
	else if (bOperation >= DELETE_RECORD_BY_ID && bOperation <= DELETE_RECORD_TIME_BY_ID)
	{
		CSimpleArray<video_record> *pArray = (CSimpleArray<video_record>*)VarData;
		m_databaseMgr.DeleteCameraRecordTable(pArray, bOperation);
	}
	else if (bOperation >= DELETE_EVENT_ACTION && bOperation <= DELETE_EVENT_ACTION)
	{
		CSimpleArray<ec_Event_Action> *pArray = (CSimpleArray<ec_Event_Action>*)VarData;
		m_databaseMgr.DeleteEventActionTable(pArray);
	}
}

void CDataMgr::UpdateDatabase(BYTE bOperation, VARIANT* VarData)
{
	if (bOperation >= UPDATE_GROUP_BY_ID && bOperation <= UPDATE_GROUP_BY_TYPE)
	{
		CSimpleArray <group> *pArray = (CSimpleArray <group>*)VarData;
		m_databaseMgr.UpdateGroupTable(pArray,bOperation);
	}
	else if (bOperation >= UPDATE_GROUP_CAM_BY_CAMID && bOperation <= UPDATE_GROUP_CAM)
	{
		CSimpleArray<group_camera> *pArray = (CSimpleArray<group_camera>*)VarData;
		m_databaseMgr.UpdateGroupCamTable(pArray,bOperation);
	}
	else if (bOperation >= UPDATE_CAM && bOperation <= UPDATE_CAM)
	{
		CSimpleArray<camera> *pArray = (CSimpleArray<camera>*)VarData;
		m_databaseMgr.UpdateCameraTable(pArray, bOperation);
	}
	else if (bOperation >= UPDATE_STREAM && bOperation <= UPDATE_STREAM)
	{
		CSimpleArray<video_stream> *pArray = (CSimpleArray<video_stream>*)VarData;
		m_databaseMgr.UpdateStreamTable(pArray,bOperation);
	}
	else if (bOperation >= UPDATE_EVENT_ACTION && bOperation <= UPDATE_EVENT_ACTION)
	{
		CSimpleArray<ec_Event_Action> *pArray = (CSimpleArray<ec_Event_Action>*)VarData;
		m_databaseMgr.UpdateEventActionTable(pArray);
	}
}