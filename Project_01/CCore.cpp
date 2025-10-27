#include "CCore.h"
#include "CSceneMgr.h"
#include "CKeyMgr.h"
#include "CCamera.h"
#include "CPathMgr.h"
#include "CCollisionMgr.h"

CCore::CCore()
	: m_bitmap(nullptr)
	, m_hDC(nullptr)
	, m_hWnd(nullptr)
	, m_memDC(nullptr)
	, m_ptResolution()
{

}
CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hDC);
	DeleteDC(m_memDC);
	DeleteObject(m_bitmap);
}

int CCore::init(HWND _hwnd, POINT _ptResolution)
{
	m_hWnd = _hwnd;
	m_ptResolution = _ptResolution;
	RECT rt = { 0, 0, m_ptResolution.x, m_ptResolution.y };

	AdjustWindowRect(&rt, WS_OVERLAPPED, true);
	SetWindowPos(m_hWnd, nullptr, 100, 25, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(m_hWnd);

	m_bitmap = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	m_memDC = CreateCompatibleDC(m_hDC);

	HBITMAP oldBitmap = (HBITMAP)SelectObject(m_memDC, m_bitmap);
	DeleteObject(oldBitmap);

	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();
	CPathMgr::GetInst()->init();
	CCamera::GetInst()->init();
	CSceneMgr::GetInst()->init();



	return S_OK;
}

void CCore::progress()
{
	CTimeMgr::GetInst()->update();
	CKeyMgr::GetInst()->update();
	CCamera::GetInst()->update();
	CSceneMgr::GetInst()->update();

	CCollisionMgr::GetInst()->update();

	


	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);

	CSceneMgr::GetInst()->render(m_memDC);

	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y, m_memDC, 0, 0, SRCCOPY);

	CTimeMgr::GetInst()->render();
}
