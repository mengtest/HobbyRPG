
#include "../OwEntities/OwAICharacter.h"
#include "OwAIMove.h"



OwAIMove::OwAIMove(DirectionEnum direction, int steps)
	: m_direction(direction), m_nSteps(steps), m_nStepsCount(0)
{

}

void OwAIMove::update(float dt)
{
	if ( getController() )
	{
		if ( m_nStepsCount < m_nSteps && !m_controller->isMoving() )
		{
			//Log::getInstance().log("OwAIMove", "Start Moving Left");
			if ( m_controller->move(m_direction) )
			{
				++m_nStepsCount;
			}
		}
	}
}

bool OwAIMove::isDone()
{
	if ( getController() ) 
	{
		if ( m_nStepsCount >= m_nSteps && !m_controller->isMoving() ) 
		{
			//Log::getInstance().log("OwAIMove", "Stop Moving Left");
			m_nStepsCount = 0;
			return true;
		}
	}
	return false;
}
