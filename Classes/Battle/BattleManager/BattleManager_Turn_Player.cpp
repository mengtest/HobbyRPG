#include "BattleManager.h"

#include "CCLuaEngine.h"

USING_NS_CC;

void BattleManager::TURN_PLAYER_LOAD()
{
	CCLOG("[BATTLE] Turn Player start");
}

void BattleManager::TURN_PLAYER_INIT()
{
	CCLuaEngine::defaultEngine()->executeGlobalFunction("battle_show_player_menu");
}

void BattleManager::TURN_PLAYER_UPDATE(float dt)
{
}

void BattleManager::TURN_PLAYER_FREE()
{
}

void BattleManager::TURN_PLAYER_UNLOAD()
{
}