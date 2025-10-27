#pragma once
#include "pch.h"

class CCamera
{
	SINGLE(CCamera);

private:
	Vec2 m_vLookAt; //where camera wants to see
	Vec2 m_vPrevLook; //where camera see previous frame
	Vec2 m_vCurLook; //where camera see currently

	Vec2 m_vDiff; //difference btw current coordinate and moving point one
	float m_fSpeed;
	float m_fAccTime;
	float m_fTime; //how much time takes to go to the point

public:
	void SetLookAt(Vec2 _vlookAt)
	{
		m_vLookAt = _vlookAt;
		m_fSpeed = (m_vLookAt - m_vPrevLook).Length() / m_fTime;
		m_fAccTime = 0;
	}
	Vec2 GetRenderPos(Vec2 _vPos)
	{
		return _vPos - m_vDiff;
	}
	Vec2 GetRealPos(Vec2 _vRenderPos)
	{
		return _vRenderPos + m_vDiff;
	}

public:
	void init();
	void update();
	void render(HDC _dc);

private:
	void CalDiff();
};

