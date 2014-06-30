#ifndef __BATTLE_ENEMY_H__
#define __BATTLE_ENEMY_H__

#include "cocos2d.h"
#include "BattleEntity.h"

class BattleEnemy : public BattleEntity
{
public:
	BattleEnemy(cocos2d::CCPoint position, int enemyID);
	
	void update(float dt) {};
	int calculateInitiative();

private:
    int m_nInitiative;
};

#endif