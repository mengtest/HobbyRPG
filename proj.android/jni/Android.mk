LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared

LOCAL_MODULE_FILENAME := libgame

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AI/iState.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/Character/Character.cpp \
                   ../../Classes/Common/Common.cpp \
                   ../../Classes/Config/Config.cpp \
                   ../../Classes/Config/ConfigReader.cpp \
                   ../../Classes/CustomActionManager/CustomActionManager.cpp \
                   ../../Classes/Inventory/Inventory.cpp \
                   ../../Classes/Item/ItemManager.cpp \
                   ../../Classes/LuaBinding/CharacterInfoEnumToLua.cpp \
                   ../../Classes/LuaBinding/GameToLua.cpp \
                   ../../Classes/LuaBinding/ItemEnumToLua.cpp \
                   ../../Classes/LuaBinding/ItemStatEnumToLua.cpp \
                   ../../Classes/LuaBinding/StatsEnumToLua.cpp \
                   ../../Classes/Overworld/OwAICommands/OwAIMove.cpp \
                   ../../Classes/Overworld/OwControlUI/OwControlUITypeA.cpp \
                   ../../Classes/Overworld/OwControlUI/OwControlUITypeB.cpp \
                   ../../Classes/Overworld/OwControlUI/OwControlUITypeBButton.cpp \
                   ../../Classes/Overworld/OwDialogUI/OwDialogUI.cpp \
                   ../../Classes/Overworld/OwEntities/OwAICharacter.cpp \
                   ../../Classes/Overworld/OwEntities/OwCharacter.cpp \
                   ../../Classes/Overworld/OwEntities/OwEntityBase.cpp \
                   ../../Classes/Overworld/OwEvents/OwEventDelay.cpp \
                   ../../Classes/Overworld/OwEvents/OwEventDialog.cpp \
                   ../../Classes/Overworld/OwManager.cpp \
                   ../../Classes/Overworld/OwManager_Event.cpp \
                   ../../Classes/Overworld/OwManager_Normal.cpp \
                   ../../Classes/Overworld/OwPlayerController/OwPlayerController.cpp \
                   ../../Classes/Overworld/OwTiledMapUserData/OwTiledMapUserData.cpp \
                   ../../Classes/OverworldScene.cpp \
                   ../../Classes/Party/Party.cpp \
                   ../../Classes/Player/Player.cpp \
                   ../../Classes/UI/cBaseUI.cpp \
                   ../../Classes/UI/cInGameUI.cpp \
                   ../../Classes/UI/Control.cpp \
                   ../../Classes/UI/Page.cpp \
                   ../../Classes/UI/PageManager.cpp \

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes  $(LOCAL_PATH)/../../Dependencies

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static cocos_extension_static cocos_lua_static box2d_static chipmunk_static tinyxml2

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx)
$(call import-module,CocosDenshion/android)
$(call import-module,scripting/lua/proj.android)
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,extensions)
$(call import-module,external/Box2D)
$(call import-module,external/chipmunk)
