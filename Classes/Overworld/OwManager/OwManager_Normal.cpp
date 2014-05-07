#include "OwManager.h"
#include "..\..\Events\EventManager.h"

#include "..\OwPlayerController\OwPlayerController.h"
#include "..\OwDialogUI\OwDialogUI.h"
#include "..\OwControlUI\OwControlUITypeB.h"
#include "..\OwEntities\OwAICharacter.h"

void OwManager::NORMAL_UPDATE(float dt)
{
	AIListType::iterator beg = m_aiList.begin();
	AIListType::iterator end = m_aiList.end();
	for(; beg != end ; ++beg)
	{
		(*beg).second->update(dt);
	}

	if ( m_controller )
		m_controller->update(dt);
	if ( m_dialog ) 
		m_dialog->update(dt);
	if (m_controlUI )
		m_controlUI->onUpdate(dt);
}

bool OwManager::NORMAL_TO_EVENT()
{
	if ( !m_eventManager )
	{
		CCLOG("[OwManager][EVENT_TO_NORMAL][error]: m_eventManager is null");
		return false;
	}

	return !m_eventManager->isEmpty();
}

bool OwManager::NORMAL_TO_PAUSE()
{
	return m_isPaused;
}