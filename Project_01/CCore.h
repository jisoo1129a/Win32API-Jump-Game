#pragma once
#include "pch.h"

class CCore
{
	SINGLE(CCore);

private:
	HWND m_hWnd;
	POINT m_ptResolution;
	HDC m_hDC;

	HBITMAP m_bitmap;
	HDC m_memDC;
public:
	int init(HWND _hwnd, POINT _ptResolution);
	void progress();
public:
	HWND GetMainHwnd()
	{
		return m_hWnd;
	}
	Vec2 GetResolution()
	{
		return m_ptResolution;
	}
	HDC GetMainDC()
	{
		return m_hDC;
	}
};

