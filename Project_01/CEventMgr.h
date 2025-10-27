#pragma once
#include "pch.h"

struct tEvent {
	EVENT_TYPE eType;
	DWORD_PTR lParam;
	DWORD_PTR wParam;
};

class CEventMgr
{
	vector<tEvent> m_vecEvent;

	void AddEvent(tEvent _e) { m_vecEvent.push_back(_e); }
};

