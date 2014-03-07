#pragma once

#include "CCApplication.h"
#include "actions\CCActionManager.h"

class CustomActionManager : public cocos2d::CCActionManager
{
public:
	CustomActionManager();
	~CustomActionManager();
	void stepUpdate(float dt);
};