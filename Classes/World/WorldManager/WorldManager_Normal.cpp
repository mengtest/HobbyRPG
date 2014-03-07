#include "WorldManager.h"
#include "..\..\Events\EventManager.h"

bool WorldManager::NORMAL_TO_EVENT()
{
	if ( m_eventManager )
	{
		return !m_eventManager->isEmpty();
	}

	return false;
}