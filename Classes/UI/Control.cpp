#include "Control.h"
#include "cBaseUI.h"
#include "Page.h"

USING_NS_CC;

Control::Control()
:m_pageOwner(NULL),m_def(NULL)
{

}

Control::~Control()
{
	CC_SAFE_DELETE(m_def);
}

bool Control::init(ControlDef* def, Page* pageOwner)
{
	if(def)
	{
		setPosition(def->m_pos);
		m_def = def;
	}

	if(pageOwner)
	{
		m_pageOwner = pageOwner;
		m_pageOwner->addControl(this);
	}

	return CCMenuItem::initWithTarget(NULL, NULL);
}


void Control::update(float dt)
{
	if(m_def)
	{
		if(m_def->m_image)
		{
			std::string imageValue(m_pageOwner->getUI()->convertedImage(m_def->m_name.c_str(), m_def->imageValue.c_str()));

			// continue only if there is change
			if ( strcmp ( imageValue.c_str(), m_def->imageValue.c_str() ) )
			{
				CCSize old = m_def->m_image->getContentSize(); //save old size
				
				// for some reason this stupid function does not take in one more variable which is the CapInsert rect
				// TODO: modify "setSpriteFrame" so that it takes in a CapInsert rect.
				m_def->m_image->setSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(imageValue.c_str()) );
				m_def->m_image->setCapInsets( m_def->m_capInsert );
	
				m_def->m_image->setAnchorPoint(ccp(0, 0));	
				m_def->m_image->setContentSize(old); // set old size
				m_def->imageValue = imageValue;
				setContentSize(old);
			}
		}

		if(m_def->m_fontstring)
		{
			std::string stringValue(m_pageOwner->getUI()->convertedString(m_def->stringValue.c_str()));
			m_def->m_fontstring->setString(stringValue.c_str());

			// TODO: need extra variable here for left/center/right alignment
			// now it's just a quick hack.
			if(m_def->m_image)
			{
				m_def->m_fontstring->setAnchorPoint(ccp(0.5, 0.5));
			}

			else
			{
				m_def->m_fontstring->setAnchorPoint(ccp(0.0f, 0.5f)); // left aligned
			}
			
		}

	}



}

void Control::activate()
{
	CCMenuItem::activate();
	if(m_pageOwner)
	{
		if(m_def)
		{
			if(m_pageOwner->getUI())
			{
				m_pageOwner->getUI()->controlClicked(m_def->m_name.c_str());
			}
		}
	}

}