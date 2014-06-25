#ifndef __BATTLE_ENTITY_H__
#define __BATTLE_ENTITY_H__

#include "cocos2d.h"

class BattleEntity
{
public:
	BattleEntity();
	
	// abstract functions you must implement
	virtual void update(float dt) = 0;
	virtual int getInitiative() = 0;

    
    void setPosition( cocos2d::CCPoint position );
    
	inline const std::string& getName() const { return m_name; }
	inline const cocos2d::CCPoint& getPosition() const { return m_sprite->getPosition(); }
	inline const cocos2d::CCSprite * getSprite() { return m_sprite; }; 

	// careful with this
	void addSpriteToLayer( cocos2d::CCLayer * layer );

protected:
    void setSprite(const std::string& spriteBaseName, const std::string& initialSpriteFrameName);

	cocos2d::CCSprite * m_sprite;
	std::string m_spriteBaseName;
	std::string m_name;
	cocos2d::CCLayer * m_layer;
};

#endif 