#ifndef __OwAIMove_H__
#define __OwAIMove_H__

#include "OwAICommand.h"
#include "../../Common/Common.h"
#include "../../Enum/DirectionEnum.h"

class OwAIMove : public OwAICommand
{
public:
	OwAIMove(DirectionEnum direction, int steps);
	void update(float dt);
	bool isDone();

private:
	int m_nSteps;
	int m_nStepsCount;
	DirectionEnum m_direction;
	
};

#endif