#include "OwDialogUI.h"
#include "Common/Common.h"

USING_NS_CC;

OwDialogUI::OwDialogUI()
	: m_bIsDone(true), m_bIsScrolling(true)
{
	m_scrollTimer = m_scrollDuration = 0.1f;
	m_currentTextIndex = 0;
	m_label = 0;
	m_sprite = 0;
	m_stringSize = 0;
}

bool OwDialogUI::load( const std::string& backgroundTexture )
{
	if ( NULL == CCEGLView::sharedOpenGLView() ) {
		CCLOG("[OwDialogUI][load][error]: CCEGLView::sharedOpenGLView() is NULL" );
		return false;
	}

	float screenWidth = CCEGLView::sharedOpenGLView()->getDesignResolutionSize().width;
	float screenHeight = CCEGLView::sharedOpenGLView()->getDesignResolutionSize().height;
	m_sprite = cocos2d::extension::CCScale9Sprite::createWithSpriteFrameName(backgroundTexture.c_str(), CCRectMake(32, 32, 32, 32));
	if ( !m_sprite ) {
		CCLOG("[OwDialogUI][load][error]: loading '%s' failed", backgroundTexture.c_str());
		return false;
	}

	//m_label = CCLabelTTF::create("Hello, welcome to our town!", "fonts/Marker Felt.ttf", 24,CCSizeMake(screenWidth, screenHeight * 0.3f), kCCTextAlignmentLeft);
	m_label = CCLabelBMFont::create("Hello, welcome to our town!", "fonts/testfont.fnt");
	if ( !m_label ) {
		CCLOG("[OwDialogUI][load][error]: loading m_label failed");
		return false;
	}


	m_sprite->setContentSize(CCSizeMake(screenWidth, screenHeight * 0.3f));
	m_sprite->setAnchorPoint(ccp(0.f, 1.f));
	m_sprite->setPosition(ccp(Common::getNormalizedPositionX(0.0f), Common::getNormalizedPositionY(1.f)));		
	m_sprite->setVisible(false);

	float offsetX = Common::getNormalizedPositionX(0.02f);
	float offsetY = Common::getNormalizedPositionX(0.015f);
	m_label->setScale(0.9f);
	CCPoint anchorPoint = m_sprite->getAnchorPointInPoints();

	m_label->setAnchorPoint(ccp(0.f, 1.f));
	m_label->setPosition(ccp(anchorPoint.x + offsetX, anchorPoint.y - offsetY));	
	m_sprite->addChild(m_label);
	return true;
}

void OwDialogUI::addPage(const std::string& text )
{
	CCLOG("[OwDialogUI][addPage]: Adding page!");
	m_otherPages.push(text);
}


void OwDialogUI::init(const std::string& text) {
	CCLOG("[OwDialogUI][init]: Init!");
	
	m_bIsDone = false;
	if ( NULL != m_sprite ) {
		m_sprite->setVisible(true);
	} else {
		CCLOG("[OwDialogUI][init][error]: m_sprite is NULL");
	}

	prepareText(text);
	hideAllLetters();
}

//TODO DEFEND
void OwDialogUI::update( float dt ) { 
	if ( getIsDone() ) 
		return; 

	//　文字は全部まだ見えない
	if ( m_bIsScrolling )
	{
		//　一々に表示させます
		m_scrollTimer -= dt;
		if ( m_scrollTimer < 0 )
		{
			m_scrollTimer = m_scrollDuration;

			// \r と \n 無視します（しなければ不具合がある）
			if ( m_label->getString()[m_currentTextIndex] == '\n' )
			{
				++m_currentTextIndex;
			}

			m_label->getChildByTag(m_currentTextIndex)->setVisible(true);
			++m_currentTextIndex;
			if (m_currentTextIndex >= m_stringSize )
			{
				m_bIsScrolling = false;
			}
		}
	}
}



void OwDialogUI::processTouchBegan() { 
	if ( getIsDone() ) {
		return; 
	}

	CCLOG("[OwDialogUI][processTouchBegan]: processTouchBegan!");

	//　文字は全部まだ見えないなら
	if ( m_bIsScrolling )
	{
		//　全部表示させる
		showAllLetters();
		m_bIsScrolling = false;
	}

	else
	{

		if ( !m_otherPages.empty() )
		{
			prepareText(m_otherPages.front().c_str());
			m_otherPages.pop();
			
		}

		else
		{
			m_bIsDone = true; 
			m_sprite->setVisible(false);
		}
	}
}


void OwDialogUI::hideAllLetters()
{
	if ( !m_label ) {
		CCLOG("[OwDialogUI][hideAllLetters]: m_label is null!");
		return;
	}

	CCObject* it = NULL;
	CCARRAY_FOREACH(m_label->getChildren(), it)
	{
		CCNode * its = dynamic_cast<CCNode*>(it);
		its->setVisible(false);
	}

}

void OwDialogUI::showAllLetters()
{
	if ( !m_label ) {
		CCLOG("[OwDialogUI][showAllLetters]: m_label is null!");
		return;
	}

	CCObject* it = NULL;
	for ( int i = 0; i < this->m_stringSize; ++i )
	{
		// \r と \n 無視します（しなければ不具合がある）
		if ( m_label->getString()[i] == '\n' ) {
			++i;
		}

		m_label->getChildByTag(i)->setVisible(true);
	}
}

void OwDialogUI::prepareText(const std::string& text)
{
	if ( !m_label ) {
		CCLOG("[OwDialogUI][prepareText]: m_label is null!");
		return;
	}

	m_label->setString(text.c_str());
	m_stringSize = text.size();
	m_bIsScrolling = true;
	m_currentTextIndex = 0;
	hideAllLetters();
	m_label->getChildByTag(0)->setVisible(true);
}