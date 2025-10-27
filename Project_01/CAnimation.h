#pragma once
#include "pch.h"

struct tAnimFrm
{
	Vec2 vLT;
	Vec2 vSliceSize;
	Vec2 vOffset;
	float fDuration;
};

class CAnimator;
class CTexture;

class CAnimation
{
private:
	wstring m_strName;
	CAnimator* m_pAnimator;
	CTexture* m_pTexture;
	vector<tAnimFrm> m_vecFrm;

	int m_iCurFrm;
	float m_fAccTime;
	bool m_bFinished;

public:
	void update();
	void render(HDC _dc);

public:
	const wstring& getName() { return m_strName; }
	tAnimFrm& getFrm(int _iIdx) { return m_vecFrm[_iIdx]; }
	UINT getMaxFrm() { return (UINT)m_vecFrm.size(); }
	bool IsFinished() { return m_bFinished; }

	void setName(const wstring& _strName) { m_strName = _strName; }
	void setAnimator(CAnimator* _pAnim) { m_pAnimator = _pAnim; }
	void setFrame(int _iIdx)
	{
		m_bFinished = false;
		m_fAccTime = 0.f;
		m_iCurFrm = _iIdx;
	}

	void Create(CTexture* _texture, Vec2 _vLT, Vec2 _vSilceSize, Vec2 _vStep, float _fDuration, UINT _iFrmCount);

public:
	CAnimation();
	~CAnimation();

};

