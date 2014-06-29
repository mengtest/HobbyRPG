#include "BattleEnemy.h"

#include "..\..\Enemy\EnemyManager.h"

BattleEnemy::BattleEnemy(cocos2d::CCPoint position, int enemyId)
{
	std::string base_sprite = EnemyManager::getInstance().getEnemyStat(EnemyEnum::PORK, EnemyStatsEnum::SPRITE);
	setSprite(base_sprite);	 
	setPosition(position);
	setIsEnemy(true);
}