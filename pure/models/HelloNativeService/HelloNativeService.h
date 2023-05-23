#ifndef ANDROID_12_HELLONATIVESERVICE_H
#define ANDROID_12_HELLONATIVESERVICE_H

#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <utils/Errors.h>
using namespace android;

class HelloNativeService: public BBinder {
public:
    HelloNativeService();
    static int instantiate();
    virtual status_t onTransact(uint32_t, const Parcel&, Parcel *, uint32_t);
};
#endif // ANDROID_12_HELLONATIVESERVICE_H