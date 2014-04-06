#ifndef __OwAICharacter_H__
#define __OwAICharacter_H__

#include <vector>
#include "..\OwEntities\OwCharacter.h"
#include "..\OwAICommands\OwAICommand.h"
#include "Common\Common.h"

/****************************************************************
Smarter character who can follow a list of commands given to it
*****************************************************************/

class OwAICharacter : public OwCharacter
{
public:
	OwAICharacter(cocos2d::CCPoint position, 
					const std::string& name, 
					const std::string& spriteBaseName = "chika",
					const std::string& initialSpriteFrameName = "chika_front_2.png",
					int id = 0);
	~OwAICharacter();

	bool loadLUA();
	void update(float dt);
	void addCommand(OwAICommand * command);
	void clearCommands();
	
	void pauseCommands()	{ m_bIsPaused = true; }
	void playCommands()		{ m_bIsPaused = false; }
	void resetCommands()	{ m_currentCmd = 0; }
	void lockCommands()		{ m_bIsCmdLock = true; }
	void unlockCommands()	{ m_bIsCmdLock = false; }
	

	inline void setLoop( bool loop ) { m_bIsLoop = loop; }
	
	void interact(OwEntityBase * interactee);
	void callback( const std::string& msg, void * data);

	void onAttach() { lockCommands() ;}
	void onDetach() { unlockCommands() ;}
protected:
	std::vector<OwAICommand*> m_commands;
	int m_currentCmd;
	bool m_bIsLoop;
	bool m_bIsPaused;
	bool m_bIsDone;
	
	bool m_bIsCmdLock;
};

#endif