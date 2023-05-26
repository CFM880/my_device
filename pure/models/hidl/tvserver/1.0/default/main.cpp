#include <hidl/HidlTransportSupport.h>
#include <utils/Looper.h>
#include <utils/StrongPointer.h>

#include "TVServer.h"

using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using device::cfm880::pure::tvserver::V1_0::ITVServer;
using device::cfm880::pure::tvserver::V1_0::implementation::TVServer;

int main(int argc, char **argv) {
    // sleep for a second, wait /data/vender to be mounted
    sleep(1);

    configureRpcThreadpool(4, true /*callerWillJoin*/);

    android::sp<ITVServer> service = new TVServer();
    android::status_t ret = service->registerAsService();
    if (ret != android::NO_ERROR)
    {
    }
    joinRpcThreadpool();
    return 0;
}
