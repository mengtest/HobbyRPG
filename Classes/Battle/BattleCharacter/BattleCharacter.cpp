#include "BattleCharacter.h"
#include "../BattleManager/BattleManager.h"
#include "../../Character/Character.h"

using namespace std;
USING_NS_CC;

BattleCharacter::BattleCharacter(cocos2d::CCPoint position, std::string name, std::string initialSpriteFrameName)
{
	m_name = name;
	setSprite(initialSpriteFrameName);
	setPosition(position);
}

void BattleCharacter::setSprite(const std::string& initialSpriteFrameName)
{
	// Sprite creation
	// Sprite‚ðì¬‚µ‚Ü‚·
	m_sprite = CCSprite::createWithSpriteFrameName( initialSpriteFrameName.c_str() );
	if ( !m_sprite ) {
		CCLOG("[BattleCharacter][setSprite][error]: m_sprite is null!");
		return;
	}
}

void BattleCharacter::setPosition( cocos2d::CCPoint position )
{
	if ( !m_sprite ) {
		CCLOG("[BattleCharacter][setPosition][error]: m_sprite is null!");
		return;
	}
	m_sprite->setPosition(position);
}
