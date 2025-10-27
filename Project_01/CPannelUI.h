#pragma once
#include "CUI.h"

class CPannelUI :
    public CUI
{
private:
    Vec2 m_vPrevMousPos;

public:
    virtual void update();
    virtual void render(HDC _dc);

public:
    CPannelUI();
    ~CPannelUI();
};

