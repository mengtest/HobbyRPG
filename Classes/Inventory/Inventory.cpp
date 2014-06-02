#include <cocos2d.h>

#include "Item\ItemManager.h"
#include "Enum\ItemStatEnum.h"
#include "Inventory.h"

Inventory::Inventory()
{
	m_masterItemList.resize(ItemEnum::NUM_ITEMS.getValue());
}

Inventory::~Inventory()
{
}

bool Inventory::addItem( ItemEnum item, int amount )
{
	// TODO: max stacks
	m_masterItemList[item.getValue()] += amount;
	CCLOG("[Inventory][addItem]: %s = %i", ItemManager::getInstance().getItemStat( item, ItemStatEnum::NAME ).c_str(), m_masterItemList[item.getValue()] );

	return true;
}

bool Inventory::removeItem(ItemEnum item, int amount)
{
	if ( m_masterItemList[item.getValue()] != 0 )
	{
		m_masterItemList[item.getValue()] -= amount;
		CCLOG("[Inventory][removeItem] success: %s = %i", ItemManager::getInstance().getItemStat( item, ItemStatEnum::NAME ).c_str(), m_masterItemList[item.getValue()] );
		return true;
	}
	CCLOG("[Inventory][removeItem] failed: %s = %i", ItemManager::getInstance().getItemStat( item, ItemStatEnum::NAME ).c_str(), m_masterItemList[item.getValue()] );

	
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
		CCLOG("%i: %s = %i", i, ItemManager::getInstance().getItemStat( ItemEnum::getItemByIndex(i), ItemStatEnum::NAME ).c_str(), *beg );
		++i;

	}
	CCLOG("-----------END INVENTORY--------------");


}


