/*
** Lua binding: AllLua
** Generated automatically by tolua++-1.0.92 on 03/31/14 22:04:01.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_AllLua_open (lua_State* tolua_S);

#include "GameToLua.h"
#include "..\Overworld\OwManager\OwManager.h"
#include "..\Overworld\OwEntities\OwEntityBase.h"
#include "..\Overworld\OwEntities\OwCharacter.h"
#include "..\Overworld\OwEntities\OwAICharacter.h"
#include "..\Overworld\OwAICommands\OwAIMove.h"
#include "..\Overworld\OwEvents\OwEventDelay.h"
#include "..\Overworld\OwEvents\OwEventDialog.h"
#include "..\Enum\DirectionEnum.h"
#include "..\Common\Common.h"
#include "..\Character\Character.h"
#include "..\Player\Player.h"
#include "..\Inventory\Inventory.h"
#include "..\Party\Party.h"
#include "..\Item\ItemManager.h"
#include "..\World\WorldManager\WorldManager.h"
#include "..\World\WorldEvents\WorldEventDialog.h"
#include "..\Enum\ItemEnum.h"
#include "..\Enum\ItemStatEnum.h"
#include "..\Enum\StatsEnum.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_OwEventDelay (lua_State* tolua_S)
{
 OwEventDelay* self = (OwEventDelay*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_OwAIMove (lua_State* tolua_S)
{
 OwAIMove* self = (OwAIMove*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_WorldEventDialog (lua_State* tolua_S)
{
 WorldEventDialog* self = (WorldEventDialog*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_OwEventDialog (lua_State* tolua_S)
{
 OwEventDialog* self = (OwEventDialog*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"OwEventDelay");
 tolua_usertype(tolua_S,"ItemManager");
 tolua_usertype(tolua_S,"OwManager");
 tolua_usertype(tolua_S,"Character");
 tolua_usertype(tolua_S,"OwAICommand");
 tolua_usertype(tolua_S,"CCNode");
 tolua_usertype(tolua_S,"OwCharacter");
 tolua_usertype(tolua_S,"OwEntityBase");
 tolua_usertype(tolua_S,"WorldEventDialog");
 tolua_usertype(tolua_S,"Common");
 tolua_usertype(tolua_S,"std::vector<std::string>");
 tolua_usertype(tolua_S,"EventBase");
 tolua_usertype(tolua_S,"OwAIMove");
 tolua_usertype(tolua_S,"WorldManager");
 tolua_usertype(tolua_S,"OwEventDialog");
 tolua_usertype(tolua_S,"Inventory");
 tolua_usertype(tolua_S,"Party");
 tolua_usertype(tolua_S,"Player");
 tolua_usertype(tolua_S,"OwAICharacter");
}

/* method: getInstance of class  ItemManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_ItemManager_getInstance00
static int tolua_AllLua_ItemManager_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ItemManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ItemManager& tolua_ret = (ItemManager&)  ItemManager::getInstance();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ItemManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getItemValues of class  ItemManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_ItemManager_getItemValues00
static int tolua_AllLua_ItemManager_getItemValues00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ItemManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ItemManager* self = (ItemManager*)  tolua_tousertype(tolua_S,1,0);
  ItemEnum type = ((ItemEnum) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getItemValues'", NULL);
#endif
  {
   const std::vector<std::string>& tolua_ret = (const std::vector<std::string>&)  self->getItemValues(type);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::vector<std::string>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getItemValues'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getItemStat of class  ItemManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_ItemManager_getItemStat00
static int tolua_AllLua_ItemManager_getItemStat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ItemManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ItemManager* self = (ItemManager*)  tolua_tousertype(tolua_S,1,0);
  ItemEnum type = ((ItemEnum) (int)  tolua_tonumber(tolua_S,2,0));
  ItemStatEnum stat = ((ItemStatEnum) (int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getItemStat'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->getItemStat(type,stat);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getItemStat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getGameWidth of class  Common */
#ifndef TOLUA_DISABLE_tolua_AllLua_Common_getGameWidth00
static int tolua_AllLua_Common_getGameWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Common",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  Common::getGameWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGameWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getGameHeight of class  Common */
#ifndef TOLUA_DISABLE_tolua_AllLua_Common_getGameHeight00
static int tolua_AllLua_Common_getGameHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Common",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  Common::getGameHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGameHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_WorldManager_getInstance00
static int tolua_AllLua_WorldManager_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"WorldManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   WorldManager* tolua_ret = (WorldManager*)  WorldManager::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"WorldManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addEvent of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_WorldManager_addEvent00
static int tolua_AllLua_WorldManager_addEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"WorldManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"EventBase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  WorldManager* self = (WorldManager*)  tolua_tousertype(tolua_S,1,0);
  EventBase* event = ((EventBase*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addEvent'", NULL);
#endif
  {
   self->addEvent(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: gotoOverworld of class  WorldManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_WorldManager_gotoOverworld00
static int tolua_AllLua_WorldManager_gotoOverworld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"WorldManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  WorldManager* self = (WorldManager*)  tolua_tousertype(tolua_S,1,0);
  std::string where = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'gotoOverworld'", NULL);
#endif
  {
   self->gotoOverworld(where);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'gotoOverworld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  WorldEventDialog */
#ifndef TOLUA_DISABLE_tolua_AllLua_WorldEventDialog_new00
static int tolua_AllLua_WorldEventDialog_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"WorldEventDialog",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string text = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   WorldEventDialog* tolua_ret = (WorldEventDialog*)  Mtolua_new((WorldEventDialog)(text));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"WorldEventDialog");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  WorldEventDialog */
#ifndef TOLUA_DISABLE_tolua_AllLua_WorldEventDialog_new00_local
static int tolua_AllLua_WorldEventDialog_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"WorldEventDialog",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string text = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   WorldEventDialog* tolua_ret = (WorldEventDialog*)  Mtolua_new((WorldEventDialog)(text));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"WorldEventDialog");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addPage of class  WorldEventDialog */
#ifndef TOLUA_DISABLE_tolua_AllLua_WorldEventDialog_addPage00
static int tolua_AllLua_WorldEventDialog_addPage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"WorldEventDialog",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  WorldEventDialog* self = (WorldEventDialog*)  tolua_tousertype(tolua_S,1,0);
  const std::string text = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addPage'", NULL);
#endif
  {
   self->addPage(text);
   tolua_pushcppstring(tolua_S,(const char*)text);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addPage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  OwManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwManager_getInstance00
static int tolua_AllLua_OwManager_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"OwManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   OwManager* tolua_ret = (OwManager*)  OwManager::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OwManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addEvent of class  OwManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwManager_addEvent00
static int tolua_AllLua_OwManager_addEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OwManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"EventBase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OwManager* self = (OwManager*)  tolua_tousertype(tolua_S,1,0);
  EventBase* event = ((EventBase*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addEvent'", NULL);
#endif
  {
   self->addEvent(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAICharacterByName of class  OwManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwManager_getAICharacterByName00
static int tolua_AllLua_OwManager_getAICharacterByName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OwManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OwManager* self = (OwManager*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAICharacterByName'", NULL);
#endif
  {
   OwAICharacter* tolua_ret = (OwAICharacter*)  self->getAICharacterByName(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OwAICharacter");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAICharacterByName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: gotoWorld of class  OwManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwManager_gotoWorld00
static int tolua_AllLua_OwManager_gotoWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OwManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OwManager* self = (OwManager*)  tolua_tousertype(tolua_S,1,0);
  int origin_node = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'gotoWorld'", NULL);
#endif
  {
   self->gotoWorld(origin_node);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'gotoWorld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: gotoOverworld of class  OwManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwManager_gotoOverworld00
static int tolua_AllLua_OwManager_gotoOverworld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OwManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OwManager* self = (OwManager*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'gotoOverworld'", NULL);
#endif
  {
   self->gotoOverworld(name,x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'gotoOverworld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addChildToUILayer of class  OwManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwManager_addChildToUILayer00
static int tolua_AllLua_OwManager_addChildToUILayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OwManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OwManager* self = (OwManager*)  tolua_tousertype(tolua_S,1,0);
  CCNode* obj = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addChildToUILayer'", NULL);
#endif
  {
   self->addChildToUILayer(obj);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addChildToUILayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeChildFromUILayer of class  OwManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwManager_removeChildFromUILayer00
static int tolua_AllLua_OwManager_removeChildFromUILayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OwManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OwManager* self = (OwManager*)  tolua_tousertype(tolua_S,1,0);
  CCNode* obj = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeChildFromUILayer'", NULL);
#endif
  {
   self->removeChildFromUILayer(obj);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeChildFromUILayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pause of class  OwManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwManager_pause00
static int tolua_AllLua_OwManager_pause00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OwManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OwManager* self = (OwManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pause'", NULL);
#endif
  {
   self->pause();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pause'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unpause of class  OwManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwManager_unpause00
static int tolua_AllLua_OwManager_unpause00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OwManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OwManager* self = (OwManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unpause'", NULL);
#endif
  {
   self->unpause();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unpause'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resetMenuLUA of class  OwManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwManager_resetMenuLUA00
static int tolua_AllLua_OwManager_resetMenuLUA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OwManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OwManager* self = (OwManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resetMenuLUA'", NULL);
#endif
  {
   self->resetMenuLUA();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resetMenuLUA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addCommand of class  OwAICharacter */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwAICharacter_addCommand00
static int tolua_AllLua_OwAICharacter_addCommand00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OwAICharacter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"OwAICommand",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OwAICharacter* self = (OwAICharacter*)  tolua_tousertype(tolua_S,1,0);
  OwAICommand* command = ((OwAICommand*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addCommand'", NULL);
#endif
  {
   self->addCommand(command);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addCommand'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearCommands of class  OwAICharacter */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwAICharacter_clearCommands00
static int tolua_AllLua_OwAICharacter_clearCommands00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OwAICharacter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OwAICharacter* self = (OwAICharacter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearCommands'", NULL);
#endif
  {
   self->clearCommands();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearCommands'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLoop of class  OwAICharacter */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwAICharacter_setLoop00
static int tolua_AllLua_OwAICharacter_setLoop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OwAICharacter",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OwAICharacter* self = (OwAICharacter*)  tolua_tousertype(tolua_S,1,0);
  bool loop = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLoop'", NULL);
#endif
  {
   self->setLoop(loop);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLoop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pauseCommands of class  OwAICharacter */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwAICharacter_pauseCommands00
static int tolua_AllLua_OwAICharacter_pauseCommands00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OwAICharacter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OwAICharacter* self = (OwAICharacter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pauseCommands'", NULL);
#endif
  {
   self->pauseCommands();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pauseCommands'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: playCommands of class  OwAICharacter */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwAICharacter_playCommands00
static int tolua_AllLua_OwAICharacter_playCommands00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OwAICharacter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OwAICharacter* self = (OwAICharacter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'playCommands'", NULL);
#endif
  {
   self->playCommands();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'playCommands'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resetCommands of class  OwAICharacter */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwAICharacter_resetCommands00
static int tolua_AllLua_OwAICharacter_resetCommands00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OwAICharacter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OwAICharacter* self = (OwAICharacter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resetCommands'", NULL);
#endif
  {
   self->resetCommands();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resetCommands'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lockCommands of class  OwAICharacter */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwAICharacter_lockCommands00
static int tolua_AllLua_OwAICharacter_lockCommands00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OwAICharacter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OwAICharacter* self = (OwAICharacter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lockCommands'", NULL);
#endif
  {
   self->lockCommands();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lockCommands'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unlockCommands of class  OwAICharacter */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwAICharacter_unlockCommands00
static int tolua_AllLua_OwAICharacter_unlockCommands00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OwAICharacter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OwAICharacter* self = (OwAICharacter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unlockCommands'", NULL);
#endif
  {
   self->unlockCommands();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unlockCommands'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  OwAIMove */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwAIMove_new00
static int tolua_AllLua_OwAIMove_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"OwAIMove",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DirectionEnum direction = ((DirectionEnum) (int)  tolua_tonumber(tolua_S,2,0));
  int steps = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   OwAIMove* tolua_ret = (OwAIMove*)  Mtolua_new((OwAIMove)(direction,steps));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OwAIMove");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  OwAIMove */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwAIMove_new00_local
static int tolua_AllLua_OwAIMove_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"OwAIMove",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DirectionEnum direction = ((DirectionEnum) (int)  tolua_tonumber(tolua_S,2,0));
  int steps = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   OwAIMove* tolua_ret = (OwAIMove*)  Mtolua_new((OwAIMove)(direction,steps));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OwAIMove");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  OwEventDialog */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwEventDialog_new00
static int tolua_AllLua_OwEventDialog_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"OwEventDialog",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"OwEntityBase",1,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"OwEntityBase",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string text = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  OwEntityBase* lhs = ((OwEntityBase*)  tolua_tousertype(tolua_S,3,0));
  OwEntityBase* rhs = ((OwEntityBase*)  tolua_tousertype(tolua_S,4,0));
  {
   OwEventDialog* tolua_ret = (OwEventDialog*)  Mtolua_new((OwEventDialog)(text,lhs,rhs));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OwEventDialog");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  OwEventDialog */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwEventDialog_new00_local
static int tolua_AllLua_OwEventDialog_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"OwEventDialog",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"OwEntityBase",1,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"OwEntityBase",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string text = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  OwEntityBase* lhs = ((OwEntityBase*)  tolua_tousertype(tolua_S,3,0));
  OwEntityBase* rhs = ((OwEntityBase*)  tolua_tousertype(tolua_S,4,0));
  {
   OwEventDialog* tolua_ret = (OwEventDialog*)  Mtolua_new((OwEventDialog)(text,lhs,rhs));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OwEventDialog");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addPage of class  OwEventDialog */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwEventDialog_addPage00
static int tolua_AllLua_OwEventDialog_addPage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OwEventDialog",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OwEventDialog* self = (OwEventDialog*)  tolua_tousertype(tolua_S,1,0);
  const std::string text = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addPage'", NULL);
#endif
  {
   self->addPage(text);
   tolua_pushcppstring(tolua_S,(const char*)text);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addPage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  OwEventDelay */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwEventDelay_new00
static int tolua_AllLua_OwEventDelay_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"OwEventDelay",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"OwEntityBase",1,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"OwEntityBase",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float delay = ((float)  tolua_tonumber(tolua_S,2,0));
  OwEntityBase* lhs = ((OwEntityBase*)  tolua_tousertype(tolua_S,3,0));
  OwEntityBase* rhs = ((OwEntityBase*)  tolua_tousertype(tolua_S,4,0));
  {
   OwEventDelay* tolua_ret = (OwEventDelay*)  Mtolua_new((OwEventDelay)(delay,lhs,rhs));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OwEventDelay");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  OwEventDelay */
#ifndef TOLUA_DISABLE_tolua_AllLua_OwEventDelay_new00_local
static int tolua_AllLua_OwEventDelay_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"OwEventDelay",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"OwEntityBase",1,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"OwEntityBase",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float delay = ((float)  tolua_tonumber(tolua_S,2,0));
  OwEntityBase* lhs = ((OwEntityBase*)  tolua_tousertype(tolua_S,3,0));
  OwEntityBase* rhs = ((OwEntityBase*)  tolua_tousertype(tolua_S,4,0));
  {
   OwEventDelay* tolua_ret = (OwEventDelay*)  Mtolua_new((OwEventDelay)(delay,lhs,rhs));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OwEventDelay");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLevel of class  Character */
#ifndef TOLUA_DISABLE_tolua_AllLua_Character_setLevel00
static int tolua_AllLua_Character_setLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  int level = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLevel'", NULL);
#endif
  {
   self->setLevel(level);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: heal of class  Character */
#ifndef TOLUA_DISABLE_tolua_AllLua_Character_heal00
static int tolua_AllLua_Character_heal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  int amount = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'heal'", NULL);
#endif
  {
   self->heal(amount);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'heal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: damage of class  Character */
#ifndef TOLUA_DISABLE_tolua_AllLua_Character_damage00
static int tolua_AllLua_Character_damage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  int amount = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'damage'", NULL);
#endif
  {
   self->damage(amount);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'damage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equipWeapon of class  Character */
#ifndef TOLUA_DISABLE_tolua_AllLua_Character_equipWeapon00
static int tolua_AllLua_Character_equipWeapon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  ItemEnum item = ((ItemEnum) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equipWeapon'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equipWeapon(item);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equipWeapon'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equipArmor of class  Character */
#ifndef TOLUA_DISABLE_tolua_AllLua_Character_equipArmor00
static int tolua_AllLua_Character_equipArmor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  ItemEnum item = ((ItemEnum) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equipArmor'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equipArmor(item);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equipArmor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equipRing of class  Character */
#ifndef TOLUA_DISABLE_tolua_AllLua_Character_equipRing00
static int tolua_AllLua_Character_equipRing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  ItemEnum item = ((ItemEnum) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equipRing'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equipRing(item);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equipRing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWeapon of class  Character */
#ifndef TOLUA_DISABLE_tolua_AllLua_Character_getWeapon00
static int tolua_AllLua_Character_getWeapon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWeapon'", NULL);
#endif
  {
   ItemEnum tolua_ret = (ItemEnum)  self->getWeapon();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWeapon'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getArmor of class  Character */
#ifndef TOLUA_DISABLE_tolua_AllLua_Character_getArmor00
static int tolua_AllLua_Character_getArmor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getArmor'", NULL);
#endif
  {
   ItemEnum tolua_ret = (ItemEnum)  self->getArmor();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getArmor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRing of class  Character */
#ifndef TOLUA_DISABLE_tolua_AllLua_Character_getRing00
static int tolua_AllLua_Character_getRing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRing'", NULL);
#endif
  {
   ItemEnum tolua_ret = (ItemEnum)  self->getRing();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStat of class  Character */
#ifndef TOLUA_DISABLE_tolua_AllLua_Character_getStat00
static int tolua_AllLua_Character_getStat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  StatsEnum type = ((StatsEnum) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStat'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getStat(type);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrentHP of class  Character */
#ifndef TOLUA_DISABLE_tolua_AllLua_Character_getCurrentHP00
static int tolua_AllLua_Character_getCurrentHP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrentHP'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getCurrentHP();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentHP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  Player */
#ifndef TOLUA_DISABLE_tolua_AllLua_Player_getInstance00
static int tolua_AllLua_Player_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Player",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Player& tolua_ret = (Player&)  Player::getInstance();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Player");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getParty of class  Player */
#ifndef TOLUA_DISABLE_tolua_AllLua_Player_getParty00
static int tolua_AllLua_Player_getParty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Player",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Player* self = (Player*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getParty'", NULL);
#endif
  {
   Party* tolua_ret = (Party*)  self->getParty();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Party");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getParty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCharacter of class  Player */
#ifndef TOLUA_DISABLE_tolua_AllLua_Player_getCharacter00
static int tolua_AllLua_Player_getCharacter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Player",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Player* self = (Player*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCharacter'", NULL);
#endif
  {
   Character* tolua_ret = (Character*)  self->getCharacter(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Character");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCharacter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInventory of class  Player */
#ifndef TOLUA_DISABLE_tolua_AllLua_Player_getInventory00
static int tolua_AllLua_Player_getInventory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Player",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Player* self = (Player*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInventory'", NULL);
#endif
  {
   Inventory* tolua_ret = (Inventory*)  self->getInventory();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Inventory");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInventory'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: replaceMemberAtSlot of class  Party */
#ifndef TOLUA_DISABLE_tolua_AllLua_Party_replaceMemberAtSlot00
static int tolua_AllLua_Party_replaceMemberAtSlot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Party",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Character",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Party* self = (Party*)  tolua_tousertype(tolua_S,1,0);
  Character* character = ((Character*)  tolua_tousertype(tolua_S,2,0));
  int slot = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'replaceMemberAtSlot'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->replaceMemberAtSlot(character,slot);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'replaceMemberAtSlot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCharacterAtSlot of class  Party */
#ifndef TOLUA_DISABLE_tolua_AllLua_Party_getCharacterAtSlot00
static int tolua_AllLua_Party_getCharacterAtSlot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Party",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Party* self = (Party*)  tolua_tousertype(tolua_S,1,0);
  int slot = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCharacterAtSlot'", NULL);
#endif
  {
   Character* tolua_ret = (Character*)  self->getCharacterAtSlot(slot);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Character");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCharacterAtSlot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addItem of class  Inventory */
#ifndef TOLUA_DISABLE_tolua_AllLua_Inventory_addItem00
static int tolua_AllLua_Inventory_addItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Inventory",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Inventory* self = (Inventory*)  tolua_tousertype(tolua_S,1,0);
  ItemEnum item = ((ItemEnum) (int)  tolua_tonumber(tolua_S,2,0));
  int amount = ((int)  tolua_tonumber(tolua_S,3,1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addItem'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->addItem(item,amount);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeItem of class  Inventory */
#ifndef TOLUA_DISABLE_tolua_AllLua_Inventory_removeItem00
static int tolua_AllLua_Inventory_removeItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Inventory",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Inventory* self = (Inventory*)  tolua_tousertype(tolua_S,1,0);
  ItemEnum item = ((ItemEnum) (int)  tolua_tonumber(tolua_S,2,0));
  int amount = ((int)  tolua_tonumber(tolua_S,3,1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeItem'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->removeItem(item,amount);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getItemByIndex of class  Inventory */
#ifndef TOLUA_DISABLE_tolua_AllLua_Inventory_getItemByIndex00
static int tolua_AllLua_Inventory_getItemByIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Inventory",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Inventory* self = (Inventory*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getItemByIndex'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getItemByIndex(index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getItemByIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInventorySize of class  Inventory */
#ifndef TOLUA_DISABLE_tolua_AllLua_Inventory_getInventorySize00
static int tolua_AllLua_Inventory_getInventorySize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Inventory",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Inventory* self = (Inventory*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInventorySize'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getInventorySize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInventorySize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_AllLua_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_constant(tolua_S,"UP",UP);
  tolua_constant(tolua_S,"DOWN",DOWN);
  tolua_constant(tolua_S,"LEFT",LEFT);
  tolua_constant(tolua_S,"RIGHT",RIGHT);
  tolua_cclass(tolua_S,"ItemManager","ItemManager","",NULL);
  tolua_beginmodule(tolua_S,"ItemManager");
   tolua_function(tolua_S,"getInstance",tolua_AllLua_ItemManager_getInstance00);
   tolua_function(tolua_S,"getItemValues",tolua_AllLua_ItemManager_getItemValues00);
   tolua_function(tolua_S,"getItemStat",tolua_AllLua_ItemManager_getItemStat00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Common","Common","",NULL);
  tolua_beginmodule(tolua_S,"Common");
   tolua_function(tolua_S,"getGameWidth",tolua_AllLua_Common_getGameWidth00);
   tolua_function(tolua_S,"getGameHeight",tolua_AllLua_Common_getGameHeight00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"WorldManager","WorldManager","",NULL);
  tolua_beginmodule(tolua_S,"WorldManager");
   tolua_function(tolua_S,"getInstance",tolua_AllLua_WorldManager_getInstance00);
   tolua_function(tolua_S,"addEvent",tolua_AllLua_WorldManager_addEvent00);
   tolua_function(tolua_S,"gotoOverworld",tolua_AllLua_WorldManager_gotoOverworld00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"WorldEventDialog","WorldEventDialog","EventBase",tolua_collect_WorldEventDialog);
  #else
  tolua_cclass(tolua_S,"WorldEventDialog","WorldEventDialog","EventBase",NULL);
  #endif
  tolua_beginmodule(tolua_S,"WorldEventDialog");
   tolua_function(tolua_S,"new",tolua_AllLua_WorldEventDialog_new00);
   tolua_function(tolua_S,"new_local",tolua_AllLua_WorldEventDialog_new00_local);
   tolua_function(tolua_S,".call",tolua_AllLua_WorldEventDialog_new00_local);
   tolua_function(tolua_S,"addPage",tolua_AllLua_WorldEventDialog_addPage00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"OwManager","OwManager","",NULL);
  tolua_beginmodule(tolua_S,"OwManager");
   tolua_function(tolua_S,"getInstance",tolua_AllLua_OwManager_getInstance00);
   tolua_function(tolua_S,"addEvent",tolua_AllLua_OwManager_addEvent00);
   tolua_function(tolua_S,"getAICharacterByName",tolua_AllLua_OwManager_getAICharacterByName00);
   tolua_function(tolua_S,"gotoWorld",tolua_AllLua_OwManager_gotoWorld00);
   tolua_function(tolua_S,"gotoOverworld",tolua_AllLua_OwManager_gotoOverworld00);
   tolua_function(tolua_S,"addChildToUILayer",tolua_AllLua_OwManager_addChildToUILayer00);
   tolua_function(tolua_S,"removeChildFromUILayer",tolua_AllLua_OwManager_removeChildFromUILayer00);
   tolua_function(tolua_S,"pause",tolua_AllLua_OwManager_pause00);
   tolua_function(tolua_S,"unpause",tolua_AllLua_OwManager_unpause00);
   tolua_function(tolua_S,"resetMenuLUA",tolua_AllLua_OwManager_resetMenuLUA00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"OwCharacter","OwCharacter","OwEntityBase",NULL);
  tolua_beginmodule(tolua_S,"OwCharacter");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"OwAICharacter","OwAICharacter","OwCharacter",NULL);
  tolua_beginmodule(tolua_S,"OwAICharacter");
   tolua_function(tolua_S,"addCommand",tolua_AllLua_OwAICharacter_addCommand00);
   tolua_function(tolua_S,"clearCommands",tolua_AllLua_OwAICharacter_clearCommands00);
   tolua_function(tolua_S,"setLoop",tolua_AllLua_OwAICharacter_setLoop00);
   tolua_function(tolua_S,"pauseCommands",tolua_AllLua_OwAICharacter_pauseCommands00);
   tolua_function(tolua_S,"playCommands",tolua_AllLua_OwAICharacter_playCommands00);
   tolua_function(tolua_S,"resetCommands",tolua_AllLua_OwAICharacter_resetCommands00);
   tolua_function(tolua_S,"lockCommands",tolua_AllLua_OwAICharacter_lockCommands00);
   tolua_function(tolua_S,"unlockCommands",tolua_AllLua_OwAICharacter_unlockCommands00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"OwAIMove","OwAIMove","OwAICommand",tolua_collect_OwAIMove);
  #else
  tolua_cclass(tolua_S,"OwAIMove","OwAIMove","OwAICommand",NULL);
  #endif
  tolua_beginmodule(tolua_S,"OwAIMove");
   tolua_function(tolua_S,"new",tolua_AllLua_OwAIMove_new00);
   tolua_function(tolua_S,"new_local",tolua_AllLua_OwAIMove_new00_local);
   tolua_function(tolua_S,".call",tolua_AllLua_OwAIMove_new00_local);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"OwEventDialog","OwEventDialog","EventBase",tolua_collect_OwEventDialog);
  #else
  tolua_cclass(tolua_S,"OwEventDialog","OwEventDialog","EventBase",NULL);
  #endif
  tolua_beginmodule(tolua_S,"OwEventDialog");
   tolua_function(tolua_S,"new",tolua_AllLua_OwEventDialog_new00);
   tolua_function(tolua_S,"new_local",tolua_AllLua_OwEventDialog_new00_local);
   tolua_function(tolua_S,".call",tolua_AllLua_OwEventDialog_new00_local);
   tolua_function(tolua_S,"addPage",tolua_AllLua_OwEventDialog_addPage00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"OwEventDelay","OwEventDelay","EventBase",tolua_collect_OwEventDelay);
  #else
  tolua_cclass(tolua_S,"OwEventDelay","OwEventDelay","EventBase",NULL);
  #endif
  tolua_beginmodule(tolua_S,"OwEventDelay");
   tolua_function(tolua_S,"new",tolua_AllLua_OwEventDelay_new00);
   tolua_function(tolua_S,"new_local",tolua_AllLua_OwEventDelay_new00_local);
   tolua_function(tolua_S,".call",tolua_AllLua_OwEventDelay_new00_local);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Character","Character","",NULL);
  tolua_beginmodule(tolua_S,"Character");
   tolua_function(tolua_S,"setLevel",tolua_AllLua_Character_setLevel00);
   tolua_function(tolua_S,"heal",tolua_AllLua_Character_heal00);
   tolua_function(tolua_S,"damage",tolua_AllLua_Character_damage00);
   tolua_function(tolua_S,"equipWeapon",tolua_AllLua_Character_equipWeapon00);
   tolua_function(tolua_S,"equipArmor",tolua_AllLua_Character_equipArmor00);
   tolua_function(tolua_S,"equipRing",tolua_AllLua_Character_equipRing00);
   tolua_function(tolua_S,"getWeapon",tolua_AllLua_Character_getWeapon00);
   tolua_function(tolua_S,"getArmor",tolua_AllLua_Character_getArmor00);
   tolua_function(tolua_S,"getRing",tolua_AllLua_Character_getRing00);
   tolua_function(tolua_S,"getStat",tolua_AllLua_Character_getStat00);
   tolua_function(tolua_S,"getCurrentHP",tolua_AllLua_Character_getCurrentHP00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Player","Player","",NULL);
  tolua_beginmodule(tolua_S,"Player");
   tolua_function(tolua_S,"getInstance",tolua_AllLua_Player_getInstance00);
   tolua_function(tolua_S,"getParty",tolua_AllLua_Player_getParty00);
   tolua_function(tolua_S,"getCharacter",tolua_AllLua_Player_getCharacter00);
   tolua_function(tolua_S,"getInventory",tolua_AllLua_Player_getInventory00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Party","Party","",NULL);
  tolua_beginmodule(tolua_S,"Party");
   tolua_function(tolua_S,"replaceMemberAtSlot",tolua_AllLua_Party_replaceMemberAtSlot00);
   tolua_function(tolua_S,"getCharacterAtSlot",tolua_AllLua_Party_getCharacterAtSlot00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Inventory","Inventory","",NULL);
  tolua_beginmodule(tolua_S,"Inventory");
   tolua_function(tolua_S,"addItem",tolua_AllLua_Inventory_addItem00);
   tolua_function(tolua_S,"removeItem",tolua_AllLua_Inventory_removeItem00);
   tolua_function(tolua_S,"getItemByIndex",tolua_AllLua_Inventory_getItemByIndex00);
   tolua_function(tolua_S,"getInventorySize",tolua_AllLua_Inventory_getInventorySize00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"PLAIN_WATER",PLAIN_WATER);
  tolua_constant(tolua_S,"POTION",POTION);
  tolua_constant(tolua_S,"HI_POTION",HI_POTION);
  tolua_constant(tolua_S,"SWORD",SWORD);
  tolua_constant(tolua_S,"KATANA",KATANA);
  tolua_constant(tolua_S,"SPEAR",SPEAR);
  tolua_constant(tolua_S,"HIDE_ARMOR",HIDE_ARMOR);
  tolua_constant(tolua_S,"CHAINMAIL",CHAINMAIL);
  tolua_constant(tolua_S,"NUM_ITEMS",NUM_ITEMS);
  tolua_constant(tolua_S,"NAME",NAME);
  tolua_constant(tolua_S,"DESCRIPTION",DESCRIPTION);
  tolua_constant(tolua_S,"STACKS",STACKS);
  tolua_constant(tolua_S,"USE",USE);
  tolua_constant(tolua_S,"USE_DESCRIPTION",USE_DESCRIPTION);
  tolua_constant(tolua_S,"EQUIP",EQUIP);
  tolua_constant(tolua_S,"WEAPON_TYPE",WEAPON_TYPE);
  tolua_constant(tolua_S,"ARMOR_TYPE",ARMOR_TYPE);
  tolua_constant(tolua_S,"ITEM_TYPE",ITEM_TYPE);
  tolua_constant(tolua_S,"LEVEL",LEVEL);
  tolua_constant(tolua_S,"HP",HP);
  tolua_constant(tolua_S,"APOW",APOW);
  tolua_constant(tolua_S,"MPOW",MPOW);
  tolua_constant(tolua_S,"ADEF",ADEF);
  tolua_constant(tolua_S,"MDEF",MDEF);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_AllLua (lua_State* tolua_S) {
 return tolua_AllLua_open(tolua_S);
};
#endif

