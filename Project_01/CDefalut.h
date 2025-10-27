#pragma once
#include "CObject.h"
#include "CCollider.h"

class CDefalut :
    public CObject
{
private:
    bool m_bVisible;

public:
    virtual void update();
    virtual void render(HDC _dc);
    virtual void SetPos(Vec2 _pos)
    {
        CObject::SetPos(_pos);
        GetCollider()->SetOffset(Vec2(0.f, 10.f));
    }
public:
    CDefalut(bool _visiblity);
    ~CDefalut();
};

