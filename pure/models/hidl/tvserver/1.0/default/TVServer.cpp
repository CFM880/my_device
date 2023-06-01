// FIXME: your file license if you have one

#include "TVServer.h"

namespace device::cfm880::pure::tvserver::implementation {

// Methods from ::device::cfm880::pure::tvserver::V1_0::ITVServer follow.
Return<void> TVServer::hello(const hidl_string& name, hello_cb _hidl_cb) {
    char buf[100];
    ::memset(buf, 0, 100);
    ::snprintf(buf, 100, "helloHIDL %s from TVServer", name.c_str());
    hidl_string result(buf);
    _hidl_cb(result);
    // TODO implement
    return Void();
}


// Methods from ::android::hidl::base::V1_0::IBase follow.

//ITVServer* HIDL_FETCH_ITVServer(const char* /* name */) {
    //return new TVServer();
//}
//
}  // namespace device::cfm880::pure::tvserver::implementation
