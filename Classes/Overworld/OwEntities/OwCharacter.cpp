
#include "OwCharacter.h"
#include "../OwManager/OwManager.h"

#include "../../Common/Common.h"

using namespace std;
USING_NS_CC;

OwCharacter::OwCharacter(CCPoint position,const std::string& name, 
						const string& spriteName, const string& initialSpriteBaseName, int id)
	: OwEntityBase(position, name, spriteName,initialSpriteBaseName, id), m_bIsMoving(false), 
	  m_moveTime(0.f), m_moveDuration(0.4f), m_action(0)
{

	snapToTile();
	face(DOWN);
	occupyTile(getPosition());
}

OwCharacter::~OwCharacter()
{
}

void OwCharacter::update(float dt)
{
	updateMovement(dt);
}

void OwCharacter::updateMovement(float dt)
{
	if ( !m_sprite ) {
		CCLOG("[OwCharacter][updateMovement][error]: m_sprite is null!");
		return;
	}

	if ( m_bIsMoving ) // movement state
	{
		m_moveTime += dt;
		if (m_moveTime >= m_moveDuration)
		{
			unoccupyTile(m_startPoint);
			stop(m_currentDirection);
		}

		float x = Common::linearLerp(m_startPoint.x, m_endPoint.x, m_moveTime, m_moveDuration);
		float y = Common::linearLerp(m_startPoint.y, m_endPoint.y, m_moveTime, m_moveDuration);
		m_sprite->setPosition(ccp(x,y));
	}

	else // idle state
	{
		stopAnimations();
	}
}

void OwCharacter::stopAnimations()
{
	if ( !m_sprite ) {
		CCLOG("[OwCharacter][stopAnimations][error]: m_sprite is null!");
		return;
	}

	// ƒAƒjƒƒVƒ‡ƒ“‚ðŽ~‚Ü‚ê
	if ( m_action )
	{
		m_sprite->stopAction(m_action);
		m_action = 0;
		face(m_currentDirection);
	}
}

bool OwCharacter::checkTileMovable(CCPoint position)
{
	return checkMetaBounds(position) && checkWorldBounds(position);
}

bool OwCharacter::stop( DirectionEnum type )
{
	m_moveTime = m_moveDuration;
	m_bIsMoving = false;

	return true;
}

bool OwCharacter::face( DirectionEnum type )
{
	if ( !m_sprite ) {
		CCLOG("[OwCharacter][face][error]: m_sprite is null!");
		return false;
	}

	string spriteStr;
	switch ( type )
	{
	case UP:
		spriteStr.append("back");
		break;
	case DOWN:
		spriteStr.append("front");
		break;
	case LEFT:
		spriteStr.append("left");
		break;
	case RIGHT:
		spriteStr.append("right");
		break;
	}

	//Log::getInstance().log("OwCharacter", "face: " + spriteStr);
	//m_sprite->initWithSpriteFrameName( ( m_spriteName + "_" + spriteStr + "_2" ).c_str() );
	m_sprite->setDisplayFrame( CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName( (m_spriteName + "_" + spriteStr + "_2.png" ).c_str() ));
	m_currentDirection = type;
	return true;
}

bool OwCharacter::move( DirectionEnum type )
{
	if ( !m_sprite ) {
		CCLOG("[OwCharacter][move][error]: m_sprite is null!");
		return false;
	}

	if ( m_bIsMoving ) { 
		return false;
	}

	int x = 0, y = 0;
	string spriteStr;
	switch ( type )
	{
	case UP:
		y = 1;
		spriteStr.append("back");
		break;
	case DOWN:
		spriteStr.append("front");
		y = -1;
		break;
	case LEFT:
		spriteStr.append("left");
		x = -1;
		break;
	case RIGHT:
		spriteStr.append("right");
		x = 1;
		break;
	}

	OwManager * mgr = OwManager::getInstance();
	if ( !mgr ) {
		CCLOG("[OwCharacter][move][error]: mgr is null!");
		return false;
	}

	// Predicted position (move 1 tile left)
	CCPoint prediction( getTileCenter( ccp(getPosition().x + x * mgr->getTiledMap()->getTileSize().width, 
										   getPosition().y + y * mgr->getTiledMap()->getTileSize().height)));

	// Tile‚Ì“®‚©‚ê‚é‚Ì‚±‚Æ’²¸‚µ‚Ü‚·
	if ( !checkTileMovable(prediction) ) {
		face(type);
		return false;
	}
	
	// Interpolate there
	m_bIsMoving = true;
	m_moveTime = 0.f;

	m_startPoint = getPosition();
	m_endPoint = prediction;

	// Animate!
	stopAnimations();
	CCAnimation * animation = CCAnimationCache::sharedAnimationCache()->animationByName(( m_spriteName + "_walk_" + spriteStr).c_str());  
	if ( !animation ) {
		CCLOG("[OwCharacter][move][error]: animation is null!");
		return false;
	}

	m_action = CCRepeatForever::create(CCAnimate::create(animation)); 
	if ( !m_action ) {
		CCLOG("[OwCharacter][move][error]: m_action is null!");
		return false;
	}
	m_sprite->runAction(m_action);
	
	
	occupyTile(m_endPoint);
	m_currentDirection = type;
	return true;

}