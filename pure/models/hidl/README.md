PACKAGE=device.cfm880.pure.tvserver@1.0
LOC=device/cfm880/pure/models/hidl/tvserver/1.0/default
hidl-gen -o $LOC -Lc++-impl -rdevice.cfm880.pure:device/cfm880/pure/models/hidl $PACKAGE
hidl-gen -o $LOC -Landroidbp-impl -rdevice.cfm880.pure:device/cfm880/pure/models/hidl $PACKAGE


hidl_package_root {
    name: "device.cfm880.pure",
// if you want to require <some path>/current.txt for interface versioning
// use_current: true,
    path: "device/cfm880/pure/models/hidl"
}