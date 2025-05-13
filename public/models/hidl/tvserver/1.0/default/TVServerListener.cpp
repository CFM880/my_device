// FIXME: your file license if you have one

#include "TVServerListener.h"

namespace device::cfm880::pure::tvserver::implementation {

// Methods from ::device::cfm880::pure::tvserver::V1_0::ITVServerListener follow.
Return<void> TVServerListener::onMessage(const hidl_string& message) {
    // TODO implement
    return Void();
}


// Methods from ::android::hidl::base::V1_0::IBase follow.

//ITVServerListener* HIDL_FETCH_ITVServerListener(const char* /* name */) {
    //return new TVServerListener();
//}
//
}  // namespace device::cfm880::pure::tvserver::implementation
