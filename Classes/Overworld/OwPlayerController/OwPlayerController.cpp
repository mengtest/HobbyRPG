#include "..\..\Common\Common.h"

#include "OwPlayerController.h"
#include "../OwEntities/OwCharacter.h"
#include "../OwManager/OwManager.h"
#include "../OwTiledMapUserData/OwTiledMapUserData.h"

#include "../../Enum/DirectionEnum.h"

#include <cocos2d.h>

USING_NS_CC;

void OwPlayerController::move( DirectionEnum type )
{
	if ( m_bDisabled )
		return;

	if ( m_character )
		m_character->move(type);
}

void OwPlayerController::interact()
{
	if ( m_bDisabled )
		return;

	// Find the front of the character
	int x = 0;
	int y = 0;
	switch (m_character->getCurrentDir())
	{
	case UP:
		y = -1;
		break;
	case DOWN:
		y = 1;
		break;
	case LEFT:
		x = -1;
		break;
	case RIGHT:
		x = 1;
		break;
	}

	//attempt to grab object in front
	CCPoint temp = m_character->getTiledPosition();
	temp.x += x;
	temp.y += y;
	OwEntityBase * object = static_cast<OwEntityBase*>(OwManager::getInstance()->getTiledMapUserData()->getUserData(temp));
	if ( !object || object == m_character)
		return;

	object->interact(m_character);
	return;
}

void OwPlayerController::update(float dt)
{
	if ( m_bDisabled )
		return;

	if ( m_bStartMoving ) {
		updateMovement(dt);		
	}

	if ( !this->m_character->isMoving() ) {
		doExitCheck();
	}
}

void OwPlayerController::updateMovement(float dt)
{
	if ( m_bDisabled )
		return;
	CCPoint playerPos = m_character->getPosition();
 
    if ( abs(m_movingDirection.x) > abs(m_movingDirection.y) ) 
	{
        if (m_movingDirection.x > 0) 
		{
			move(RIGHT);

        } 
		else 
		{
            move(LEFT);
        }
    } 
	else 
	{
        if (m_movingDirection.y > 0) 
		{
			move(UP);
        } 
		else 
		{
			move(DOWN);
        }
    }
}

void OwPlayerController::moveUp()
{
	if ( m_bDisabled )
		return;
	move(UP);
	m_bCheckExit = true;
}

void OwPlayerController::moveDown()
{
	if ( m_bDisabled )
		return;
	move(DOWN);
	m_bCheckExit = true;
}

void OwPlayerController::moveLeft()
{
	if ( m_bDisabled )
		return;
	move(LEFT);
	m_bCheckExit = true;
}

void OwPlayerController::moveRight()
{
	if ( m_bDisabled )
		return;
	move(RIGHT);
	m_bCheckExit = true;
}

void OwPlayerController::doExitCheck()
{
	if ( !m_bCheckExit ) 
		return;
	
	OwManager::getInstance()->checkExit();
	m_bCheckExit = false;
}