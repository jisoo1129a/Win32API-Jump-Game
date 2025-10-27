#pragma once
#include "CScene.h"
class CStage2 :
    public CScene
{
public:
    virtual void Enter();
    virtual void Exit();

public:
    CStage2();
    ~CStage2();
};

