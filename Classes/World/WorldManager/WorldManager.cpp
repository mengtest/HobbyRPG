#include <cocos2d.h>

#include "WorldManager.h"
#include "..\..\World\WorldScene.h"
#include "..\..\World\WorldDialogUI\WorldDialogUI.h"
#include "..\..\World\WorldEvents\WorldEventDialog.h"

#include "..\..\Common\Common.h"
#include "..\..\Config\Config.h"

#include "..\..\Graph\Graph2D.h"
#include "..\..\Graph\GraphNode.h"

#include "CCLuaEngine.h"

#include "..\..\Events\EventManager.h"

#include "..\..\Overworld\OverworldScene.h"

USING_NS_CC;
using namespace std;


WorldManager* WorldManager::instance = 0;

WorldManager::WorldManager()
	: m_isInit(false), 
	  m_eventManager(0),
	  m_isEvent(false)
{
}

WorldManager * WorldManager::getInstance()
{
	if ( !instance )
	{
		instance = new WorldManager();
	}

	return instance;
}

bool WorldManager::init(WorldScene * scene, const std::string& world_name, int origin_node_id)
{
	if ( m_isInit )
	{
		CCLOG("[WorldManager][init]: Already Init, please call Release");
		return false;
	}

	m_scene = scene;
	m_isInit = true;
	m_originNodeID = m_currentNode = origin_node_id;
	m_worldName = world_name;

	if ( !loadDialog() )
	{
		CCLOG("[WorldManager][init]: loadDialog() failed");
		return false;
	}

	if ( !loadFSM() )
	{
		CCLOG("[WorldManager][init]: loadFSM() failed");
		return false;
	}

	// load event manager
	m_eventManager = new EventManager();
	
	// background
	CCSprite * background = CCSprite::createWithSpriteFrameName("world_map.png");
	background->setPositionX(Config::getInstance().getDesignWidth() * 0.5f);
	background->setPositionY(Config::getInstance().getDesignHeight() * 0.5f);
	this->addChildToBackgroundLayer(background);

	// test scene
	// render nodes //
	m_graph = new Graph2D();
	m_graph->addNode(200.f, 200.f);
	m_graph->addNode(100.f, 100.f);
	m_graph->setAdjAll();

	/*for ( unsigned int i = 0 ; i < m_graph->getGraph().size(); ++i )
	{
		std::stringstream test;
		for ( unsigned int j = 0; j < m_graph->getGraph().size(); ++j )
		{
			test << m_graph->getAdjMatrix()[i][j];	
		}

		CCLOG("%s", test.str().c_str() );
	}*/
	
	readGraphData( "maps/world_maps/MainWorld.csv");
	
	/*for ( unsigned int i = 0 ; i < m_graph->getGraph().size(); ++i )
	{
		GraphNode& temp = m_graph->getNode(i);
		
		// add graph user data
		GraphUserData * data = new GraphUserData();
		std::stringstream str;
		str << world_name << "_node" << i << "()";
		data->m_scriptName =  str.str();
		data->m_type = NodeTypes::OVERWORLD;

		m_graphDatas.push_back(data);
		temp.setUserData(data);

		// add graph graphic
		CCSprite * test = CCSprite::createWithSpriteFrameName("world_node.png");
		test->setPosition(ccp( temp.getX(), temp.getY() ));
		this->addChildToNodeLayer(test);
	}*/

	m_character = CCSprite::createWithSpriteFrameName("chika");
	float x = m_graph->getNode(origin_node_id).getX();
	float y = m_graph->getNode(origin_node_id).getY();
	m_character->setPosition( ccp( x, y ));
	this->addChildToNodeLayer(m_character);

	return true;
}

bool WorldManager::loadDialog()
{
	//dialog test//
	m_dialog = new WorldDialogUI();
	if ( m_dialog->load("menu_background.png"))
	{
		m_scene->getUILayer()->addChild(m_dialog->getSprite());
		return true;
	}

	return false;
}

bool WorldManager::loadFSM()
{
	// State Machine //
	m_stateMachine = new cStateMachine<WorldManager>(this);

	cStateTemplate<WorldManager> * normalState;
	normalState = m_stateMachine->AddState(&WorldManager::NORMAL_LOAD,
											&WorldManager::NORMAL_INIT,
											&WorldManager::NORMAL_UPDATE,
											&WorldManager::NORMAL_FREE,
											&WorldManager::NORMAL_UNLOAD );

	cStateTemplate<WorldManager> * eventState;
	eventState = m_stateMachine->AddState( &WorldManager::EVENT_LOAD,
											  &WorldManager::EVENT_INIT,
											  &WorldManager::EVENT_UPDATE,
											  &WorldManager::EVENT_FREE,
											  &WorldManager::EVENT_UNLOAD );
	
	normalState->AddTriggerCheck( &WorldManager::NORMAL_TO_EVENT, eventState);
	eventState->AddTriggerCheck( &WorldManager::EVENT_TO_NORMAL, normalState);
	
	m_stateMachine->SetCurrentState(normalState);

	return true;
}


void WorldManager::update(float dt)
{
	m_stateMachine->OnUpdate(dt);
	m_dialog->update(dt);
}


void WorldManager::destroy()
{
	//clean up here
	if ( instance->m_isInit )
	{
		instance->release();
	}

	
}

void WorldManager::release()
{
	if ( !m_isInit )
	{
		CCLOG("[WorldManager][release]: Already Released, please call Init");
		return;
	}

	m_isInit = false;

	std::list<GraphUserData*>::iterator beg, end;
	for ( beg = m_graphDatas.begin(), end = m_graphDatas.end(); beg != end; ++beg )
	{
		delete (*beg);
	}
	m_graphDatas.clear();

	CC_SAFE_DELETE(m_graph);
	CC_SAFE_DELETE(m_dialog);
	CC_SAFE_DELETE(m_eventManager);
}

void WorldManager::addEvent( EventBase * event )
{
	m_eventManager->addEvent(event);
}

void WorldManager::addChildToNodeLayer( cocos2d::CCNode * obj )
{
	m_scene->getNodeLayer()->addChild(obj); 
}

void WorldManager::removeChildFromNodeLayer(cocos2d::CCNode * obj )
{
    m_scene->getNodeLayer()->removeChild(obj);
}

void WorldManager::addChildToCharacterLayer( cocos2d::CCNode * obj )
{
	m_scene->getCharacterLayer()->addChild(obj); 
}

void WorldManager::removeChildFromCharacterLayer(cocos2d::CCNode * obj )
{
	m_scene->getCharacterLayer()->removeChild(obj);
}

void WorldManager::addChildToBackgroundLayer( cocos2d::CCNode * obj )
{
	m_scene->getBackgroundLayer()->addChild(obj); 
}

void WorldManager::removeChildFromBackgroundLayer(cocos2d::CCNode * obj )
{
	m_scene->getBackgroundLayer()->removeChild(obj);
}

bool WorldManager::processTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
	m_dialog->processTouchBegan();

	if ( !m_isEvent )
	{
		// temp touch code
		float width = Common::getNormalizedPositionX(0.1f);
		float height = Common::getNormalizedPositionY(0.1f);
	
		for ( unsigned int i = 0 ; i < m_graph->getGraph().size(); ++i )
		{
			CCRect rect = CCRect(m_graph->getNode(i).getX() - width/2, m_graph->getNode(i).getY() - height/2, width, height);
			if ( rect.containsPoint( touch->getLocation() ) )
			{
				if ( m_currentNode == i )
				{
					processNodeData(m_graph->getNode(m_currentNode));
				}

				else
				{
					float x = m_graph->getNode(i).getX();
					float y = m_graph->getNode(i).getY();
					m_character->setPosition( ccp( x, y ));
					m_currentNode = i;
				}
			}
		}
	}

	return true;
}

void WorldManager::processTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
}

void WorldManager::processTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
}

void WorldManager::gotoOverworld(std::string t_where)
{
	CCLOG("[WorldManager][gotoOverworld] called at location: %s", t_where.c_str() );
	//CCDirector::sharedDirector()->replaceScene(OverworldScene::scene(t_where.c_str(), 10, 17) );
}

void WorldManager::processNodeData(GraphNode& node)
{
	GraphUserData * data = (GraphUserData*)(node.getUserData());
	switch (data->m_type)
	{
	case NodeTypes::NOTHING:
		CCLOG("[WorldManager][processNodeData] NOTHING");
		break;
	case NodeTypes::BATTLE:
		CCLOG("[WorldManager][processNodeData] BATTLE");
		break;
	case NodeTypes::MERCHANT:
		CCLOG("[WorldManager][processNodeData] MERCHANT");
		break;
	case NodeTypes::OVERWORLD:
		CCLOG("[WorldManager][processNodeData] OVERWORLD");
		CCLOG("GO! %s", ((GraphUserData*)(m_graph->getNode(m_currentNode).getUserData()))->m_scriptName.c_str() );
		CCLuaEngine::defaultEngine()->executeString(((GraphUserData*)(m_graph->getNode(m_currentNode).getUserData()))->m_scriptName.c_str());
		break;
	};
}

void WorldManager::readGraphData(const std::string& filename )
{

}