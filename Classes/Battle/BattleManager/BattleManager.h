#ifndef __BattleManager_H__
#define __BattleManager_H__

#include <cocos2d.h>
#include <string>
#include <map>

#include "../../AI/AIHeaders.h"
#include "../../Enum/DirectionEnum.h"
#include "../../Enum/EnemyEnum.h"

class BattleScene;
class BattleEntity;
class BattleEnemy;
class BattleCharacter;
class CustomActionManager;
class EventManager;
class EventBase;
class Character;

//essentially a nice global class that stores data for everyone 
//in battle to use so that we don't have to pass pointers around.
//NOTE: This is currently NOT intended to be a manager.
//Management SHOULD be done by the state that uses this class.
//All this class does is to store global variables for 'Ow' classes
class BattleManager
{
public:
	static BattleManager * getInstance();
	static void destroy(); // MUST call this first AFTER using
	
	bool init( BattleScene * scene );  // MUST call this first BEFORE using
	void release();
	void update(float dt);
	
    void addChildToGameLayer( cocos2d::CCNode * obj );
    void addChildToUILayer( cocos2d::CCNode * obj );
    void removeChildFromGameLayer(cocos2d::CCNode * obj );
    void removeChildFromUILayer( cocos2d::CCNode * obj ); 

	bool processTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	void processTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	void processTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	
	void gotoOverworld();

	BattleCharacter * addBattleCharacter(cocos2d::CCPoint position, Character * character, DirectionEnum direction);
	BattleEnemy * addBattleEnemy(cocos2d::CCPoint position, EnemyEnum enemyID);
    
    BattleEntity * getParticipant( unsigned index );
	inline unsigned int getParticipantInitiative(unsigned index) { return m_participantList[index].getInitiative(); }
    inline unsigned int getParticipantCount() { return m_participantList.size(); }
    inline unsigned int getParticipantCountAlive() { return m_nPlayerCount + m_nEnemyCount; }
    inline unsigned int getParticipantCountDead() { return getParticipantCount() - getParticipantCountAlive(); }
private:
	bool m_isInit;
	
	BattleManager() ;
	~BattleManager() {}

	bool loadCharacters();
	bool loadEnemies();
	bool loadFSM();

	// Statemachine
	cStateMachine<BattleManager> * m_stateMachine;
	void START_LOAD();
	void START_INIT();
	void START_UPDATE(float dt);
	void START_FREE();
	void START_UNLOAD();
    
    void INIT_LOAD();
	void INIT_INIT();
	void INIT_UPDATE(float dt);
	void INIT_FREE();
	void INIT_UNLOAD();

    void TURN_PLAYER_LOAD();
	void TURN_PLAYER_INIT();
	void TURN_PLAYER_UPDATE(float dt);
	void TURN_PLAYER_FREE();
	void TURN_PLAYER_UNLOAD();
    
    void TURN_ENEMY_LOAD();
	void TURN_ENEMY_INIT();
	void TURN_ENEMY_UPDATE(float dt);
	void TURN_ENEMY_FREE();
	void TURN_ENEMY_UNLOAD();
    
    bool START_TO_INIT();
	bool INIT_TO_TURN_PLAYER();
	bool INIT_TO_TURN_ENEMY();
    
	BattleScene * m_scene;

	static BattleManager * instance;

    struct BattleEntityContainer {
        public:
            BattleEntityContainer(BattleEntity * entity, int initiative = 0) : m_entity(entity), m_nInitiative(initiative) {}
            inline BattleEntity * getEntity() { return m_entity; }
            inline int getInitiative() { return m_nInitiative; }
            inline void addInitiative(int value) { m_nInitiative += value; }
            inline void subInitiative(int value) { m_nInitiative -= value; }
            inline void setInitiative(int value) { m_nInitiative = value; }
        private:
            BattleEntity * m_entity;
            int m_nInitiative;
    };
	std::vector<BattleEntityContainer> m_participantList;
	int m_nEnemyCount;
	int m_nPlayerCount;
};


#endif