//
//  IdCardOptCharReg.h
//  libidcardocr
//
//  Created by 张杨 on 2020/9/1.
//  Copyright © 2020 张杨. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, IdCardType) {
    IDCARD_NO_LIMIT = 0,//不限制卡片类型
    IDCARD_FRONT = 1,   //身份证正面
    IDCARD_BACK  = 2,   //身份证反面
};

/// 配置类
@interface IdcardConfig : NSObject
#define MSIdcardConfigInstance [IdcardConfig config]
/// 是否开启高准确率识别：默认NO 如果开启则通过多次识别来实现，速度稍慢，准确率提高
@property (nonatomic, assign) BOOL bHighAccuracy;
/// 是否做地址校验：默认YES
@property (nonatomic, assign) BOOL bAddressCheck;
/// 是否做距离控制：默认NO
@property (nonatomic, assign) BOOL bDistanceControl;
/// 是否做角度控制：默认NO
@property (nonatomic, assign) BOOL bLeanAngleControl;
/// 距离控制的阈值：默认0.4f
@property (nonatomic, assign) float distanceThreshold;
/// 角度控制的阈值：默认5
@property (nonatomic, assign) int leanAngleThreshold;
/// 质量阈值：默认0.5f
@property (nonatomic, assign) float idCardQualityThres;
/// 身份证外扩比例 默认0.03f
@property (nonatomic, assign) float expandedRatio;
/// 超时时间 默认15s
@property (nonatomic, assign) int iTimeLimit;
/// 单例
+ (instancetype)config;
@end

/// 结果类
@interface IdcardResult : NSObject
/// 身份证正反面类型： 1正面 2反面
@property (nonatomic, assign) int idCardType;
/// 姓名
@property (nonatomic, copy) NSString *idcardName;
/// 性别
@property (nonatomic, copy) NSString *idcardGender;
/// 出生日期
@property (nonatomic, copy) NSString *idcardBirth;
/// 民族
@property (nonatomic, copy) NSString *idcardNation;
/// 地址
@property (nonatomic, copy) NSString *idcardAddress;
/// 身份证号
@property (nonatomic, copy) NSString *idcardNumber;
/// 签发机关
@property (nonatomic, copy) NSString *idcardAuthority;
/// 有效日期
@property (nonatomic, copy) NSString *idcardValiddate;
@end

@interface IdCardOptCharReg : NSObject

/**
 * 身份证识别初始化
 * strModelRootDir: 资源路径
 * licenseName 授权证书文件名
 * 返回：
 *      1 ：初始化成功
 *      0 ：初始化失败
 *      100 ：授权成功
 *      101 ：授权证书读取失败
 *      102 ：授权证书校验失败(不匹配)
 *      103 ：应用包名错误
 *      104 ：应用包名长度错误
 *      105 ：设备类型错误
 *      106 ：证书未到有效期
 *      107 ：证书已过有效期
 */
+ (int)initWithStrModelRootDir:(NSString *)strModelRootDir;
+ (int)initWithStrModelRootDir:(NSString *)strModelRootDir
                   licenseName:(nullable NSString *)licenseName;

/// 校验授权证书有效性
/// @param licenseName 授权证书名称 eg:facex_live_ios
/// 返回：
///      100 ：授权成功
///      101 ：授权证书读取失败
///      102 ：授权证书校验失败(不匹配)
///      103 ：应用包名错误
///      104 ：应用包名长度错误
///      105 ：设备类型错误
///      106 ：证书未到有效期
///      107 ：证书已过有效期
+ (int)authorizationWithLicenseName:(NSString *)licenseName;

/**
 * 身份证识别配置
 * config: IdcardConfig
 */
+ (void)idCardDetectionConfig:(IdcardConfig *)config;

/**
 * 启动身份证识别检测
 * 注意：先调用此方法，再调用 XXXXInputData相关接口
 * 返回：
 *     100 ： 检测算法启动成功
 *    -101 ：SDK未初始化
 */
+ (int)idCardDetectionStart:(IdCardType)cardType;

/**
 * 身份证识别检测，送入从摄像头抓拍的图像序列
 * 调用此接口前，需调用idCardDetectionStart接口
 * image:图像数据 - 从摄像头获取的图像数据，已转码为RGB 或 RGBA格式
 * roiBoxX:     引导框左上角X 坐标
 * roiBoxY:     引导框左上角Y 坐标
 * roiBoxW:     引导框宽度
 * roiBoxH:     引导框高度
 * bestImagePath: 抓拍的身份证图像存储路径
 * completion:  x - 身份证左上角X 坐标
 *              y - 身份证左上角Y 坐标
 *              w - 身份证宽度
 *              h - 身份证高度
 * 返回： 100 ：身份证检测过程中，请继续输入图像数据
 *       101 ：检测超时未完成
 *       102 ：成功
 *       103 ：未检测到身份证
 *       104 ：身份证距离太远
 *       105 ：身份证区域超出引导框
 *       106 ：身份证倾斜过大
 *       110 ：未开启检测 idCardDetectionStart
 *      -101 ：SDK未初始化
 *      -102 ：输入图像数据长度异常
 *      -103 ：输入数据为空
 *      -104 ：图像宽或高小于20，无法处理
 *      -105 ：引导框超出输入图像
 *      -106 ：单次识别图像的宽高发生变化
 *      继续送帧需要重新启动检测，-101到-106为开发异常
 */
+ (int)idCardDetRecInputData:(UIImage *)image
                     roiBoxX:(int)iRoiBoxX
                     roiBoxY:(int)iRoiBoxY
                     roiBoxW:(int)iRoiBoxW
                     roiBoxH:(int)iRoiBoxH
               bestImagePath:(NSString *)bestImagePath
                  completion:(void (^)(int x, int y, int width, int height))completion;

/**
 * 停止身份证识别检测
 */
+ (void)idCardDetectionStop;

/**
 * 获取身份证识别结果
 * 返回：结果字段分别为：IdcardResult
 */
+ (void)getIdCardTextRecResults:(void (^)(IdcardResult *idcardResult))completion;

/**
 * 身份证识别反初始化，释放相关资源
 */
+ (void)unInit;

/**
 * 版本号
 */
+ (NSString *)currentVersion;

//###########################################################
//###################***身份证埋点信息***######################
//###########################################################

/**
 * 身份证日志 【自动识别】
 * strCallTime         – 当前时间
 * strEventNum         - 事件编号
 * strOrderNum         – 申请单号
 * strResultFinal      – 最终返给app的结果
 * strSdkPackage       – 包名
 * strDeviceType       – 设备类型
 * strDeviceVersion    – 系统版本
 * strAppVersion       – 应用版本
 * strSdkVersion       – Sdk版本
 */
+ (NSString *)getIdcardLogsWithCallTime:(NSString *)strCallTime
                               eventNum:(NSString *)strEventNum
                               orderNum:(NSString *)strOrderNum
                            resultFinal:(NSString *)strResultFinal
                             sdkPackage:(NSString *)strSdkPackage
                             deviceType:(NSString *)strDeviceType
                          deviceVersion:(NSString *)strDeviceVersion
                             appVersion:(NSString *)strAppVersion
                             sdkVersion:(NSString *)strSdkVersion;

/**
 * 身份证正面日志【手动识别】
 * 设置手动调用身份证正面埋点信息
 * strCallTime              – 当前时间
 * strEventNum              - 事件类型
 * strOrderNum              – 申请单号
 * strResultFinal           – 最终返给app的结果
 * strSdkPackage            – 包名
 * strDeviceType            – 系统类型（IOS,ANDROID）
 * strDeviceVersion         – 设备版本
 * strAppVersion            – 应用版本
 * strSdkVersion            – Sdk版本
 * strIdcardFrontName       - 姓名
 * strIdcardFrontAddress    - 地址
 * strIdcardFrontNumber     - 身份证号
 * strIdcardFrontNation     - 民族
 */
+ (NSString *)getIdcardFrontManualLogsWithCallTime:(NSString *)strCallTime
                                          eventNum:(NSString *)strEventNum
                                          OrderNum:(NSString *)strOrderNum
                                       resultFinal:(NSString *)strResultFinal
                                        sdkPackage:(NSString *)strSdkPackage
                                        deviceType:(NSString *)strDeviceType
                                     deviceVersion:(NSString *)strDeviceVersion
                                        appVersion:(NSString *)strAppVersion
                                        sdkVersion:(NSString *)strSdkVersion
                                   idcardFrontName:(NSString *)strIdcardFrontName
                                idcardFrontAddress:(NSString *)strIdcardFrontAddress
                                 idcardFrontNumber:(NSString *)strIdcardFrontNumber
                                 idcardFrontNation:(NSString *)strIdcardFrontNation;

/**
 * 身份证反面日志【手动识别】
 * strCallTime              – 当前时间
 * strEventNum              - 事件类型
 * strOrderNum              – 申请单号
 * strResultFinal           – 最终返给app的结果
 * strSdkPackage            – 包名
 * strDeviceType            – 系统类型（IOS,ANDROID）
 * strDeviceVersion         – 设备版本
 * strAppVersion            – 应用版本
 * strSdkVersion            – Sdk版本
 * strIdcardBackAuthority   - 签发机关
 * strIdcardBackValiddate   - 有效日期
 */
+ (NSString *)getIdcardReverseManualLogsWithCallTime:(NSString *)strCallTime
                                            eventNum:(NSString *)strEventNum
                                            OrderNum:(NSString *)strOrderNum
                                         resultFinal:(NSString *)strResultFinal
                                          sdkPackage:(NSString *)strSdkPackage
                                          deviceType:(NSString *)strDeviceType
                                       deviceVersion:(NSString *)strDeviceVersion
                                          appVersion:(NSString *)strAppVersion
                                          sdkVersion:(NSString *)strSdkVersion
                                 idcardBackAuthority:(NSString *)strIdcardBackAuthority
                                 idcardBackValiddate:(NSString *)strIdcardBackValiddate;

@end

NS_ASSUME_NONNULL_END
