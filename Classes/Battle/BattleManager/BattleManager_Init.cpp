#include "BattleManager.h"
#include "..\BattleEntities\BattleEntity.h"
#include "CCLuaEngine.h"

USING_NS_CC;

void BattleManager::INIT_LOAD()
{
	CCLOG("[BATTLE] Init Start");
}

void BattleManager::INIT_INIT()
{
	CCLOG("[BATTLE] Calculating initiative");
    // calculate everyone's init
    std::vector< BattleEntityContainer >::iterator beg = m_participantList.begin();
    std::vector< BattleEntityContainer >::iterator end = m_participantList.end();
   
	std::stringstream init_log;
    for ( ; beg != end; ++beg ){
		beg->addInitiative( beg->getEntity()->getSpeed() );
		init_log << "(" + beg->getEntity()->getName() << " = " << beg->getInitiative() << "), ";
    }

	CCLOG("[BATTLE] Initiatives: %s", init_log.str().c_str());

	CCLuaEngine::defaultEngine()->executeGlobalFunction("battle_create_init_images");
    
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
	return !m_participantList.begin()->getEntity()->getIsEnemy();
}

bool BattleManager::INIT_TO_TURN_ENEMY()
{
	return m_participantList.begin()->getEntity()->getIsEnemy();
}