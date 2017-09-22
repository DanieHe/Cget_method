LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := Test
LOCAL_SRC_FILES := Test.c
APP_STL := gnustl_static
# for native audio
LOCAL_LDLIBS    += 
# for logging
LOCAL_LDLIBS    += -llog
# for native asset manager
#LOCAL_LDLIBS    += -landroid

include $(BUILD_SHARED_LIBRARY)
