#ifndef __OwControlUITypeB_H__
#define __OwControlUITypeB_H__

#include <string>
#include <vector>
#include "cocos2d.h"

#include "cocos-ext.h"
typedef void(cocos2d::CCObject::*CallbackHandler)();
#define ow_selector(_SELECTOR) static_cast<CallbackHandler>(&_SELECTOR)

class OwPlayerController;
class OwControlUITypeBButton;

class OwControlUITypeB : public cocos2d::CCLayer
{
public:
	OwControlUITypeB( OwPlayerController * player_controller ) ;
	 
	bool onInit();
	void onUpdate(float dt);
	void onDestroy();

	void processTouchBegin(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	void processTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	void processTouchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);

private:
	OwPlayerController * m_playerController;
	
	OwControlUITypeBButton * m_upButton;
	OwControlUITypeBButton * m_downButton;
	OwControlUITypeBButton * m_rightButton;
	OwControlUITypeBButton * m_leftButton;
	OwControlUITypeBButton * m_aButton;
	//OwControlUITypeBButton * m_bButton;

};

#endif