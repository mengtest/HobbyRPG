#ifndef __WorldEventDialog_H__
#define __WorldEventDialog_H__

#include <string>
#include "..\..\Events\EventBase.h"

class WorldEventDialog : public EventBase
{
public:
	WorldEventDialog(const std::string& text);
	~WorldEventDialog() {};

	void addPage(const std::string& text);

	void update(float dt);
	bool isDone();
	void init();
	void free();
	
private:
	std::string m_text;
};

#endif