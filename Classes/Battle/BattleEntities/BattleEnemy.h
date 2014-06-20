#ifndef __BATTLE_ENEMY_H__
#define __BATTLE_ENEMY_H__

#include "cocos2d.h"
#include "BattleEntity.h"

class BattleEnemy : public BattleEntity
{
public:
	BattleEnemy(cocos2d::CCPoint position, const std::string& spriteBaseName, const std::string& initialSpriteFrameName);
	
	void update(float dt) {};
	int getInitiative() { return 1; }


};

#endif