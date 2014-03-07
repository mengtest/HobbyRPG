#ifndef ISTATE_H
#define ISTATE_H

#include <list>

class iTrigger;

/******************************************************************************/
/*!
  \brief
    Base state object
*/
/******************************************************************************/
class iState
{
private:
  std::list<iTrigger*> mTriggerList;
  unsigned mTriggerCount;
public:
  iState(void);
  virtual ~iState();
  virtual void OnLoad() = 0;
  virtual void OnEnter() = 0;
  virtual void OnUpdate(float dt) = 0;
  virtual void OnExit() = 0;
  virtual void OnUnload() = 0;
  std::list<iTrigger*> & GetTriggerList() { return mTriggerList; } //Get Trigger List
  
  int AddTriggerToList(iTrigger* trigger); //Add the trigger to the list
  void RemoveTriggerFromList(int ID);      //Remove a specific trigger
};

#endif