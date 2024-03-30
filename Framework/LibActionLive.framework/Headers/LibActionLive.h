//
//  LibActionLive.h
//  LibActionLive
//
//  Created by 张杨 on 2021/1/15.
//

//  v1.0.0.0 更新动作活体MNN框架 2021/01/15
//  v1.0.1.0 增强模糊判断 2021/01/21
//  v1.0.2.0 修改动作阈值,降低纸质晃动的通过率;增加光照检测方法 2021/01/22
//  v1.0.3.0 更新了人脸检测和防翻拍模型,提高了人脸检出率和防翻拍的准确率;修改了活体检测的逻辑,加大了假体通过难度 2021/03/30
//  v1.0.4.0 针对相纸攻击准确率提升明显 2021/04/22
//  v1.0.5.0 增加部分入参配置;增加光照检测;检测过程返回Code: 108-人脸图像模糊 109-人脸姿态不正常 2021/06/04
//  v1.0.6.0 增加部分入参配置;检测过程返回Code: 110-人脸区域有遮挡 2021/07/12
//  v1.0.7.0 检测过程返回Code: 111-非指定动作，请保持与指定动作一致 2021/08/10
//  v1.0.8.0 精简模型，减小包大小 2022/03/01
//  v1.0.9.0 遮挡误判优化，默认阈值改为0.95f  2022/03/15
//  v1.1.0.0 增加人脸跟踪算法，提升检测速度 2022/03/31
//  v1.1.1.0 翻拍模型更新 2022/04/20
//  v1.1.2.0 增加多人脸检测;修正动作不一致检测误判率 2022/06/07
//  v1.1.2.1 修复iOS16图片存储异常问题 2022/09/26
//  v2.0.0.0 适配定制化MNN和Opencv库，避免库冲突 2022/10/14
//  v2.0.1.0 修复多人脸检测成功后再次调用start方法无法正常识别问题 2022/11/15
//  v2.0.2.0 优化模糊阈值默认值、光照阈值默认值 2022/11/17
//  v2.0.3.0 增加rom攻击检测算法 2022/12/03
//  v2.0.4.0 优化光照检测 2023/02/06
//  v2.1.0.0 更新MNN2.3.0框架并压缩模型 2023/05/05
//  v2.1.1.0 检测逻辑由异步改为同步，方便控制识别频率 2023/05/31
//  v3.0.0.0 人脸识别SDK并入活体识别SDK，人脸识别增加姿态、光照、模糊等姿态检测 2023/09/10
//  v3.0.1.0 修复MNN命名空间修改不完善问题 2023/11/02
//  v3.0.1.1 增加MNN能耗配置 2023/12/15

/// 活体检测
#if __has_include(<LibActionLive/Actionlive.h>)
#import <LibActionLive/Actionlive.h>
#else
#import "Actionlive.h"
#endif

/// Rom检测
#if __has_include(<LibActionLive/ActionColorAntiRom.h>)
#import <LibActionLive/ActionColorAntiRom.h>
#else
#import "ActionColorAntiRom.h"
#endif

/// 人脸检测
#if __has_include(<LibActionLive/Facexdet.h>)
#import <LibActionLive/Facexdet.h>
#else
#import "Facexdet.h"
#endif

/// 日志
#if __has_include(<LibActionLive/MSActionLiveLogUtils.h>)
#import <LibActionLive/MSActionLiveLogUtils.h>
#else
#import "MSActionLiveLogUtils.h"
#endif


