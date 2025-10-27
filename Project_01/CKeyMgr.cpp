#include "CKeyMgr.h"

int Key[(int)KEY::LAST] = {
	VK_UP,
	VK_DOWN,
	VK_LEFT,
	VK_RIGHT,

	VK_RETURN,
	VK_LSHIFT,
	VK_SPACE,
	VK_CONTROL,

	VK_LBUTTON,
	VK_RBUTTON,

	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
	'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z',
	'X', 'C', 'V', 'B', 'N', 'M',
};

CKeyMgr::CKeyMgr()
	:m_curMousePos{}
{

}

CKeyMgr::~CKeyMgr()
{
}

void CKeyMgr::init()
{
	for (int i = 0; i < (int)KEY::LAST; i++)
	{
		m_vecKey.push_back(KeyInfo{ KEY_STATE::NONE, false });
	}
}

void CKeyMgr::update()
{
	HWND hWnd = GetFocus();
	if (hWnd != nullptr)
	{
		for (int i = 0; i < (int)KEY::LAST; i++)
		{
			if (GetAsyncKeyState(Key[i]) & 0x8000)
			{
				if (m_vecKey[i].bPrevPress)
				{
					m_vecKey[i].eKeyState = KEY_STATE::HOLD;
				}
				else
				{
					m_vecKey[i].eKeyState = KEY_STATE::TAP;
				}
				m_vecKey[i].bPrevPress = true;
			}
			else
			{
				if (m_vecKey[i].bPrevPress)
				{
					m_vecKey[i].eKeyState = KEY_STATE::AWAY;
				}
				else
				{
					m_vecKey[i].eKeyState = KEY_STATE::NONE;
				}
				m_vecKey[i].bPrevPress = false;
			}
		}
		POINT ptPos = {};
		GetCursorPos(&ptPos);
		ScreenToClient(CCore::GetInst()->GetMainHwnd(), &ptPos);
		m_curMousePos = Vec2((float)ptPos.x, (float)ptPos.y);
	}
	else
	{
		for (int i = 0; i < (int)KEY::LAST; i++)
		{
			if (m_vecKey[i].bPrevPress)
			{
				m_vecKey[i].eKeyState = KEY_STATE::AWAY;
			}
			else
			{
				m_vecKey[i].eKeyState = KEY_STATE::NONE;
			}
		}
	}
}
