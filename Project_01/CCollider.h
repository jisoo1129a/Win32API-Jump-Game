#pragma once
#include "pch.h"

class CObject;

class CCollider
{
private:
	static UINT g_iNextID;

	CObject* m_pOwner;

	Vec2 m_vOffset;
	Vec2 m_vScale;
	Vec2 m_vFinalPos;

	UINT m_iID;

	int color;
	bool m_bCollisionExit;

public:
	void SetScale(Vec2 _scale) { m_vScale = _scale; }
	void SetOffset(Vec2 _offSet) {
		m_vOffset = _offSet;
		m_vFinalPos = m_pOwner->GetPos() + m_vOffset;
	}
	void SetCollisionExit(bool _collision) { m_bCollisionExit = _collision; }
	bool IsCollisionExit() { return m_bCollisionExit; }
	CObject* GetOwner() { return m_pOwner; }
	Vec2 GetScale() { return m_vScale; }
	Vec2 GetOffSet() { return m_vOffset; }
	Vec2 GetPos() { return m_vFinalPos; }
	UINT GetID() { return m_iID; }

public:
	void render(HDC _dc);
	void finalUpdate();

	void OnCollisionEnter();
	void OnCollision();
	void OnCollisionExit();
public:
	CCollider();
	~CCollider();

	friend class CObject;
};

