#include <cocos2d.h>

#include "Item\ItemManager.h"
#include "Enum\ItemStatEnum.h"
#include "InventoryBag.h"

InventoryBag::InventoryBag(int slots)
{
	m_items.resize(slots, ItemStorage() );
}

InventoryBag::~InventoryBag()
{
	m_items.empty();
}

bool InventoryBag::addItem( ItemEnum item, int bag, int slot )
{
	// -1 will cause problems. For now we don't cater to insertion directly into 'bags'
	// TODO: Insert directly into bags
	if ( slot < 0 )
	{
		CCLOG("[InventoryBag][addItem]: slot %d is invalid", slot);
		return false;
	}

	return addItem( item, bag * SPACE_PER_BAG + slot);
}

bool InventoryBag::addItem(ItemEnum item, int slot )
{
	if ( slot > getSpace() || slot < -1 )
	{
		CCLOG("[InventoryBag][addItem]: slot %d is invalid", slot);
		return false;
	}

	if ( slot == -1 )
	{
		int max_stacks = atoi(ItemManager::getInstance().getItemStat( item, STACKS ).c_str() );
		
		// アイテムは積み重ねられます
		// Item is stackable
		if ( max_stacks > 1 )
		{
			// アイテムの存在を探します
			// Look if there is already such an item
			std::vector< ItemStorage >::iterator beg = m_items.begin();
			std::vector< ItemStorage >::iterator end = m_items.end();
			int i = 0;
			int empty_slot = -1;
			for ( ; beg != end; ++beg )
			{
				// 増加してみます
				// try to add to it
				if ( beg->item == item && beg->stacks < max_stacks )
				{
					++beg->stacks;
					CCLOG("[InventoryBag][addItem]: adding item at %i for %s", slot, ItemManager::getInstance().getItemStat( item, NAME ).c_str());
					return true;
				}

				if ( empty_slot == -1 &&  beg->item == EMPTY )
				{
					empty_slot = i;
				}

				++i;
			}

			// 空きのスロットを見つけました
			// Empty slot found
			if ( empty_slot != -1 )
			{
				m_items[empty_slot].item = item;
				m_items[empty_slot].stacks = 1;
				return true;
			}

			CCLOG("[InventoryBag][addItem]: No Space at slot %i for %s", slot, ItemManager::getInstance().getItemStat( item, NAME ).c_str());
			return false;
		}

		else // Not stackable
		{
			// 空きのスロットを探索します
			// Find empty slot
			std::vector< ItemStorage >::iterator beg = m_items.begin();
			std::vector< ItemStorage >::iterator end = m_items.end();
			for ( ; beg != end; ++beg )
			{
				if ( beg->item == EMPTY )
				{
					beg->item = item;
					beg->stacks = 1;
					CCLOG("[InventoryBag][addItem]: adding item at %i for %s", slot, ItemManager::getInstance().getItemStat( item, NAME ).c_str());
					return true;
				}
			}

			CCLOG("[InventoryBag][addItem]: No Space at slot %i for %s", slot, ItemManager::getInstance().getItemStat( item, NAME ).c_str());
			return false;
		}

	} 

	// there's an indicated slot　
	// 指定スロットはあります
	else 
	{
		//　完全に空きです
		// Completely empty
		if ( m_items[slot].item == EMPTY )
		{
			m_items[slot].item = item;
			m_items[slot].stacks = 1;
			CCLOG("[InventoryBag][addItem]: adding item at %i for %s", slot, ItemManager::getInstance().getItemStat( item, NAME ).c_str());
			return true;
		}

		// 同じアイテムを持ています
		// Contains same item
		else if (m_items[slot].item == item )
		{
			int max_stacks = atoi(ItemManager::getInstance().getItemStat( item, STACKS ).c_str() );
		
			// アイテムは積み重ねられます
			// Item is stackable
			if ( max_stacks > 1 && m_items[slot].stacks < max_stacks )
			{
				++m_items[slot].stacks;
				CCLOG("[InventoryBag][addItem]: adding item at %i for %s", slot, ItemManager::getInstance().getItemStat( item, NAME ).c_str());
				return true;
			}

			CCLOG("[InventoryBag][addItem]: No Space at slot %i for %s", slot, ItemManager::getInstance().getItemStat( item, NAME ).c_str());
			return false;
		}

		else {
			CCLOG("[InventoryBag][addItem]: No Space at slot %i for %s", slot, ItemManager::getInstance().getItemStat( item, NAME ).c_str());
			return false;
		}

		
	}


}

bool InventoryBag::removeItem(int bag, int slot)
{
	return removeItem(bag * SPACE_PER_BAG + slot);
}

bool InventoryBag::removeItem(int slot)
{
	m_items[slot].item = EMPTY;
	m_items[slot].stacks = 0;
	return true;
}

void InventoryBag::outputInventoryBag()
{
	CCLOG("-----------START InventoryBag--------------");

	std::vector< ItemStorage >::iterator beg = m_items.begin();
	std::vector< ItemStorage >::iterator end = m_items.end();
	int i = 0;
	for ( ; beg != end; ++beg )
	{
		CCLOG("%i: %s = %i", i++, ItemManager::getInstance().getItemStat( beg->item, NAME ).c_str(), beg->stacks );
	}
	CCLOG("-----------END InventoryBag--------------");


}

bool InventoryBag::swapItems( int bag1, int index1, int bag2, int index2 )
{
	return swapItems( bag1 * SPACE_PER_BAG + index1, bag2 * SPACE_PER_BAG + index2 );
}

bool InventoryBag::swapItems( int index1, int index2 )
{
	ItemStorage temp = m_items[index2];
	m_items[index2] = m_items[index1];
	m_items[index1] = temp;
	return true;
}

bool InventoryBag::discardItem(int bag, int slot)
{
	return discardItem(bag * SPACE_PER_BAG + slot);
}

bool InventoryBag::discardItem(int slot)
{
	if ( m_items[slot].item == EMPTY )
	{
		CCLOG("[InventoryBag][discardItem]: item already empty at slot %d", slot );
		return false;
	}

	if ( m_items[slot].stacks > 1 )
	{
		m_items[slot].stacks -= 1;
	}

	else // stacks <= 1
	{
		m_items[slot].item = EMPTY;
		m_items[slot].stacks = 0;
	}

	return true;
}