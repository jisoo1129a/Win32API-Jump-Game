#include "CObject.h"
#include "pch.h"
#include "CCamera.h"
#include "CCollider.h"
#include "CAnimator.h"

CObject::CObject()
	:m_strName()
	,m_vPos(Vec2(0.f, 0.f))
	,m_vScale(Vec2(0.f, 0.f))
	,m_pCollider(nullptr)
	,m_pAnimator(nullptr)
{
}

CObject::~CObject()
{
}


void CObject::render(HDC _dc)
{
	Vec2 vPos = m_vPos;
	Vec2 vScale = m_vScale;

	vPos = CCamera::GetInst()->GetRenderPos(vPos);

	Rectangle(_dc,
		(int)(vPos.x - vScale.x / 2.f),
		(int)(vPos.y - vScale.y / 2.f),
		(int)(vPos.x + vScale.x / 2.f),
		(int)(vPos.y + vScale.y / 2.f)
		);

}

void CObject::finalUpdate()
{
	if (m_pCollider != nullptr)
		m_pCollider->finalUpdate();
	if (m_pAnimator != nullptr)
		m_pAnimator->finalUpdate();
}


void CObject::CreateCollider()
{
	m_pCollider = new CCollider;
	m_pCollider->m_pOwner = this;
}

void CObject::CreateAnimation()
{
	m_pAnimator = new CAnimator();
	m_pAnimator->m_pOwner = this;
}

