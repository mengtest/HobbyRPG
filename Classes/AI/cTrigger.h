#ifndef CTRIGGER_H
#define CTRIGGER_H

#include "iTrigger.h"
#include "cState.h"


/******************************************************************************/
/*!
  \brief
    Base Trigger class
*/
/******************************************************************************/
template <typename T>
class cTriggerTemplate : public iTrigger
{
public:
  typedef bool (T::*PFNTRIGGER) (void);
  void InitTrigger( T* instance, PFNTRIGGER pfnTrigger, iState* state );
  bool isTriggered();
protected:
  T* mInstance;
  PFNTRIGGER mpfnTrigger;

};

#include "cTrigger.inl"



#endif