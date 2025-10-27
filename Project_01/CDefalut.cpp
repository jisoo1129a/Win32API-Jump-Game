#include "CDefalut.h"
#include "CCollider.h"
#include "CCamera.h"

CDefalut::CDefalut(bool _visiblity)
	:m_bVisible(_visiblity)
{
	CreateCollider();
}

CDefalut::~CDefalut()
{
}

void CDefalut::update()
{
}

void CDefalut::render(HDC _dc)
{
	if (m_bVisible)
	{
		Vec2 vPos = GetPos();
		Vec2 vScale = GetScale();

		vPos = CCamera::GetInst()->GetRenderPos(vPos);

		Rectangle(_dc,
			(int)(vPos.x - vScale.x / 2.f),
			(int)(vPos.y - vScale.y / 2.f),
			(int)(vPos.x + vScale.x / 2.f),
			(int)(vPos.y + vScale.y / 2.f)
		);
	}

	GetCollider()->render(_dc);
}
