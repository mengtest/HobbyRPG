#include "OwManager.h"

#include "..\..\Events\EventBase.h"
#include "..\..\Events\EventManager.h"

#include "..\OwPlayerController\OwPlayerController.h"
#include "..\OwDialogUI\OwDialogUI.h"
#include "..\OwControlUI\OwControlUITypeB.h"
#include "..\OwEntities\OwAICharacter.h"

#include "cocos2d.h"

USING_NS_CC;

void OwManager::EVENT_INIT()
{
	CCLOG("[OwManager][EVENT_INIT]: Init" );
	this->m_controller->setDisabled(true);
	m_eventManager->start();
}

void OwManager::EVENT_UPDATE(float dt)
{
	AIListType::iterator beg = m_aiList.begin();
	AIListType::iterator end = m_aiList.end();
	for(; beg != end ; ++beg)
	{
		(*beg).second->update(dt);
	}

	m_controller->update(dt);
	m_dialog->update(dt);
	m_controlUI->update(dt);

	m_eventManager->update(dt);

}

void OwManager::EVENT_FREE()
{
	CCLOG("[OwManager][EVENT_FREE]: Free" );
	this->m_controller->setDisabled(false);
}

bool OwManager::EVENT_TO_NORMAL()
{
	if ( m_eventManager )
	{
		return m_eventManager->isEmpty();
	}

	return false;
}