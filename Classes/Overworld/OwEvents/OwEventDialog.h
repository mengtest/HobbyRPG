#ifndef __OwEventDialog_H__
#define __OwEventDialog_H__

#include <string>
#include "..\..\Events\EventBase.h"

class OwEntityBase;
class OwEventDialog : public EventBase
{
public:
	OwEventDialog(const std::string& text, OwEntityBase * lhs = 0, OwEntityBase * rhs = 0);
	~OwEventDialog() {};

	void addPage(const std::string& text);

	void update(float dt);
	bool isDone();
	void init();
	void free();
	
private:
	OwEntityBase * m_lhs;
	OwEntityBase * m_rhs;

	std::string m_text;
};

#endif