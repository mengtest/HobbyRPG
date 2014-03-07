#ifndef __OWEVENTDELAY_H__
#define __OWEVENTDELAY_H__

#include <string>
#include "..\..\Events\EventBase.h"

class OwEntityBase;
class OwEventDelay : public EventBase
{
public:
	OwEventDelay(float delay, OwEntityBase * lhs = 0, OwEntityBase * rhs = 0);
	~OwEventDelay() {};

	void update(float dt);
	bool isDone();
	void init();
	void free();
	
private:
	OwEntityBase * m_lhs;
	OwEntityBase * m_rhs;

	float m_delay;
};

#endif