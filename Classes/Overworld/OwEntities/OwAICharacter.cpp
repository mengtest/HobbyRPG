#include "OwAICharacter.h"
#include "..\OwAICommands\OwAICommand.h"
#include "..\OwEntities\OwCharacter.h"
#include "..\OwManager\OwManager.h"
#include "..\OwEvents\OwEventDialog.h"
#include "..\..\Enum\DirectionEnum.h"

#include "CCLuaEngine.h"


using namespace std;

USING_NS_CC;

OwAICharacter::OwAICharacter(CCPoint position, const std::string& name, const string& spriteName, const string& initialSpriteBaseName, int id)
	: OwCharacter(position, name, spriteName, initialSpriteBaseName, id),
	  m_bIsLoop(true), m_bIsPaused(false), m_currentCmd(0), m_bIsDone(false),
	  m_bIsCmdLock(false)
{
	
}

OwAICharacter::~OwAICharacter()
{
	clearCommands();
}

bool OwAICharacter::loadLUA()
{
	// LUA‚ðŽÀs‚µ‚Ü‚·
	std::string path = CCFileUtils::sharedFileUtils()->fullPathForFilename( ("lua/world/" + m_name + "_functions.lua" ).c_str() );
	
	std::string errorMsg ( path + " cannot be found!" );
	if (CCFileUtils::sharedFileUtils()->isFileExist( path ) )
	{
		if (  CCLuaEngine::defaultEngine()->executeScriptFile(path.c_str()) != 0 )
		{
			CCLOG("[OwAICharacter][constr]: LUA Error: %s", path.c_str() );
			return false;
		}
	}

	else
	{
		CCLOG("[OwAICharacter][constr]: Note that '%s' has no LUA functions", m_name.c_str() );
	}

	return true;
}

void OwAICharacter::clearCommands()
{
	std::vector<OwAICommand*>::iterator beg = m_commands.begin();
	std::vector<OwAICommand*>::iterator end = m_commands.end();
	for (; beg != end; ++beg )
	{
		delete (*beg);
	}
}

void OwAICharacter::update(float dt)
{
	OwCharacter::update(dt);
	if (m_commands.empty() || 
		m_bIsPaused ||
		m_bIsDone || 
		m_bIsCmdLock ) 
	{
		return;
	}

	m_commands[m_currentCmd]->update(dt);

	if ( m_commands[m_currentCmd]->isDone() )
	{
		++m_currentCmd;
		if ( m_currentCmd >= m_commands.size() )
		{
			if (m_bIsLoop)
			{
				m_currentCmd = 0;
			} 
			
			else
			{
				m_bIsDone = true;
			}
		}
	}



}

void OwAICharacter::addCommand(OwAICommand * command)
{
	if ( !command )
	{
		CCLOG("[OwAICharacter][addCommand]: command is null ");
		return;
	}

	command->setController(this);
	this->m_commands.push_back(command);
}




void OwAICharacter::interact(OwEntityBase * interactee)
{
	if ( !interactee )
	{
		CCLOG("[OwAICharacter][interact]: interactee is null ");
		return;
	}

	CCLOG("[OwAICharacter][interact]: '%s' interacted with '%s' ", interactee->getName().c_str(), this->getName().c_str() );
	
	// face interactee
	CCPoint temp = this->getPosition() - interactee->getPosition();
	DirectionEnum dir;
	float abs_x = fabs(temp.x);
	float abs_y = fabs(temp.y);

	if ( abs_x > abs_y )
	{
		if ( temp.x < 0 ) 
			dir = RIGHT;
		else if ( temp.x > 0 )
			dir = LEFT;
	}
	
	else 
	{
		if ( temp.y < 0 )
			dir = UP;
		else if ( temp.y > 0 )
			dir = DOWN;
	}

	
	face(dir);
	stopAnimations();

	CCLuaEngine::defaultEngine()->executeGlobalFunction( (m_name + "_interact").c_str() );

}

void OwAICharacter::callback( const std::string& msg, void * data)
{
	if ( !strcmp(msg.c_str(), "pause") )
	{
		this->pauseCommands();
	}

	else if ( !strcmp(msg.c_str(), "play"))
	{
		this->playCommands();
	}

}