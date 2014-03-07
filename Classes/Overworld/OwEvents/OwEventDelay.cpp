#include "OwEventDelay.h"
#include "../OwManager/OwManager.h"
#include "../OwDialogUI/OwDialogUI.h"
#include "../OwEntities/OwEntityBase.h"

#include "cocos2d.h"

USING_NS_CC;
/****************************************************
If rhs and lhs are null, that means that the callee
is probably some world event. If not, it should be
the normal conversation-type event
****************************************************/


OwEventDelay::OwEventDelay(float delay, OwEntityBase * lhs, OwEntityBase * rhs)
	: m_lhs(lhs), m_rhs(rhs), m_delay(delay)
{
	m_bIsDone = false;
}

void OwEventDelay::update(float dt)
{
	m_delay -= dt;
	if (m_delay < 0 )
	{
		m_bIsDone = true;
	}

}

void OwEventDelay::init()
{
	CCLOG("[OwEventDelay][init]: Initialized!");
	
	if ( m_lhs )
		m_lhs->callback("pause",0);
	if ( m_rhs )
		m_rhs->callback("pause",0);
}

void OwEventDelay::free()
{
	CCLOG("[OwEventDelay][free]: Free!");
	if ( m_lhs )
		m_lhs->callback("play",0);
	if ( m_rhs )
		m_rhs->callback("play",0);
}

bool OwEventDelay::isDone()
{
	return m_bIsDone;
}