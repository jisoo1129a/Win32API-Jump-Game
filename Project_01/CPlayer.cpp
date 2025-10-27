#include "CPlayer.h"
#include "CKeyMgr.h"
#include "pch.h"
#include "CCollider.h"
#include "CCamera.h"
#include "CTexture.h"
#include "CResMgr.h"
#include "CSceneMgr.h"
#include "CScene.h"
#include "CCollisionMgr.h"
#include "CObstacle.h"
#include "CDefalut.h"


CPlayer::CPlayer()
	: m_vStartPos(Vec2(0.f, 280.f))
	, m_bStarted(false)
	, m_bSecondJump(false)
	, m_dAcc(0.f)
	, m_dAccDis(0.f)
	, m_vCurPos(m_vStartPos)
	, m_vPrevPos(m_vStartPos)
	, m_pTex(nullptr)
	, m_iScore(0)
	, m_bCollision(false)
{
	CreateCollider();
	m_pTex = CResMgr::GetInst()->LoadTexture(L"playerTexture", L"ghost.bmp");
}

CPlayer::~CPlayer()
{
}

void CPlayer::update()
{
	m_vCurPos.x = CCamera::GetInst()->GetRealPos(Vec2(300.f, 0.f)).x;

	vector<CObject*> mongroup = CSceneMgr::GetInst()->GetCurScene()->GetGroupObject(GROUP_TYPE::MONSTER);
	vector<CObject*> defgroup = CSceneMgr::GetInst()->GetCurScene()->GetGroupObject(GROUP_TYPE::DEFALUT);

	CObstacle* pObj;
	CDefalut* pDft;

	for (int i = 0; i < mongroup.size(); i++)
	{

		pObj = (CObstacle*)(mongroup[i]);
		pDft = (CDefalut*)(defgroup[i]);

		if (CCollisionMgr::GetInst()->isCollision(this->GetCollider(), pDft->GetCollider()))
		{
			if (CCollisionMgr::GetInst()->isCollision(this->GetCollider(), pObj->GetCollider()))
			{
				m_bCollision = true;
			}
			pObj->collisionPlayer();
		}

		if (pDft->GetCollider()->IsCollisionExit())
		{
			if (m_bCollision)
			{
				m_iScore--;
			}
			else
			{
				m_iScore++;
			}
			m_bCollision = false;
		}
	}

	if (!m_bStarted && CKeyMgr::GetInst()->GetKeyState(KEY::SPACE) == KEY_STATE::TAP)
	{
		m_bStarted = true;
		jump();
	}
	else if (m_bStarted)
	{
		if (!m_bSecondJump && CKeyMgr::GetInst()->GetKeyState(KEY::SPACE) == KEY_STATE::TAP)
		{
 			m_bSecondJump = true;
			m_dAcc = 0.f;
		}

		jump();
	}
	


	SetPos(m_vCurPos);
	m_vPrevPos = m_vCurPos;
}
void CPlayer::jump()
{
	double dVal;
	m_dAcc += (m_vCurPos.x - m_vPrevPos.x);
	dVal = -1 * pow((m_dAcc - 100.f), 3) / 600.f;
	m_vCurPos.y -= (float)dVal * fDT;
	//dVal = -1 * pow((m_dAcc - 400.f), 3) / 64000.f;
	//dVal = 500.f * sin(2 * PI * m_dAcc / 300.f);

	if (m_bSecondJump)
	{
		if (m_dAcc >= 200.f)
		{
			m_dAccDis += dVal;
		}

		if (m_dAccDis <= 0.f)
		{
			m_bStarted = false;
			m_bSecondJump = false;
			m_dAcc = 0.f;
			m_dAccDis = 0.f;
			m_vCurPos.y = m_vStartPos.y;
		}
	}
	else
	{
		m_dAccDis += dVal;

		if (m_dAcc >= 200.f)
		{
			m_bStarted = false;
			m_dAcc = 0.f;
			m_vCurPos.y = m_vStartPos.y;
		}
	}
}


void CPlayer::render(HDC _dc)
{

	float iWidth = GetScale().x;
	float iHeight = GetScale().y;
	Vec2 vPos = CCamera::GetInst()->GetRenderPos(m_vCurPos);


	TransparentBlt(_dc
		, (int)(vPos.x - iWidth/2.f)
		, (int)(vPos.y - iHeight / 2.f)
		, (int)iWidth, (int)iHeight
		, m_pTex->GetDC()
		, 0, 0, m_pTex->GetWidth(), m_pTex->GetHeight()
		, RGB(255, 255, 255));

	GetCollider()->render(_dc);
}
