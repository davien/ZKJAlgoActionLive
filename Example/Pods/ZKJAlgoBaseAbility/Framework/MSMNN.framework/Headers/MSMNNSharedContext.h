//
//  MSMNNSharedContext.h
//  MSMNN
//
//  Created by MSMNN on 2018/10/11.
//  Copyright © 2018, Alibaba Group Holding Limited
//

#ifndef MSMNNSharedContext_h
#define MSMNNSharedContext_h
#include "MSMNNDefine.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h> /*uint32_t*/
#ifdef MSMNN_VULKAN

struct MSMNNVulkanContext {
    VkInstance pInstance;
    VkPhysicalDevice pPhysicalDevice;
    VkDevice pDevice;
    VkQueue pQueue;
    uint32_t iQueueFamilyIndex;
};

#endif

#ifdef MSMNN_METAL
struct MSMNNMetalSharedContext {
    id<MTLDevice> device;
    id<MTLCommandQueue> queue;
};

struct MSMNNMetalTensorContent {
    id<MTLBuffer> buffer;
    int32_t offset;
    id<MTLTexture> texture;
    int32_t forFuture[8];
};

MSMNN_PUBLIC int MSMNNMetalGetTensorContent(MSMNNMetalTensorContent* content, void* tensor);
#endif


#ifdef __cplusplus
}
#endif

#endif /* MSMNNSharedContext_h */
