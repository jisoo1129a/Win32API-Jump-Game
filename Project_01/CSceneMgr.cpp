#include "CSceneMgr.h"
#include "CScene.h"
#include "CScene_start.h"

CSceneMgr::CSceneMgr()
	: m_pCurScene(nullptr)
	, m_arrScene{}
{

}
CSceneMgr::~CSceneMgr()
{
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; i++)
	{
		delete m_arrScene[i];
	}
}

void CSceneMgr::init()
{
	m_arrScene[(UINT)SCENE_TYPE::START_SCENE] = new CScene_start;
	m_arrScene[(UINT)SCENE_TYPE::START_SCENE]->SetName(L"state_scene");
	
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::START_SCENE];
	m_pCurScene->Enter();
}

void CSceneMgr::update()
{
	m_pCurScene->update();
	m_pCurScene->finalUpdate();
}

void CSceneMgr::render(HDC _dc)
{
	m_pCurScene->render(_dc);
}

void CSceneMgr::changeScene(SCENE_TYPE _eNext)
{
	m_pCurScene->Exit();
	m_pCurScene = m_arrScene[(UINT)_eNext];
	m_pCurScene->Enter();
}
