#include "CTimeMgr.h"

CTimeMgr::CTimeMgr()
	: m_dAcc(0)
	, m_dDT(0)
	, m_iCallCount(0)
	, m_iFPS(0)
	, m_llPreCount{}
	, m_llCurCount{}
	, m_llFrequency{}
{

}

CTimeMgr::~CTimeMgr()
{

}

void CTimeMgr::init()
{
	//current count number
	QueryPerformanceCounter(&m_llPreCount);

	//how many count in a second
	QueryPerformanceFrequency(&m_llFrequency);
}

void CTimeMgr::update()
{
	QueryPerformanceCounter(&m_llCurCount);
	m_dDT = (double)(m_llCurCount.QuadPart - m_llPreCount.QuadPart) / (double)m_llFrequency.QuadPart;
	m_llPreCount = m_llCurCount;
}

void CTimeMgr::render()
{
	m_iCallCount++;
	m_dAcc += m_dDT;
	if (m_dAcc >= 1.f)
	{
		m_iFPS = m_iCallCount;
		m_iCallCount = 0;
		m_dAcc = 0;

		//wchar_t szBuffer[255] = {};
		//swprintf_s(szBuffer, L"FPS: %d, DT: %f", m_iFPS, m_dDT);
		//SetWindowText(CCore::GetInst()->GetMainHwnd(), szBuffer);
	}
}
