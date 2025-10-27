#pragma once
#include "CObject.h"
#include "CCollider.h"

class CTexture;
class CCollider;

class CPlayer :
    public CObject
{
private:
    Vec2 m_vStartPos;
    Vec2 m_vPrevPos;
    Vec2 m_vCurPos;

    CTexture* m_pTex;

    bool m_bStarted;
    bool m_bSecondJump;
    double m_dAcc;
    double m_dAccDis;

    int m_iScore;
    bool m_bCollision;
public:
    void SetPos(Vec2 _pos)
    { 
        CObject::SetPos(_pos);
        GetCollider()->SetScale(Vec2(70.f, 70.f));
    }
    virtual void update();
    virtual void render(HDC _dc);

    int GetScore() { return m_iScore; }
    void AddScore() { m_iScore++; }
private:
    void jump();
public:
    CPlayer();
    ~CPlayer();
};

