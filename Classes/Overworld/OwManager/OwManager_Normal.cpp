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

	m_controller->update(dt);
	m_dialog->update(dt);
	m_controlUI->onUpdate(dt);
}

bool OwManager::NORMAL_TO_EVENT()
{
	if ( m_eventManager )
	{
		return !m_eventManager->isEmpty();
	}

	return false;
}

bool OwManager::NORMAL_TO_PAUSE()
{
	return m_isPaused;
}