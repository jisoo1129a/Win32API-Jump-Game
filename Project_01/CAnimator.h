#pragma once
#include "pch.h"

class CObject;
class CAnimation;
class CTexture;

class CAnimator
{
private:
	CObject* m_pOwner;
	CAnimation* m_pCurAnim;
	map<wstring, CAnimation*> m_mapAnim;

	bool m_bRepeat;

public:
	void update();
	void render(HDC _dc);
	void finalUpdate();

	void play(wstring& _strKey, bool _bRepeat);
	CAnimation* findAnimation(const wstring& _strName);
	void CreateAnimaton(const wstring& _strName, CTexture* _pTex, Vec2 _vLT, Vec2 _vSlice, Vec2 _vStep, float _fDuration, UINT _iFrmCount);
public:
	CObject* getOwner() { return m_pOwner; }

	void setOwner(CObject* _pOwner) { m_pOwner = _pOwner; }
public:
	CAnimator();
	~CAnimator();

	friend class CObject;
};

