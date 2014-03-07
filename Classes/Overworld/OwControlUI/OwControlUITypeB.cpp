#include "OwControlUITypeB.h"
#include "OwControlUITypeBButton.h"
#include "../OwManager/OwManager.h"
#include "../OwPlayerController/OwPlayerController.h"
#include "../../Common/Common.h"

USING_NS_CC;

OwControlUITypeB::OwControlUITypeB( OwPlayerController * player_controller )
	: m_playerController(player_controller)
{
}
	 
bool OwControlUITypeB::onInit()
{
	m_upButton = new OwControlUITypeBButton("up_arrow_up.png", "up_arrow.png");
	m_downButton = new OwControlUITypeBButton("down_arrow_up.png", "down_arrow.png");
	m_leftButton = new OwControlUITypeBButton("left_arrow_up.png", "left_arrow.png");
	m_rightButton = new OwControlUITypeBButton("right_arrow_up.png", "right_arrow.png");
	m_aButton = new OwControlUITypeBButton("a_button_up.png", "a_button.png");
	//m_bButton = new OwControlUITypeBButton("b_arrow_up.png", "b_arrow.png");

	CCPoint center = ccp (Common::getNormalizedPositionX(0.15f), Common::getNormalizedPositionY(0.25f));
	float offset = Common::getNormalizedPositionX(0.075f);
	
	OwManager::getInstance()->addChildToUILayer(m_upButton->getSprite());
	m_upButton->setPosition(ccp( center.x, center.y + offset ));
	m_upButton->setDownCallback( m_playerController, ow_selector(OwPlayerController::moveUp));

	OwManager::getInstance()->addChildToUILayer(m_downButton->getSprite());
	m_downButton->setPosition(ccp( center.x, center.y - offset));
	m_downButton->setDownCallback( m_playerController, ow_selector(OwPlayerController::moveDown));


	OwManager::getInstance()->addChildToUILayer(m_leftButton->getSprite());
	m_leftButton->setPosition(ccp( center.x - offset, center.y ));
	m_leftButton->setDownCallback( m_playerController, ow_selector(OwPlayerController::moveLeft));


	OwManager::getInstance()->addChildToUILayer(m_rightButton->getSprite());
	m_rightButton->setPosition(ccp( center.x + offset, center.y ));
	m_rightButton->setDownCallback( m_playerController, ow_selector(OwPlayerController::moveRight));

	OwManager::getInstance()->addChildToUILayer(m_aButton->getSprite());
	m_aButton->setPosition(ccp( Common::getNormalizedPositionX(0.85f), Common::getNormalizedPositionX(0.1f) ));
	m_aButton->setPressCallback( m_playerController, ow_selector(OwPlayerController::interact));


	return true;
}

void OwControlUITypeB::onUpdate(float dt)
{
	m_upButton->update(dt);
	m_downButton->update(dt);
	m_leftButton->update(dt);
	m_rightButton->update(dt);
	m_aButton->update(dt);

}

void OwControlUITypeB::onDestroy()
{
	CC_SAFE_DELETE( m_upButton );
	CC_SAFE_DELETE( m_downButton );
	CC_SAFE_DELETE( m_leftButton );
	CC_SAFE_DELETE( m_rightButton );
	CC_SAFE_DELETE( m_aButton );
}


void OwControlUITypeB::processTouchBegin(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
	 m_upButton->processTouchBegan(touch, event);
	 m_downButton->processTouchBegan(touch, event);
	 m_leftButton->processTouchBegan(touch, event);
	 m_rightButton->processTouchBegan(touch, event);
	 m_aButton->processTouchBegan(touch, event);
}

void OwControlUITypeB::processTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
	m_upButton->processTouchEnd(touch, event);
	m_downButton->processTouchEnd(touch, event);
	m_leftButton->processTouchEnd(touch, event);
	m_rightButton->processTouchEnd(touch, event);
	m_aButton->processTouchEnd(touch, event);
}

void OwControlUITypeB::processTouchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
	m_upButton->processTouchMoved(touch, event);
	m_downButton->processTouchMoved(touch, event);
	m_leftButton->processTouchMoved(touch, event);
	m_rightButton->processTouchMoved(touch, event);
	m_aButton->processTouchMoved(touch, event);

}

