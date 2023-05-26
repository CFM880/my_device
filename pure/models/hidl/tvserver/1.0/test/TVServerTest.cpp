#include <device/cfm880/pure/tvserver/1.0/ITVServer.h>
#include <hidl/Status.h>
#include <utils/misc.h>
#include <hidl/HidlSupport.h>
#include <stdio.h>
#include <string>

using namespace std;
using ::android::hardware::hidl_string;
using ::android::sp;
using device::cfm880::pure::tvserver::V1_0::ITVServer;

int main() {
    android::sp<ITVServer> service = ITVServer::getService();
    if (service == nullptr)
    {
        printf("Failed to get service\n");
        return -1;
    }
    service->hello("cfm880", [&](hidl_string result){
        printf("%s\n", result.c_str());
    }); 
    return 0;
}