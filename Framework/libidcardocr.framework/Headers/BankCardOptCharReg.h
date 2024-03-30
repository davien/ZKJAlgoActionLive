//
//  BankCardOptCharReg.h
//  libidcardocr
//
//  Created by 张杨 on 2020/8/19.
//  Copyright © 2020 张杨. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface BankCardOptCharReg : NSObject

/**
 * 银行卡识别初始化
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
                   licenseName:(NSString *)licenseName;

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
 * 启动银行卡号检测
 * 注意：先调用此方法，再调用 XXXXInputData相关接口
 * 返回：
 *     100 ： 检测算法启动成功
 *     -101 ：SDK未初始化
 */
+ (int)bankCardDetectionStart;

/**
 * 银行卡号检测，送入从摄像头抓拍的图像序列
 * 调用此接口前，需调用BkcardDetectionStart接口
 * image:     图像数据 - 从摄像头获取的图像数据，已转码为RGB 或 RGBA格式
 * roiBoxX:   引导框左上角X 坐标
 * roiBoxY:   引导框左上角Y 坐标
 * roiBoxW：   引导框宽度
 * roiBoxH：   引导框高度
 * iCardAngleType： 0-0,1-90,2-180,3-270
 * bestImagePath: 抓拍的银行卡图像存储路径
 * 返回： 100 ：银行卡号检测过程中，请继续输入图像数据
 *       101 ：检测超时未完成
 *       102 ：成功
 *       110 ：未调用Start方法
 *       -101 ：SDK未初始化
 *       -102 ：输入图像数据长度异常
 *       -103 ：输入数据为空
 *       -104 ：图像宽或高小于20，无法处理
 *       -105 ：引导框超出输入图像
 */
+ (int)bankCardDetRecInputData:(UIImage *)image
                       roiBoxX:(int)iRoiBoxX
                       roiBoxY:(int)iRoiBoxY
                       roiBoxW:(int)iRoiBoxW
                       roiBoxH:(int)iRoiBoxH
                 cardAngleType:(int)iCardAngleType
                 bestImagePath:(NSString *)bestImagePath;

/**
 * 停止银行卡号检测
 */
+ (void)bankCardDetectionStop;

/**
 * 获取卡片识别结果
 * 返回：结果字段分别为：
 *      r_cardNum 银行卡号,
 *      r_bankName 发卡行,
 *      r_cardName 卡种名,
 *      r_cardType卡类型
 */
+ (void)getBankCardTextRecResults:(void (^)(NSString *r_cardNum,
                                    NSString *r_bankName,
                                    NSString *r_cardName,
                                    NSString *r_cardType))completion;

/**
 * 银行卡识别反初始化，释放相关资源
 */
+ (void)unInit;

/**
 * 设置超时时长
 */
+ (void)config:(int)outTime;

//###########################################################
//###################***银行卡埋点信息***######################
//###########################################################

/**
 * 银行卡日志 【自动识别】
 * strCallTime         – 当前时间
 * strEventNum         - 事件编号
 * strOrderNum         – 申请单号
 * strResultFinal      – 最终返给app的结果
 * strSdkPackage       – 包名
 * strDeviceType       – 系统类型（IOS,ANDROID）
 * strDeviceVersion    – 设备版本
 * strAppVersion       – 应用版本
 * strSdkVersion       – Sdk版本
 */
+ (NSString *)getBankCardLogsWithCallTime:(NSString *)strCallTime
                                 eventNum:(NSString *)strEventNum
                                 orderNum:(NSString *)strOrderNum
                              resultFinal:(NSString *)strResultFinal
                               sdkPackage:(NSString *)strSdkPackage
                               deviceType:(NSString *)strDeviceType
                            deviceVersion:(NSString *)strDeviceVersion
                               appVersion:(NSString *)strAppVersion
                               sdkVersion:(NSString *)strSdkVersion;

/**
 * 银行卡日志 【手动识别】
 * strCallTime         – 当前时间
 * strEventNum         - 事件类型
 * strOrderNum         – 申请单号
 * strResultFinal      – 最终返给app的结果
 * strSdkPackage       – 包名
 * strDeviceType       – 系统类型（IOS,ANDROID）
 * strDeviceVersion    – 设备版本
 * strAppVersion       – 应用版本
 * strSdkVersion       – Sdk版本
 * strBankNumber       - 银行卡号
 * strBankName         - 银行名（比如建设银行，农业银行）
 * strBankType         - 银行卡类型（比如借记卡，储蓄卡）
 */
+ (NSString *)getBankCardManualLogsWithCallTime:(NSString *)strCallTime
                                       eventNum:(NSString *)strEventNum
                                       orderNum:(NSString *)strOrderNum
                                    resultFinal:(NSString *)strResultFinal
                                     sdkPackage:(NSString *)strSdkPackage
                                     deviceType:(NSString *)strDeviceType
                                  deviceVersion:(NSString *)strDeviceVersion
                                     appVersion:(NSString *)strAppVersion
                                     sdkVersion:(NSString *)strSdkVersion
                                     bankNumber:(NSString *)strBankNumber
                                       bankName:(NSString *)strBankName
                                       bankType:(NSString *)strBankType;

@end

NS_ASSUME_NONNULL_END
