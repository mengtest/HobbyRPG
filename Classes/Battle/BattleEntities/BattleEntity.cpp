#include "BattleEntity.h"
#include "../BattleManager/BattleManager.h"
#include "../../Character/Character.h"

using namespace std;
USING_NS_CC;

BattleEntity::BattleEntity(CCPoint position, const std::string& spriteBaseName, const std::string& initialSpriteFrameName)
{
	setSprite(spriteBaseName, initialSpriteFrameName);
	setPosition(position);
}

void BattleEntity::setSprite(const std::string& spriteBaseName, const std::string& initialSpriteFrameName)
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

void BattleEntity::setPosition( cocos2d::CCPoint position )
{
	if ( !m_sprite ) {
		CCLOG("[BattleCharacter][setPosition][error]: m_sprite is null!");
		return;
	}
	m_sprite->setPosition(position);
}
