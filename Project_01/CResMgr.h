#pragma once
#include "pch.h"

class CRes;
class CTexture;

class CResMgr
{
	SINGLE(CResMgr);
private:
	map<wstring, CRes*> m_mapTex;

public:
	CTexture* LoadTexture(const wstring& _strKey, const wstring& _strRelativePath);
	CTexture* CreateTexture(const wstring& _strKey, UINT _width, UINT _height);
	CTexture* FindTexture(const wstring _strKey);
};

