#ifndef __InventoryBag_H__
#define __InventoryBag_H__

#include <vector>

#include "..\Enum\ItemEnum.h"

class InventoryBag
{
public:
	InventoryBag(int slots);
	~InventoryBag();

	bool addItem(ItemEnum item, int slot = -1 );
	bool addItem(ItemEnum item, int bag, int slot );
	bool removeItem(int slot);
	bool removeItem(int bag, int slot);
	bool swapItems( int index1, int index2 );
	bool swapItems( int bag1, int index1, int bag2, int index2 );
	bool discardItem( int slot );
	bool discardItem( int bag, int slot );
	

	void outputInventoryBag();

	inline ItemEnum getItemByIndex(int index) { return m_items[index].item; }
	inline ItemEnum getItemByIndex(int bag, int index) { return m_items[bag * SPACE_PER_BAG + index].item; }
	inline int getItemStacksByIndex(int index) { return m_items[index].stacks; }
	inline int getItemStacksByIndex(int bag, int index) { return m_items[bag * SPACE_PER_BAG + index].stacks; }

	inline int getSpace() { return m_items.size(); }
	inline int getBags() { return ( getSpace() - 1 ) / getSpacePerBag() + 1; }
	inline int getSpacePerBag() { return SPACE_PER_BAG; }
	inline int setSpace( int space ) { return m_items.size(); }

private:
	struct ItemStorage
	{
		ItemStorage() : item(EMPTY), stacks(0) {}
		ItemEnum item;

		//0 means ItemStorage is emtpy
		//0ÇÕItemStorageÇ™ãÛÇ´Ç∆Ç¢Ç§èoëÉ
		int stacks; 
	};

	
	std::vector< ItemStorage > m_items;

	const static int SPACE_PER_BAG = 10;
};

#endif