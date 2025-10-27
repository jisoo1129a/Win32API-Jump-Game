#pragma once

#define SINGLE(type) public:\
						static type* GetInst()\
						{\
							static type pObject;\
							return &pObject;\
						}\
					private:\
						type();\
						~type();


#define fDT CTimeMgr::GetInst()->GetfDT();
#define DT CTimeMgr::GetInst()->GetDT();

#define PI 3.141592


enum class GROUP_TYPE
{
	DEFALUT,
	PLAYER,
	MONSTER,
	MISSILE,

	UI = 31,
	END = 32,
};
enum class SCENE_TYPE
{
	START_SCENE,
	STAGE_01,
	STAGE_02,
	STAGE_03,

	END,
};

enum class EVENT_TYPE
{
	SCENE_CHANGE,
	DELETE_OBJECT,
	CREATE_OBJECT,

	END,
};