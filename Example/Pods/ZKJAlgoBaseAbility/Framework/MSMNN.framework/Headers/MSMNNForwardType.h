//
//  MSMNNForwardType.h
//  MSMNN
//
//  Created by MSMNN on 2019/01/19.
//  Copyright © 2018, Alibaba Group Holding Limited
//

#ifndef MSMNNForwardType_h
#define MSMNNForwardType_h
#include <stdint.h>
#include <stddef.h>

typedef enum {
    MSMNN_FORWARD_CPU = 0,

    /*
     Firtly find the first available backends not equal to CPU
     If no other backends, use cpu
     */
    MSMNN_FORWARD_AUTO = 4,

    /*Hand write metal*/
    MSMNN_FORWARD_METAL = 1,

    /*NVIDIA GPU API*/
    MSMNN_FORWARD_CUDA = 2,

    /*Android / Common Device GPU API*/
    MSMNN_FORWARD_OPENCL = 3,
    MSMNN_FORWARD_OPENGL = 6,
    MSMNN_FORWARD_VULKAN = 7,

    /*Android 8.1's NNAPI or CoreML for ios*/
    MSMNN_FORWARD_NN = 5,

    /*User can use API from Backend.hpp to add or search Backend*/
    MSMNN_FORWARD_USER_0 = 8,
    MSMNN_FORWARD_USER_1 = 9,
    MSMNN_FORWARD_USER_2 = 10,
    MSMNN_FORWARD_USER_3 = 11,

    MSMNN_FORWARD_ALL,

    /* Apply arm extension instruction set to accelerate some Ops, this forward type
       is only used in MSMNN internal, and will be active automatically when user set forward type
       to be MSMNN_FORWARD_CPU and extension instruction set is valid on hardware.
    */
    MSMNN_FORWARD_CPU_EXTENSION

} MSMNNForwardType;

typedef enum {
    // choose one tuning mode Only
    MSMNN_GPU_TUNING_NONE    = 1 << 0,/* Forbidden tuning, performance not good */
    MSMNN_GPU_TUNING_HEAVY  = 1 << 1,/* heavily tuning, usually not suggested */
    MSMNN_GPU_TUNING_WIDE   = 1 << 2,/* widely tuning, performance good. Default */
    MSMNN_GPU_TUNING_NORMAL = 1 << 3,/* normal tuning, performance may be ok */
    MSMNN_GPU_TUNING_FAST   = 1 << 4,/* fast tuning, performance may not good */

    // choose one opencl memory mode Only
    /* User can try OpenCL_MEMORY_BUFFER and OpenCL_MEMORY_IMAGE both,
     then choose the better one according to performance*/
    MSMNN_GPU_MEMORY_BUFFER = 1 << 6,/* User assign mode */
    MSMNN_GPU_MEMORY_IMAGE  = 1 << 7,/* User assign mode */
} MSMNNGpuMode;

#ifdef __cplusplus
namespace MSMNN {
struct BackendConfig {
    enum MemoryMode { Memory_Normal = 0, Memory_High, Memory_Low };

    MemoryMode memory = Memory_Normal;

    enum PowerMode { Power_Normal = 0, Power_High, Power_Low };

    PowerMode power = Power_Normal;

    enum PrecisionMode { Precision_Normal = 0, Precision_High, Precision_Low, Precision_Low_BF16 };

    PrecisionMode precision = Precision_Normal;

    /** user defined context */
    union {
        void* sharedContext = nullptr;
        size_t flags; // Valid for CPU Backend
    };
};

    /** acquire runtime status by Runtime::getCurrentStatus with following keys,
    */
    enum RuntimeStatus {
        /**
         * get status whether this runtime support 16-bits float point arithmetic
         */
        STATUS_SUPPORT_FP16,
        /**
         * get status whether this runtime support dot-product arithmetic
         */
        STATUS_SUPPORT_DOT_PRODUCT,
        /**
         * get status whether this runtime support power-low (means low priority for opencl)
         */
        STATUS_SUPPORT_POWER_LOW,
        /**
         * emum total number
         */
        STATUS_COUNT
    };

}; // namespace MSMNN
#endif
#endif /* MSMNNForwardType_h */
