#ifndef __WorldDialogUI_H__
#define __WorldDialogUI_H__

#include <string>
#include <queue>

#include "cocos2d.h"
#include "cocos-ext.h"


class WorldDialogUI
{
public:
	WorldDialogUI();	

	void addPage( const std::string& text );

	bool load( const std::string& backgroundTexture );
	void init(const std::string& text);
	void update(float dt);
	void processTouchBegan();
	inline bool getIsDone() { return m_bIsDone; }
	inline cocos2d::extension::CCScale9Sprite * getSprite() { return m_sprite; }
	 
private:
	bool m_bIsDone;
	cocos2d::extension::CCScale9Sprite * m_sprite;
	cocos2d::CCLabelBMFont * m_label;
	std::queue<std::string> m_otherPages; // for now
	
	// scrolling variables
	bool m_bIsScrolling;
	float m_scrollTimer;
	float m_scrollDuration;
	int m_currentTextIndex;
	int m_stringSize;

	void hideAllLetters();
	void showAllLetters();
	void prepareText(const std::string& text);

};

#endif