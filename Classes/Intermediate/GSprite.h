#ifndef __G_SPRITE_H__
#define __G_SPRITE_H__

#include <cocos2d.h>

// Intermediate class between engine and game.
// All instances of sprite calls in game must call this.
class GLayer;
class GSprite
{
public:
    GSprite();
    ~GSprite();
    
    void addSpriteToLayer (GLayer * layer);
private:
    cocos2d::CCSprite * m_sprite;
};

#endif //__G_SPRITE_H__