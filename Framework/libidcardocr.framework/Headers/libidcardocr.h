//
//  libidcardocr.h
//  libidcardocr
//
//  Created by 张杨 on 2020/9/2.
//  Copyright © 2020 张杨. All rights reserved.

//  v1.0.0.0 更新MNN框架 2020/09/02
//  v1.0.1.0 MNN模型文件加密 2020/09/04
//  v1.0.2.0 增加配置参数 2020/12/30
//  v1.0.3.0 修复多次识别传入图像的分辨率不一致导致的崩溃问题 2021/04/01
//  v1.0.4.0 修复身份证扫描获取结果偶现异常导致崩溃问题 2021/07/06
//  v1.0.5.0 身份证识别接口增加是否裁图参数 2021/09/10
//  v1.0.6.0 优化识别图片保存路径方案 2021/11/22
//  v1.1.0.0 增加质量检测模型，提高识别准确率 2022/02/22
//  v1.1.0.1 初始化方法增加自定义授权文名 2022/08/24
//  v1.1.1.0 外扩剪裁区域保证身份证图片完整性 2022/09/19
//  v2.0.0.0 适配定制化MNN和Opencv库，避免库冲突 2022/10/19
//  v2.0.1.0 增加自定义外扩参数配置 2022/12/13
//  v2.1.0.0 通过多次识别来实现高准确率，速度稍慢 2022/12/26
//  v2.1.1.0 银行卡支持竖屏图片识别（宽高比小于1的图片）2023/05/18
//  v2.2.0.0 身份证支持正反面自适应识别 2023/05/23
//  v2.2.1.0 适配MNN2.3.0框架 对模型文件压缩 2023/05/24
//  v2.2.2.0 身份证提高竖屏图片识别准确率（宽高比小于1的图片） 2023/08/06
//  v2.2.2.1 更新MNN库，修复MNN命名空间修改不完全的问题 2023/11/06

#if __has_include(<libidcardocr/IdCardOptCharReg.h>)
#import <libidcardocr/IdCardOptCharReg.h>
#else
#import "IdCardOptCharReg.h"
#endif

#if __has_include(<libidcardocr/BankCardOptCharReg.h>)
#import <libidcardocr/BankCardOptCharReg.h>
#else
#import "BankCardOptCharReg.h"
#endif
