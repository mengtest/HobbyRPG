#include "WorldManager.h"

#include "..\..\Events\EventBase.h"
#include "..\..\Events\EventManager.h"

#include "cocos2d.h"

USING_NS_CC;

void WorldManager::EVENT_INIT()
{
	CCLOG("[WorldManager][EVENT_INIT]: Init" );
	m_eventManager->start();
	m_isEvent = true;
}

void WorldManager::EVENT_UPDATE(float dt)
{
	m_eventManager->update(dt);
}

void WorldManager::EVENT_FREE()
{
	CCLOG("[WorldManager][EVENT_FREE]: Free" );
	m_isEvent = false;
}

bool WorldManager::EVENT_TO_NORMAL()
{
	if ( m_eventManager )
	{
		return m_eventManager->isEmpty();
	}

	return false;
}