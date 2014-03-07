#ifndef CSTATEMACHINE_H
#define CSTATEMACHINE_H

#include "AIHeaders.h"

class iState;

/******************************************************************************/
/*!
  \brief
    State machine object

    Todo: Add states without have to new them
*/
/******************************************************************************/
template<typename T>
class cStateMachine
{
protected:
  typedef void (T::*PFNSTATE) (void);
  typedef void (T::*PFNUPDATESTATE) (float dt);
  iState* mCurrentState;
  T* mInstance;
  std::list<iState*> mStateList;
public:
  cStateMachine (T* instance);
  ~cStateMachine();
  void OnUpdate(float dt);               //Update the State Machine
  void SetCurrentState( iState* state ); //Set the initial state of State Machine
  iState* GetCurrentState() { return mCurrentState; }
  void RestartCurrentState();            //Reset the current state of state machine
  void ExitCurrentState();               //Force exit the current state of state machine
  cStateTemplate<T>* AddState(PFNSTATE loadFunc, PFNSTATE EnterFunc, PFNUPDATESTATE updateFunc, PFNSTATE exitFunc, PFNSTATE unloadFunc);
};

#include "cStateMachine.inl"


#endif