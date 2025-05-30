LOCAL_PATH := $(call my-dir)
BOARD_VENDOR_SEPOLICY_DIRS += device/cfm880/public/models/hidl/tvserver/1.0/default/sepolicy/
BOARD_VENDOR_SEPOLICY_DIRS += device/cfm880/public/models/HelloNativeService/sepolicy/
BOARD_VENDOR_SEPOLICY_DIRS += device/cfm880/public/models/HelloApi/sepolicy/
BOARD_VENDOR_SEPOLICY_DIRS += device/cfm880/public/models/hidl/virt/1.0/default/sepolicy/vendor/

TARGET_SYSTEM_PROP += device/cfm880/public/system.prop
TARGET_VENDOR_PROP += device/cfm880/public/vendor.prop

BOARD_USERDATAIMAGE_PARTITION_SIZE := 2147483648

# copy files
PRODUCT_COPY_FILES += device/cfm880/public/init.cfm880.rc:root/init.cfm880.rc

PRODUCT_PACKAGES += \
    cfm880_release_key \
	hello \
	pure_utils \
	api.pure \
	busybox \
	androidasynchttp \
	libpure_utils1 \
	nRFConnect \
	com.pure.api \
	PureSettings \
	remove_unused_module \
	HelloNativeService \
	HelloNativeTest \
	device.cfm880.pure.tvserver@1.0-service \
	TVServerTest \
	epam.virt@1.0-service \
	VirtTest


# 前面的几个例子，我们只有输出到 system 或者　vendor 分区这两种选择，　其实系统还有其它几个目录可以输出的，下面对这些目录的作用及怎么指定模块的输出分区作下说明：

# system :主要包含 Android 框架， google 官方实现
# Android.mk 默认就是输出到 system 分区，不用指定
# Android.bp 默认就是输出到 system 分区，不用指定
# vendor :SoC芯片商分区(系统级核心厂商，如高通), 为他们提供一些核心功能和服务，由 soc 实现
# Android.mk LOCAL_VENDOR_MODULE := true
# Android.bp vendor: true
# odm :设备制造商分区（如华为、小米），为他们的传感器或外围设备提供一些核心功能和服务
# Android.mk LOCAL_ODM_MODULE := true
# Android.bp device_specific: true
# product :产品机型分区
# Android.mk LOCAL_PRODUCT_MODULE := true
# Android.bp product_specific

