#include "BattleCharacter.h"
#include "../BattleManager/BattleManager.h"
#include "../../Character/Character.h"

using namespace std;
USING_NS_CC;

BattleCharacter::BattleCharacter(CCPoint position, Character * character, DirectionEnum direction)
	: m_character(character)
{
	std::string actual_initial_sprite;
	std::string base_sprite = character->getInfo(CharacterInfoEnum::SPRITE_BASE);
	switch ( direction ) {
	case UP:
		actual_initial_sprite = base_sprite + "_back_2.png";
		break;
	case DOWN:
		actual_initial_sprite = base_sprite + "_front_2.png";
		break;
	case LEFT:
		actual_initial_sprite = base_sprite + "_left_2.png";
		break;
	case RIGHT:
		actual_initial_sprite = base_sprite + "_right_2.png";
		break;
	}
	
	setPosition(position);
	setSprite(base_sprite, actual_initial_sprite)	;	     
}

void BattleCharacter::update(float dt) 
{
}