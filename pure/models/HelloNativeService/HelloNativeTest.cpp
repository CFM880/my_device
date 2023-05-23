#include <binder/IServiceManager.h>
#include <binder/Parcel.h>
#include <utils/Errors.h>
#include <stdio.h>

using namespace android;

enum {
    CMD_SYS_HELLO = 1,
    CMD_CAL_SUM = 2
};

static sp<IBinder> service;

static void test_sysHello() {
    Parcel request, reply;
    request.writeCString("cfm880");
    service->transact(CMD_SYS_HELLO, request, &reply);
}

static void test_calSum() {
    Parcel request, reply;
    request.writeInt32(2);
    request.writeInt32(3);
    service->transact(CMD_CAL_SUM, request, &reply);
    int sum = reply.readInt32();
    printf("sum of 2 + 3 = %d\n", sum);
}

int main() {
    service = defaultServiceManager()->getService(String16("HelloNativeService"));
    test_sysHello();
    test_calSum();
    return 0;
}