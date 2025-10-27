#include "CPannelUI.h"
#include "CKeyMgr.h"
#include "CCamera.h"
#include "CSceneMgr.h"
#include "CScene.h"
#include "CPlayer.h"

CPannelUI::CPannelUI()
	: CUI(false)
	, m_vPrevMousPos{}
{
}

CPannelUI::~CPannelUI()
{
}

void CPannelUI::update()
{

	Vec2 vMousePos = CKeyMgr::GetInst()->GetMousePos();
	

	if (IsMouseOn() && CKeyMgr::GetInst()->GetKeyState(KEY::LBTN) == KEY_STATE::HOLD)
	{
		SetPos(GetFinalPos() + (vMousePos - m_vPrevMousPos));
	}

	m_vPrevMousPos = vMousePos;
}

void CPannelUI::render(HDC _dc)
{
	CUI::render(_dc);
	Vec2 vpos = GetFinalPos();
	Vec2 vscale = GetScale();
	CPlayer* player = (CPlayer*)(CSceneMgr::GetInst()->GetCurScene()->GetGroupObject(GROUP_TYPE::PLAYER)[0]);
	int score = player->GetScore();

	

	wchar_t szBuffer[255] = {};
	swprintf_s(szBuffer, L"Score: %d", score);
	
	TextOut(_dc, (int)(vpos.x - vscale.x/2.f), (int)(vpos.y - vscale.y/2.f), szBuffer, lstrlen(szBuffer));

}


