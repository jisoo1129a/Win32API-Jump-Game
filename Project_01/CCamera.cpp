#include "CCamera.h"
#include "pch.h"
#include "CKeyMgr.h"

CCamera::CCamera()
	: m_fAccTime(0.f)
	, m_fSpeed(0.f)
	, m_fTime(1.f)
{

}
CCamera::~CCamera()
{

}

void CCamera::init()
{
	m_vCurLook = CCore::GetInst()->GetResolution() / 2.f;
	m_vLookAt = m_vCurLook;
	m_vDiff = m_vCurLook - m_vCurLook / 2.f;
}

void CCamera::update()
{
	if (CKeyMgr::GetInst()->GetKeyState(KEY::UP) == KEY_STATE::HOLD)
	{
		m_vLookAt.y -= 500.f * fDT;
	}
	else if (CKeyMgr::GetInst()->GetKeyState(KEY::DOWN) == KEY_STATE::HOLD)
	{
		m_vLookAt.y += 500.f * fDT;
	}
	else if (CKeyMgr::GetInst()->GetKeyState(KEY::RIGHT) == KEY_STATE::HOLD)
	{
		m_vLookAt.x += 500.f * fDT;
	}
	else if (CKeyMgr::GetInst()->GetKeyState(KEY::LEFT) == KEY_STATE::HOLD)
	{
		m_vLookAt.x -= 500.f * fDT;
	}
	else
	{
		m_vLookAt.x += 250.f * fDT;
	}
	

	CalDiff();
}

void CCamera::render(HDC _dc)
{
}

void CCamera::CalDiff()
{
	m_fAccTime += fDT;
	if (m_fTime <= m_fAccTime)
	{
		m_vCurLook = m_vLookAt;
	}
	else
	{
		Vec2 vDiff = m_vLookAt - m_vPrevLook;
		if (!(vDiff.x == 0.f && vDiff.y == 0.f))
		{
			m_vCurLook = m_vPrevLook + m_vLookAt.Nomalize() * m_fSpeed * fDT;
		}
	}

	Vec2 vCenter = CCore::GetInst()->GetResolution() / 2.f;
	m_vDiff = m_vCurLook - vCenter;

	m_vPrevLook = m_vCurLook;
}
