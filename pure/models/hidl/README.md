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
cfm880@cfm880:~/aosp/device/cfm880/pure/models/hidl/tvserver/1.0$ device.cfm880.pure.tvserver@1.0
cfm880@cfm880:~/aosp/device/cfm880/pure/models/hidl/tvserver/1.0$ LOC=default
cfm880@cfm880:~/aosp/device/cfm880/pure/models/hidl/tvserver/1.0$ hidl-gen -o $LOC -Lc++-impl -rdevice.cfm880.pure:device/cfm880/pure/models/hidl $PACKAGE
cfm880@cfm880:~/aosp/device/cfm880/pure/models/hidl/tvserver/1.0$ hidl-gen -o $LOC -Lc++-impl -rdevice.cfm880.pure:device/cfm880/pure/models/hidl $PACKAGE
ERROR: device.cfm880.pure.tvserver@1.0::ITVServerListener has hash 92abb0de23e98175b58a1ad17e93976f96e0b95f2f7a21f457f6c29a2835ce26 which does not match hash on record. This interface has been frozen. Do not change it!
ERROR: Could not parse device.cfm880.pure.tvserver@1.0::ITVServer. Aborting.
cfm880@cfm880:~/aosp/device/cfm880/pure/models/hidl/tvserver/1.0$ hidl-gen -o $LOC -Lc++-impl -rdevice.cfm880.pure:device/cfm880/pure/models/hidl $PACKAGE
ERROR: device.cfm880.pure.tvserver@1.0::ITVServer has hash 67e36c17a88e2a40f5b1cd365128185d8c828bad8b6e07b7d38d3238c291b6ea which does not match hash on record. This interface has been frozen. Do not change it!
ERROR: Could not parse device.cfm880.pure.tvserver@1.0::ITVServer. Aborting.
cfm880@cfm880:~/aosp/device/cfm880/pure/models/hidl/tvserver/1.0$ hidl-gen -o $LOC -Lc++-impl -rdevice.cfm880.pure:device/cfm880/pure/models/hidl $PACKAGE
ERROR: device.cfm880.pure.tvserver@1.0::ITVServerListener has hash 92abb0de23e98175b58a1ad17e93976f96e0b95f2f7a21f457f6c29a2835ce26 which does not match hash on record. This interface has been frozen. Do not change it!
ERROR: Could not parse device.cfm880.pure.tvserver@1.0::ITVServer. Aborting.
cfm880@cfm880:~/aosp/device/cfm880/pure/models/hidl/tvserver/1.0$ ^C
cfm880@cfm880:~/aosp/device/cfm880/pure/models/hidl/tvserver/1.0$ ^C
cfm880@cfm880:~/aosp/device/cfm880/pure/models/hidl/tvserver/1.0$ hidl-gen -o $LOC -Lc++-impl -rdevice.cfm880.pure:device/cfm880/pure/models/hidl $PACKAGE
cfm880@cfm880:~/aosp/device/cfm880/pure/models/hidl/tvserver/1.0$ 


pure:/ # TVServerTest                                                                                                                                                                                               
helloHIDL helloHIDL cfm880 from TVServer
onMessage message from server
serviceDied cookie = 0

pure:/ # ps -e | grep tvserver                                                                                                                                                                                      
root          1908     1 10903932  5760 binder_wait_for_work 0 S device.cfm880.pure.tvserver@1.0-service
pure:/ # kill 1908
