// FIXME: your file license if you have one

#pragma once

#include <device/cfm880/pure/tvserver/1.0/ITVServer.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace device::cfm880::pure::tvserver::V1_0::implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct TVServer : public V1_0::ITVServer {
    // Methods from ::device::cfm880::pure::tvserver::V1_0::ITVServer follow.
    Return<void> hello(const hidl_string& name, hello_cb _hidl_cb) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.

};

// FIXME: most likely delete, this is only for passthrough implementations
// extern "C" ITVServer* HIDL_FETCH_ITVServer(const char* name);

}  // namespace device::cfm880::pure::tvserver::implementation
