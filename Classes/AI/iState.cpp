
#include "iState.h"
#include "iTrigger.h"


/******************************************************************************/
/*!
  \brief
    Constructor
*/
/******************************************************************************/
iState::iState(void)
:mTriggerCount(0)
{

}

/******************************************************************************/
/*!
  \brief
    Destructor
*/
/******************************************************************************/
iState::~iState() 
{
  for(std::list<iTrigger*>::iterator itr = mTriggerList.begin(); itr != mTriggerList.end(); ++itr)
  {
    iTrigger* trigger = *itr;
      
    if(trigger)
    {
      delete trigger;
    }
  }
}

/******************************************************************************/
/*!
  \brief
    Add the trigger to state
  \param trigger
    trigger to push to state
  \return
     the index of the trigger

*/
/******************************************************************************/
int iState::AddTriggerToList(iTrigger* trigger)
{
  trigger->SetID(mTriggerCount);
  mTriggerList.push_back(trigger);
  return mTriggerCount++;
}

/******************************************************************************/
/*!
  \brief
    Remove trigger from the list
  \param ID
    index of trigger to remove

*/
/******************************************************************************/
void iState::RemoveTriggerFromList(int ID)
{
  for(std::list<iTrigger*>::iterator itr = mTriggerList.begin(); itr != mTriggerList.end(); ++itr)
  {
    iTrigger* trigger = *itr;
      
    if(trigger)
    {
    if(trigger->GetID() == ID)
    {
      mTriggerList.erase(itr);
      delete trigger;
      break;
    }
    }
  }
}
