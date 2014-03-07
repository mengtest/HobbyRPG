#include "OwControlUITypeBButton.h"
#include "..\OwManager\OwManager.h"

USING_NS_CC;

OwControlUITypeBButton::OwControlUITypeBButton(const std::string& up_texture_name, const std::string& down_texture_name)
	: m_bIsDown(false), m_upTextureName(up_texture_name), m_downTextureName(down_texture_name), 
	m_upCallback(0), m_downCallback(0), m_upCallbackInstance(0), m_downCallbackInstance(0), m_bPrevIsDown(false),
	m_pressCallback(0), m_pressCallbackInstance(0)
{
	m_currentTexture = CCSprite::createWithSpriteFrameName( up_texture_name.c_str() );
}

void OwControlUITypeBButton::update(float dt)
{
    if ( m_bIsDown )
    {   
		if ( m_downCallback && m_downCallbackInstance ) {
			(m_downCallbackInstance->*m_downCallback)(); // O_O;;
		}
    }
}

void OwControlUITypeBButton::processTouchMoved( cocos2d::CCTouch * touch, cocos2d::CCEvent * event )
{
	if ( !m_currentTexture )
		return;

	CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    touchLocation = this->m_currentTexture->getParent()->convertToNodeSpace(touchLocation);
	 
    m_bIsDown = checkCollision(touchLocation);
	if ( (m_bIsDown && !m_bPrevIsDown) || (m_bIsDown && m_bPrevIsDown )) {
		m_currentTexture->setDisplayFrame( CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(m_downTextureName.c_str()));
	} else {
		m_currentTexture->setDisplayFrame( CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(m_upTextureName.c_str()));
	}//*/



	m_bPrevIsDown = m_bIsDown;
}

void OwControlUITypeBButton::processTouchBegan( cocos2d::CCTouch * touch, cocos2d::CCEvent * event )
{
	if ( !m_currentTexture )
		return;
	CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
	touchLocation = this->m_currentTexture->getParent()->convertToNodeSpace(touchLocation); // relative to parent, that is the layer

    m_bIsDown = checkCollision(touchLocation);
	if ( m_bIsDown )
	{
		 // Swap texture   
		m_currentTexture->setDisplayFrame( CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(m_downTextureName.c_str()));

		// Press callback
		if ( m_pressCallback && m_pressCallbackInstance ) {
			(m_pressCallbackInstance->*m_pressCallback)(); // O_O;;
		}
	}

	m_bPrevIsDown = m_bIsDown;
}

void OwControlUITypeBButton::processTouchEnd( cocos2d::CCTouch * touch, cocos2d::CCEvent * event )
{
	if ( !m_currentTexture )
		return;

    m_bIsDown = m_bPrevIsDown = false;
	m_currentTexture->setDisplayFrame( CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(m_upTextureName.c_str()));
    
	// do up callback
	if ( m_upCallback && m_upCallbackInstance ) {
		(m_upCallbackInstance->*m_upCallback)();
	}

}

void OwControlUITypeBButton::setUpTexture( const std::string& name )
{
	m_upTextureName = name;
}

void OwControlUITypeBButton::setDownTexture( const std::string& name )
{
	m_downTextureName = name;   
}

void OwControlUITypeBButton::setPosition(cocos2d::CCPoint position)
{
    if ( m_currentTexture )
        m_currentTexture->setPosition(position);
}


void OwControlUITypeBButton::setUpCallback(cocos2d::CCObject * instance,  void (cocos2d::CCObject::*funcToCall)(void))
{
	m_upCallback = funcToCall;
	m_upCallbackInstance = instance;
}

void OwControlUITypeBButton::setDownCallback(cocos2d::CCObject * instance,  void (cocos2d::CCObject::*funcToCall)(void))
{
	m_downCallback = funcToCall;
	m_downCallbackInstance = instance;
}

void OwControlUITypeBButton::setPressCallback(cocos2d::CCObject * instance,  void (cocos2d::CCObject::*funcToCall)(void))
{
	m_pressCallback = funcToCall;
	m_pressCallbackInstance = instance;
}


bool OwControlUITypeBButton::checkCollision(CCPoint point)
{
    CCRect rect = m_currentTexture->getTextureRect();
	CCPoint position = m_currentTexture->getPosition();

	float minX = position.x - rect.size.width / 2;
	float minY = position.y - rect.size.height / 2;
	float maxX = position.x + rect.size.width / 2;
	float maxY = position.y + rect.size.height / 2;

    return (point.x <= maxX && point.x >= minX  && point.y <= maxY && point.y >= minY );
}
