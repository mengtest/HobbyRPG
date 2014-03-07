#ifndef __EVENT_MANAGER_H__
#define __EVENT_MANAGER_H__

#include <queue>

// Queue based event manager
class EventBase;
class EventManager
{
public:
	EventManager();
	~EventManager();

	bool isEmpty();
	void start();
	void addEvent(EventBase * t_event);
	void update(float dt);

private:
	//queue based event system...
	std::queue<EventBase*> m_eventQueue;

	void safePop();

};

#endif