#include "CCollisionMgr.h"
#include "pch.h"
#include "CScene.h"
#include "CObject.h"
#include "CSceneMgr.h"
#include "CCollider.h"

CCollisionMgr::CCollisionMgr()
	: m_arrCheck()
	, m_mapColInfo()
{

}
CCollisionMgr::~CCollisionMgr()
{

}


void CCollisionMgr::init()
{
}

void CCollisionMgr::update()
{
	for (UINT iRow = 0; iRow < (UINT)GROUP_TYPE::END; iRow++)
	{
		for (UINT iCol = iRow; iCol < (UINT)GROUP_TYPE::END; iCol++)
		{
			if (m_arrCheck[iRow] & (1 << iCol))
			{
				CollisionUpdate((GROUP_TYPE)iRow, (GROUP_TYPE)iCol);
			}
		}
	}
}

void CCollisionMgr::CheckGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight)
{
	UINT iRow = (UINT)_eLeft;
	UINT iCol = (UINT)_eRight;

	if (iRow > iCol)
	{
		iRow = (UINT)_eRight;
		iCol = (UINT)_eLeft;
	}

	if (m_arrCheck[iRow] & (1 << iCol))
	{
		m_arrCheck[iRow] &= ~(1 << iCol);
	}
	else
	{
		m_arrCheck[iRow] |= (1 << iCol);
	}

}

void CCollisionMgr::reset()
{
	memset(m_arrCheck, 0, sizeof(int) * 32);
}

void CCollisionMgr::CollisionUpdate(GROUP_TYPE _eLeft, GROUP_TYPE _eRight)
{
	CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();
	vector<CObject*>& leftObj = pCurScene->GetGroupObject(_eLeft);
	vector<CObject*>& rightObj = pCurScene->GetGroupObject(_eRight);

	map<ULONGLONG, bool>::iterator iter;

	for (size_t i = 0; i < leftObj.size(); i++)
	{
		if (leftObj[i]->GetCollider() == nullptr)
		{
			continue;
		}
		for (size_t j = 0; j < rightObj.size(); j++)
		{
			if (rightObj[j]->GetCollider() == nullptr || rightObj[j] == leftObj[i])
			{
				continue;
			}
			else
			{
				CCollider* pLeftCollider = leftObj[i]->GetCollider();
				CCollider* pRightCollider = rightObj[j]->GetCollider();

				COLLIDER_ID ID{};
				ID.iLeft = pLeftCollider->GetID();
				ID.iRight = pRightCollider->GetID();
				
				iter = m_mapColInfo.find(ID.ID);
				if (iter == m_mapColInfo.end())
				{
					m_mapColInfo.insert(make_pair(ID.ID, false));
					iter = m_mapColInfo.find(ID.ID);
				}

				if (isCollision(pLeftCollider, pRightCollider))
				{
					if (iter->second)
					{
						pLeftCollider->OnCollision();
						pRightCollider->OnCollision();

					}
					else
					{
						pLeftCollider->OnCollisionEnter();
						pRightCollider->OnCollisionEnter();
						iter->second = true;
					}
				}
				else
				{
					if (iter->second)
					{
						pLeftCollider->OnCollisionExit();
						pRightCollider->OnCollisionExit();
						pLeftCollider->SetCollisionExit(true);
						pRightCollider->SetCollisionExit(true);
						iter->second = false;
					}
					else
					{
						pLeftCollider->SetCollisionExit(false);
						pRightCollider->SetCollisionExit(false);
					}
				}
			}
		}
	}
}

bool CCollisionMgr::isCollision(CCollider* _pLeft, CCollider* _pRight)
{
	Vec2 vLPos = _pLeft->GetPos();
	Vec2 vRPos = _pRight->GetPos();
	Vec2 vLScale = _pLeft->GetScale();
	Vec2 vRScale = _pRight->GetScale();
	if (abs(vLPos.x - vRPos.x) < (vLScale.x + vRScale.x) / 2.f
		&& abs(vLPos.y - vRPos.y) < (vLScale.y + vRScale.y) / 2.f)
	{
		return true;
	}

	return false;
}
