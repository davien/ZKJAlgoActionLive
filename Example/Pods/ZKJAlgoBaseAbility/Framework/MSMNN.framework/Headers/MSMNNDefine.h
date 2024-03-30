//
//  MSMNNDefine.h
//  MSMNN
//
//  Created by MSMNN on 2018/08/09.
//  Copyright © 2018, Alibaba Group Holding Limited
//

#ifndef MSMNNDefine_h
#define MSMNNDefine_h

#include <assert.h>
#include <stdio.h>

#if defined(__APPLE__)
#include <TargetConditionals.h>
#if TARGET_OS_IPHONE
#define MSMNN_BUILD_FOR_IOS
#endif
#endif

#ifdef MSMNN_USE_LOGCAT
#include <android/log.h>
#define MSMNN_ERROR(format, ...) __android_log_print(ANDROID_LOG_ERROR, "MSMNNJNI", format, ##__VA_ARGS__)
#define MSMNN_PRINT(format, ...) __android_log_print(ANDROID_LOG_INFO, "MSMNNJNI", format, ##__VA_ARGS__)
#elif defined MSMNN_BUILD_FOR_IOS
// on iOS, stderr prints to XCode debug area and syslog prints Console. You need both.
#include <syslog.h>
#define MSMNN_PRINT(format, ...) syslog(LOG_WARNING, format, ##__VA_ARGS__); fprintf(stderr, format, ##__VA_ARGS__)
#define MSMNN_ERROR(format, ...) syslog(LOG_WARNING, format, ##__VA_ARGS__); fprintf(stderr, format, ##__VA_ARGS__)
#else
#define MSMNN_PRINT(format, ...) printf(format, ##__VA_ARGS__)
#define MSMNN_ERROR(format, ...) printf(format, ##__VA_ARGS__)
#endif

#ifdef DEBUG
#define MSMNN_ASSERT(x)                                            \
    {                                                            \
        int res = (x);                                           \
        if (!res) {                                              \
            MSMNN_ERROR("Error for %s, %d\n", __FILE__, __LINE__); \
            assert(res);                                         \
        }                                                        \
    }
#else
#define MSMNN_ASSERT(x)
#endif

#define FUNC_PRINT(x) MSMNN_PRINT(#x "=%d in %s, %d \n", x, __func__, __LINE__);
#define FUNC_PRINT_ALL(x, type) MSMNN_PRINT(#x "=" #type " %" #type " in %s, %d \n", x, __func__, __LINE__);

#define MSMNN_CHECK(success, log) \
if(!(success)){ \
MSMNN_ERROR("Check failed: %s ==> %s\n", #success, #log); \
}

#if defined(_MSC_VER)
#if defined(BUILDING_MSMNN_DLL)
#define MSMNN_PUBLIC __declspec(dllexport)
#elif defined(USING_MSMNN_DLL)
#define MSMNN_PUBLIC __declspec(dllimport)
#else
#define MSMNN_PUBLIC
#endif
#else
#define MSMNN_PUBLIC __attribute__((visibility("default")))
#endif
#define STR_IMP(x) #x
#define STR(x) STR_IMP(x)
#define MSMNN_VERSION_MAJOR 2
#define MSMNN_VERSION_MINOR 3
#define MSMNN_VERSION_PATCH 0
#define MSMNN_VERSION STR(MSMNN_VERSION_MAJOR) "." STR(MSMNN_VERSION_MINOR) "." STR(MSMNN_VERSION_PATCH)
#endif /* MSMNNDefine_h */
