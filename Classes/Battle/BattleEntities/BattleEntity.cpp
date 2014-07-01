#include "BattleEntity.h"
#include "../BattleManager/BattleManager.h"
#include "../../Character/Character.h"

using namespace std;
USING_NS_CC;

BattleEntity::BattleEntity()
	: m_layer(0), m_sprite(0), m_bIsEnemy(false)
{
}

void BattleEntity::setSprite(const std::string& initialSpriteFrameName)
{
	// Sprite creation
	// Sprite‚ðì¬‚µ‚Ü‚·
	m_sprite = CCSprite::createWithSpriteFrameName( initialSpriteFrameName.c_str() );
	if ( !m_sprite ) {
		CCLOG("[BattleCharacter][setSprite][error]: m_sprite is null!");
		return;
	}
}

void BattleEntity::setPosition( cocos2d::CCPoint position )
{
	if ( !m_sprite ) {
		CCLOG("[BattleCharacter][setPosition][error]: m_sprite is null!");
		return;
	}
	m_sprite->setPosition(position);
}

void BattleEntity::addSpriteToLayer( cocos2d::CCLayer * layer )
{
	if ( m_layer != 0 )
	{
		m_layer->removeChild(m_sprite);
	}

	layer->addChild(m_sprite);
	m_layer = layer;
}

