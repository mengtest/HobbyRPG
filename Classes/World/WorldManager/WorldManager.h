#ifndef __WORLD_MANAGER_H__
#define __WORLD_MANAGER_H__

#include <cocos2d.h>

#include "..\..\Graph\GraphNode.h"

#include "../../AI/AIHeaders.h"

class WorldDialogUI;
class Graph2D;
class WorldScene;
class EventManager;
class EventBase;
class WorldManager
{
public:
	static WorldManager * getInstance();
	static void destroy(); // MUST call this first AFTER using
	
	bool init( WorldScene * scene, const std::string& world_name, int origin_node_id );  // MUST call this first BEFORE using
	void release();
	void update(float dt);

	void addEvent( EventBase * event );

	void addChildToNodeLayer(cocos2d::CCNode * obj);
	void removeChildFromNodeLayer(cocos2d::CCNode * obj );
	void addChildToCharacterLayer(cocos2d::CCNode * obj);
	void removeChildFromCharacterLayer(cocos2d::CCNode * obj );
	void addChildToBackgroundLayer(cocos2d::CCNode * obj);
	void removeChildFromBackgroundLayer(cocos2d::CCNode * obj );

	bool processTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	void processTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	void processTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	void gotoOverworld( std::string t_where );

	WorldDialogUI * getDialog() { return m_dialog; }
private:
	enum NodeTypes
	{
		NOTHING,
		BATTLE, 
		OVERWORLD,
		MERCHANT
	};

	struct GraphUserData
	{
		std::string m_scriptName;
		NodeTypes m_type;
	};

	void readGraphData(const std::string& filename );
	void processNodeData(GraphNode& node);
	bool loadDialog();
	bool loadFSM();

	std::list<GraphUserData*> m_graphDatas;

	WorldManager();
	~WorldManager() {}

	WorldScene * m_scene;
	static WorldManager * instance;

	WorldDialogUI * m_dialog;

	Graph2D * m_graph;
	bool m_isInit;
	bool m_isEvent;

	cocos2d::CCSprite * m_character;

	int m_originNodeID;
	int m_currentNode;
	std::string m_worldName;

	EventManager * m_eventManager;

	// Statemachine
	cStateMachine<WorldManager> * m_stateMachine;
	void NORMAL_LOAD(){}
	void NORMAL_INIT(){}
	void NORMAL_UPDATE(float dt) {}
	void NORMAL_FREE(){}
	void NORMAL_UNLOAD() {}

	void EVENT_LOAD(){}
	void EVENT_INIT();
	void EVENT_UPDATE(float dt);
	void EVENT_FREE();
	void EVENT_UNLOAD() {}

	bool NORMAL_TO_EVENT();
	bool EVENT_TO_NORMAL();
};

#endif