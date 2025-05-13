// FIXME: your file license if you have one

#pragma once

#include <device/cfm880/pure/tvserver/1.0/ITVServerListener.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace device::cfm880::pure::tvserver::implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct TVServerListener : public V1_0::ITVServerListener {
    // Methods from ::device::cfm880::pure::tvserver::V1_0::ITVServerListener follow.
    Return<void> onMessage(const hidl_string& message) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.

};

// FIXME: most likely delete, this is only for passthrough implementations
// extern "C" ITVServerListener* HIDL_FETCH_ITVServerListener(const char* name);

}  // namespace device::cfm880::pure::tvserver::implementation
