#include "cBaseUI.h"
#include "cocoa\CCObject.h"
#include "Page.h"
#include "Control.h"

USING_NS_CC;


cBaseUI::cBaseUI()
:m_curPage(NULL),m_pageArray(NULL)
{

}

cBaseUI::~cBaseUI()
{
	destroy();
}

bool cBaseUI::init(OverworldScene* scene)
{
	m_overWorldScene = scene;
	schedule(schedule_selector(cBaseUI::update), 1.0f/60.0f);
	return onInit();
}

void cBaseUI::destroy()
{
	onDestroy();
}

Page* cBaseUI::findPage(const char* pageName)
{

	if(pageName)
	{
		if(m_pageArray)
		{
			for(int i = 0; i < m_pageArray->size(); ++i)
			{
				if((*m_pageArray)[i]->getDef())
				{
					if(strcmp((*m_pageArray)[i]->getDef()->m_pageName.c_str(), pageName) == 0)
					{
						return (*m_pageArray)[i];
					}

				}
			}
		}
	}

	return NULL;
}

void cBaseUI::update(float dt)
{
	if(m_curPage)
	{
		m_curPage->update(dt);
	}
	onUpdate(dt);
}

void cBaseUI::controlClicked(const char* name)
{
	onControlClicked(name);
	if(m_curPage)
	{
		Control* control = m_curPage->findControl(name);
		if(control)
		{
			if(control->getDef()->goToPage.size())
			{
				Page* page = findPage(control->getDef()->goToPage.c_str());
				if(page)
				{
					m_curPage->setEnabled(false);
					m_curPage->setVisible(false);
					page->setEnabled(true);
					page->setVisible(true);
					m_curPage = page;
				}
			}
		}
	}
}

std::string cBaseUI::convertedString(const char* currentstring)
{
	return onConvertedString(currentstring);
}

std::string cBaseUI::convertedImage(const char * uiName, const char* currentstring)
{
	return onConvertedImage(uiName, currentstring);
}




