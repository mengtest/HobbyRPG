#ifndef __BATTLE_CHARACTER_H__
#define __BATTLE_CHARACTER_H__

#include "cocos2d.h"

#include "..\..\Enum\DirectionEnum.h"
#include "BattleEntity.h"

class Character;
class BattleCharacter : public BattleEntity
{
public:
	BattleCharacter(cocos2d::CCPoint position, Character * character, DirectionEnum direction);

	void update(float dt);
	int getSpeed();

protected:
    Character * m_character;
	std::string m_spriteBaseName;
    int m_nInitiative;
};

#endif 