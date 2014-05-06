#ifndef __BattleScene_H__
#define __BattleScene_H__

#include "cocos2d.h"

class cBaseUI;
class CustomActionManager;
class BattleScene : public cocos2d::CCLayer
{
private:
	cBaseUI* ui;
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
	void onExit();
	void onEnter();

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // implement the "static node()" method manually
    CREATE_FUNC(BattleScene);

	void update(float dt);

	void registerWithTouchDispatcher();
 
	bool ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	void ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	inline cocos2d::CCLayer * getGameLayer() { return m_gameLayer; }
	inline cocos2d::CCLayer * getUILayer() { return m_uiLayer; }
private:
	CustomActionManager* m_customActionManager;
	cocos2d::CCLayer * m_gameLayer;
	cocos2d::CCLayer * m_uiLayer;

};

#endif // __BattleScene_H__
