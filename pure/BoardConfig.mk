include $(SRC_TARGET_DIR)/board/emulator_x86_64/BoardConfig.mk
include device/cfm880/sepolicy/sepolicy.mk
BOARD_USERDATAIMAGE_PARTITION_SIZE := 2147483648
# /home/cfm880/source/aosp/build/make/core/sysprop.mk:281  key word TARGET_SYSTEM_PROP
# TARGET_SYSTEM_PROP += $(LOCAL_DIR)/system.prop
# TARGET_VENDOR_PROP += $(LOCAL_DIR)/vendor.prop
