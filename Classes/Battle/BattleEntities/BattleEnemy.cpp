#include "BattleEnemy.h"

#include "..\..\Enemy\EnemyManager.h"

BattleEnemy::BattleEnemy(cocos2d::CCPoint position, EnemyEnum enemyId)
	: m_nEnemyId(enemyId)
{
	std::string base_sprite = EnemyManager::getInstance().getEnemyStat(enemyId, EnemyStatsEnum::SPRITE);
	setSprite(base_sprite);	 
	setPosition(position);
	setIsEnemy(true);
}

void BattleEnemy::calculateInitiative()
{
	std::string temp = EnemyManager::getInstance().getEnemyStat(m_nEnemyId, EnemyStatsEnum::SPEED);
	m_nInitiative += atoi(temp.c_str());
}