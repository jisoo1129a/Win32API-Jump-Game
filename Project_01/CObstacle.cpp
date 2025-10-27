#include "CObstacle.h"
#include "pch.h"
#include "CCollider.h"
#include "CAnimator.h"
#include "CTexture.h"
#include "CResMgr.h"
#include "CCamera.h"


CObstacle::CObstacle()
	: m_pTex(nullptr)
	, m_bCollision(false)
{
	int height[4] = { 255, 350, 450, 545 };

	CreateCollider();
	CreateAnimation();
	m_pTex = CResMgr::GetInst()->LoadTexture(L"obstacle", L"obstacle.bmp");
	m_iType = rand() % 4;
	m_iHeight = (UINT)height[(int)m_iType];
	//GetAnimator()->CreateAnimaton(L"obstacle", pTex, Vec2(0, 0), Vec2(200.f, 554.f), Vec2(200.f, 0.f), 1.f, 4);
}

CObstacle::~CObstacle()
{
}

void CObstacle::update()
{

}

void CObstacle::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	vPos = CCamera::GetInst()->GetRenderPos(vPos);
	TransparentBlt(_dc,
		(int)(vPos.x - vScale.x / 2.f), (int)(vPos.y - vScale.y / 2.f),
		(int)vScale.x, (int)vScale.y,
		m_pTex->GetDC(),
		m_iType * 200 + 20, 581 - m_iHeight,
		180, m_iHeight,
		RGB(255, 255, 255)
	);
	GetCollider()->render(_dc);
}
