#pragma once
#include "pch.h"

class CCollider;
class CAnimator;

class CObject
{
private:
	wstring m_strName;

	Vec2 m_vPos;
	Vec2 m_vScale;
	
	CCollider* m_pCollider;
	CAnimator* m_pAnimator;

public:
	virtual void SetPos(Vec2 _pos) { m_vPos = _pos; }
	void SetScale(Vec2 _scale) { m_vScale = _scale; }
	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }
	CCollider* GetCollider() { return m_pCollider; }
	CAnimator* GetAnimator() { return m_pAnimator; }

	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

public:
	void CreateCollider();
	void CreateAnimation();

public:
	virtual void update() = 0;
	virtual void render(HDC _dc);
	virtual void finalUpdate();

public:
	CObject();
	virtual ~CObject();
};

