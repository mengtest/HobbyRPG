#include "OwManager.h"

#include "..\..\Events\EventBase.h"
#include "..\..\Events\EventManager.h"

#include "..\OwPlayerController\OwPlayerController.h"
#include "cocos2d.h"

USING_NS_CC;

void OwManager::PAUSE_INIT()
{
	CCLOG("[OwManager][PAUSE_INIT]: Init" );
	this->m_controller->setDisabled(true);
}

void OwManager::PAUSE_UPDATE(float dt)
{
}

void OwManager::PAUSE_FREE()
{
	CCLOG("[OwManager][PAUSE_FREE]: Free" );
	this->m_controller->setDisabled(false);
}

bool OwManager::PAUSE_TO_NORMAL()
{
	return !m_isPaused;
}