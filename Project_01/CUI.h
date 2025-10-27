#pragma once
#include "CObject.h"

class CUI :
    public CObject
{
private:
    vector<CUI*> m_vecChildren;
    CUI* m_pParent;
    Vec2 m_vFinalPos;

    bool m_bMouseOn;
    bool m_bLbtnDown;
    bool m_bCamAffected;

public:
    void AddChild(CUI* _child) { m_vecChildren.push_back(_child); }
    
    bool IsLbtnDown() { return m_bLbtnDown; }
    bool IsMouseOn() { return m_bMouseOn; }
    CUI* GetParent() { return m_pParent; }
    Vec2 GetFinalPos() { return m_vFinalPos; }

public:
    void MouseOnCheck();
    void MouseOn();
    void MouseLbtnDown();
    void MouseLbtnUp();

    void child_update();
    void child_finalUpdate();
    void child_render(HDC _dc);

    virtual void update();
    virtual void finalUpdate();
    virtual void render(HDC _dc);

public:
    CUI(bool _bCamAff);
    CUI(CUI* _orgin);
    ~CUI();
};

