// FIXME: your file license if you have one

#pragma once

#include <device/cfm880/pure/tvserver/1.0/ITVServer.h>
#include <device/cfm880/pure/tvserver/1.0/ITVServerListener.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace device::cfm880::pure::tvserver::implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::hidl_death_recipient;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;
using namespace std;

class ClientDeathRecipient;

class TVServer : public V1_0::ITVServer {
public:
    // Methods from ::device::cfm880::pure::tvserver::V1_0::ITVServer follow.
    TVServer();
    Return<void> hello(const hidl_string& name, hello_cb _hidl_cb) override;
    Return<void> registerListener(uint32_t pid, const sp<V1_0::ITVServerListener>& listenr) override;
    Return<void> unregisterListener(uint32_t pid) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.
private:
    map<uint32_t, sp<V1_0::ITVServerListener>> mListeners;
    sp<ClientDeathRecipient> mDeathRecipient;

};

// FIXME: most likely delete, this is only for passthrough implementations
// extern "C" ITVServer* HIDL_FETCH_ITVServer(const char* name);

}  // namespace device::cfm880::pure::tvserver::implementation
