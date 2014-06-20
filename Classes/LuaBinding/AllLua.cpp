/*
** Lua binding: AllLua
** Generated automatically by tolua++-1.0.92 on 06/20/14 23:56:55.
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
#include "..\Battle\BattleManager\BattleManager.h"
#include "..\Battle\BattleEntities\BattleCharacter.h"
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
#include "..\Enum\CharacterInfoEnum.h"
#include "..\Enum\EnemyStatsEnum.h"
#include "..\Enum\EnemyEnum.h"

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

static int tolua_collect_EnemyEnum (lua_State* tolua_S)
{
 EnemyEnum* self = (EnemyEnum*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_ItemEnum (lua_State* tolua_S)
{
 ItemEnum* self = (ItemEnum*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CCPoint");
 tolua_usertype(tolua_S,"ItemManager");
 tolua_usertype(tolua_S,"OwManager");
 tolua_usertype(tolua_S,"ItemEnum");
 tolua_usertype(tolua_S,"EnemyEnum");
 tolua_usertype(tolua_S,"Character");
 tolua_usertype(tolua_S,"StatsEnum");
 tolua_usertype(tolua_S,"OwCharacter");
 tolua_usertype(tolua_S,"OwAICommand");
 tolua_usertype(tolua_S,"CCNode");
 tolua_usertype(tolua_S,"BattleManager");
 tolua_usertype(tolua_S,"ItemStatEnum");
 tolua_usertype(tolua_S,"CharacterInfoEnum");
 tolua_usertype(tolua_S,"OwEntityBase");
 tolua_usertype(tolua_S,"WorldEventDialog");
 tolua_usertype(tolua_S,"Common");
 tolua_usertype(tolua_S,"Inventory");
 tolua_usertype(tolua_S,"Party");
 tolua_usertype(tolua_S,"BattleCharacter");
 tolua_usertype(tolua_S,"EventBase");
 tolua_usertype(tolua_S,"Player");
 tolua_usertype(tolua_S,"OwAIMove");
 tolua_usertype(tolua_S,"WorldManager");
 tolua_usertype(tolua_S,"OwEventDialog");
 tolua_usertype(tolua_S,"OwEventDelay");
 tolua_usertype(tolua_S,"OwAICharacter");
 tolua_usertype(tolua_S,"std::vector<std::string>");
 tolua_usertype(tolua_S,"EnemyStatsEnum");
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
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ItemEnum",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ItemManager* self = (ItemManager*)  tolua_tousertype(tolua_S,1,0);
  const ItemEnum type = *((const ItemEnum*)  tolua_tousertype(tolua_S,2,0));
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
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ItemEnum",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const ItemStatEnum",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ItemManager* self = (ItemManager*)  tolua_tousertype(tolua_S,1,0);
  const ItemEnum type = *((const ItemEnum*)  tolua_tousertype(tolua_S,2,0));
  const ItemStatEnum stat = *((const ItemStatEnum*)  tolua_tousertype(tolua_S,3,0));
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

/* method: getInstance of class  BattleManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_BattleManager_getInstance00
static int tolua_AllLua_BattleManager_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"BattleManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   BattleManager* tolua_ret = (BattleManager*)  BattleManager::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"BattleManager");
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

/* method: addChildToGameLayer of class  BattleManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_BattleManager_addChildToGameLayer00
static int tolua_AllLua_BattleManager_addChildToGameLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BattleManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BattleManager* self = (BattleManager*)  tolua_tousertype(tolua_S,1,0);
  CCNode* obj = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addChildToGameLayer'", NULL);
#endif
  {
   self->addChildToGameLayer(obj);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addChildToGameLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addChildToUILayer of class  BattleManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_BattleManager_addChildToUILayer00
static int tolua_AllLua_BattleManager_addChildToUILayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BattleManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BattleManager* self = (BattleManager*)  tolua_tousertype(tolua_S,1,0);
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

/* method: removeChildFromGameLayer of class  BattleManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_BattleManager_removeChildFromGameLayer00
static int tolua_AllLua_BattleManager_removeChildFromGameLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BattleManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BattleManager* self = (BattleManager*)  tolua_tousertype(tolua_S,1,0);
  CCNode* obj = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeChildFromGameLayer'", NULL);
#endif
  {
   self->removeChildFromGameLayer(obj);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeChildFromGameLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeChildFromUILayer of class  BattleManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_BattleManager_removeChildFromUILayer00
static int tolua_AllLua_BattleManager_removeChildFromUILayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BattleManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BattleManager* self = (BattleManager*)  tolua_tousertype(tolua_S,1,0);
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

/* method: addBattleCharacter of class  BattleManager */
#ifndef TOLUA_DISABLE_tolua_AllLua_BattleManager_addBattleCharacter00
static int tolua_AllLua_BattleManager_addBattleCharacter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BattleManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCPoint",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"Character",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BattleManager* self = (BattleManager*)  tolua_tousertype(tolua_S,1,0);
  CCPoint position = *((CCPoint*)  tolua_tousertype(tolua_S,2,0));
  Character* character = ((Character*)  tolua_tousertype(tolua_S,3,0));
  DirectionEnum direction = ((DirectionEnum) (int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addBattleCharacter'", NULL);
#endif
  {
   BattleCharacter* tolua_ret = (BattleCharacter*)  self->addBattleCharacter(position,character,direction);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"BattleCharacter");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addBattleCharacter'.",&tolua_err);
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
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ItemEnum",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  const ItemEnum item = *((const ItemEnum*)  tolua_tousertype(tolua_S,2,0));
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
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ItemEnum",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  const ItemEnum item = *((const ItemEnum*)  tolua_tousertype(tolua_S,2,0));
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
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ItemEnum",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  const ItemEnum item = *((const ItemEnum*)  tolua_tousertype(tolua_S,2,0));
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
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((ItemEnum)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"ItemEnum");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(ItemEnum));
     tolua_pushusertype(tolua_S,tolua_obj,"ItemEnum");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
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
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((ItemEnum)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"ItemEnum");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(ItemEnum));
     tolua_pushusertype(tolua_S,tolua_obj,"ItemEnum");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
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
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((ItemEnum)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"ItemEnum");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(ItemEnum));
     tolua_pushusertype(tolua_S,tolua_obj,"ItemEnum");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
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
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const StatsEnum",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  const StatsEnum type = *((const StatsEnum*)  tolua_tousertype(tolua_S,2,0));
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

/* method: getInfo of class  Character */
#ifndef TOLUA_DISABLE_tolua_AllLua_Character_getInfo00
static int tolua_AllLua_Character_getInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CharacterInfoEnum",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  const CharacterInfoEnum type = *((const CharacterInfoEnum*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInfo'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->getInfo(type);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInfo'.",&tolua_err);
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
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ItemEnum",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Inventory* self = (Inventory*)  tolua_tousertype(tolua_S,1,0);
  const ItemEnum item = *((const ItemEnum*)  tolua_tousertype(tolua_S,2,0));
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
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ItemEnum",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Inventory* self = (Inventory*)  tolua_tousertype(tolua_S,1,0);
  const ItemEnum item = *((const ItemEnum*)  tolua_tousertype(tolua_S,2,0));
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

/* get function: EMPTY of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_EMPTY
static int tolua_get_ItemEnum_EMPTY(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::EMPTY,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: PLAIN_WATER of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_PLAIN_WATER
static int tolua_get_ItemEnum_PLAIN_WATER(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::PLAIN_WATER,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CHILI of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_CHILI
static int tolua_get_ItemEnum_CHILI(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::CHILI,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DASHI of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_DASHI
static int tolua_get_ItemEnum_DASHI(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::DASHI,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ITEM_1 of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_ITEM_1
static int tolua_get_ItemEnum_ITEM_1(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::ITEM_1,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ITEM_2 of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_ITEM_2
static int tolua_get_ItemEnum_ITEM_2(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::ITEM_2,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ITEM_3 of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_ITEM_3
static int tolua_get_ItemEnum_ITEM_3(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::ITEM_3,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ITEM_4 of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_ITEM_4
static int tolua_get_ItemEnum_ITEM_4(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::ITEM_4,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ITEM_5 of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_ITEM_5
static int tolua_get_ItemEnum_ITEM_5(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::ITEM_5,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ITEM_6 of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_ITEM_6
static int tolua_get_ItemEnum_ITEM_6(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::ITEM_6,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SWORD of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_SWORD
static int tolua_get_ItemEnum_SWORD(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::SWORD,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KATANA of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_KATANA
static int tolua_get_ItemEnum_KATANA(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::KATANA,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SPEAR of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_SPEAR
static int tolua_get_ItemEnum_SPEAR(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::SPEAR,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WEAPON1 of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_WEAPON1
static int tolua_get_ItemEnum_WEAPON1(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::WEAPON1,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WEAPON2 of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_WEAPON2
static int tolua_get_ItemEnum_WEAPON2(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::WEAPON2,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WEAPON3 of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_WEAPON3
static int tolua_get_ItemEnum_WEAPON3(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::WEAPON3,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WEAPON4 of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_WEAPON4
static int tolua_get_ItemEnum_WEAPON4(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::WEAPON4,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WEAPON5 of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_WEAPON5
static int tolua_get_ItemEnum_WEAPON5(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::WEAPON5,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WEAPON6 of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_WEAPON6
static int tolua_get_ItemEnum_WEAPON6(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::WEAPON6,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WEAPON7 of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_WEAPON7
static int tolua_get_ItemEnum_WEAPON7(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::WEAPON7,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WEAPON8 of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_WEAPON8
static int tolua_get_ItemEnum_WEAPON8(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::WEAPON8,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WEAPON9 of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_WEAPON9
static int tolua_get_ItemEnum_WEAPON9(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::WEAPON9,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: T_SHIRT of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_T_SHIRT
static int tolua_get_ItemEnum_T_SHIRT(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::T_SHIRT,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: HIDE_ARMOR of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_HIDE_ARMOR
static int tolua_get_ItemEnum_HIDE_ARMOR(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::HIDE_ARMOR,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CHAINMAIL of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_CHAINMAIL
static int tolua_get_ItemEnum_CHAINMAIL(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::CHAINMAIL,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: NUM_ITEMS of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemEnum_NUM_ITEMS
static int tolua_get_ItemEnum_NUM_ITEMS(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemEnum::NUM_ITEMS,"const ItemEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getValue of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_AllLua_ItemEnum_getValue00
static int tolua_AllLua_ItemEnum_getValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ItemEnum",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ItemEnum* self = (const ItemEnum*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getValue'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getItemByIndex of class  ItemEnum */
#ifndef TOLUA_DISABLE_tolua_AllLua_ItemEnum_getItemByIndex00
static int tolua_AllLua_ItemEnum_getItemByIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ItemEnum",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   ItemEnum tolua_ret = (ItemEnum)  ItemEnum::getItemByIndex(index);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((ItemEnum)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"ItemEnum");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(ItemEnum));
     tolua_pushusertype(tolua_S,tolua_obj,"ItemEnum");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
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

/* get function: NAME of class  ItemStatEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemStatEnum_NAME
static int tolua_get_ItemStatEnum_NAME(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemStatEnum::NAME,"const ItemStatEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DESCRIPTION of class  ItemStatEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemStatEnum_DESCRIPTION
static int tolua_get_ItemStatEnum_DESCRIPTION(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemStatEnum::DESCRIPTION,"const ItemStatEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: STACKS of class  ItemStatEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemStatEnum_STACKS
static int tolua_get_ItemStatEnum_STACKS(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemStatEnum::STACKS,"const ItemStatEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: USE of class  ItemStatEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemStatEnum_USE
static int tolua_get_ItemStatEnum_USE(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemStatEnum::USE,"const ItemStatEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: USE_DESCRIPTION of class  ItemStatEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemStatEnum_USE_DESCRIPTION
static int tolua_get_ItemStatEnum_USE_DESCRIPTION(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemStatEnum::USE_DESCRIPTION,"const ItemStatEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: EQUIP of class  ItemStatEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemStatEnum_EQUIP
static int tolua_get_ItemStatEnum_EQUIP(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemStatEnum::EQUIP,"const ItemStatEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WEAPON_TYPE of class  ItemStatEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemStatEnum_WEAPON_TYPE
static int tolua_get_ItemStatEnum_WEAPON_TYPE(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemStatEnum::WEAPON_TYPE,"const ItemStatEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ARMOR_TYPE of class  ItemStatEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemStatEnum_ARMOR_TYPE
static int tolua_get_ItemStatEnum_ARMOR_TYPE(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemStatEnum::ARMOR_TYPE,"const ItemStatEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ITEM_TYPE of class  ItemStatEnum */
#ifndef TOLUA_DISABLE_tolua_get_ItemStatEnum_ITEM_TYPE
static int tolua_get_ItemStatEnum_ITEM_TYPE(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ItemStatEnum::ITEM_TYPE,"const ItemStatEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getValue of class  ItemStatEnum */
#ifndef TOLUA_DISABLE_tolua_AllLua_ItemStatEnum_getValue00
static int tolua_AllLua_ItemStatEnum_getValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ItemStatEnum",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ItemStatEnum* self = (const ItemStatEnum*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getValue'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: LEVEL of class  StatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_StatsEnum_LEVEL
static int tolua_get_StatsEnum_LEVEL(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&StatsEnum::LEVEL,"const StatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: HP of class  StatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_StatsEnum_HP
static int tolua_get_StatsEnum_HP(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&StatsEnum::HP,"const StatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: APOW of class  StatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_StatsEnum_APOW
static int tolua_get_StatsEnum_APOW(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&StatsEnum::APOW,"const StatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MPOW of class  StatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_StatsEnum_MPOW
static int tolua_get_StatsEnum_MPOW(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&StatsEnum::MPOW,"const StatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ADEF of class  StatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_StatsEnum_ADEF
static int tolua_get_StatsEnum_ADEF(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&StatsEnum::ADEF,"const StatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MDEF of class  StatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_StatsEnum_MDEF
static int tolua_get_StatsEnum_MDEF(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&StatsEnum::MDEF,"const StatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SPEED of class  StatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_StatsEnum_SPEED
static int tolua_get_StatsEnum_SPEED(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&StatsEnum::SPEED,"const StatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getValue of class  StatsEnum */
#ifndef TOLUA_DISABLE_tolua_AllLua_StatsEnum_getValue00
static int tolua_AllLua_StatsEnum_getValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StatsEnum",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StatsEnum* self = (StatsEnum*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getValue'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ALIAS of class  CharacterInfoEnum */
#ifndef TOLUA_DISABLE_tolua_get_CharacterInfoEnum_ALIAS
static int tolua_get_CharacterInfoEnum_ALIAS(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&CharacterInfoEnum::ALIAS,"const CharacterInfoEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SPRITE_BASE of class  CharacterInfoEnum */
#ifndef TOLUA_DISABLE_tolua_get_CharacterInfoEnum_SPRITE_BASE
static int tolua_get_CharacterInfoEnum_SPRITE_BASE(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&CharacterInfoEnum::SPRITE_BASE,"const CharacterInfoEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SPRITE_INITIAL of class  CharacterInfoEnum */
#ifndef TOLUA_DISABLE_tolua_get_CharacterInfoEnum_SPRITE_INITIAL
static int tolua_get_CharacterInfoEnum_SPRITE_INITIAL(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&CharacterInfoEnum::SPRITE_INITIAL,"const CharacterInfoEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CLASS of class  CharacterInfoEnum */
#ifndef TOLUA_DISABLE_tolua_get_CharacterInfoEnum_CLASS
static int tolua_get_CharacterInfoEnum_CLASS(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&CharacterInfoEnum::CLASS,"const CharacterInfoEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ARMOR of class  CharacterInfoEnum */
#ifndef TOLUA_DISABLE_tolua_get_CharacterInfoEnum_ARMOR
static int tolua_get_CharacterInfoEnum_ARMOR(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&CharacterInfoEnum::ARMOR,"const CharacterInfoEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WEAPON of class  CharacterInfoEnum */
#ifndef TOLUA_DISABLE_tolua_get_CharacterInfoEnum_WEAPON
static int tolua_get_CharacterInfoEnum_WEAPON(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&CharacterInfoEnum::WEAPON,"const CharacterInfoEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: AGE of class  CharacterInfoEnum */
#ifndef TOLUA_DISABLE_tolua_get_CharacterInfoEnum_AGE
static int tolua_get_CharacterInfoEnum_AGE(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&CharacterInfoEnum::AGE,"const CharacterInfoEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getValue of class  CharacterInfoEnum */
#ifndef TOLUA_DISABLE_tolua_AllLua_CharacterInfoEnum_getValue00
static int tolua_AllLua_CharacterInfoEnum_getValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CharacterInfoEnum",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CharacterInfoEnum* self = (CharacterInfoEnum*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getValue'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: NAME of class  EnemyStatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_EnemyStatsEnum_NAME
static int tolua_get_EnemyStatsEnum_NAME(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EnemyStatsEnum::NAME,"const EnemyStatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: LEVEL of class  EnemyStatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_EnemyStatsEnum_LEVEL
static int tolua_get_EnemyStatsEnum_LEVEL(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EnemyStatsEnum::LEVEL,"const EnemyStatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: HP of class  EnemyStatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_EnemyStatsEnum_HP
static int tolua_get_EnemyStatsEnum_HP(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EnemyStatsEnum::HP,"const EnemyStatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: APOW of class  EnemyStatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_EnemyStatsEnum_APOW
static int tolua_get_EnemyStatsEnum_APOW(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EnemyStatsEnum::APOW,"const EnemyStatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MPOW of class  EnemyStatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_EnemyStatsEnum_MPOW
static int tolua_get_EnemyStatsEnum_MPOW(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EnemyStatsEnum::MPOW,"const EnemyStatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ADEF of class  EnemyStatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_EnemyStatsEnum_ADEF
static int tolua_get_EnemyStatsEnum_ADEF(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EnemyStatsEnum::ADEF,"const EnemyStatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MDEF of class  EnemyStatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_EnemyStatsEnum_MDEF
static int tolua_get_EnemyStatsEnum_MDEF(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EnemyStatsEnum::MDEF,"const EnemyStatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DROP_1 of class  EnemyStatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_EnemyStatsEnum_DROP_1
static int tolua_get_EnemyStatsEnum_DROP_1(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EnemyStatsEnum::DROP_1,"const EnemyStatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DROP_2 of class  EnemyStatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_EnemyStatsEnum_DROP_2
static int tolua_get_EnemyStatsEnum_DROP_2(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EnemyStatsEnum::DROP_2,"const EnemyStatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DROP_3 of class  EnemyStatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_EnemyStatsEnum_DROP_3
static int tolua_get_EnemyStatsEnum_DROP_3(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EnemyStatsEnum::DROP_3,"const EnemyStatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DROP_RATE_1 of class  EnemyStatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_EnemyStatsEnum_DROP_RATE_1
static int tolua_get_EnemyStatsEnum_DROP_RATE_1(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EnemyStatsEnum::DROP_RATE_1,"const EnemyStatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DROP_RATE_2 of class  EnemyStatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_EnemyStatsEnum_DROP_RATE_2
static int tolua_get_EnemyStatsEnum_DROP_RATE_2(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EnemyStatsEnum::DROP_RATE_2,"const EnemyStatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DROP_RATE_3 of class  EnemyStatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_EnemyStatsEnum_DROP_RATE_3
static int tolua_get_EnemyStatsEnum_DROP_RATE_3(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EnemyStatsEnum::DROP_RATE_3,"const EnemyStatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: GOLD_DROP of class  EnemyStatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_EnemyStatsEnum_GOLD_DROP
static int tolua_get_EnemyStatsEnum_GOLD_DROP(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EnemyStatsEnum::GOLD_DROP,"const EnemyStatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SPRITE of class  EnemyStatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_EnemyStatsEnum_SPRITE
static int tolua_get_EnemyStatsEnum_SPRITE(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EnemyStatsEnum::SPRITE,"const EnemyStatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SKILL_1 of class  EnemyStatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_EnemyStatsEnum_SKILL_1
static int tolua_get_EnemyStatsEnum_SKILL_1(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EnemyStatsEnum::SKILL_1,"const EnemyStatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SKILL_2 of class  EnemyStatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_EnemyStatsEnum_SKILL_2
static int tolua_get_EnemyStatsEnum_SKILL_2(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EnemyStatsEnum::SKILL_2,"const EnemyStatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SKILL_3 of class  EnemyStatsEnum */
#ifndef TOLUA_DISABLE_tolua_get_EnemyStatsEnum_SKILL_3
static int tolua_get_EnemyStatsEnum_SKILL_3(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EnemyStatsEnum::SKILL_3,"const EnemyStatsEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getValue of class  EnemyStatsEnum */
#ifndef TOLUA_DISABLE_tolua_AllLua_EnemyStatsEnum_getValue00
static int tolua_AllLua_EnemyStatsEnum_getValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EnemyStatsEnum",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EnemyStatsEnum* self = (EnemyStatsEnum*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getValue'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: PORK of class  EnemyEnum */
#ifndef TOLUA_DISABLE_tolua_get_EnemyEnum_PORK
static int tolua_get_EnemyEnum_PORK(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EnemyEnum::PORK,"const EnemyEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: NUM_ENEMIES of class  EnemyEnum */
#ifndef TOLUA_DISABLE_tolua_get_EnemyEnum_NUM_ENEMIES
static int tolua_get_EnemyEnum_NUM_ENEMIES(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EnemyEnum::NUM_ENEMIES,"const EnemyEnum");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getValue of class  EnemyEnum */
#ifndef TOLUA_DISABLE_tolua_AllLua_EnemyEnum_getValue00
static int tolua_AllLua_EnemyEnum_getValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EnemyEnum",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EnemyEnum* self = (const EnemyEnum*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getValue'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEnemyByIndex of class  EnemyEnum */
#ifndef TOLUA_DISABLE_tolua_AllLua_EnemyEnum_getEnemyByIndex00
static int tolua_AllLua_EnemyEnum_getEnemyByIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EnemyEnum",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   EnemyEnum tolua_ret = (EnemyEnum)  EnemyEnum::getEnemyByIndex(index);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((EnemyEnum)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"EnemyEnum");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(EnemyEnum));
     tolua_pushusertype(tolua_S,tolua_obj,"EnemyEnum");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEnemyByIndex'.",&tolua_err);
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
  tolua_cclass(tolua_S,"BattleManager","BattleManager","",NULL);
  tolua_beginmodule(tolua_S,"BattleManager");
   tolua_function(tolua_S,"getInstance",tolua_AllLua_BattleManager_getInstance00);
   tolua_function(tolua_S,"addChildToGameLayer",tolua_AllLua_BattleManager_addChildToGameLayer00);
   tolua_function(tolua_S,"addChildToUILayer",tolua_AllLua_BattleManager_addChildToUILayer00);
   tolua_function(tolua_S,"removeChildFromGameLayer",tolua_AllLua_BattleManager_removeChildFromGameLayer00);
   tolua_function(tolua_S,"removeChildFromUILayer",tolua_AllLua_BattleManager_removeChildFromUILayer00);
   tolua_function(tolua_S,"addBattleCharacter",tolua_AllLua_BattleManager_addBattleCharacter00);
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
   tolua_function(tolua_S,"getInfo",tolua_AllLua_Character_getInfo00);
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
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"ItemEnum","ItemEnum","",tolua_collect_ItemEnum);
  #else
  tolua_cclass(tolua_S,"ItemEnum","ItemEnum","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"ItemEnum");
   tolua_variable(tolua_S,"EMPTY",tolua_get_ItemEnum_EMPTY,NULL);
   tolua_variable(tolua_S,"PLAIN_WATER",tolua_get_ItemEnum_PLAIN_WATER,NULL);
   tolua_variable(tolua_S,"CHILI",tolua_get_ItemEnum_CHILI,NULL);
   tolua_variable(tolua_S,"DASHI",tolua_get_ItemEnum_DASHI,NULL);
   tolua_variable(tolua_S,"ITEM_1",tolua_get_ItemEnum_ITEM_1,NULL);
   tolua_variable(tolua_S,"ITEM_2",tolua_get_ItemEnum_ITEM_2,NULL);
   tolua_variable(tolua_S,"ITEM_3",tolua_get_ItemEnum_ITEM_3,NULL);
   tolua_variable(tolua_S,"ITEM_4",tolua_get_ItemEnum_ITEM_4,NULL);
   tolua_variable(tolua_S,"ITEM_5",tolua_get_ItemEnum_ITEM_5,NULL);
   tolua_variable(tolua_S,"ITEM_6",tolua_get_ItemEnum_ITEM_6,NULL);
   tolua_variable(tolua_S,"SWORD",tolua_get_ItemEnum_SWORD,NULL);
   tolua_variable(tolua_S,"KATANA",tolua_get_ItemEnum_KATANA,NULL);
   tolua_variable(tolua_S,"SPEAR",tolua_get_ItemEnum_SPEAR,NULL);
   tolua_variable(tolua_S,"WEAPON1",tolua_get_ItemEnum_WEAPON1,NULL);
   tolua_variable(tolua_S,"WEAPON2",tolua_get_ItemEnum_WEAPON2,NULL);
   tolua_variable(tolua_S,"WEAPON3",tolua_get_ItemEnum_WEAPON3,NULL);
   tolua_variable(tolua_S,"WEAPON4",tolua_get_ItemEnum_WEAPON4,NULL);
   tolua_variable(tolua_S,"WEAPON5",tolua_get_ItemEnum_WEAPON5,NULL);
   tolua_variable(tolua_S,"WEAPON6",tolua_get_ItemEnum_WEAPON6,NULL);
   tolua_variable(tolua_S,"WEAPON7",tolua_get_ItemEnum_WEAPON7,NULL);
   tolua_variable(tolua_S,"WEAPON8",tolua_get_ItemEnum_WEAPON8,NULL);
   tolua_variable(tolua_S,"WEAPON9",tolua_get_ItemEnum_WEAPON9,NULL);
   tolua_variable(tolua_S,"T_SHIRT",tolua_get_ItemEnum_T_SHIRT,NULL);
   tolua_variable(tolua_S,"HIDE_ARMOR",tolua_get_ItemEnum_HIDE_ARMOR,NULL);
   tolua_variable(tolua_S,"CHAINMAIL",tolua_get_ItemEnum_CHAINMAIL,NULL);
   tolua_variable(tolua_S,"NUM_ITEMS",tolua_get_ItemEnum_NUM_ITEMS,NULL);
   tolua_function(tolua_S,"getValue",tolua_AllLua_ItemEnum_getValue00);
   tolua_function(tolua_S,"getItemByIndex",tolua_AllLua_ItemEnum_getItemByIndex00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ItemStatEnum","ItemStatEnum","",NULL);
  tolua_beginmodule(tolua_S,"ItemStatEnum");
   tolua_variable(tolua_S,"NAME",tolua_get_ItemStatEnum_NAME,NULL);
   tolua_variable(tolua_S,"DESCRIPTION",tolua_get_ItemStatEnum_DESCRIPTION,NULL);
   tolua_variable(tolua_S,"STACKS",tolua_get_ItemStatEnum_STACKS,NULL);
   tolua_variable(tolua_S,"USE",tolua_get_ItemStatEnum_USE,NULL);
   tolua_variable(tolua_S,"USE_DESCRIPTION",tolua_get_ItemStatEnum_USE_DESCRIPTION,NULL);
   tolua_variable(tolua_S,"EQUIP",tolua_get_ItemStatEnum_EQUIP,NULL);
   tolua_variable(tolua_S,"WEAPON_TYPE",tolua_get_ItemStatEnum_WEAPON_TYPE,NULL);
   tolua_variable(tolua_S,"ARMOR_TYPE",tolua_get_ItemStatEnum_ARMOR_TYPE,NULL);
   tolua_variable(tolua_S,"ITEM_TYPE",tolua_get_ItemStatEnum_ITEM_TYPE,NULL);
   tolua_function(tolua_S,"getValue",tolua_AllLua_ItemStatEnum_getValue00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"StatsEnum","StatsEnum","",NULL);
  tolua_beginmodule(tolua_S,"StatsEnum");
   tolua_variable(tolua_S,"LEVEL",tolua_get_StatsEnum_LEVEL,NULL);
   tolua_variable(tolua_S,"HP",tolua_get_StatsEnum_HP,NULL);
   tolua_variable(tolua_S,"APOW",tolua_get_StatsEnum_APOW,NULL);
   tolua_variable(tolua_S,"MPOW",tolua_get_StatsEnum_MPOW,NULL);
   tolua_variable(tolua_S,"ADEF",tolua_get_StatsEnum_ADEF,NULL);
   tolua_variable(tolua_S,"MDEF",tolua_get_StatsEnum_MDEF,NULL);
   tolua_variable(tolua_S,"SPEED",tolua_get_StatsEnum_SPEED,NULL);
   tolua_function(tolua_S,"getValue",tolua_AllLua_StatsEnum_getValue00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CharacterInfoEnum","CharacterInfoEnum","",NULL);
  tolua_beginmodule(tolua_S,"CharacterInfoEnum");
   tolua_variable(tolua_S,"ALIAS",tolua_get_CharacterInfoEnum_ALIAS,NULL);
   tolua_variable(tolua_S,"SPRITE_BASE",tolua_get_CharacterInfoEnum_SPRITE_BASE,NULL);
   tolua_variable(tolua_S,"SPRITE_INITIAL",tolua_get_CharacterInfoEnum_SPRITE_INITIAL,NULL);
   tolua_variable(tolua_S,"CLASS",tolua_get_CharacterInfoEnum_CLASS,NULL);
   tolua_variable(tolua_S,"ARMOR",tolua_get_CharacterInfoEnum_ARMOR,NULL);
   tolua_variable(tolua_S,"WEAPON",tolua_get_CharacterInfoEnum_WEAPON,NULL);
   tolua_variable(tolua_S,"AGE",tolua_get_CharacterInfoEnum_AGE,NULL);
   tolua_function(tolua_S,"getValue",tolua_AllLua_CharacterInfoEnum_getValue00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"EnemyStatsEnum","EnemyStatsEnum","",NULL);
  tolua_beginmodule(tolua_S,"EnemyStatsEnum");
   tolua_variable(tolua_S,"NAME",tolua_get_EnemyStatsEnum_NAME,NULL);
   tolua_variable(tolua_S,"LEVEL",tolua_get_EnemyStatsEnum_LEVEL,NULL);
   tolua_variable(tolua_S,"HP",tolua_get_EnemyStatsEnum_HP,NULL);
   tolua_variable(tolua_S,"APOW",tolua_get_EnemyStatsEnum_APOW,NULL);
   tolua_variable(tolua_S,"MPOW",tolua_get_EnemyStatsEnum_MPOW,NULL);
   tolua_variable(tolua_S,"ADEF",tolua_get_EnemyStatsEnum_ADEF,NULL);
   tolua_variable(tolua_S,"MDEF",tolua_get_EnemyStatsEnum_MDEF,NULL);
   tolua_variable(tolua_S,"DROP_1",tolua_get_EnemyStatsEnum_DROP_1,NULL);
   tolua_variable(tolua_S,"DROP_2",tolua_get_EnemyStatsEnum_DROP_2,NULL);
   tolua_variable(tolua_S,"DROP_3",tolua_get_EnemyStatsEnum_DROP_3,NULL);
   tolua_variable(tolua_S,"DROP_RATE_1",tolua_get_EnemyStatsEnum_DROP_RATE_1,NULL);
   tolua_variable(tolua_S,"DROP_RATE_2",tolua_get_EnemyStatsEnum_DROP_RATE_2,NULL);
   tolua_variable(tolua_S,"DROP_RATE_3",tolua_get_EnemyStatsEnum_DROP_RATE_3,NULL);
   tolua_variable(tolua_S,"GOLD_DROP",tolua_get_EnemyStatsEnum_GOLD_DROP,NULL);
   tolua_variable(tolua_S,"SPRITE",tolua_get_EnemyStatsEnum_SPRITE,NULL);
   tolua_variable(tolua_S,"SKILL_1",tolua_get_EnemyStatsEnum_SKILL_1,NULL);
   tolua_variable(tolua_S,"SKILL_2",tolua_get_EnemyStatsEnum_SKILL_2,NULL);
   tolua_variable(tolua_S,"SKILL_3",tolua_get_EnemyStatsEnum_SKILL_3,NULL);
   tolua_function(tolua_S,"getValue",tolua_AllLua_EnemyStatsEnum_getValue00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"EnemyEnum","EnemyEnum","",tolua_collect_EnemyEnum);
  #else
  tolua_cclass(tolua_S,"EnemyEnum","EnemyEnum","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"EnemyEnum");
   tolua_variable(tolua_S,"PORK",tolua_get_EnemyEnum_PORK,NULL);
   tolua_variable(tolua_S,"NUM_ENEMIES",tolua_get_EnemyEnum_NUM_ENEMIES,NULL);
   tolua_function(tolua_S,"getValue",tolua_AllLua_EnemyEnum_getValue00);
   tolua_function(tolua_S,"getEnemyByIndex",tolua_AllLua_EnemyEnum_getEnemyByIndex00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_AllLua (lua_State* tolua_S) {
 return tolua_AllLua_open(tolua_S);
};
#endif

