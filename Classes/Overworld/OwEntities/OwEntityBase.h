#ifndef __OWENTITYBASE_H__
#define __OWENTITYBASE_H__

#include "cocos2d.h"


class OwEntityBase
{
public:
	OwEntityBase(cocos2d::CCPoint position,
				const std::string& name, 
				const std::string& spriteName = "testsprite",
				int id = 0);

	void setSprite(const std::string& spriteName);
	void setPosition( cocos2d::CCPoint position );
	void setTiledMap( cocos2d::CCTMXTiledMap * tiledMap );

	virtual void update(float dt) {} 
	
	virtual void interact (OwEntityBase * ) {}
	//inline void setActive( bool active ) { m_bIsActive = active; }
	//inline bool getActive() { return m_bIsActive; }
	
	inline const std::string& getName() { return m_name; }
	inline cocos2d::CCSprite * getSprite() { return m_sprite; }
	inline cocos2d::CCPoint getPosition() { return m_sprite->getPosition(); }
	cocos2d::CCPoint getTiledPosition();
	
	virtual void callback( const std::string& msg, void * data) {}
protected:
	enum MetaDataEnum {
		COLLIDABLE = 0
	};


	void snapToTile();

	cocos2d::CCPoint convertPositionToTileCoord(cocos2d::CCPoint position);
	cocos2d::CCPoint convertTileCoordToPosition(cocos2d::CCPoint position);
	cocos2d::CCPoint getTileCenter(cocos2d::CCPoint position);

	bool checkWorldBounds(cocos2d::CCPoint position);
	bool checkMetaBounds(cocos2d::CCPoint position);

	void occupyTile(cocos2d::CCPoint Position);
	void unoccupyTile(cocos2d::CCPoint Position);

	cocos2d::CCSprite * m_sprite;
	std::string m_spriteName;
	std::string m_name;
	int m_id;
};

#endif 