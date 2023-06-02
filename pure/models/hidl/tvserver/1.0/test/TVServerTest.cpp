#include <device/cfm880/pure/tvserver/1.0/ITVServer.h>
#include <device/cfm880/pure/tvserver/1.0/ITVServerListener.h>
#include <hidl/Status.h>
#include <utils/misc.h>
#include <hidl/HidlSupport.h>
#include <stdio.h>
#include <string>

using namespace std;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_death_recipient;
using ::android::sp;
using device::cfm880::pure::tvserver::V1_0::ITVServer;
using device::cfm880::pure::tvserver::V1_0::ITVServerListener;
android::sp<ITVServer> service = nullptr;

class TVServerListener: public ITVServerListener {
public:
    android::hardware::Return<void> onMessage(const hidl_string& message) override {
        printf("onMessage %s\n", message.c_str());
        return android::hardware::Return<void>();
    }
};


class ServerDeathRecipient: public hidl_death_recipient {
    virtual void serviceDied(uint64_t cookie, const android::wp<::android::hidl::base::V1_0::IBase> &who) {
        printf("serviceDied cookie = %d\n", cookie);
        service = nullptr;
    }
};

int main() {
    sp<ITVServerListener> listener = new TVServerListener();
    sp<ServerDeathRecipient> deathRecipient = new ServerDeathRecipient();
    service = ITVServer::getService();
    if (service == nullptr)
    {
        printf("helloHIDL Failed to get service\n");
        return -1;
    }
    service->linkToDeath(deathRecipient, 0);
    service->registerListener(getpid(), listener);
    service->hello("helloHIDL cfm880", [&](hidl_string result){
        printf("%s\n", result.c_str());
    }); 
    sleep(10);

    // service->unregisterListener(getpid());
    return 0;
}