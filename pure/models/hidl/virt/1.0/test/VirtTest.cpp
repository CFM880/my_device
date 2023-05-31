#include <epam/virt/1.0/IVirt.h>
#include <hidl/Status.h>
#include <utils/misc.h>
#include <hidl/HidlSupport.h>
#include <stdio.h>
#include <string>

using namespace std;
using ::android::hardware::hidl_string;
using ::android::sp;
using epam::virt::V1_0::IVirt;

int main() {
    android::sp<IVirt> service = IVirt::getService();
    if (service == nullptr)
    {
        printf("helloHIDL IVirt Failed to get service\n");
        return -1;
    }
    service->init(); 
    return 0;
}