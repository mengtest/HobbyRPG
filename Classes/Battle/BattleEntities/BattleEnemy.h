#ifndef __BATTLE_ENEMY_H__
#define __BATTLE_ENEMY_H__

#include "cocos2d.h"
#include "BattleEntity.h"
#include "..\..\Enum\EnemyEnum.h"

class BattleEnemy : public BattleEntity
{
public:
	BattleEnemy(cocos2d::CCPoint position, EnemyEnum enemyID);
	
	void update(float dt) {};
	void calculateInitiative();

private:
    int m_nInitiative;
	EnemyEnum m_nEnemyId;
};

#endif