#pragma once
#include "pch.h"

class CObject;

class CScene
{
private:
	wstring m_strName;
	vector<CObject*> m_arrObj[(UINT)GROUP_TYPE::END];
public:
	const wstring& GetName() { return m_strName; }
	void SetName(const wstring& _strName) { m_strName = _strName; }

	void AddObject(CObject* _object, GROUP_TYPE _eGroup) { m_arrObj[(UINT)_eGroup].push_back(_object); }
	vector<CObject*>& GetGroupObject(GROUP_TYPE _eGroup) { return m_arrObj[(UINT)_eGroup]; }

public:
	virtual void update();
	virtual void finalUpdate();
	virtual void render(HDC _dc);
	

	virtual void Enter() = 0;
	virtual void Exit() = 0;
public:
	CScene();
	virtual ~CScene();
};

