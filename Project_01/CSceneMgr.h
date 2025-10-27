#pragma once
#include "pch.h"

class CScene;

class CSceneMgr
{
	SINGLE(CSceneMgr);

private:
	CScene* m_pCurScene;
	CScene* m_arrScene[(UINT)SCENE_TYPE::END];

public:
	CScene* GetCurScene() { return m_pCurScene; }
public:
	void init();
	void update();
	void render(HDC _dc);

public:
	void changeScene(SCENE_TYPE _eNext);
};

