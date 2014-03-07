/*
** Lua binding: ItemStatEnumToLua
** Generated automatically by tolua++-1.0.92 on 03/08/14 01:41:43.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_ItemStatEnumToLua_open (lua_State* tolua_S);

#include "..\Enum\ItemStatEnum.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
}

/* Open function */
TOLUA_API int tolua_ItemStatEnumToLua_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_constant(tolua_S,"NAME",NAME);
  tolua_constant(tolua_S,"DESCRIPTION",DESCRIPTION);
  tolua_constant(tolua_S,"STACKS",STACKS);
  tolua_constant(tolua_S,"USE",USE);
  tolua_constant(tolua_S,"USE_DESCRIPTION",USE_DESCRIPTION);
  tolua_constant(tolua_S,"EQUIP",EQUIP);
  tolua_constant(tolua_S,"WEAPON_TYPE",WEAPON_TYPE);
  tolua_constant(tolua_S,"ARMOR_TYPE",ARMOR_TYPE);
  tolua_constant(tolua_S,"ITEM_TYPE",ITEM_TYPE);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_ItemStatEnumToLua (lua_State* tolua_S) {
 return tolua_ItemStatEnumToLua_open(tolua_S);
};
#endif

