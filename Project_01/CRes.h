#pragma once
#include "pch.h"
class CRes
{
private:
	wstring m_strKey; //resource key
	wstring m_strRelativePath; //resource relative path

public:
	const wstring& GetKey() { return m_strKey; }
	const wstring& GetRelativePath() { return m_strRelativePath; }

	void SetKey(const wstring& _key) { m_strKey = _key; }
	void SetRelativePath(const wstring& _relativePath) { m_strRelativePath = _relativePath; }

public:
	CRes();
	~CRes();
};

