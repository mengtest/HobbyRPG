#include "OwEntityBase.h"
#include "../OwTiledMapUserData/OwTiledMapUserData.h"
#include "../OwManager/OwManager.h"

using namespace std;
USING_NS_CC;

OwEntityBase::OwEntityBase(CCPoint position, const std::string& name, 
							const string& spriteBaseName, const std::string& initialSpriteFrameName)
							: m_name(name), m_sprite(0), m_spriteName(), m_layer(0)
{
	setSprite(spriteBaseName, initialSpriteFrameName);
	setPosition(position);
}

void OwEntityBase::setSprite(const std::string& spriteBaseName, const std::string& initialSpriteFrameName)
{
	// Sprite creation
	// Spriteを作成します
	m_sprite = CCSprite::createWithSpriteFrameName( initialSpriteFrameName.c_str() );
	if ( !m_sprite ) {
		CCLOG("[OwEntityBase][setSprite][error]: m_sprite is null!");
		return;
	}
	m_spriteName = spriteBaseName;
}

void OwEntityBase::setPosition( cocos2d::CCPoint position )
{
	if ( !m_sprite ) {
		CCLOG("[OwEntityBase][setPosition][error]: m_sprite is null!");
		return;
	}
	m_sprite->setPosition(position);
}


bool OwEntityBase::checkWorldBounds(CCPoint position)
{
	OwManager * mgr = OwManager::getInstance();
	if ( !mgr ) {
		CCLOG("[OwEntityBase][checkWorldBounds][error]: mgr is null!");
		return false;
	}

	if ( !mgr->getTiledMap() )
	{
		CCLOG("[OwEntityBase][checkWorldBounds][error]: mgr->getTiledMap() is null!");
		return false;
	}


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
	if ( !mgr ) {
		CCLOG("[OwEntityBase][checkMetaBounds][error]: mgr is null!");
		return false;
	}

	if ( !mgr->getMetaLayer() ) {
		CCLOG("[OwEntityBase][checkMetaBounds][error]: mgr->getMetaLayer() is null!");
		return false;
	}

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
	if ( !mgr ) {
		CCLOG("[OwEntityBase][occupyTile][error]: mgr is null!");
		return;
	}

	if ( !mgr->getMetaLayer() ) {
		CCLOG("[OwEntityBase][occupyTile][error]: mgr->getMetaLayer() is null!");
		return;
	}

	if ( !mgr->getTiledMapUserData() ) {
		CCLOG("[OwEntityBase][occupyTile][error]: mgr->getTiledMapUserData() is null!");
		return;
	}

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
	if ( !mgr ) {
		CCLOG("[OwEntityBase][unoccupyTile][error]: mgr is null!");
		return;
	}

	if ( !mgr->getMetaLayer() ) {
		CCLOG("[OwEntityBase][unoccupyTile][error]: mgr->getMetaLayer() is null!");
		return;
	}

	if ( !mgr->getTiledMapUserData() ) {
		CCLOG("[OwEntityBase][unoccupyTile][error]: mgr->getTiledMapUserData() is null!");
		return;
	}

	CCPoint tileCoord = this->convertPositionToTileCoord(Position);
    int tileGid = mgr->getMetaLayer()->tileGIDAt(tileCoord);
    if ( tileGid ) {
		mgr->getTiledMapUserData()->setUserData(tileCoord, 0);
		mgr->getMetaLayer()->removeTileAt(tileCoord);

    }

}

void OwEntityBase::snapToTile()
{
	if ( !m_sprite ) {
		CCLOG("[OwEntityBase][snapToTile][error]: m_sprite is null!");
		return;
	}
	// Tileの中心で位置を設定する
	m_sprite->setPosition(getTileCenter(getPosition()));

}


CCPoint OwEntityBase::convertPositionToTileCoord(CCPoint position)
{
	OwManager * mgr = OwManager::getInstance();
	if ( !mgr ) {
		CCLOG("[OwEntityBase][convertPositionToTileCoord][error]: mgr is null!");
		return ccp(-1, -1);
	}

	if ( !mgr->getTiledMap() ) {
		CCLOG("[OwEntityBase][convertPositionToTileCoord][error]: mgr->getTiledMap() is null!");
		return ccp(-1, -1);
	}

	int x = position.x / mgr->getTiledMap()->getTileSize().width;
	int y = position.y / mgr->getTiledMap()->getTileSize().height;
	y = mgr->getTiledMap()->getMapSize().height - y - 1;

    return ccp(x, y);
}

CCPoint OwEntityBase::convertTileCoordToPosition(CCPoint position)
{
	OwManager * mgr = OwManager::getInstance();
	if ( !mgr ) {
		CCLOG("[OwEntityBase][convertPositionToTileCoord][error]: mgr is null!");
		return ccp(-1, -1);
	}

	if ( !mgr->getTiledMap() ) {
		CCLOG("[OwEntityBase][convertPositionToTileCoord][error]: mgr->getTiledMap() is null!");
		return ccp(-1, -1);
	}

	int x = position.x * mgr->getTiledMap()->getTileSize().width + mgr->getTiledMap()->getTileSize().width * 0.5f;
	
	position.y = mgr->getTiledMap()->getMapSize().height - position.y - 1;
	int y = position.y * mgr->getTiledMap()->getTileSize().height + mgr->getTiledMap()->getTileSize().height * 0.5f;
	
		
	return ccp(x, y);
}

// TODO DEFENSIVE
CCPoint OwEntityBase::getTileCenter(CCPoint position)
{
	CCPoint result = convertTileCoordToPosition( convertPositionToTileCoord(position));
	return result;
}

// TODO DEFENSIVE
CCPoint OwEntityBase::getTiledPosition()
{
	return convertPositionToTileCoord(getPosition());
}

void OwEntityBase::addSpriteToLayer( cocos2d::CCLayer * layer )
{
	if ( m_layer != 0 )
	{
		m_layer->removeChild(m_sprite);
	}

	layer->addChild(m_sprite);
	m_layer = layer;
}