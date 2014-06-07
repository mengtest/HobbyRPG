#include <cocos2d.h>

#include "Item\ItemManager.h"
#include "Inventory.h"

Inventory::Inventory()
{
	m_masterItemList.resize(ItemManager::getInstance().getItemTypeMax());
}

Inventory::~Inventory()
{
}

bool Inventory::addItem( int item, int amount )
{
	// TODO: max stacks
	m_masterItemList[item] += amount;
	CCLOG("[Inventory][addItem]: item id: %i = %i", item, m_masterItemList[item] );

	return true;
}

bool Inventory::removeItem(int item, int amount)
{
	if ( m_masterItemList[item] != 0 )
	{
		m_masterItemList[item] -= amount;
		CCLOG("[Inventory][removeItem] success: item id:%i = %i", item, m_masterItemList[item] );
		return true;
	}
	CCLOG("[Inventory][removeItem] failed: item id:%i = %i", item, m_masterItemList[item] );

	
	return false;
}

void Inventory::outputInventory()
{
	CCLOG("-----------START INVENTORY--------------");

	ItemListType::iterator beg = m_masterItemList.begin();
	ItemListType::iterator end = m_masterItemList.end();
	int i = 0;
	for ( ; beg != end; ++beg )
	{
		CCLOG("item id: %i = %i", i, *beg );
		++i;

	}
	CCLOG("-----------END INVENTORY--------------");


}


