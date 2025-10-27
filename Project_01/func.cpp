#include "func.h"
#include "CSceneMgr.h"
#include "CEventMgr.h"

void CreateObejct(CObject* _pObj, GROUP_TYPE _eGroup)
{
	tEvent evn = {};
	evn.eType = EVENT_TYPE::CREATE_OBJECT;
	evn.lParam = (DWORD_PTR)_pObj;
	evn.wParam = (DWORD_PTR)_eGroup;

}

void DeleteObject(CObject* _pObj)
{
	tEvent evn = {};
	evn.eType = EVENT_TYPE::DELETE_OBJECT;
	evn.lParam = (DWORD_PTR)_pObj;
}

void ChangeScene(SCENE_TYPE _eNext)
{
	
}
