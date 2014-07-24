#ifndef __OwAICommand_H__
#define __OwAICommand_H__

class OwAICharacter;
class OwAICommand
{
public:
	OwAICommand() : m_controller(0) {}

	virtual void update(float){}
	virtual bool isDone(){ return false; }

	inline void setController(OwAICharacter ** controller) { m_controller = controller; }
    	inline OwAICharacter * getController() { return (*m_controller); }
protected:
	OwAICharacter ** m_controller;
};

#endif //__OwAICommand_H__
