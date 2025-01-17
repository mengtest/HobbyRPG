#!/bin/sh

echo 'LOCAL_PATH := $(call my-dir)'
echo "" 
echo 'include $(CLEAR_VARS)'
echo "" 
echo 'LOCAL_MODULE := game_shared'
echo "" 
echo 'LOCAL_MODULE_FILENAME := libgame'
echo "" 

echo "LOCAL_SRC_FILES := hellocpp/main.cpp \\" 

while read data; do
    echo "                   ../$data \\" 
done

echo "" 
echo 'LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes  $(LOCAL_PATH)/../../Dependencies'
echo "" 
echo 'LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static cocos_extension_static cocos_lua_static box2d_static chipmunk_static tinyxml2'
echo "" 
echo 'include $(BUILD_SHARED_LIBRARY)'
echo "" 
echo '$(call import-module,cocos2dx)'
echo '$(call import-module,CocosDenshion/android)'
echo '$(call import-module,scripting/lua/proj.android)'
echo '$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)'
echo '$(call import-module,extensions)'
echo '$(call import-module,external/Box2D)'
echo '$(call import-module,external/chipmunk)'
