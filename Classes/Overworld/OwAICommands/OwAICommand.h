#ifndef __OwAICommand_H__
#define __OwAICommand_H__

class OwAICharacter;
class OwAICommand
{
public:
	OwAICommand(){}

	virtual void update(float){}
	virtual bool isDone(){ return false; }

	inline void setController(OwAICharacter * controller) { m_controller = controller; }
protected:
	OwAICharacter * m_controller;
};

#endif //__OwAICommand_H__