#pragma once
#include "CRes.h"

class CTexture :
    public CRes
{
private:
    HDC m_hDC; //where picture put in
    HBITMAP m_hBit; //where picture draw
    BITMAP m_bitInfo; //bitmap information

public:
    void Load(const wstring& _strFilePath);
    void Create(UINT _width, UINT _height);

public:
    UINT GetWidth() { return m_bitInfo.bmWidth; }
    UINT GetHeight() { return m_bitInfo.bmHeight; }
    HDC GetDC() { return m_hDC; }
public:
    CTexture();
    virtual ~CTexture();

    friend class CRes;
};

