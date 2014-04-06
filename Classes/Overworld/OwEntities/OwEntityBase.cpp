#include "OwEntityBase.h"
#include "../OwTiledMapUserData/OwTiledMapUserData.h"
#include "../OwManager/OwManager.h"

using namespace std;
USING_NS_CC;

OwEntityBase::OwEntityBase(CCPoint position, const std::string& name, 
							const string& spriteBaseName, const std::string& initialSpriteFrameName, int id )
							: m_name(name), m_id(id)
{
	setSprite(spriteBaseName, initialSpriteFrameName);
	setPosition(position);
}

void OwEntityBase::setSprite(const std::string& spriteBaseName, const std::string& initialSpriteFrameName)
{
	// Sprite creation
	// Spriteを作成します
	m_sprite = CCSprite::createWithSpriteFrameName( initialSpriteFrameName.c_str() );
	m_spriteName = spriteBaseName;
}

void OwEntityBase::setPosition( cocos2d::CCPoint position )
{
	m_sprite->setPosition(position);
}


bool OwEntityBase::checkWorldBounds(CCPoint position)
{
	OwManager * mgr = OwManager::getInstance();
	// Tilemapの境界をチェークする
	if (getPosition().x <= (mgr->getTiledMap()->getMapSize().width * mgr->getTiledMap()->getTileSize().width) &&
        getPosition().y <= (mgr->getTiledMap()->getMapSize().height * mgr->getTiledMap()->getTileSize().height) &&
        getPosition().y >= 0 &&
        getPosition().x >= 0 )
	{
		return true;
	}

	return false;
}

bool OwEntityBase::checkMetaBounds(CCPoint position)
{
	OwManager * mgr = OwManager::getInstance();
	CCPoint tileCoord = this->convertPositionToTileCoord(position);
	int tileGid = mgr->getMetaLayer()->tileGIDAt(tileCoord);
    if ( tileGid ) {
		CCDictionary *properties = mgr->getTiledMap()->propertiesForGID(tileGid);
        if (properties) {
            const CCString * collision = properties->valueForKey("Collidable");
            if (collision && (collision->compare("True") == 0)) {
                return false;
            }
        }
    }

	return true;
}

void OwEntityBase::occupyTile(CCPoint Position)
{
	OwManager * mgr = OwManager::getInstance();
	CCPoint tileCoord = this->convertPositionToTileCoord(Position);
	int tileGid = mgr->getMetaLayer()->tileGIDAt(tileCoord);
    if ( !tileGid ) {
		mgr->getMetaLayer()->setTileGID(mgr->getMetaLayer()->getTileSet()->m_uFirstGid + COLLIDABLE, tileCoord);
		mgr->getTiledMapUserData()->setUserData(tileCoord, this);
    }

}

void OwEntityBase::unoccupyTile(CCPoint Position)
{
	OwManager * mgr = OwManager::getInstance();
	CCPoint tileCoord = this->convertPositionToTileCoord(Position);
    int tileGid = mgr->getMetaLayer()->tileGIDAt(tileCoord);
    if ( tileGid ) {
		mgr->getTiledMapUserData()->setUserData(tileCoord, 0);
		mgr->getMetaLayer()->removeTileAt(tileCoord);

    }

}

void OwEntityBase::snapToTile()
{
	// Tileの中心で位置を設定する
	m_sprite->setPosition(getTileCenter(getPosition()));

}


CCPoint OwEntityBase::convertPositionToTileCoord(CCPoint position)
{
	OwManager * mgr = OwManager::getInstance();
	int x = position.x / mgr->getTiledMap()->getTileSize().width;
	int y = position.y / mgr->getTiledMap()->getTileSize().height;
	y = mgr->getTiledMap()->getMapSize().height - y - 1;

    return ccp(x, y);
}

CCPoint OwEntityBase::convertTileCoordToPosition(CCPoint position)
{
	OwManager * mgr = OwManager::getInstance();
	int x = position.x * mgr->getTiledMap()->getTileSize().width + mgr->getTiledMap()->getTileSize().width * 0.5f;
	
	position.y = mgr->getTiledMap()->getMapSize().height - position.y - 1;
	int y = position.y * mgr->getTiledMap()->getTileSize().height + mgr->getTiledMap()->getTileSize().height * 0.5f;
	
		
	return ccp(x, y);
}

CCPoint OwEntityBase::getTileCenter(CCPoint position)
{
	CCPoint result = convertTileCoordToPosition( convertPositionToTileCoord(position));
	return result;
}

CCPoint OwEntityBase::getTiledPosition()
{
	return convertPositionToTileCoord(getPosition());
}