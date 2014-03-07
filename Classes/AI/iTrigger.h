#ifndef ITRIGGER_H
#define ITRIGGER_H


class iState;

/******************************************************************************/
/*!
  \brief
    Base Trigger object
*/
/******************************************************************************/
class iTrigger
{
  protected:
    iState* targetState;
  int mTriggerID;
  public:
    iTrigger():targetState(0),mTriggerID(0) {};
    ~iTrigger(){};
    virtual bool isTriggered () = 0;                 // To be overwritten
    void SetID(int ID) { mTriggerID = ID; }          // Set the index of the trigger
    int GetID() { return mTriggerID; }               // Get the index of the trigger
    iState* GetTargetState() { return targetState; } // Get the Targeted State of the trigger
};

#endif