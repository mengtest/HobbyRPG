/*
** Lua binding: StatsEnumToLua
** Generated automatically by tolua++-1.0.92 on 03/09/14 16:09:14.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_StatsEnumToLua_open (lua_State* tolua_S);

#include "..\Enum\StatsEnum.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
}

/* Open function */
TOLUA_API int tolua_StatsEnumToLua_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
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
 TOLUA_API int luaopen_StatsEnumToLua (lua_State* tolua_S) {
 return tolua_StatsEnumToLua_open(tolua_S);
};
#endif

