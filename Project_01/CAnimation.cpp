#include "CAnimation.h"
#include "CAnimator.h"
#include "CCamera.h"
#include "CObject.h"
#include "CTexture.h"
#include "CTimeMgr.h"


CAnimation::CAnimation()
	: m_bFinished(false)
	, m_fAccTime(0.f)
	, m_iCurFrm(0)
	, m_pAnimator(nullptr)
	, m_pTexture(nullptr)
	, m_strName()
{
}

CAnimation::~CAnimation()
{
}

void CAnimation::update()
{
	if (m_bFinished)
		return;

	tAnimFrm tFrm = m_vecFrm[m_iCurFrm];
	m_fAccTime += fDT;

	if (m_fAccTime > tFrm.fDuration)
	{
		m_fAccTime = m_fAccTime - tFrm.fDuration;
		m_iCurFrm++;
		if (m_vecFrm.size() <= m_iCurFrm)
		{
			m_iCurFrm = -1;
			m_fAccTime = 0.f;
			m_bFinished = true;
		}
	}
}

void CAnimation::render(HDC _dc)
{
	if (m_bFinished)
		return;

	tAnimFrm tFrm = m_vecFrm[m_iCurFrm];
	CObject* pObj = m_pAnimator->getOwner();
	Vec2 vPos = pObj->GetPos() + tFrm.vOffset;
	
	vPos = CCamera::GetInst()->GetRenderPos(vPos);
	
	TransparentBlt(_dc,
		(int)(vPos.x - tFrm.vSliceSize.x / 2.f),
		(int)(vPos.y - tFrm.vSliceSize.y / 2.f),
		(int)(tFrm.vSliceSize.x), (int)(tFrm.vSliceSize.y),
		m_pTexture->GetDC(),
		(int)(tFrm.vLT.x), (int)(tFrm.vLT.y),
		(int)(tFrm.vSliceSize.x), (int)(tFrm.vSliceSize.y),
		RGB(255, 255, 255)
	);
}

void CAnimation::Create(CTexture* _texture, Vec2 _vLT, Vec2 _vSilceSize, Vec2 _vStep, float _fDuration, UINT _iFrmCount)
{
	m_pTexture = _texture;

	tAnimFrm tFrm = {};
	for (UINT i = 0; i < _iFrmCount; i++)
	{
		tFrm.fDuration = _fDuration;
		tFrm.vSliceSize = _vSilceSize;
		tFrm.vLT = _vLT + _vStep * (float)i;
	}
}

