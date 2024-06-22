LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := raylib
LOCAL_SRC_FILES := raylib5/$(TARGET_ARCH_ABI)/libraylib.a
include $(PREBUILT_STATIC_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE    := libnative_app_glue
LOCAL_SRC_FILES := raylib5/$(TARGET_ARCH_ABI)/libnative_app_glue.a
include $(PREBUILT_STATIC_LIBRARY)

###

include $(CLEAR_VARS)
LOCAL_MODULE    := game
LOCAL_LDFLAGS   += -u ANativeActivity_onCreate -Wc++11-narrowing
LOCAL_LDLIBS    := -llog -landroid -lEGL -lGLESv2 -ldl -lOpenSLES -latomic -lm -lc
LOCAL_STATIC_LIBRARIES := raylib libnative_app_glue
LOCAL_SRC_FILES := main.cpp

include $(BUILD_SHARED_LIBRARY)
