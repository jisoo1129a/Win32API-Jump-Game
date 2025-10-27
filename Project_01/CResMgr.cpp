#include "CResMgr.h"
#include "CPathMgr.h"
#include "CTexture.h"

CResMgr::CResMgr()
{

}
CResMgr::~CResMgr()
{

}

CTexture* CResMgr::LoadTexture(const wstring& _strKey, const wstring& _strRelativePath)
{
	CTexture* pTex = FindTexture(_strKey);
	if (pTex != nullptr)
		return pTex;

	pTex = new CTexture;

	wstring strPath = CPathMgr::GetInst()->GetContentPath();
	strPath += _strRelativePath;
	pTex->Load(strPath);

	pTex->SetKey(_strKey);
	pTex->SetRelativePath(_strRelativePath);

	m_mapTex.insert(make_pair(_strKey, pTex));

	return pTex;
}

CTexture* CResMgr::CreateTexture(const wstring& _strKey, UINT _width, UINT _height)
{
	CTexture* pTex = FindTexture(_strKey);
	if (pTex != nullptr)
		return pTex;

	pTex = new CTexture;

	pTex->Create(_width, _height);
	pTex->SetKey(_strKey);

	m_mapTex.insert(make_pair(_strKey, pTex));

	return pTex;
}

CTexture* CResMgr::FindTexture(const wstring _strKey)
{
	map<wstring, CRes*>::iterator iter = m_mapTex.find(_strKey);
	if (iter == m_mapTex.end())
		return nullptr;

	return (CTexture*)iter->second;
}
