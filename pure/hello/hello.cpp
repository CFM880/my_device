#include <cstdio>
#include <android/log.h>

#define LOG_TAG "cfm880"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

int main() {
    printf("hello cfm880\n");
    LOGD("hello cfm880");
    return 0;
}