#ifndef __WORLDSCENE_H__
#define __WORLDSCENE_H__

#include "cocos2d.h"

class WorldScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
	void onExit();
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene(int origin_node);

	// a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(WorldScene);

	void update(float dt);

	void registerWithTouchDispatcher();
 
	bool ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	void ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	cocos2d::CCLayer * getNodeLayer() { return m_nodeLayer; }
	cocos2d::CCLayer * getBackgroundLayer() { return m_backgroundLayer; }
	cocos2d::CCLayer * getCharacterLayer() { return m_characterLayer; }
	cocos2d::CCLayer * getUILayer() { return m_characterLayer; }

private:
	cocos2d::CCLayer * m_backgroundLayer;
	cocos2d::CCLayer * m_nodeLayer;
	cocos2d::CCLayer * m_characterLayer;
	cocos2d::CCLayer * m_uiLayer;

	static int m_originNode;
};

#endif