#pragma once
#include "PageManager.h"
#include <cocos2d.h>

class Page;
class OverworldScene;

class cBaseUI : public cocos2d::CCLayer
{
private:
	
	//things to overwrite
	virtual bool onInit() { return true; }
	virtual void onUpdate(float dt){}
	virtual void onDestroy(){}
	virtual void onControlClicked(const char* buttonname) {}
	virtual std::string onConvertedString(const char* currentString) { return NULL; }
	virtual std::string onConvertedImage(const char * uiName, const char* currentString ) { return NULL; }
protected:
	Page* findPage(const char* pagename = NULL);
	PageManager::PageArray* m_pageArray;
	Page* m_curPage;
	OverworldScene* m_overWorldScene;
public:
	cBaseUI();
	~cBaseUI();
	bool init(OverworldScene* scene = NULL);
	void update(float dt);
	void destroy();
	void controlClicked(const char* buttonname);
	std::string convertedString(const char* currentString);
	std::string convertedImage(const char * uiName, const char* currentString);

};