/******************************************************************************/
/*!
  \brief
    Set the function pointer of the trigger, targeted state and instance of object
  \param instance
     instance of object
  \param pfnTrigger
     function pointer of trigger condition
  \param state
     targeted state
*/
/******************************************************************************/
template<typename T>
void cTriggerTemplate<T>::InitTrigger( T* instance, PFNTRIGGER pfnTrigger, iState* state )
{
  mInstance = instance;
  mpfnTrigger = pfnTrigger;
  targetState = state;
}

/******************************************************************************/
/*!
  \brief
    check the condition of trigger
   \return
      true if triggered
*/
/******************************************************************************/
template<typename T>
bool cTriggerTemplate<T>::isTriggered()
{
  return (mInstance->*mpfnTrigger)();
}
