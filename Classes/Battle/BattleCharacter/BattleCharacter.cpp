#include "BattleCharacter.h"
#include "../BattleManager/BattleManager.h"
#include "../../Character/Character.h"

using namespace std;
USING_NS_CC;

BattleCharacter::BattleCharacter(CCPoint position, Character * character, DirectionEnum direction, std::string spriteBaseName)
{
	std::string initialSpriteFrameName;
	
	switch ( direction ) {
	case UP:
		initialSpriteFrameName = spriteBaseName + "_back_2.png";
		break;
	case DOWN:
		initialSpriteFrameName = spriteBaseName + "_front_2.png";
		break;
	case LEFT:
		initialSpriteFrameName = spriteBaseName + "_left_2.png";
		break;
	case RIGHT:
		initialSpriteFrameName = spriteBaseName + "_right_2.png";
		break;
	
	}
	setSprite(spriteBaseName, initialSpriteFrameName);
	setPosition(position);
}

void BattleCharacter::setSprite(const std::string& spriteBaseName, const std::string& initialSpriteFrameName)
{
	// Sprite creation
	// Sprite‚ðì¬‚µ‚Ü‚·
	m_sprite = CCSprite::createWithSpriteFrameName( initialSpriteFrameName.c_str() );
	if ( !m_sprite ) {
		CCLOG("[BattleCharacter][setSprite][error]: m_sprite is null!");
		return;
	}
	m_spriteName = spriteBaseName;
}

void BattleCharacter::setPosition( cocos2d::CCPoint position )
{
	if ( !m_sprite ) {
		CCLOG("[BattleCharacter][setPosition][error]: m_sprite is null!");
		return;
	}
	m_sprite->setPosition(position);
}
