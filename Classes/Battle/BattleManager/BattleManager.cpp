#include "BattleManager.h"
#include "..\BattleScene.h"
#include "..\BattleEntities\BattleCharacter.h"

#include "..\..\GameMaster\GameMaster.h"
#include "..\..\Overworld\OverworldScene.h"
#include "..\..\Player\Player.h"
#include "..\..\Party\Party.h"
#include "..\..\Character\Character.h"

#include "CCLuaEngine.h"

USING_NS_CC;
using namespace std;
//USING_NS_CC_EXT;

BattleManager* BattleManager::instance = 0;

BattleManager::BattleManager()
	: m_isInit(false), 
	  m_scene(0),
      m_stateMachine(0)
{
}

BattleManager * BattleManager::getInstance()
{
	if ( !instance )
	{
		instance = new BattleManager();
	}

	return instance;

}

void BattleManager::destroy()
{
	//clean up here
	if ( instance->m_isInit )
	{
		instance->release();
	}

}

bool BattleManager::init(BattleScene * scene)
{
	if ( m_isInit )
	{
		CCLOG("[BattleManager][init]: Already Init, please call Release");
		return false;
	}
    
     if ( !loadFSM() )
	{
		CCLOG("[BattleManager][init][error]: loadFSM() failed!");
		return false;
	}

	m_scene = scene;
	m_isInit = true;

	loadCharacters();
	loadEnemies();

	return true;
}

void BattleManager::loadCharacters()
{
	//create sprites according to how many characters in party
	for ( int i = 0; i < Player::getInstance().getParty()->MAX_MEMBERS; ++i )
	{
		Character * character = Player::getInstance().getParty()->getCharacterAtSlot(i);
		if ( NULL == character )
		{
			CCLOG("[BattleManager][init]: character is null");
			continue;
		}

		addBattleCharacter(ccp(100, 100), character, LEFT);
	}

}

void BattleManager::loadEnemies()
{
}

void BattleManager::loadFSM()
{
	// State Machine //
	m_stateMachine = new cStateMachine<OwManager>(this);

	cStateTemplate<OwManager> * startState;
	startState = m_stateMachine->AddState( &OwManager::START_LOAD,
											&OwManager::START_INIT,
											&OwManager::START_UPDATE,
											&OwManager::START_FREE,
											&OwManager::START_UNLOAD );

	cStateTemplate<OwManager> * initState;
	initState = m_stateMachine->AddState(   &OwManager::INIT_LOAD,
											&OwManager::INIT_INIT,
											&OwManager::INIT_UPDATE,
											&OwManager::INIT_FREE,
											&OwManager::INIT_UNLOAD );
                                              
    cStateTemplate<OwManager> * turnPlayerState;
	turnPlayerState = m_stateMachine->AddState(  &OwManager::TURN_PLAYER_LOAD,
                                                 &OwManager::TURN_PLAYER_INIT,
                                                 &OwManager::TURN_PLAYER_UPDATE,
                                                 &OwManager::TURN_PLAYER_FREE,
                                                 &OwManager::TURN_PLAYER_UNLOAD );
                                              
    cStateTemplate<OwManager> * turnEnemyState;
	turnEnemyState = m_stateMachine->AddState(  &OwManager::TURN_PLAYER_LOAD,
                                                &OwManager::TURN_PLAYER_INIT,
                                                &OwManager::TURN_PLAYER_UPDATE,
                                                &OwManager::TURN_PLAYER_FREE,
                                                &OwManager::TURN_PLAYER_UNLOAD );

	
	startState->AddTriggerCheck( &OwManager::START_TO_INIT, initState);
	initState->AddTriggerCheck( &OwManager::INIT_TO_TURN_PLAYER, turnPlayerState);
	initState->AddTriggerCheck( &OwManager::INIT_TO_TURN_ENEMY, turnEnemyState);

	
	m_stateMachine->SetCurrentState(startState);

	return true;
}

void BattleManager::release()
{
	if ( !m_isInit )
	{
		CCLOG("[BattleManager][release]: Already Released, please call Init");
		return;
	}
    
   

	m_isInit = false;
}

BattleCharacter * BattleManager::addBattleCharacter(CCPoint position, Character * character, DirectionEnum direction)
{
	std::string name = character->getInfo(CharacterInfoEnum::SPRITE_BASE);

	CCLOG("[BattleManager][addBattleCharacter]: adding '%s'", name);
	BattleCharacter * rtn	= new BattleCharacter(position, character, direction);
	m_scene->getGameLayer()->addChild(rtn->getSprite());
	m_characterList.insert(make_pair(name, rtn));

	return rtn;
}

void BattleManager::update(float dt)
{
}


bool BattleManager::processTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	gotoOverworld();
    return true;
}
  
void BattleManager::processTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
}

void BattleManager::processTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
}

 
void BattleManager::addChildToGameLayer( cocos2d::CCNode * obj )
{
    m_scene->getGameLayer()->addChild(obj);
}

void BattleManager::addChildToUILayer( cocos2d::CCNode * obj )
{
    m_scene->getUILayer()->addChild(obj); 
}

void BattleManager::removeChildFromGameLayer(cocos2d::CCNode * obj )
{
    m_scene->getGameLayer()->removeChild(obj);
}

void BattleManager::removeChildFromUILayer( cocos2d::CCNode * obj )
{
    m_scene->getUILayer()->removeChild(obj); 
}
    
void BattleManager::gotoOverworld()
{
	CCDirector::sharedDirector()->popScene();

}