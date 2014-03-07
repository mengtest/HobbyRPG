#ifndef CSTATE_H
#define CSTATE_H

#include "iState.h"
#include "cTrigger.h"

/******************************************************************************/
/*!
  \brief
    Generic State template
*/
/******************************************************************************/
template <typename T>
class cStateTemplate : public iState
{
protected:
  typedef void (T::*PFNSTATE) (void);
  typedef void (T::*PFNUPDATESTATE) (float dt);
  typedef bool (T::*PFNTRIGGER) (void);
  T* mInstance;
  PFNSTATE  mpfnLoadState;
  PFNSTATE  mpfnBeginState;
  PFNUPDATESTATE mpfnUpdateState;
  PFNSTATE  mpfnEndState;
  PFNSTATE  mpfnUnloadState;

public:
  cStateTemplate();
  void InitState(T* instance, PFNSTATE pfnLoadState, PFNSTATE pfnBeginState,
             PFNUPDATESTATE pfnUpdateState, PFNSTATE pfnEndState, PFNSTATE pfnUnloadState);
  void OnLoad(void);
  void OnEnter(void);
  void OnUpdate(float dt);
  void OnExit(void);
  void OnUnload(void);
  void AddTriggerCheck(PFNTRIGGER triggerFunc, iState* targetState);
};

#include "cState.inl"


#endif

