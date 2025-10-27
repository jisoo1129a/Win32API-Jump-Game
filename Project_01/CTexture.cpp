#include "CTexture.h"
#include "pch.h"

CTexture::CTexture()
	: m_hDC(0)
	, m_hBit(0)
	, m_bitInfo{}
{
}

CTexture::~CTexture()
{
}

void CTexture::Load(const wstring& _strFilePath)
{
	//create bitmap based on the file
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	//create dc to connect with bitmap
	m_hDC = CreateCompatibleDC(CCore::GetInst()->GetMainDC());

	//connect bitmap and dc
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_hDC, m_hBit);
	DeleteObject(hPrevBit);

	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);

	assert(m_hBit);
}

void CTexture::Create(UINT _width, UINT _height)
{
	HDC pMainDC = CCore::GetInst()->GetMainDC();
	m_hBit = CreateCompatibleBitmap(pMainDC, _width, _height);
	m_hDC = CreateCompatibleDC(pMainDC);

	HBITMAP pOldBit = (HBITMAP)SelectObject(m_hDC, m_hBit);
	DeleteObject(pOldBit);

	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);
}