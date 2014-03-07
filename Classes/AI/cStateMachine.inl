#include "cState.h"

/******************************************************************************/
/*!
  \brief
    Constructor
*/
/******************************************************************************/
template<typename T>
cStateMachine<T>::cStateMachine(T* instance)
: mCurrentState(0),mInstance(instance)
{
 
}

/******************************************************************************/
/*!
  \brief
    Destructor
*/
/******************************************************************************/
template<typename T>
cStateMachine<T>::~cStateMachine()
{
  if(mCurrentState)
  {
    mCurrentState->OnExit();
    mCurrentState->OnUnload();
  }

  for(std::list<iState*>::iterator itr = mStateList.begin(); itr != mStateList.end(); ++itr)
  {
    iState* state = (*itr);
    delete state;
  }

  mStateList.clear();

}

/******************************************************************************/
/*!
  \brief
    Update State Machine
  \param dt
    delta time of game

*/
/******************************************************************************/
template<typename T>
void cStateMachine<T>::OnUpdate(float dt)
{
  if(mCurrentState)
  {
    mCurrentState->OnUpdate(dt);
  }

  std::list<iTrigger*> triggerList = mCurrentState->GetTriggerList();

  for(std::list<iTrigger*>::iterator itr = triggerList.begin(); itr != triggerList.end(); ++itr)
  {
    iTrigger* trigger = *itr;
    if(trigger->isTriggered())
    {
      mCurrentState->OnExit();
      mCurrentState->OnUnload();
      if(trigger->GetTargetState())
      {
        mCurrentState = trigger->GetTargetState();
        mCurrentState->OnLoad();
        mCurrentState->OnEnter();
      }
      else
      {
        mCurrentState = NULL;
      }
      break;
    }
  }

}

/******************************************************************************/
/*!
  \brief
    Set the initial State of StateMachine
  \param state
    initial state of state machine

*/
/******************************************************************************/
template<typename T>
void cStateMachine<T>::SetCurrentState( iState* state )
{
  mCurrentState = state;
  mCurrentState->OnLoad();
  mCurrentState->OnEnter();
}

/******************************************************************************/
/*!
  \brief
    Exit the current state of state machine
*/
/******************************************************************************/
template<typename T>
void cStateMachine<T>::ExitCurrentState()
{
  if(mCurrentState)
  {
    mCurrentState->OnExit();
    mCurrentState->OnUnload();
  }
}

/******************************************************************************/
/*!
  \brief
    Restart the current state of state machine
*/
/******************************************************************************/
template<typename T>
void cStateMachine<T>::RestartCurrentState()
{
  mCurrentState->OnExit();
  mCurrentState->OnEnter();
}

template<typename T>
cStateTemplate<T>* cStateMachine<T>::AddState(PFNSTATE loadFunc, 
                                   PFNSTATE EnterFunc, 
                                   PFNUPDATESTATE updateFunc, 
                                   PFNSTATE exitFunc, 
                                   PFNSTATE unloadFunc)
{
  cStateTemplate<T>* state = new cStateTemplate<T>();
  state->InitState(mInstance, loadFunc, EnterFunc, updateFunc, exitFunc, unloadFunc);
  mStateList.push_back(state);
  return state;
}
