#include <cocos2d.h>

#include "Item\ItemManager.h"
#include "Enum\ItemStatEnum.h"
#include "Inventory.h"

Inventory::Inventory()
{
	m_masterItemList.resize(NUM_ITEMS);
}

Inventory::~Inventory()
{
}

bool Inventory::addItem( ItemEnum item, int amount )
{
	// TODO: max stacks
	m_masterItemList[item] += amount;
	CCLOG("[Inventory][addItem]: %s = %i", ItemManager::getInstance().getItemStat( item, ItemStatEnum::NAME ).c_str(), m_masterItemList[item] );

	return true;
}

bool Inventory::removeItem(ItemEnum item, int amount)
{
	if ( m_masterItemList[item] != 0 )
	{
		m_masterItemList[item] -= amount;
		CCLOG("[Inventory][removeItem] success: %s = %i", ItemManager::getInstance().getItemStat( item, ItemStatEnum::NAME ).c_str(), m_masterItemList[item] );
		return true;
	}
	CCLOG("[Inventory][removeItem] failed: %s = %i", ItemManager::getInstance().getItemStat( item, ItemStatEnum::NAME ).c_str(), m_masterItemList[item] );

	
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
		CCLOG("%i: %s = %i", i, ItemManager::getInstance().getItemStat( static_cast<ItemEnum>(i), ItemStatEnum::NAME ).c_str(), *beg );
		++i;

	}
	CCLOG("-----------END INVENTORY--------------");


}


