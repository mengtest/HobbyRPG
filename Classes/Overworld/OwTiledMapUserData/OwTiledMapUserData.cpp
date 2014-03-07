
#include "OwTiledMapUserData.h"


 void OwTiledMapUserData::init(cocos2d::CCTMXTiledMap * map)
 {
	 init(map->getMapSize().width, map->getMapSize().height);
 }

 void OwTiledMapUserData::init(int width, int height)
 {
	 m_width = width;
	 m_height = height;
	 m_userDataList.resize(width * height);
 }



