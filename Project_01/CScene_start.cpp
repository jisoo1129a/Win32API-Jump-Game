#include "CScene_start.h"
#include "CObject.h"
#include "CKeyMgr.h"
#include "CPlayer.h"
#include "CObstacle.h"
#include "CCollisionMgr.h"
#include "CCollider.h"
#include "CAnimator.h"
#include "CDefalut.h"
#include "CCamera.h"
#include "CUI.h"
#include "CPannelUI.h"

CScene_start::CScene_start()
{
}

CScene_start::~CScene_start()
{
}

void CScene_start::Enter()
{
	CObject* pObj = new CPlayer();
	pObj->SetPos(Vec2(0.f, 300.f));
	pObj->SetScale(Vec2(100.f, 100.f));

	AddObject(pObj, GROUP_TYPE::PLAYER);
	
	int rHeight;
	int ObsNum = 50;
	int accDis = 100;

	CObstacle* pObt;
	CDefalut* pDft;

	for (int i = 0; i < ObsNum; i++)
	{

		pObt = new CObstacle();
		pDft = new CDefalut(false);

		rHeight = pObt->getHeight() / 3;
		pObt->SetPos(Vec2((float)accDis, 330.f - rHeight/2.f));
		pObt->SetScale(Vec2(60.f, (float)rHeight));
		pObt->GetCollider()->SetScale(pObt->GetScale() - Vec2(15.f, 10.f));

		pDft->SetPos(Vec2((float)accDis, 330.f - rHeight / 2.f));
		pDft->SetScale(Vec2(60.f, 1000.f));
		pDft->GetCollider()->SetScale(pDft->GetScale() - Vec2(0.f, 10.f));

		accDis += rand() % 500 + 200 + 60;

		AddObject((CObject*)pObt, GROUP_TYPE::MONSTER);
		AddObject((CObject*)pDft, GROUP_TYPE::DEFALUT);
	}
	Vec2 vRes = CCore::GetInst()->GetResolution();
	Vec2 vPos = CCamera::GetInst()->GetRealPos(Vec2(0.f, 0.f));

	//CObject* pDefalut = new CDefalut();
	//pDefalut->SetPos(Vec2(vPos.x + vRes.x, 340.f));
	//pDefalut->SetScale(Vec2((float)accDis + vRes.x / 2.f , 20.f));
	//AddObject(pDefalut, GROUP_TYPE::DEFALUT);

	CObject* pUI = new CPannelUI;
	pUI->SetPos(Vec2(600.f, 100.f));
	pUI->SetScale(Vec2(100.f, 50.f));
	AddObject(pUI, GROUP_TYPE::UI);

	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::DEFALUT);
}

void CScene_start::Exit()
{
	//clear vector
}

