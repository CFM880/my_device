#include <hidl/HidlTransportSupport.h>
#include <utils/Looper.h>
#include <utils/StrongPointer.h>
#include <binder/ProcessState.h>

#include "TVServer.h"
#include <log/log.h>

using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using device::cfm880::pure::tvserver::V1_0::ITVServer;
using device::cfm880::pure::tvserver::implementation::TVServer;

int main() {
    // sleep for a second, wait /data/vender to be mounted
    ALOGI("===device.cfm880.pure.tvserver@1.0-service ====");
    sleep(1);
    android::ProcessState::initWithDriver("/dev/vndbinder");
    android::ProcessState::self()->setThreadPoolMaxThreadCount(4);
    android::ProcessState::self()->startThreadPool();
    android::hardware::configureRpcThreadpool(4, true /* will join */);

    configureRpcThreadpool(4, true /*callerWillJoin*/);

    android::sp<ITVServer> service = new TVServer;
    android::status_t ret = service->registerAsService();
    LOG_ALWAYS_FATAL_IF(ret != android::OK, "Could not register exit .....");
    ALOGI("===device.cfm880.pure.tvserver@1.0-service registered====");
    joinRpcThreadpool();
    return 0;
}
