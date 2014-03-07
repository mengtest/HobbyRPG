#ifndef __EVENTBASE_H__
#define __EVENTBASE_H__

class EventBase
{
public:
	EventBase() : m_bIsDone(true) {}
	~EventBase() {}

	virtual void init() = 0;
	virtual void update( float dt ) = 0;
	virtual void free() = 0;
	virtual bool isDone() = 0;
protected:
	bool m_bIsDone;
};

#endif