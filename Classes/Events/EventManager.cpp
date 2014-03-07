#include "EventManager.h"
#include "EventBase.h"

EventManager::EventManager()
{
}

EventManager::~EventManager()
{
	while (!isEmpty() ) {
		safePop();
	}
}

bool EventManager::isEmpty()
{
	return m_eventQueue.empty();
}

void EventManager::start()
{
	if ( isEmpty() )
	{
		return;
	}

	m_eventQueue.front()->init();
}

void EventManager::addEvent(EventBase * t_event)
{
	m_eventQueue.push(t_event);
}


void EventManager::update(float dt)
{
	if ( isEmpty() )
		return;
	
	EventBase * temp = m_eventQueue.front();
	if ( temp->isDone() )
	{
		safePop();

		if (  !m_eventQueue.empty() )
		{
			// Init next guy
			// 次のイベンットを準備する
			m_eventQueue.front()->init(); 
		}
	}

	else {
		temp->update(dt);
	}
}

void EventManager::safePop()
{
	EventBase * temp = m_eventQueue.front();
	temp->free();
	m_eventQueue.pop();
	delete temp;
}