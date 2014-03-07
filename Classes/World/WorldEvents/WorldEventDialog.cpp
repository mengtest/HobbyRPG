#include "WorldEventDialog.h"

#include "..\WorldDialogUI\WorldDialogUI.h"
#include "..\WorldManager\WorldManager.h"

#include "cocos2d.h"

USING_NS_CC;
/****************************************************
If rhs and lhs are null, that means that the callee
is probably some world event. If not, it should be
the normal conversation-type event
****************************************************/


WorldEventDialog::WorldEventDialog(const std::string& text)
	: m_text(text)
{
}

void WorldEventDialog::addPage(const std::string& text)
{
	WorldManager::getInstance()->getDialog()->addPage(text);
}

void WorldEventDialog::update(float dt)
{

}

void WorldEventDialog::init()
{
	CCLOG("[WorldEventDialog][init]: Initialized!");
	WorldManager::getInstance()->getDialog()->init(m_text.c_str());
}

void WorldEventDialog::free()
{
	CCLOG("[WorldEventDialog][free]: Free!");
}

bool WorldEventDialog::isDone()
{
	return WorldManager::getInstance()->getDialog()->getIsDone();
}