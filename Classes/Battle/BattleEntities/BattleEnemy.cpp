#include "BattleEnemy.h"

#include "..\..\Enemy\EnemyManager.h"

BattleEnemy::BattleEnemy(cocos2d::CCPoint position, int enemyId)
{
	std::string base_sprite = EnemyManager::getInstance().getEnemyStat(EnemyEnum::getEnemyByIndex(enemyId, EnemyStatsEnum::SPRITE);
	setSprite(base_sprite);	 
	setPosition(position);
	setIsEnemy(true);
}

void BattleEnemy::calculateInitiative()
{
   m_nInitiative += EnemyManager::getInstance().getEnemyStat(EnemyEnum::getEnemyByIndex(enemyId, EnemyStatsEnum::SPEED);
}