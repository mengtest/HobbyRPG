#ifndef __OwControlUITypeBButton_H__
#define __OwControlUITypeBButton_H__

#include "cocos2d.h"
#include <string>




class OwControlUITypeBButton
{
public:
    OwControlUITypeBButton( const std::string& up_texture_name, const std::string& down_texture_name );
    ~OwControlUITypeBButton() {} 
    
    void update(float dt);
    void processTouchMoved( cocos2d::CCTouch * touch, cocos2d::CCEvent * event );
    void processTouchBegan( cocos2d::CCTouch * touch, cocos2d::CCEvent * event );
    void processTouchEnd( cocos2d::CCTouch * touch, cocos2d::CCEvent * event );

    void setUpTexture( const std::string& name );
    void setDownTexture( const std::string& name );
  
    void setPosition(cocos2d::CCPoint position);
    
    void setUpCallback(cocos2d::CCObject * instance,  void (cocos2d::CCObject::*funcToCall)(void));
    void setDownCallback(cocos2d::CCObject * instance,  void (cocos2d::CCObject::*funcToCall)(void));
    void setPressCallback(cocos2d::CCObject * instance,  void (cocos2d::CCObject::*funcToCall)(void));

	inline cocos2d::CCSprite * getSprite() { return m_currentTexture; }
    
private:
    std::string m_upTextureName;
    std::string m_downTextureName;
    cocos2d::CCSprite * m_currentTexture;
    
    cocos2d::CCPoint m_position;

    void (cocos2d::CCObject::*m_upCallback)(void);
    void (cocos2d::CCObject::*m_downCallback)(void);
	void (cocos2d::CCObject::*m_pressCallback)(void);
    
    cocos2d::CCObject * m_upCallbackInstance;
    cocos2d::CCObject * m_downCallbackInstance;
    cocos2d::CCObject * m_pressCallbackInstance;

    bool m_bIsDown, m_bPrevIsDown;
    
    bool checkCollision(cocos2d::CCPoint point);

};

#endif



