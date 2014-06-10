#include "BattleCharacter.h"
#include "../BattleManager/BattleManager.h"
#include "../../Character/Character.h"

using namespace std;
USING_NS_CC;

BattleCharacter::BattleCharacter(CCPoint position, Character * character, DirectionEnum direction)
    : BattleEntity(position, 
                   character->getInfo(CharacterInfoEnum::BASE_SPRITE), 
                   character->getInfo(CharacterInfoEnum::INITIAL_SPRITE)),
      m_character(character)
{
	/*switch ( direction ) {
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
	}*/
}