#include <binder/IServiceManager.h>
#include <binder/Parcel.h>
#include <utils/Errors.h>
#include <stdio.h>

using namespace android;

enum {
    CMD_SYS_HELLO = 1,
    CMD_CAL_SUM = 2,
    CMD_CONNECT = 3
};
class Callback : public BBinder {
    enum {
        CALLBACK_SYS_HELLO = 1,
    };
    status_t onTransact(uint32_t code, const Parcel &request, Parcel *reply, uint32_t flag) {
        printf("Callback onTransact\n");
        switch (code)
        {
        case CALLBACK_SYS_HELLO:
            const char *str = request.readCString();
            printf("msg from server:%s\n", str);
            break;
        }
        return BBinder::onTransact(code, request, reply, flag);
    }
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

static void test_connect(sp<Callback> callback) {
    Parcel request, reply;
    request.writeStrongBinder(callback);
    service->transact(CMD_CONNECT, request, &reply);
}

int main() {
    service = defaultServiceManager()->getService(String16("HelloNativeService"));
    sp<Callback> callback = new Callback();
    test_connect(callback);
    test_sysHello();
    test_calSum();
    sleep(10);
    return 0;
}