https://source.android.com/docs/security/features/selinux/device-policy#label_new_services_and_address_denials

06-01 19:22:38.554     0     0 I init    : Parsing file /vendor/etc/init/device.cfm880.pure.tvserver@1.0-service.rc...
06-01 19:22:42.936     0     0 E init    : Could not start service 'tvserver' as part of class 'hal': File /vendor/bin/hw/device.cfm880.pure.tvserver@1.0-service(labeled "u:object_r:vendor_file:s0") has incorrect label or no domain transition from u:r:init:s0 to another SELinux domain defined. Have you configured your service correctly? https://source.android.com/security/selinux/device-policy#label_new_services_and_address_denials. Note: this error shows up even in permissive mode in order to make auditing denials possible.



cfm880@cfm880:~/aosp$ adb logcat | grep "tvserver"
- waiting for device -
06-01 20:00:38.549     0     0 I init    : Parsing file /vendor/etc/init/device.cfm880.pure.tvserver@1.0-service.rc...
06-01 20:00:43.374     0     0 I init    : starting service 'tvserver'...
06-01 20:00:43.380   373   373 I device.cfm880.pure.tvserver@1.0-service: ===device.cfm880.pure.tvserver@1.0-service ====
06-01 20:00:44.380   373   373 W device.cfm880.p: type=1400 audit(0.0:5): avc: denied { read } for name="vndbinder" dev="binder" ino=6 scontext=u:r:tvserver:s0 tcontext=u:object_r:vndbinder_device:s0 tclass=chr_file permissive=0
06-01 20:00:44.391   373   373 I HidlServiceManagement: Registered device.cfm880.pure.tvserver@1.0::ITVServer/default
06-01 20:00:44.391   373   373 I HidlServiceManagement: Removing namespace from process name device.cfm880.pure.tvserver@1.0-service to tvserver@1.0-service.
06-01 20:00:44.391   373   373 I device.cfm880.pure.tvserver@1.0-service: ===device.cfm880.pure.tvserver@1.0-service registered====

添加vndbinder_use(tvserver)避免警告

cfm880@cfm880:~/aosp$ adb logcat | grep "tvserver"
- waiting for device -
06-01 20:06:50.168     0     0 I init    : Parsing file /vendor/etc/init/device.cfm880.pure.tvserver@1.0-service.rc...
06-01 20:06:55.284     0     0 I init    : starting service 'tvserver'...
06-01 20:06:55.204   367   367 I device.cfm880.pure.tvserver@1.0-service: ===device.cfm880.pure.tvserver@1.0-service ====
06-01 20:06:56.207   367   367 I HidlServiceManagement: Registered device.cfm880.pure.tvserver@1.0::ITVServer/default
06-01 20:06:56.207   367   367 I HidlServiceManagement: Removing namespace from process name device.cfm880.pure.tvserver@1.0-service to tvserver@1.0-service.
06-01 20:06:56.207   367   367 I device.cfm880.pure.tvserver@1.0-service: ===device.cfm880.pure.tvserver@1.0-service registered====