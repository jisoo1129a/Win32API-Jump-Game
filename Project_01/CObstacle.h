#pragma once
#include "CObject.h"
#include "CCollider.h"

class CTexture;

class CObstacle :
    public CObject
{
private:
    CTexture* m_pTex;
    UINT m_iType;
    UINT m_iHeight;

    bool m_bCollision;
public:
    virtual void SetPos(Vec2 _pos)
    {
        CObject::SetPos(_pos);
        GetCollider()->SetOffset(Vec2(0.f, 10.f));
    }

    UINT getType() { return m_iType; }
    UINT getHeight() { return m_iHeight; }
    bool getCollision() { return m_bCollision; }
    void collisionPlayer() { m_bCollision = true; }
    
public:
    virtual void update();
    virtual void render(HDC _dc);

public:
    CObstacle();
    ~CObstacle();
};

