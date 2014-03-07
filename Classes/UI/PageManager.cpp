#include "Page.h"
#include "Control.h"
#include "PageManager.h"

#include "Common\Common.h"

USING_NS_CC;

PageManager::PageManager()
{

}

PageManager::~PageManager()
{

}

PageManager* PageManager::getInstance()
{
	static PageManager instance;
	return &instance;
}

void PageManager::init()
{

}

void PageManager::destroy()
{

}


PageManager::PageArray* PageManager::createPageArray(const char* xmlfileName, cBaseUI* baseUI)
{
	PageManager::PageArray* newPageArray = NULL;

	float screenWidth = cocos2d::CCEGLView::sharedOpenGLView()->getDesignResolutionSize().width;
	float screenHeight = cocos2d::CCEGLView::sharedOpenGLView()->getDesignResolutionSize().height;

	std::string fullPath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename(xmlfileName);
	unsigned long lSize;
	unsigned char* pchFileData = cocos2d::CCFileUtils::sharedFileUtils()->getFileData( fullPath.c_str(), "r", &lSize );
	char* pchBuf = new char[ lSize + 1 ];
	memcpy(pchBuf, pchFileData, lSize);
	pchBuf[lSize] = '\0';
	
	CCLOG("Path %s", fullPath.c_str());
	tinyxml2::XMLDocument doc;
    int result = tinyxml2::XML_SUCCESS;
	result = doc.Parse(pchBuf);
    if( result == tinyxml2::XML_NO_ERROR ) //if success, then parse
	{
		newPageArray = new PageManager::PageArray();
		newPageArray->reserve(30);

		tinyxml2::XMLElement* pageelement = doc.FirstChildElement("menu")->FirstChildElement("Page");
		
		for(int i = 0; pageelement != NULL;pageelement = pageelement->NextSiblingElement(), ++i)
		{
			const char* pageName = pageelement->Attribute("name", NULL);
			const char* pagePos = pageelement->Attribute("pos", NULL);
			const char* pageSize = pageelement->Attribute("size", NULL);
			const char* pageImage = pageelement->Attribute("image", NULL);
			const char* scale9Value = pageelement->Attribute("scale9Value", NULL);
			Page* page = new Page();
			PageDef* pagedef = new PageDef();
			
			char test[256] = {0};
			snprintf(test, sizeof(test), "%s", pagePos);
			char* pch = strtok (test," ");
			float value[2] = {0.0f};
			int index = 0;
			while (pch != NULL)
			{
				value[index] = atof(pch);
				pch = strtok (NULL, " ");
				++index;
			}

			if(strcmp(pageImage, "") != 0)
			{
				float value[2] = {0.0f};
				if(pageSize)
				{
					char test[20] = {0};
					snprintf(test, sizeof(test), "%s", pageSize);
					char* pch = strtok (test," ");
					int index = 0;
					while (pch != NULL)
					{
						value[index] = atof(pch);
						pch = strtok (NULL, " ");
						++index;
					}
				}

				float scale9Values[4] = {0.0f};
				if(scale9Value)
				{
					char test[20] = {0};
					snprintf(test, sizeof(test), "%s", scale9Value);
					char* pch = strtok (test," ");
					int index = 0;
					while (pch != NULL)
					{
						scale9Values[index] = atof(pch);
						pch = strtok (NULL, " ");
						++index;
					}
				}

				cocos2d::CCMenuItem* item = cocos2d::CCMenuItem::create();
				cocos2d::extension::CCScale9Sprite* pageimage =  cocos2d::extension::CCScale9Sprite::createWithSpriteFrameName(pageImage, cocos2d::CCRectMake(scale9Values[0], scale9Values[1], scale9Values[2], scale9Values[3]));
				pageimage->setContentSize(cocos2d::CCSizeMake(screenWidth * value[0], screenHeight * value[1]));
				
				item->addChild(pageimage);
				page->addChild(item, 0);

				
			}

			pagedef->m_pageIndex = i;
			pagedef->m_pageName.append(pageName);
			pagedef->m_position.setPoint(Common::getNormalizedPositionX(value[0]), Common::getNormalizedPositionY(value[1]));
			page->init(pagedef,baseUI);

			tinyxml2::XMLElement* controlelement = pageelement->FirstChildElement("control");
			for(;controlelement != NULL;controlelement = controlelement->NextSiblingElement())
			{
				Control* control = new Control();
				ControlDef* def = new ControlDef();
				const char* controlName = controlelement->Attribute("name", NULL);
				const char* controlType = controlelement->Attribute("type", NULL);
				const char* controlPos = controlelement->Attribute("pos", NULL);
				const char* buttonimage = controlelement->Attribute("image", NULL);
				const char* controlSize = controlelement->Attribute("size", NULL);
				const char* controlText = controlelement->Attribute("text", NULL);
				const char* fontSize = controlelement->Attribute("fontSize", NULL);
				const char* scale9Rect = controlelement->Attribute("scale9Rect", NULL);
				def->m_name.append(controlName);

				char test[256] = {0};
				snprintf(test, sizeof(test), "%s", controlPos);
				char* pch = strtok (test," ");
				float value[2] = {0.0f};
				int index = 0;
				while (pch != NULL)
				{
					value[index] = atof(pch);
					pch = strtok (NULL, " ");
					++index;
				}


				def->m_pos.setPoint(Common::getNormalizedPositionX(value[0]), Common::getNormalizedPositionY(value[1]));
			
				if(controlType)
				{
					if(strcmp(controlType, "button") == 0)
					{
						const char* gotopage = controlelement->Attribute("goto", NULL);
						if(gotopage)
						{
							def->goToPage.append(gotopage);
						}
					}
				}

				

				float sizeValues[2] = {0.f};
				if(controlSize)
				{
					if(strcmp(controlSize, "") != 0)
					{
						char test[256] = {0};
						snprintf(test, sizeof(test), "%s", controlSize);
						char* pch = strtok (test," ");
						int index = 0;
						while (pch != NULL)
						{
							sizeValues[index] = atof(pch);
							pch = strtok (NULL, " ");
							++index;
						}

					}
				}

				float scale9RectValues[4] = {0.f};
				if(scale9Rect)
				{
					if(strcmp(scale9Rect, "") != 0)
					{
						char test[256] = {0};
						snprintf(test, sizeof(test), "%s", scale9Rect);
						char* pch = strtok (test," ");
						int index = 0;
						while (pch != NULL)
						{
							scale9RectValues[index] = atof(pch);
							pch = strtok (NULL, " ");
							++index;
						}

					}
				}

				float fontSizeValues = 1.f;
				if ( fontSize )
				{
					fontSizeValues = atof(fontSize);
				}

				cocos2d::extension::CCScale9Sprite * nodeimage = NULL;
				if ( buttonimage )
				{
					if(strcmp(buttonimage, "") != 0)
					{
						def->m_capInsert = cocos2d::CCRectMake(scale9RectValues[0], scale9RectValues[1], scale9RectValues[2], scale9RectValues[3]);
						nodeimage = cocos2d::extension::CCScale9Sprite::createWithSpriteFrameName(buttonimage, def->m_capInsert);
					
						def->m_image = nodeimage;
						def->imageValue = buttonimage;
					
						nodeimage->setContentSize(cocos2d::CCSizeMake(screenWidth * sizeValues[0], screenHeight * sizeValues[1]));
						control->setContentSize( nodeimage->getContentSize() );

						nodeimage->setAnchorPoint(ccp(0, 0));
						control->addChild(nodeimage);

					}
				}

				if(controlText)
				{
					if(strcmp(controlText, "") != 0)
					{
						
						//font->setContentSize(cocos2d::CCSizeMake(screenWidth * sizeValues[0], screenHeight * sizeValues[1]));
						
						// TODO: need extra variable here for left/center/right alignment
						// now it's just a quick hack.
						if(nodeimage)
						{
							cocos2d::CCLabelBMFont * font = cocos2d::CCLabelBMFont::create(controlText, "fonts/testfont.fnt");
							control->addChild(font);
							def->m_fontstring = font;
							def->stringValue.append(controlText);
							font->setAnchorPoint(ccp(0.5f, 0.5f)); //center aligned
							font->setPosition(control->getPositionX() + control->getContentSize().width/2, 
											  control->getPositionY() + control->getContentSize().height/2);
							font->setScale(fontSizeValues);
						}

						else
						{
							cocos2d::CCLabelBMFont * font = cocos2d::CCLabelBMFont::create(controlText, "fonts/testfont.fnt", kCCLabelAutomaticWidth, kCCTextAlignmentLeft);
							control->addChild(font);
							def->m_fontstring = font;
							def->stringValue.append(controlText);
							font->setAnchorPoint(ccp(0.0f, 0.5f)); // left aligned
							font->setScale(fontSizeValues);
						}
					}
				}
				

				control->init(def, page);

			}


			newPageArray->push_back(page);
			

		}
		delete [] pchBuf;
	}


	return newPageArray;
}

void PageManager::destroyPageArray(PageArray * pageArray )
{
	for(int i = 0; i < pageArray->size(); ++i)
	{
		CC_SAFE_DELETE( (*pageArray)[i]);
	}

	delete pageArray;
}
