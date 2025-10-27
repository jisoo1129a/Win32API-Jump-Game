#pragma once
#include "pch.h"
class CTimeMgr
{
	SINGLE(CTimeMgr);

private:
	LARGE_INTEGER m_llCurCount;
	LARGE_INTEGER m_llPreCount;
	LARGE_INTEGER m_llFrequency;

	double m_dDT; //time between each frames
	double m_dAcc;//accumulated time for checking 1 second
	UINT m_iCallCount;//number of call in a second
	UINT m_iFPS;//number of call in a second

public:
	void init();
	void update();
	void render();

public:
	double GetDT() { return m_dDT; }
	float GetfDT() { return (float)m_dDT; }
};

