#include <android/log.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include "HelloNativeService.h"
using namespace android;

#define MY_LOG_TAG "HelloNativeService"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, MY_LOG_TAG, __VA_ARGS__)

enum {
    CMD_SYS_HELLO = 1,
    CMD_CAL_SUM = 2
};

static void sayHello(const char *name) {
    LOGD("hello %s from HelloNativeService", name);
}

static int sum(int a, int b) {
    return a + b;
}

HelloNativeService::HelloNativeService() {
    LOGD("HelloNativeService created");
}

int HelloNativeService::instantiate() {
    int r = defaultServiceManager()->addService(String16("HelloNativeService"), new HelloNativeService());
    LOGD("add HelloNativeService r = %d", r);
    return r;
}

status_t HelloNativeService::onTransact(uint32_t code, const Parcel &request, Parcel *reply, uint32_t flag) {
    switch (code)
    {
    case CMD_SYS_HELLO:
        sayHello(request.readCString());
        return NO_ERROR;
    case CMD_CAL_SUM:
        int a = request.readInt32();
        int b = request.readInt32();
        reply->writeInt32(sum(a, b));
        return NO_ERROR;
    }
    return BBinder::onTransact(code, request, reply, flag);
}