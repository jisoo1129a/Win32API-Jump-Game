#include "CAnimator.h"
#include "CAnimation.h"

CAnimator::CAnimator()
	: m_pOwner(nullptr)
	, m_bRepeat(false)
	, m_pCurAnim(nullptr)
{
}

CAnimator::~CAnimator()
{
}

void CAnimator::update()
{
}

void CAnimator::render(HDC _dc)
{
	if (nullptr != m_pCurAnim)
		m_pCurAnim->render(_dc);
}

void CAnimator::finalUpdate()
{
	if (m_pCurAnim != nullptr)
	{
		m_pCurAnim->update();
		if (m_bRepeat && m_pCurAnim->IsFinished())
		{
			m_pCurAnim->setFrame(0);
		}
	}
		
}

void CAnimator::play(wstring& _strKey, bool _bRepeat)
{
	m_pCurAnim = findAnimation(_strKey);
	m_bRepeat = _bRepeat;
}

CAnimation* CAnimator::findAnimation(const wstring& _strKey)
{
	map<wstring, CAnimation*>::iterator iter = m_mapAnim.find(_strKey);

	if (m_mapAnim.end() == iter)
		return nullptr;
	return iter->second;
}

void CAnimator::CreateAnimaton(const wstring& _strName, CTexture* _pTex, Vec2 _vLT, Vec2 _vSlice, Vec2 _vStep, float _fDuration, UINT _iFrmCount)
{
	CAnimation* pAnim = findAnimation(_strName);
	if (pAnim != nullptr)
		return;

	pAnim = new CAnimation();
	pAnim->setName(_strName);
	pAnim->Create(_pTex, _vLT, _vSlice, _vStep, _fDuration, _iFrmCount);
	pAnim->setAnimator(this);

	m_mapAnim.insert(make_pair(_strName, pAnim));
}


