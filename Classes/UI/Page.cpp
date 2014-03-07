#include "Page.h"
#include "Control.h"
Page::Page()
:m_pagedef(NULL)
{

}

Page::~Page()
{
	destroy();
}

bool Page::init(PageDef* pagedef, cBaseUI* baseui)
{
	cocos2d::CCMenu::init();

	if(pagedef)
	{
		setPosition(pagedef->m_position);
		m_pagedef = pagedef;
	}
	if(baseui)
	{
		m_ui = baseui;
	}

	return false;
}

void Page::destroy()
{
	CC_SAFE_DELETE(m_pagedef);
	std::list<Control*>::iterator beg = m_controllist.begin();
	std::list<Control*>::iterator end = m_controllist.end();

	for ( ; beg != end; ++ beg )
	{
		CC_SAFE_DELETE((*beg));
	}

	m_controllist.clear();

}

void Page::update(float dt)
{
	for(std::list<Control*>::iterator itr = m_controllist.begin(); itr != m_controllist.end(); ++itr)
	{
		(*itr)->update(dt);
	}
}

void Page::addControl(Control* control)
{
	if(control)
	{
		m_controllist.push_back(control);
		addChild(control, 1);
	}
}

void Page::setEnabled(bool value)
{
	CCMenu::setEnabled(value);
	for(std::list<Control*>::iterator itr = m_controllist.begin(); itr != m_controllist.end(); ++itr)
	{
		(*itr)->setEnabled(value);
	}
}

Control* Page::findControl(const char* controlname)
{
	if(controlname)
	{
		for(std::list<Control*>::iterator itr = m_controllist.begin(); itr != m_controllist.end(); ++itr)
		{
			if((*itr)->getDef())
			{
				if(strcmp((*itr)->getDef()->m_name.c_str(), controlname) == 0)
				{
					return (*itr);
				}
			}
		}
	}

	return NULL;
}
