#ifndef __OwTiledMapUserData_h__
#define __OwTiledMapUserData_h__

#include <vector>
#include <cocos2d.h>

class OwTiledMapUserData
{
public:
    void init(cocos2d::CCTMXTiledMap * map);
    void init(int width, int height);
    
	inline void* getUserData(cocos2d::CCPoint position) { return m_userDataList[getIndex(position.x, position.y)]; }
    inline void* getUserData(int x, int y) { return m_userDataList[getIndex(x,y)]; }
    
	inline void setUserData(int x, int y, void * data) { m_userDataList[getIndex(x,y)] = data; }
	inline void setUserData(cocos2d::CCPoint position, void * data) { m_userDataList[getIndex(position.x, position.y)] = data; }
private:
	inline int getIndex(int x, int y) { return x * m_width + y; }
    std::vector<void*> m_userDataList;
	int m_width, m_height;
};

#endif