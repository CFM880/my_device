include $(CLEAR_VARS)
LOCAL_MODULE := remove_unused_module
LOCAL_MODULE_TAGS := optional

LOCAL_MODULE_CLASS := FAKE
LOCAL_MODULE_SUFFIX := $(COMMON_ANDROID_PACKAGE_SUFFIX)

LOCAL_OVERRIDES_PACKAGES += \
	Contacts \
	Email

include $(BUILD_SYSTEM)/base_rules.mk
$(LOCAL_BUILT_MODULE):
	$(hide) echo "Fake: $@"
	$(hide) mkdir -p $(dir $@)
	$(hide) touch $@

PACKAGES.$(LOCAL_MODULE).OVERRIDES := $(strip $(LOCAL_OVERRIDES_PACKAGES))
