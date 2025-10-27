#include "CCollider.h"
#include "pch.h"
#include "CObject.h"
#include "CCamera.h"

UINT CCollider::g_iNextID = 0;

CCollider::CCollider()
	: m_pOwner(nullptr)
	, m_iID(g_iNextID++)
	, color(1)
{
}

CCollider::~CCollider()
{
}

void CCollider::render(HDC _dc)
{
	Vec2 vPos = CCamera::GetInst()->GetRenderPos(m_vFinalPos);

	HPEN pPen;
	HBRUSH pHollowBrush = (HBRUSH)GetStockObject(HOLLOW_BRUSH);

	if (color < 0)
	{
		pPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	}
	else
	{
		pPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	}

	HPEN oldPen = (HPEN)SelectObject(_dc, pPen);
	HBRUSH oldBrush = (HBRUSH)SelectObject(_dc, pHollowBrush);

	Rectangle(_dc,
		(int)(vPos.x - m_vScale.x / 2.f),
		(int)(vPos.y - m_vScale.y / 2.f),
		(int)(vPos.x + m_vScale.x / 2.f),
		(int)(vPos.y + m_vScale.y / 2.f)
	);

	SelectObject(_dc, oldPen);
	SelectObject(_dc, oldBrush);

	DeleteObject(pPen);
}

void CCollider::finalUpdate()
{
	Vec2 vPos = m_pOwner->GetPos() + m_vOffset;
	m_vFinalPos = vPos;
}

void CCollider::OnCollisionEnter()
{
	color *= -1;
}

void CCollider::OnCollision()
{
}

void CCollider::OnCollisionExit()
{
	color *= -1;
}


