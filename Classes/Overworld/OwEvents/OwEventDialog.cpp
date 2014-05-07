#include "OwEventDialog.h"
#include "../OwManager/OwManager.h"
#include "../OwDialogUI/OwDialogUI.h"
#include "../OwEntities/OwEntityBase.h"

#include "cocos2d.h"

USING_NS_CC;
/****************************************************
If rhs and lhs are null, that means that the callee
is probably some world event. If not, it should be
the normal conversation-type event
****************************************************/


OwEventDialog::OwEventDialog(const std::string& text, OwEntityBase * lhs, OwEntityBase * rhs)
	: m_lhs(lhs), m_rhs(rhs), m_text(text)
{
}

void OwEventDialog::addPage(const std::string& text)
{
	OwManager * mgr = OwManager::getInstance();
	if ( !mgr ) {
		CCLOG("[OwEventDialog][addPage][error]: mgr is null!");
		return;
	}

	if ( !mgr->getDialog() ) {
		CCLOG("[OwEventDialog][addPage][error]: mgr->getDialog() is null!");
		return;
	}

	mgr->getDialog()->addPage(text);
}

void OwEventDialog::update(float dt)
{

}

void OwEventDialog::init()
{
	OwManager * mgr = OwManager::getInstance();
	if ( !mgr ) {
		CCLOG("[OwEventDialog][init][error]: mgr is null!");
		return;
	}

	if ( !mgr->getDialog() ) {
		CCLOG("[OwEventDialog][init][error]: mgr->getDialog() is null!");
		return;
	}

	CCLOG("[OwEventDialog][init]: Initialized!");
	mgr->getDialog()->init(m_text.c_str());

	if ( m_lhs )
		m_lhs->callback("pause",0);
	if ( m_rhs )
		m_rhs->callback("pause",0);
}

void OwEventDialog::free()
{
	CCLOG("[OwEventDialog][free]: Free!");
	if ( m_lhs )
		m_lhs->callback("play",0);
	if ( m_rhs )
		m_rhs->callback("play",0);
}

bool OwEventDialog::isDone()
{
	OwManager * mgr = OwManager::getInstance();
	if ( !mgr ) {
		CCLOG("[OwEventDialog][init][error]: mgr is null!");
		return false;
	}

	if ( !mgr->getDialog() ) {
		CCLOG("[OwEventDialog][init][error]: mgr->getDialog() is null!");
		return false;
	}

	return mgr->getDialog()->getIsDone();
}