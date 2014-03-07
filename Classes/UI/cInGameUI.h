#pragma once

#include "cBaseUI.h"
#include "PageManager.h"
#include <vector>

class Page;

class cInGameUI : public cBaseUI
{	
public:
	cInGameUI();
	virtual ~cInGameUI();
	bool onInit();
	void onUpdate(float dt);
	void onDestroy();
	void onControlClicked(const char* buttonname);
	std::string onConvertedString(const char* stringValue = NULL);
	std::string onConvertedImage(const char * uiName = NULL, const char * stringValue = NULL);

private:
	enum InventoryActions
	{
		MOVE_ITEM,
		USE_ITEM,
		DISCARD_ITEM,
		MOVE_TO_ITEM
	} m_InventoryAction;

	// NOTE: This MUST correspond to the xml
	enum PageEnum
	{
		START_MENU,
		GAME_MENU,
		STATUS,
		INVENTORY,
		INVENTORY_CHARACTER
	};

	std::string m_helpMessage;
	int m_selectedInventoryBag;
	int m_selectedInventorySlot;

	int m_confirmInventoryBag;
	int m_confirmInventorySlot;

	int m_selectedInventoryCharacter;
	int m_confirmInventoryCharacter;

	int m_selectedStatus;

	int m_selectedUnequip;
	int m_confirmUnequip;

	// function organization for different pages
	void onControlClicked_Inventory(const char* buttonname);
	std::string onConvertedString_Inventory(const char* stringValue = NULL);
	std::string onConvertedImage_Inventory(const char * uiName = NULL, const char * stringValue = NULL);
		void onControlClicked_Inventory_MOVE(const char* buttonname);
		void onControlClicked_Inventory_USE(const char* buttonname);
		void onControlClicked_Inventory_DISCARD(const char* buttonname);
		void onControlClicked_Inventory_MOVETO(const char* buttonname);


	void onControlClicked_InventoryCharacter(const char* buttonname);
	std::string onConvertedString_InventoryCharacter(const char* stringValue = NULL);
	std::string onConvertedImage_InventoryCharacter(const char * uiName = NULL, const char * stringValue = NULL);

	void onControlClicked_Status(const char* buttonname);
	std::string onConvertedString_Status(const char* stringValue = NULL);
	std::string onConvertedImage_Status(const char * uiName = NULL, const char * stringValue = NULL);

};