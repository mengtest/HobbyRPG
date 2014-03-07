#include "Page.h"
#include "Control.h"
#include "support\tinyxml2\tinyxml2.h"
#include "cInGameUI.h"

#include "Player\Player.h"
#include "Inventory\Inventory.h"
#include "Item\ItemManager.h"
#include "Character\Character.h"
#include "Party\Party.h"
#include "..\Overworld\OverworldScene.h"

#include "CCLuaEngine.h"

#include <string>

#include <cocos2d.h>
USING_NS_CC; 


cInGameUI::cInGameUI()
{

}

cInGameUI::~cInGameUI()
{
	onDestroy();
}

bool cInGameUI::onInit()
{
	m_pageArray = PageManager::getInstance()->createPageArray("testui.xml", this);
	
	// Disable all pages
	int size = m_pageArray->size();
	for(int i = 0; i < size; ++i)
	{
		addChild((*m_pageArray)[i]);
		(*m_pageArray)[i]->setEnabled(false);
		(*m_pageArray)[i]->setVisible(false);
	}

	// Set the current page and set it visible
	m_curPage = (*m_pageArray)[0];
	m_curPage->setEnabled(true);
	m_curPage->setVisible(true);

	

	// init variables;
	m_selectedInventoryBag = 0;
	m_selectedInventorySlot = -1;
	m_confirmInventorySlot = -1;
	m_confirmInventoryBag = -1;

	m_confirmInventoryCharacter = -1;
	m_selectedInventoryCharacter = 0;
	m_selectedStatus = 0;
	m_helpMessage = "Tap twice to choose item to move!";
	m_InventoryAction = USE_ITEM;

	return true;
}

void cInGameUI::onUpdate(float dt)
{
}

void cInGameUI::onDestroy()
{
	int size = m_pageArray->size();
	for(int i = 0; i < size; ++i)
	{
		removeChild((*m_pageArray)[i]);
	}

	delete m_pageArray;
	// Not safe yet
	//PageManager::getInstance()->destroyPageArray(m_pageArray);
}

void cInGameUI::onControlClicked(const char* name)
{
	CCLOG("ButtonClicked: %s", name);
	switch ( m_curPage->getDef()->m_pageIndex )
	{
		case STATUS:
			onControlClicked_Status(name);
			break;
		case INVENTORY:
			onControlClicked_Inventory(name);
			break;
		case INVENTORY_CHARACTER:
			onControlClicked_InventoryCharacter(name);
			break;
		default:
			break;
	};

	if(strcmp(name, "reset") == 0)
	{
		if(m_overWorldScene)
			m_overWorldScene->ResetUI();
	}
	
}

std::string cInGameUI::onConvertedImage(const char * uiName, const char* stringValue)
{
	if ( stringValue && uiName)
	{
		switch ( m_curPage->getDef()->m_pageIndex )
		{
			case STATUS:
				return onConvertedImage_Status(uiName, stringValue);
				break;
			case INVENTORY:
				return onConvertedImage_Inventory(uiName, stringValue);
				break;
			case INVENTORY_CHARACTER:
				return onConvertedImage_InventoryCharacter(uiName, stringValue);
				break;
			default:
				break;
		};
		
	}

	return std::string(stringValue);
}

std::string cInGameUI::onConvertedString(const char* stringValue)
{
	if(stringValue)
	{
		switch ( m_curPage->getDef()->m_pageIndex )
		{
			case STATUS:
				return onConvertedString_Status(stringValue);
				break;
			case INVENTORY:
				return onConvertedString_Inventory(stringValue);
				break;
			case INVENTORY_CHARACTER:
				return onConvertedString_InventoryCharacter(stringValue);
				break;
			default:
				break;
		};

	}

	return std::string(stringValue);
}


void cInGameUI::onControlClicked_InventoryCharacter(const char* name)
{
	int size = Player::getInstance().getInventory()->getSpacePerBag();
	for ( int i = 0 ; i < size; ++i )
	{
		std::stringstream temp; 
		temp << "back" << i;
		if ( !strcmp(name, temp.str().c_str() ))
		{
			CCLOG("[cInGameUI][onControlClicked_InventoryCharacter]: slot %d touched", i);
			if ( m_selectedInventoryCharacter != i )
			{
				if ( Player::getInstance().getParty()->getCharacterAtSlot( i ) != 0 )
				{
					m_selectedInventoryCharacter = i;
					m_confirmInventoryCharacter = -1;
				}
			}

			else if ( m_selectedInventoryCharacter == i  && m_confirmInventoryCharacter != i)
			{
				m_confirmInventoryCharacter = i;
			}

			// Use item
			else if ( m_confirmInventoryCharacter == i )
			{
				std::stringstream script;
				ItemEnum item = Player::getInstance().getInventory()->getItemByIndex(m_confirmInventoryBag, m_confirmInventorySlot);
				script << ItemManager::getInstance().getItemStat(item, USE);
				if ( script.str().compare("null") ) //NOT null
				{
					script << "(" << m_confirmInventoryCharacter << "," 
								  << m_confirmInventoryBag << "," 
								  << m_confirmInventorySlot << ")";
					CCLuaEngine::defaultEngine()->executeString(script.str().c_str());					
				}

				m_helpMessage = ItemManager::getInstance().getItemStat(item, USE_DESCRIPTION);
				m_confirmInventoryCharacter = -1;

			}
		
			return;
		}
	}

	for ( int i = 0 ; i < size; ++i )
	{
		std::stringstream temp; 
		temp << "unequip" << i;
		if ( !strcmp(name, temp.str().c_str() ))
		{
			CCLOG("[cInGameUI][onControlClicked_InventoryCharacter]: slot %d touched", i);
			if ( m_selectedUnequip != i )
			{
				m_confirmUnequip = -1;
				m_selectedUnequip = i;
			}

			else if ( m_selectedUnequip == i  && m_confirmUnequip != i)
			{
				m_confirmUnequip = i;
			}

			
			else if ( m_confirmUnequip == i )
			{
				if ( m_selectedInventoryCharacter < 0 || m_selectedInventoryCharacter >= Party::MAX_MEMBERS ) {
					return;
				}

				Character * temp = Player::getInstance().getParty()->getCharacterAtSlot(m_selectedInventoryCharacter);
				if ( i == 0 ) // discard weapon
				{
					if ( !Player::getInstance().getInventory()->addItem(temp->getWeapon()) ) {
						m_helpMessage = "Inventory is full";
					} 

					else {
						m_helpMessage = "Unequipped!";
						temp->unequipWeapon();
						m_confirmInventoryBag = -1;
					}

				
				}

				else if ( i == 1 ) // discard armor 
				{
					if ( !Player::getInstance().getInventory()->addItem(temp->getArmor()) ) {
						m_helpMessage = "Inventory is full";
					} 

					else {
						m_helpMessage = "Unequipped!";
						temp->unequipArmor();
					}


				}

				else if ( i == 2 ) // discard ring
				{
					if ( !Player::getInstance().getInventory()->addItem(temp->getRing()) ) {
						m_helpMessage = "Inventory is full";
					} 

					else {
						m_helpMessage = "Unequipped!";
						temp->unequipRing();
					}

				}

				m_confirmUnequip = -1;
			}
		
			return;
		}
	}

	if ( !strcmp(name, "return") )
	{
		m_selectedInventoryBag = 0;
		m_selectedInventorySlot = -1;
		m_confirmInventorySlot = -1;
		m_confirmInventoryBag = -1;
		m_confirmUnequip = -1;
		m_selectedUnequip = 0;
	}
}

std::string cInGameUI::onConvertedString_InventoryCharacter(const char* stringValue)
{
	// description
	if(stringValue[0] == '$')
	{
		if ( !strcmp( stringValue, "$desc" ) )
		{
			std::stringstream result;
			ItemEnum selectItem = Player::getInstance().getInventory()->getItemByIndex(m_selectedInventoryBag, m_selectedInventorySlot);
			if ( selectItem == EMPTY )
				return "";

			result << Player::getInstance().getInventory()->getItemStacksByIndex(m_selectedInventoryBag, m_selectedInventorySlot)  << " x  "
				   << ItemManager::getInstance().getItemStat(selectItem, NAME)
				   <<  ": "
				   << ItemManager::getInstance().getItemStat(selectItem, DESCRIPTION );


			return result.str();
		}

		if ( !strcmp( stringValue, "$charName0" ) )
		{
			std::stringstream result;
			
			result << Player::getInstance().getParty()->getCharacterAtSlot(0)->getInfo(ALIAS);

			return result.str();
		}

		if ( !strcmp( stringValue, "$help" ) )
		{
			return m_helpMessage;
		}

		if ( !strcmp( stringValue, "$stats" ) )
		{
			std::stringstream result;
			
			Character * chosen_character = Player::getInstance().getParty()->getCharacterAtSlot( this->m_selectedInventoryCharacter );
			
			if ( chosen_character != 0 )
			{
				result << "HP:   " << chosen_character->getCurrentHP() << "/" << chosen_character->getStat(HP) << "\n"
					<< "APow: " << chosen_character->getStat(APOW) << "\n"
					<< "ADef: " << chosen_character->getStat(ADEF) << "\n"
					<< "MPow: " << chosen_character->getStat(MPOW) << "\n"
					<< "MDef: " << chosen_character->getStat(MDEF);
					
			}	
				
				
			return result.str();
		}

		if ( !strcmp ( stringValue, "$equipment" ))
		{
			std::stringstream result;
			
			Character * chosen_character = Player::getInstance().getParty()->getCharacterAtSlot( this->m_selectedInventoryCharacter );
			
			if ( chosen_character != 0 )
			{
				result << "Weapon: " << ItemManager::getInstance().getItemStat(chosen_character->getWeapon(), NAME )  << "\n"
					<< "Armor: " << ItemManager::getInstance().getItemStat(chosen_character->getArmor(), NAME ) << "\n"
					<< "Ring: " << ItemManager::getInstance().getItemStat(chosen_character->getRing(), NAME );
			}

			return result.str();
		}
	}

	return std::string(stringValue);
}

std::string cInGameUI::onConvertedImage_InventoryCharacter(const char * uiName, const char * stringValue)
{
	if( !strcmp(uiName, "charImage0" ) )
	{
		return Player::getInstance().getParty()->getCharacterAtSlot(0)->getInfo(SPRITE);
	}

	for ( int i = 0 ; i < 3 ; ++i )
	{
		std::stringstream temp; 
		temp << "back" << i;
			
		if( !strcmp(uiName, temp.str().c_str() ))
		{
			// TODO: hardcode
			if ( i == m_selectedInventoryCharacter && i != m_confirmInventoryCharacter )
			{
				return "menu_background_selected.png";
			}

			else if ( i == m_confirmInventoryCharacter )
			{
				return "menu_background_selected_confirm.png";
			}
			
			else
			{
				return "menu_background.png";
			}
		}
	}

	for ( int i = 0 ; i < 3 ; ++i )
	{
		std::stringstream temp; 
		temp << "unequip" << i;
			
		if( !strcmp(uiName, temp.str().c_str() ))
		{
			if ( i == m_selectedUnequip && i != m_confirmUnequip )
			{
				return "menu_background_selected.png";
			}

			else if ( i == m_confirmUnequip )
			{
				return "menu_background_selected_confirm.png";
			}
			
			else
			{
				return "menu_background.png";
			}
		}
	}

	return std::string(stringValue);
}

void cInGameUI::onControlClicked_Inventory(const char* name)
{
	if ( !strcmp(name, "move") )
	{
		m_selectedInventorySlot = -1;
		m_confirmInventorySlot = -1;
		m_confirmInventoryBag = -1;
		m_InventoryAction = MOVE_ITEM;
		m_helpMessage = "Tap twice to choose item to move!";
		return;
	}

	if ( !strcmp(name, "discard") )
	{
		m_selectedInventorySlot = -1;
		m_confirmInventorySlot = -1;
		m_confirmInventoryBag = -1;
		m_InventoryAction = DISCARD_ITEM;
		m_helpMessage = "Tap twice to choose item to discard!";
		return;
	}

	if ( !strcmp(name, "use") )
	{
		m_selectedInventorySlot = -1;
		m_confirmInventorySlot = -1;
		m_confirmInventoryBag = -1;
		m_InventoryAction = USE_ITEM;
		m_helpMessage = "Tap twice to choose item to use!";
		return;
	}	

	switch ( m_InventoryAction )
	{
	case MOVE_ITEM:
		onControlClicked_Inventory_MOVE(name);
		break;
	case DISCARD_ITEM:
		onControlClicked_Inventory_DISCARD(name);
		break;
	case MOVE_TO_ITEM:
		onControlClicked_Inventory_MOVETO(name);
		break;
	case USE_ITEM:
		onControlClicked_Inventory_USE(name);
		break;
	}

	
}

std::string cInGameUI::onConvertedImage_Inventory(const char * uiName, const char * stringValue)
{
	// Modes
	if ( !strcmp ( "move", uiName ))
	{
		if ( m_InventoryAction == MOVE_ITEM || m_InventoryAction == MOVE_TO_ITEM)
		{
			return "menu_background_selected.png";
		}

		return "menu_background.png";
	}

	else if ( !strcmp("discard", uiName ))
	{
		if ( m_InventoryAction == DISCARD_ITEM )
		{
			return "menu_background_selected.png";
		}

		return "menu_background.png";
	}

	else if ( !strcmp("use", uiName )) 
	{
		if ( m_InventoryAction == USE_ITEM )
		{
			return "menu_background_selected.png";
		}

		return "menu_background.png";
	}


	// ensure all bags are using default image
	// 全ての箱スロットが元に戻すこと確認します
	int bags = Player::getInstance().getInventory()->getBags();
	for ( int i = 0 ; i < bags ; ++i )
	{
		std::stringstream temp; 
		temp << "bag" << i;
			
		if( !strcmp(uiName, temp.str().c_str() ))
		{
			// TODO: hardcode
			if ( i == m_selectedInventoryBag )
			{
				return "menu_background_selected.png";
			}
			
			else
			{
				return "menu_background.png";
			}
		}
	}


	int space_per_bag = Player::getInstance().getInventory()->getSpacePerBag();
	for ( int i = 0 ; i < space_per_bag ; ++i )
	{
		std::stringstream temp; 
		temp << "back" << i;
			
		if( !strcmp(uiName, temp.str().c_str() ))
		{
			// TODO: hardcode
			if ( i == m_selectedInventorySlot && i != m_confirmInventorySlot )
			{
				return "menu_background_selected.png";
			}

			else if ( i == m_confirmInventorySlot && m_confirmInventoryBag == m_selectedInventoryBag )
			{
				return "menu_background_selected_confirm.png";
			}
			
			else
			{
				return "menu_background.png";
			}
		}
	}

	return std::string(stringValue);
	
}

std::string cInGameUI::onConvertedString_Inventory(const char* stringValue)
{
	if(stringValue[0] == '$')
	{
		// Inventory //
		int inventory_space = Player::getInstance().getInventory()->getSpace();
		int inventory_space_per_bag = Player::getInstance().getInventory()->getSpacePerBag();
		for ( int i = 0 ; i < inventory_space; ++i )
		{
			std::stringstream temp; 
			temp << "$inv" << i;
			
			if( !strcmp(stringValue, temp.str().c_str() ))
			{
				ItemEnum item = Player::getInstance().getInventory()->getItemByIndex(inventory_space_per_bag * m_selectedInventoryBag + i);
				if ( item == EMPTY )
					return "";
				return ItemManager::getInstance().getItemStat(item, NAME);
			}
		}

		for ( int i = 0 ; i < inventory_space; ++i )
		{
			std::stringstream temp; 
			temp << "$stack" << i;
			
			if( !strcmp(stringValue, temp.str().c_str() ))
			{
				std::stringstream inventoryStackStr; 
				int amount = Player::getInstance().getInventory()->getItemStacksByIndex(inventory_space_per_bag * m_selectedInventoryBag + i);
				if ( amount < 2 )
					return "";
				inventoryStackStr << "x " << amount;
				return inventoryStackStr.str().c_str();
			}
		}

		// help
		if( !strcmp(stringValue, "$help" ))
		{
			return m_helpMessage;
		}

		// description
	
		if ( !strcmp( stringValue, "$desc" ) )
		{
			std::stringstream result;

			if ( m_selectedInventoryBag != -1 && m_selectedInventorySlot != -1 )
			{
				ItemEnum selectItem = Player::getInstance().getInventory()->getItemByIndex(m_selectedInventoryBag, m_selectedInventorySlot);
			
				if (selectItem != EMPTY )
				{
					result << ItemManager::getInstance().getItemStat(selectItem, NAME)
						   <<  ": "
						<< ItemManager::getInstance().getItemStat(selectItem, DESCRIPTION );
				}

				else
				{
					result << "Empty";
				}

				return result.str();
			}

			else
			{
				return "Item Description Here";
			}
		
		}

		return std::string(stringValue);
	}

		
	else
	{
		return std::string(stringValue);
	}

	return std::string(stringValue);

}


//Inventory's HFSM
void cInGameUI::onControlClicked_Inventory_MOVE(const char* name)
{
	// slots //
	int size = Player::getInstance().getInventory()->getSpacePerBag();
	for ( int i = 0 ; i < size; ++i )
	{
		std::stringstream temp; 
		temp << "back" << i;
		if ( !strcmp(name, temp.str().c_str() ))
		{
			CCLOG("[cInGameUI][onControlClicked]: slot %d touched", i);
			
			// if something else is clicked
			if ( m_selectedInventorySlot != i )
			{
				m_selectedInventorySlot = i;
				m_confirmInventorySlot = -1;
				m_confirmInventoryBag = -1;
			}

			else if ( m_selectedInventorySlot == i  && m_confirmInventorySlot != i )
			{
				m_confirmInventorySlot = i;
				m_confirmInventoryBag = m_selectedInventoryBag;
				m_InventoryAction = MOVE_TO_ITEM;	
				m_helpMessage = "Tap twice on another item to move!";
			}

		
			return;
		}
	}

	// bag //
	int bags = Player::getInstance().getInventory()->getBags();
	for ( int i = 0 ; i < bags; ++i )
	{
		std::stringstream temp; 
		temp << "bag" << i;
		if ( !strcmp(name, temp.str().c_str() ))
		{
			CCLOG("[cInGameUI][onControlClicked]: bag %d touched", i);
			m_selectedInventoryBag = i;
			m_confirmInventorySlot = -1;
			m_confirmInventoryBag = -1;
			m_selectedInventorySlot = -1;
			return;
		}
	}
}

void cInGameUI::onControlClicked_Inventory_USE(const char* name)
{
	// slots //
	int size = Player::getInstance().getInventory()->getSpacePerBag();
	for ( int i = 0 ; i < size; ++i )
	{
		std::stringstream temp; 
		temp << "back" << i;
		if ( !strcmp(name, temp.str().c_str() ))
		{
			CCLOG("[cInGameUI][onControlClicked]: slot %d touched", i);
			
			// if something else is clicked
			if ( m_selectedInventorySlot != i  )
			{
				m_selectedInventorySlot = i;
				m_confirmInventorySlot = -1;
				m_confirmInventoryBag = -1;
			}

			else if ( m_selectedInventorySlot == i  && m_confirmInventorySlot != i)
			{
				m_confirmInventorySlot = i;
				m_confirmInventoryBag = m_selectedInventoryBag;
			}


			else if ( m_confirmInventorySlot == i )
			{
				//tapped the second time
				Page * tempPage = this->findPage("Inventory_Character");
				m_curPage->setEnabled(false);
				m_curPage->setVisible(false);

				m_curPage = tempPage;
				m_curPage->setEnabled(true);
				m_curPage->setVisible(true);			

				m_helpMessage = "Double tap character to use!";
			}
		
			return;
		}
	}

	// bag //
	int bags = Player::getInstance().getInventory()->getBags();
	for ( int i = 0 ; i < bags; ++i )
	{
		std::stringstream temp; 
		temp << "bag" << i;
		if ( !strcmp(name, temp.str().c_str() ))
		{
			CCLOG("[cInGameUI][onControlClicked]: bag %d touched", i);
			m_selectedInventoryBag = i;
			m_confirmInventorySlot = -1;
			m_confirmInventoryBag = -1;
			m_selectedInventorySlot = -1;
			return;
		}
	}
}

void cInGameUI::onControlClicked_Inventory_DISCARD(const char* name)
{
	// slots //
	int size = Player::getInstance().getInventory()->getSpacePerBag();
	for ( int i = 0 ; i < size; ++i )
	{
		std::stringstream temp; 
		temp << "back" << i;
		if ( !strcmp(name, temp.str().c_str() ))
		{
			CCLOG("[cInGameUI][onControlClicked]: slot %d touched", i);
			
			// if something else is clicked
			if ( m_selectedInventorySlot != i  )
			{
				m_selectedInventorySlot = i;
				m_confirmInventorySlot = -1;
				m_confirmInventoryBag = -1;
			}

			else if ( m_selectedInventorySlot == i  && m_confirmInventorySlot != i )
			{
				m_confirmInventorySlot = i;
				m_confirmInventoryBag = m_selectedInventoryBag;
			}

			else if ( m_confirmInventorySlot == i )
			{
				Player::getInstance().getInventory()->discardItem(m_confirmInventoryBag, m_confirmInventorySlot);
				m_confirmInventoryBag = m_confirmInventorySlot = -1;
			}
		
			return;
		}
	}

	// bag //
	int bags = Player::getInstance().getInventory()->getBags();
	for ( int i = 0 ; i < bags; ++i )
	{
		std::stringstream temp; 
		temp << "bag" << i;
		if ( !strcmp(name, temp.str().c_str() ))
		{
			CCLOG("[cInGameUI][onControlClicked]: bag %d touched", i);
			m_selectedInventoryBag = i;
			m_confirmInventorySlot = -1;
			m_confirmInventoryBag = -1;
			m_selectedInventorySlot = -1;
			return;
		}
	}
}

void cInGameUI::onControlClicked_Inventory_MOVETO(const char* name)
{
	// slots //
	int size = Player::getInstance().getInventory()->getSpacePerBag();
	for ( int i = 0 ; i < size; ++i )
	{
		std::stringstream temp; 
		temp << "back" << i;
		if ( !strcmp(name, temp.str().c_str() ))
		{
			CCLOG("[cInGameUI][onControlClicked]: slot %d touched", i);

			if ( m_selectedInventorySlot != i )
			{
				m_selectedInventorySlot = i;
				
			}

			else
			{
				Player::getInstance().getInventory()->swapItems( m_confirmInventoryBag, m_confirmInventorySlot, m_selectedInventoryBag, i);
				m_InventoryAction = MOVE_ITEM;
				m_confirmInventoryBag = -1;
				m_confirmInventorySlot = -1;
				m_selectedInventorySlot = -1;
				m_helpMessage = "Tap twice to choose item to move!";
			}

			return;
		}
	}

	// bag //
	int bags = Player::getInstance().getInventory()->getBags();
	for ( int i = 0 ; i < bags; ++i )
	{
		std::stringstream temp; 
		temp << "bag" << i;
		if ( !strcmp(name, temp.str().c_str() ))
		{
			CCLOG("[cInGameUI][onControlClicked]: bag %d touched", i);
			m_selectedInventoryBag = i;
			m_selectedInventorySlot = -1;
			return;
		}
	}
}

void cInGameUI::onControlClicked_Status(const char* name)
{
	int size = Player::getInstance().getInventory()->getSpacePerBag();
	for ( int i = 0 ; i < size; ++i )
	{
		std::stringstream temp; 
		temp << "back" << i;
		if ( !strcmp(name, temp.str().c_str() ))
		{
			CCLOG("[cInGameUI][onControlClicked_Status]: slot %d touched", i);
			if ( m_selectedStatus != i )
			{
				if ( Player::getInstance().getParty()->getCharacterAtSlot( i ) != 0 )
				{
					m_selectedStatus = i;
				}
			}
		
			return;
		}
	}

	for ( int i = 0 ; i < size; ++i )
	{
		std::stringstream temp; 
		temp << "unequip" << i;
		if ( !strcmp(name, temp.str().c_str() ))
		{
			CCLOG("[cInGameUI][onControlClicked_Status]: slot %d touched", i);
			if ( m_selectedUnequip != i )
			{
				m_confirmUnequip = -1;
				m_selectedUnequip = i;
			}

			else if ( m_selectedUnequip == i  && m_confirmUnequip != i)
			{
				m_confirmUnequip = i;
			}

			
			else if ( m_confirmUnequip == i )
			{
				if ( m_selectedStatus < 0 || m_selectedStatus >= Party::MAX_MEMBERS ) {
					return;
				}

				Character * temp = Player::getInstance().getParty()->getCharacterAtSlot(m_selectedStatus);
				if ( i == 0 ) // discard weapon
				{
					if ( !Player::getInstance().getInventory()->addItem(temp->getWeapon()) ) {
						m_helpMessage = "Inventory is full";
					} 

					else {
						m_helpMessage = "Unequipped!";
						temp->unequipWeapon();
					}

				
				}

				else if ( i == 1 ) // discard armor 
				{
					if ( !Player::getInstance().getInventory()->addItem(temp->getArmor()) ) {
						m_helpMessage = "Inventory is full";
					} 

					else {
						m_helpMessage = "Unequipped!";
						temp->unequipArmor();
					}


				}

				else if ( i == 2 ) // discard ring
				{
					if ( !Player::getInstance().getInventory()->addItem(temp->getRing()) ) {
						m_helpMessage = "Inventory is full";
					} 

					else {
						m_helpMessage = "Unequipped!";
						temp->unequipRing();
					}

				}

				m_confirmUnequip = -1;

			}
		
			return;
		}
	}

	if ( !strcmp(name, "return") )
	{
		m_selectedInventoryBag = 0;
		m_selectedInventorySlot = -1;
		m_confirmInventorySlot = -1;
		m_confirmInventoryBag = -1;
		m_confirmUnequip = -1;
		m_selectedUnequip = 0;
	}
}

std::string cInGameUI::onConvertedString_Status(const char* stringValue)
{
	// description
	if(stringValue[0] == '$')
	{

		if ( !strcmp( stringValue, "$charName0" ) )
		{
			std::stringstream result;
			
			result << Player::getInstance().getParty()->getCharacterAtSlot(0)->getInfo(ALIAS);

			return result.str();
		}

		if ( !strcmp( stringValue, "$help" ) )
		{
			return m_helpMessage;
		}

		if ( !strcmp( stringValue, "$stats" ) )
		{
			std::stringstream result;
			
			Character * chosen_character = Player::getInstance().getParty()->getCharacterAtSlot( this->m_selectedInventoryCharacter );
			
			if ( chosen_character != 0 )
			{
				result << "HP:   " << chosen_character->getCurrentHP() << "/" << chosen_character->getStat(HP) << "\n"
					<< "APow: " << chosen_character->getStat(APOW) << "\n"
					<< "ADef: " << chosen_character->getStat(ADEF) << "\n"
					<< "MPow: " << chosen_character->getStat(MPOW) << "\n"
					<< "MDef: " << chosen_character->getStat(MDEF);
					
			}	
				
				
			return result.str();
		}

		if ( !strcmp ( stringValue, "$equipment" ))
		{
			std::stringstream result;
			
			Character * chosen_character = Player::getInstance().getParty()->getCharacterAtSlot( this->m_selectedInventoryCharacter );
			
			if ( chosen_character != 0 )
			{
				result << "Weapon: " << ItemManager::getInstance().getItemStat(chosen_character->getWeapon(), NAME )  << "\n"
					<< "Armor: " << ItemManager::getInstance().getItemStat(chosen_character->getArmor(), NAME ) << "\n"
					<< "Ring: " << ItemManager::getInstance().getItemStat(chosen_character->getRing(), NAME );
			}

			return result.str();
		}
	}

	return std::string(stringValue);
}

std::string cInGameUI::onConvertedImage_Status(const char * uiName, const char * stringValue)
{
	if( !strcmp(uiName, "charImage0" ) )
	{
		return Player::getInstance().getParty()->getCharacterAtSlot(0)->getInfo(SPRITE);
	}

	for ( int i = 0 ; i < 3 ; ++i )
	{
		std::stringstream temp; 
		temp << "back" << i;
			
		if( !strcmp(uiName, temp.str().c_str() ))
		{
			// TODO: hardcode
			if ( i == m_selectedStatus )
			{
				return "menu_background_selected.png";
			}

			else
			{
				return "menu_background.png";
			}
		}
	}

	for ( int i = 0 ; i < 3 ; ++i )
	{
		std::stringstream temp; 
		temp << "unequip" << i;
			
		if( !strcmp(uiName, temp.str().c_str() ))
		{
			if ( i == m_selectedUnequip && i != m_confirmUnequip )
			{
				return "menu_background_selected.png";
			}

			else if ( i == m_confirmUnequip )
			{
				return "menu_background_selected_confirm.png";
			}
			
			else
			{
				return "menu_background.png";
			}
		}
	}

	return std::string(stringValue);
}
