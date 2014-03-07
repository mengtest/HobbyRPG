#include "OwControlUITypeA.h"
#include "..\OwPlayerController\OwPlayerController.h"


USING_NS_CC;

OwControlUITypeA::OwControlUITypeA( OwPlayerController * player_controller) 
	: m_playerController ( player_controller ), m_fInteractDuration(0.1f),
	m_moveDirection(0)
{

}


bool OwControlUITypeA::onInit() { 

	if (!m_playerController )
	{
		CCLOG("[OwControlUITypeA][onInit]: No player controller assigned");
		return false;
	}
	
	
	return true; 

}

void OwControlUITypeA::onUpdate(float dt){
	if ( m_bIsTouched )
	{
		m_fInteractTimer += dt;
	}

	if ( m_moveDirection & MOVE_LEFT ) {
		m_playerController->moveLeft();
	} else if ( m_moveDirection & MOVE_RIGHT ){
		m_playerController->moveRight();
	} else if ( m_moveDirection & MOVE_UP ) {
		m_playerController->moveUp();
	} else if ( m_moveDirection & MOVE_DOWN ) {
		m_playerController->moveDown();
	}

}

void OwControlUITypeA::onDestroy()
{
}



void OwControlUITypeA::processTouchBegin(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
	// Grab the start location
	m_bIsTouched = true;
	m_fInteractTimer = 0.f;
	m_startTouchPosition = touch->getLocation();
}

void OwControlUITypeA::processTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
	m_bIsTouched = false;
	m_moveDirection = 0;
}

void OwControlUITypeA::processTouchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
	CCPoint relative_from_start = touch->getLocation() - m_startTouchPosition;

	if ( abs(relative_from_start.x) > abs(relative_from_start.y) )
	{
		if ( relative_from_start.x < 0 ) {
			//Log::getInstance().log("OwControlUITypeA", "moving left");
			m_moveDirection = 0;
			m_moveDirection |= MOVE_LEFT;
		}
		else if ( relative_from_start.x > 0 ) {
			//Log::getInstance().log("OwControlUITypeA", "moving right");
			m_moveDirection = 0;
			m_moveDirection |= MOVE_RIGHT;
		}
		//else relative_from_start.x == 0
	} 

	else if ( abs(relative_from_start.x) < abs(relative_from_start.y) )
	{
		if ( relative_from_start.y < 0 ) {
			//Log::getInstance().log("OwControlUITypeA", "moving down");
			m_moveDirection = 0;
			m_moveDirection |= MOVE_DOWN;
		}

		else if ( relative_from_start.y > 0 ) {
			//Log::getInstance().log("OwControlUITypeA", "moving up");
			m_moveDirection = 0;
			m_moveDirection |= MOVE_UP;
		}
		//else relative_from_start.y == 0
	} 
	//else relative_from_start.x == relative_from_start.y

}
