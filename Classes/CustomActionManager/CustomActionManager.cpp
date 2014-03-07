#include "CustomActionManager.h"

CustomActionManager::CustomActionManager()
{

}

CustomActionManager::~CustomActionManager()
{

}

void CustomActionManager::stepUpdate(float dt)
{
	cocos2d::CCActionManager::update(dt);
}