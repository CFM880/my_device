// FIXME: your file license if you have one

#include "TVServer.h"
#include "TVServerListener.h"

#include <android/log.h>


#define LOG_TAG "TVServer"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)



namespace device::cfm880::pure::tvserver::implementation {
class ClientDeathRecipient: public hidl_death_recipient {
private:
    sp<TVServer> mTVServer;
public:
    ClientDeathRecipient(sp<TVServer> tvserver) : mTVServer(tvserver) {}
     virtual void serviceDied(uint64_t cookie, const android::wp<::android::hidl::base::V1_0::IBase> &who) {
        uint32_t pid = cookie;
        LOGD("clientDied cookie = %d\n", pid);
        mTVServer->unregisterListener(pid);
        
    }
};
TVServer::TVServer() {
    LOGD("TVServer start....");
    mDeathRecipient = new ClientDeathRecipient(this);
}

// Methods from ::device::cfm880::pure::tvserver::V1_0::ITVServer follow.
Return<void> TVServer::hello(const hidl_string& name, hello_cb _hidl_cb) {
    char buf[100];
    ::memset(buf, 0, 100);
    ::snprintf(buf, 100, "helloHIDL %s from TVServer", name.c_str());
    hidl_string result(buf);
    _hidl_cb(result);
    // TODO implement
    LOGD("listener size %d", mListeners.size());
    map<uint32_t, sp<V1_0::ITVServerListener>>::iterator it;
    for (it = mListeners.begin(); it != mListeners.end(); ++it) 
    {
        sp<V1_0::ITVServerListener> listener = it->second;
        listener->onMessage("message from server");
    }
    
    
    return Void();
}

Return<void> TVServer::registerListener(uint32_t pid, const sp<V1_0::ITVServerListener>& listener) {
    // TODO implement
    mListeners[pid] = listener;
    listener->linkToDeath(mDeathRecipient, pid);
    LOGD("registerListener %d, %x", pid, listener.get());
    return Void();
}

Return<void> TVServer::unregisterListener(uint32_t pid) {
    // TODO implement
    mListeners[pid]->unlinkToDeath(mDeathRecipient);
    mListeners.erase(pid);
    LOGD("unregisterListener %d", pid);
    return Void();
}


// Methods from ::android::hidl::base::V1_0::IBase follow.

//ITVServer* HIDL_FETCH_ITVServer(const char* /* name */) {
    //return new TVServer();
//}
//
}  // namespace device::cfm880::pure::tvserver::implementation
