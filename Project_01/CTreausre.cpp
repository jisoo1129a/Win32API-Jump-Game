#include "CTreausre.h"
#include "pch.h"
#include "CCollider.h"

CTreausre::CTreausre()
	: m_fAccTime(0.f)
	, m_fTime(10.f)
{
	CreateCollider();
	GetCollider()->SetScale(GetScale() - Vec2(10.f, 10.f));
}

CTreausre::~CTreausre()
{
}

void CTreausre::update()
{
	m_fAccTime += fDT;

	if (m_fAccTime >= m_fTime)
	{
		m_fAccTime = 0.f;

		int x = rand() % 1000;
		int y = rand() % 1000;

		SetPos(Vec2((float)x, (float)y));
	}
}

//void CTreausre::render(HDC _dc)
//{
//}

