#include "BattleManager.h"
#include "..\BattleEntities\BattleEntity.h"

void BattleManager::INIT_LOAD()
{
}

void BattleManager::INIT_INIT()
{
    // calculate everyone's init
    std::vector< BattleEntity* >::iterator beg = m_participantList.begin();
    std::vector< BattleEntity* >::iterator end = m_participantList.end();
    
    for ( ; beg != end; ++beg ){
		(*beg)->calculateInitiative();
    }
    
}

void BattleManager::INIT_UPDATE(float dt)
{
}

void BattleManager::INIT_FREE()
{
}

void BattleManager::INIT_UNLOAD()
{
}

bool BattleManager::INIT_TO_TURN_PLAYER()
{
	return false;
}

bool BattleManager::INIT_TO_TURN_ENEMY()
{
	return false;
}