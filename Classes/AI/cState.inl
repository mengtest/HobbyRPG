
template <typename T>
cStateTemplate<T>::cStateTemplate()
:mInstance(0),
 mpfnLoadState(0),
 mpfnBeginState(0),
 mpfnUpdateState(0),
 mpfnEndState(0),
 mpfnUnloadState(0)
{

}

/******************************************************************************/
/*!
  \brief
    Set the function pointers of the state and the instance of the object
  \param instance
    instance of object
  \param pfnLoadState
    function pointer of load state
  \param pfnBeginState
    function pointer of enter state
  \param pfnUpdateState
    function pointer of update state
  \param pfnEndState
    function pointer of end state
  \param pfnUnloadState
    function pointer of unload state
*/
/******************************************************************************/
template<typename T>
void cStateTemplate<T>::InitState(T* instance, PFNSTATE pfnLoadState, PFNSTATE pfnBeginState,
                            PFNUPDATESTATE pfnUpdateState, PFNSTATE pfnEndState, PFNSTATE pfnUnloadState)
{
  mInstance = instance;
  mpfnLoadState = pfnLoadState;
  mpfnBeginState = pfnBeginState;
  mpfnUpdateState = pfnUpdateState;
  mpfnEndState = pfnEndState;
  mpfnUnloadState = pfnUnloadState;
}

/******************************************************************************/
/*!
  \brief
    load state
*/
/******************************************************************************/
template<typename T>
void cStateTemplate<T>::OnLoad(void)
{
  (mInstance->*mpfnLoadState)();
}

/******************************************************************************/
/*!
  \brief
    enter state
*/
/******************************************************************************/
template<typename T>
void cStateTemplate<T>::OnEnter(void)
{
  (mInstance->*mpfnBeginState)();
}

/******************************************************************************/
/*!
  \brief
    Update state
  \param dt
     delta time
*/
/******************************************************************************/
template<typename T>
void cStateTemplate<T>::OnUpdate(float dt)
{
  (mInstance->*mpfnUpdateState)(dt);
}

/******************************************************************************/
/*!
  \brief
    exit state
*/
/******************************************************************************/
template<typename T>
void cStateTemplate<T>::OnExit(void)
{
  (mInstance->*mpfnEndState)();
}

/******************************************************************************/
/*!
  \brief
    unload state
*/
/******************************************************************************/
template<typename T>
void cStateTemplate<T>::OnUnload(void)
{
  (mInstance->*mpfnUnloadState)();
}

template<typename T>
void cStateTemplate<T>::AddTriggerCheck(PFNTRIGGER triggerFunc, iState* targetState)
{
  cTriggerTemplate<T>* trigger = new cTriggerTemplate<T>();
  trigger->InitTrigger(mInstance, triggerFunc, targetState);
  AddTriggerToList(trigger);
}