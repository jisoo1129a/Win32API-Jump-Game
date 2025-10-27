#pragma once
#include "pch.h"


enum class KEY_STATE
{
	NONE,
	TAP,
	HOLD,
	AWAY,
};

enum class KEY
{
	UP,
	DOWN,
	LEFT,
	RIGHT,

	ENTER,
	LSHIFT,
	SPACE,
	CTRL,

	LBTN,
	RBTN,

	Q, W, E, R, T, Y, U, I, O, P,
	A, S, D, F, G, H, J, K, L, Z,
	X, C, V, B, N, M,

	LAST,
};

struct KeyInfo
{
	KEY_STATE eKeyState;
	bool bPrevPress;
};

class CKeyMgr
{
	SINGLE(CKeyMgr);

private:
	vector<KeyInfo> m_vecKey;
	Vec2 m_curMousePos;

public:

	void init();
	void update();

	KEY_STATE GetKeyState(KEY _eKey)
	{
		return m_vecKey[(int)_eKey].eKeyState;
	}

	Vec2 GetMousePos()
	{
		return m_curMousePos;
	}
};

