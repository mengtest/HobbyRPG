#ifndef __BattleManager_H__
#define __BattleManager_H__

#include <cocos2d.h>
#include <string>
#include <map>

#include "../../AI/AIHeaders.h"
#include "../../Enum/DirectionEnum.h"

class BattleScene;
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

	BattleCharacter * addBattleCharacter(cocos2d::CCPoint position, std::string name, std::string initialSpriteFrameName, bool enemy);

private:
	bool m_isInit;
	
	BattleManager() ;
	~BattleManager() {}

	BattleScene * m_scene;

	static BattleManager * instance;

	std::map<std::string, BattleCharacter*> m_characterList;
};


#endif