#pragma once

#include <vector>

class Page;

class cBaseUI;

class PageManager
{
public:
	typedef std::vector<Page*> PageArray; 
	static PageManager* getInstance();
	PageManager();
	~PageManager();
	void init();
	void destroy();
	PageArray* createPageArray(const char* xmlfilename, cBaseUI* baseUI = 0);
	void destroyPageArray(PageArray * pageArray );
};