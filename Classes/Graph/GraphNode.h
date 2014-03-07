#ifndef __GRAPH_NODE_H__
#define __GRAPH_NODE_H__

class GraphNode
{
public:
    GraphNode(float x = 0.f, float y = 0.f, float z = 0.f)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    inline float getX() { return x; }
    inline float getY() { return y; }
    inline float getZ() { return z; }
    inline void setX( float x ) { this->x = x; }
    inline void setY( float y ) { this->y = y; }
    inline void setZ( float z ) { this->z = z; }
    
    inline void * getUserData() { return m_userData; } const
    inline void setUserData(void * userData) { m_userData = userData; }

private:
    float x;
    float y;
    float z;
    void * m_userData;
};

#endif 