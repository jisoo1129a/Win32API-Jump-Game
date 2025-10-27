#pragma once
#include "pch.h"

class CCollider;

union COLLIDER_ID
{
	struct {
		UINT iLeft;
		UINT iRight;
	};
	ULONGLONG ID;
};

class CCollisionMgr
{
	SINGLE(CCollisionMgr);

private:
	UINT m_arrCheck[(UINT)GROUP_TYPE::END];
	map<ULONGLONG, bool> m_mapColInfo;

public:
	void init();
	void update();
	void CheckGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight);
	void reset();

public:
	void CollisionUpdate(GROUP_TYPE _eLeft, GROUP_TYPE _eRight);
	bool isCollision(CCollider* _pLeft, CCollider* _pRight);

};

