#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include "HelloNativeService.h"


using namespace android;

int main(int argc, char *argv[]) {
    sp<ProcessState> proc(ProcessState::self());

    HelloNativeService::instantiate();
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
    return 0;
}