include $(SRC_TARGET_DIR)/board/generic_x86/BoardConfig.mk
include device/cfm880/sepolicy/sepolicy.mk
BOARD_USERDATAIMAGE_PARTITION_SIZE := 2147483648
# /home/cfm880/source/aosp/build/make/core/sysprop.mk:281  key word TARGET_SYSTEM_PROP
TARGET_SYSTEM_PROP += device/cfm880/privacy/system.prop
TARGET_VENDOR_PROP += device/cfm880/privacy/vendor.prop
