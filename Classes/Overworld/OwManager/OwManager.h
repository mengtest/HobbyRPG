#ifndef __OwManager_H__
#define __OwManager_H__

#include <cocos2d.h>
#include <string>
#include <queue>
#include <map>

#include "../../AI/AIHeaders.h"

class OwDialogUI;
class OwTiledMapUserData;
class OverworldScene;
class OwCharacter;
class OwEntityBase;
class OwPlayerController;
class OwAICharacter;
class OwControlUITypeB;
class CustomActionManager;
class EventManager;
class EventBase;

//essentially a nice global class that stores data for everyone 
//in overworld to use so that we don't have to pass pointers around.
//NOTE: This is currently NOT intended to be a manager.
//Management SHOULD be done by the state that uses this class.
//All this class does is to store global variables for 'Ow' classes
class OwManager
{
public:
	static OwManager * getInstance();
	static void destroy(); // MUST call this first AFTER using
	
	bool init( OverworldScene * scene, const std::string& tmxDir, int startX, int startY );  // MUST call this first BEFORE using
	void release();
	void update(float dt);
	
	OwAICharacter * addAICharacter(cocos2d::CCPoint position, const std::string& name, const std::string& spritename, const std::string& initialSpriteName);
	OwAICharacter * getAICharacterByName(const std::string& name);
    
    void addChildToGameLayer( cocos2d::CCNode * obj );
    void addChildToUILayer( cocos2d::CCNode * obj );
    void removeChildFromGameLayer(cocos2d::CCNode * obj );
    void removeChildFromUILayer( cocos2d::CCNode * obj );
    

	inline OwTiledMapUserData * getTiledMapUserData() { return m_tiledMapUserData; }
	inline cocos2d::CCTMXTiledMap * getTiledMap() { return m_tiledMap; }
	inline cocos2d::CCTMXLayer * getMetaLayer() { return m_metaLayer; }
	inline cocos2d::CCTMXObjectGroup * getExitGroup() { return m_exitGroup; }

	bool processTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	void processTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	void processTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	
	void addEvent(EventBase * event); 
	OwDialogUI * getDialog() { return m_dialog; }

	void callback( const std::string& msg, void * data  );

	void checkExit();
	void gotoWorld( int origin_node );
	void gotoOverworld(const std::string& name, int x, int y);

	void pause();
	void unpause();

	void resetMenuLUA();
private:
	bool m_isInit;

	bool loadEntities();
	bool loadTileMap( const std::string& tmxDir );
	bool loadPlayer(int startX, int startY);
	bool loadFSM();
	bool loadDialog();

	bool isPlayerOnExit();
	
	OwManager() ;
	~OwManager() {}

	OverworldScene * m_scene;

	static OwManager * instance;

	cocos2d::CCTMXTiledMap * m_tiledMap;
	cocos2d::CCTMXLayer * m_metaLayer;
	cocos2d::CCTMXObjectGroup * m_objectGroup;
	cocos2d::CCTMXObjectGroup * m_exitGroup;
	OwTiledMapUserData * m_tiledMapUserData;
	
	
	OwPlayerController * m_controller;
	OwAICharacter * m_npcCharacter;
	OwAICharacter * m_character;
	EventManager * m_eventManager;

	// Statemachine
	cStateMachine<OwManager> * m_stateMachine;
	void NORMAL_LOAD(){}
	void NORMAL_INIT(){}
	void NORMAL_UPDATE(float dt);
	void NORMAL_FREE(){}
	void NORMAL_UNLOAD() {}

	void EVENT_LOAD(){}
	void EVENT_INIT();
	void EVENT_UPDATE(float dt);
	void EVENT_FREE();
	void EVENT_UNLOAD() {}

	void PAUSE_LOAD(){}
	void PAUSE_INIT();
	void PAUSE_UPDATE(float dt);
	void PAUSE_FREE();
	void PAUSE_UNLOAD() {}

	bool NORMAL_TO_EVENT();
	bool NORMAL_TO_PAUSE();
	bool EVENT_TO_NORMAL();
	bool PAUSE_TO_NORMAL();
	
	typedef std::map<std::string,OwAICharacter*> AIListType;
	AIListType m_aiList;

	bool m_isPaused;
	// UI
	OwDialogUI * m_dialog;
	OwControlUITypeB * m_controlUI;
};


#endif