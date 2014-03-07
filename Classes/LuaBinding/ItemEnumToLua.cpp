/*
** Lua binding: ItemEnumToLua
** Generated automatically by tolua++-1.0.92 on 03/08/14 01:41:43.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_ItemEnumToLua_open (lua_State* tolua_S);

#include "..\Enum\ItemEnum.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
}

/* Open function */
TOLUA_API int tolua_ItemEnumToLua_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_constant(tolua_S,"PLAIN_WATER",PLAIN_WATER);
  tolua_constant(tolua_S,"POTION",POTION);
  tolua_constant(tolua_S,"SWORD",SWORD);
  tolua_constant(tolua_S,"CHAINMAIL",CHAINMAIL);
  tolua_constant(tolua_S,"NUM_ITEMS",NUM_ITEMS);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_ItemEnumToLua (lua_State* tolua_S) {
 return tolua_ItemEnumToLua_open(tolua_S);
};
#endif

