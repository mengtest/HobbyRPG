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
	//temp
	int getInitiative() { return 1; }

protected:
    Character * m_character;
};

#endif 