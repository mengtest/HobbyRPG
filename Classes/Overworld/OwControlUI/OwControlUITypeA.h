#ifndef __OwControlUITypeA_H__
#define __OwControlUITypeA_H__

#include <string>
#include <vector>
#include "cocos2d.h"

#include "cocos-ext.h"

#include "../../UI/cBaseUI.h"

class OwPlayerController;
class OwControlUITypeA : public cBaseUI
{
public:
	OwControlUITypeA( OwPlayerController * player_controller ) ;
	 
	bool onInit();
	void onUpdate(float dt);
	void onDestroy();

	void processTouchBegin(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	void processTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	void processTouchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);

private:
	OwPlayerController * m_playerController;

	bool m_bIsTouched;
	cocos2d::CCPoint m_startTouchPosition;
	float m_fInteractTimer;
	float m_fInteractDuration;

	int m_moveDirection;

	const static int MOVE_LEFT = 0x01;
	const static int MOVE_RIGHT = 0x02;
	const static int MOVE_UP = 0x04;
	const static int MOVE_DOWN = 0x08;
};

#endif