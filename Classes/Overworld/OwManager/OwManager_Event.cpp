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
	
	if ( !m_controller )
	{
		CCLOG("[OwManager][EVENT_INIT][error]: m_controller is null");
		return;
	}

	if ( !m_eventManager )
	{
		CCLOG("[OwManager][EVENT_INIT][error]: m_eventManager is null");
		return;
	}

	CCLOG("[OwManager][EVENT_INIT]: Init" );
	m_controller->setDisabled(true);
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

	if ( m_controller ) 
		m_controller->update(dt);
	if ( m_dialog) 
		m_dialog->update(dt);
	if ( m_controlUI ) 
		m_controlUI->update(dt);
	if (m_eventManager )
		m_eventManager->update(dt);

}

void OwManager::EVENT_FREE()
{
	if ( !m_controller )
	{
		CCLOG("[OwManager][EVENT_FREE][error]: m_controller is null");
		return;
	}

	CCLOG("[OwManager][EVENT_FREE]: Free" );
	this->m_controller->setDisabled(false);
}

bool OwManager::EVENT_TO_NORMAL()
{
	if ( !m_eventManager )
	{
		CCLOG("[OwManager][EVENT_TO_NORMAL][error]: m_eventManager is null");
		return false;
	}

	return m_eventManager->isEmpty();

}