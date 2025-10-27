#include "CUI.h"
#include "CKeyMgr.h"
#include "CCamera.h"

CUI::CUI(bool _bCamAff)
	: m_bCamAffected(_bCamAff)
	, m_bLbtnDown(false)
	, m_bMouseOn(false)
	, m_pParent(nullptr)
	, m_vFinalPos()
	, m_vecChildren()
{
}

CUI::CUI(CUI* _orgin)
	: m_bCamAffected(_orgin->m_bCamAffected)
	, m_bLbtnDown(false)
	, m_bMouseOn(false)
	, m_pParent(nullptr)
	, m_vFinalPos()
{
	for (size_t i = 0; i < _orgin->m_vecChildren.size(); i++)
	{
		//_orgin->m_vecChildren[i]->clone();
	}
}

CUI::~CUI()
{
}


void CUI::MouseOnCheck()
{
	Vec2 vMousePos = CKeyMgr::GetInst()->GetMousePos();
	Vec2 vScale = GetScale();
	Vec2 vPos = m_vFinalPos;

	if (m_bCamAffected)
		vPos = CCamera::GetInst()->GetRealPos(m_vFinalPos);

	if (vPos.x - vScale.x <= vMousePos.x && vPos.x + vScale.x >= vMousePos.x
		&& vPos.y - vScale.y <= vMousePos.y && vPos.y + vScale.y >= vMousePos.y)
	{
		m_bMouseOn = true;
	}
	else
	{
		m_bMouseOn = false;
	}
}

void CUI::MouseOn()
{
}

void CUI::MouseLbtnDown()
{
}

void CUI::MouseLbtnUp()
{
}

void CUI::update()
{
	child_update();
}

void CUI::finalUpdate()
{
	CObject::finalUpdate();

	m_vFinalPos = GetPos();

	CUI* pParent = GetParent();

	if (pParent != nullptr)
		m_vFinalPos += pParent->GetFinalPos();

	MouseOnCheck();

	child_finalUpdate();
}

void CUI::render(HDC _dc)
{
	Vec2 vPos = m_vFinalPos;
	Vec2 vScale = GetScale();

	if (m_bCamAffected)
		vPos = CCamera::GetInst()->GetRenderPos(vPos);

	HBRUSH hollowBrush = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	HBRUSH oldBrush = (HBRUSH)SelectObject(_dc, hollowBrush);

	if (m_bMouseOn)
	{
		HPEN pPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(_dc, pPen);

		Rectangle(_dc,
			(int)(vPos.x - vScale.x),
			(int)(vPos.y - vScale.y),
			(int)(vPos.x + vScale.x),
			(int)(vPos.y + vScale.y));

		SelectObject(_dc, oldPen);
		DeleteObject(pPen);
	}
	else
	{
		Rectangle(_dc,
			(int)(vPos.x - vScale.x),
			(int)(vPos.y - vScale.y),
			(int)(vPos.x + vScale.x),
			(int)(vPos.y + vScale.y));
	}

	(HBRUSH)SelectObject(_dc, oldBrush);

	child_render(_dc);
}


void CUI::child_update()
{
	for (size_t i = 0; i < m_vecChildren.size(); i++)
	{
		m_vecChildren[i]->update();
	}
}

void CUI::child_finalUpdate()
{
	for (size_t i = 0; i < m_vecChildren.size(); i++)
	{
		m_vecChildren[i]->finalUpdate();
	}
}

void CUI::child_render(HDC _dc)
{
	for (size_t i = 0; i < m_vecChildren.size(); i++)
	{
		m_vecChildren[i]->render(_dc);
	}
}



