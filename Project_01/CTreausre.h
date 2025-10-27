#pragma once
#include "CObject.h"
class CTreausre :
    public CObject
{
private:
    float m_fAccTime;
    float m_fTime; //stay the same location

public:
    virtual void update();
    //virtual void render(HDC _dc);

public:
    CTreausre();
    ~CTreausre();
};

