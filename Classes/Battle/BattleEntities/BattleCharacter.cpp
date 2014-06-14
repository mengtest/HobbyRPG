#include "BattleCharacter.h"
#include "../BattleManager/BattleManager.h"
#include "../../Character/Character.h"

using namespace std;
USING_NS_CC;

BattleCharacter::BattleCharacter(CCPoint position, Character * character, DirectionEnum direction)
    : BattleEntity(position, 
                   character->getInfo(CharacterInfoEnum::SPRITE), 
                   character->getInfo(CharacterInfoEnum::SPRITE) + "_left_2_.png"),
      m_character(character)
{
	std::string actual_initial_sprite;
	switch ( direction ) {
	case UP:
		actual_initial_sprite = m_spriteBaseName + "_back_2.png";
		break;
	case DOWN:
		actual_initial_sprite = m_spriteBaseName + "_front_2.png";
		break;
	case LEFT:
		actual_initial_sprite = m_spriteBaseName + "_left_2.png";
		break;
	case RIGHT:
		actual_initial_sprite = m_spriteBaseName + "_right_2.png";
		break;
	}
	
	m_sprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(actual_initial_sprite.c_str()));
	
}

void BattleCharacter::update(float dt) 
{
}