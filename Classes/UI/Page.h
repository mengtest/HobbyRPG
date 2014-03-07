#pragma once

#include <cocos2d.h>
#include <string>
#include <list>

class cBaseUI;
class Control;

struct PageDef
{
	std::string m_pageName;
	cocos2d::CCPoint m_position;
	int m_pageIndex;
};

class Page : public cocos2d::CCMenu
{
private:
	PageDef* m_pagedef;
	cBaseUI* m_ui;
	std::list<Control*> m_controllist;
public:
	Page();
	~Page();
	bool init(PageDef* pagedef = NULL, cBaseUI* baseui = NULL);
	void destroy();
	void update(float dt);
	void addControl(Control* control = NULL);
	cBaseUI* getUI() { return m_ui; }
	Control* findControl(const char* controlname = NULL);
	PageDef* getDef() { return m_pagedef; }
	void setEnabled(bool value);
};