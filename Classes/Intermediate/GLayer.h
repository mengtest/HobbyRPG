#ifndef __G_LAYER_H__
#define __G_LAYER_H__

#include <cocos2d.h>

// Intermediate class between engine and game.
// All instances of sprite calls in game must call this.
class GLayer
{
public:
    GLayer();
    ~GLayer();
    
private:
    cocos2d::CCLayer * m_layer;

};

#endif