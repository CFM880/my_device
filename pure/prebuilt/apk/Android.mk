LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := nRFConnect
LOCAL_SRC_FILES := $(LOCAL_MODULE)_4.25.0.apk
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := APPS #模块类型为 apk
LOCAL_CERTIFICATE := platform #使用系统签名
LOCAL_MODULE_SUFFIX := .apk
include $(BUILD_PREBUILT)