#pragma once

#include <cocos2d.h>
#include <cocos-ext.h>
#include <string>
class Page;

struct ControlDef
{
	std::string m_name;
	cocos2d::CCPoint m_pos;
	cocos2d::extension::CCScale9Sprite* m_image; //used for manipulating image
	std::string imageValue;
	cocos2d::CCLabelBMFont* m_fontstring; //used for manipulating string
	std::string stringValue;
	std::string goToPage;
	cocos2d::CCRect m_capInsert;
	ControlDef()
	{
		m_image = NULL;
		m_fontstring = NULL;
	}
};

class Control : public cocos2d::CCMenuItem
{
private:
	Page* m_pageOwner;
	ControlDef* m_def;
public:
	Control();
	~Control();
	bool init(ControlDef* def = NULL,Page* pageOwner = NULL);
	void destroy();
	void update(float dt);
	void activate();
	ControlDef* getDef() { return m_def; }

};