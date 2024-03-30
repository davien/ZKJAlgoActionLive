//
//  Actionlive.h
//  LibActionLive
//
//  Created by 张杨 on 2021/1/15.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// **************配置类**************

typedef enum {
    ActionPower_Normal = 0,
    ActionPower_High,
    ActionPower_Low
} ActionPowerMode;

@interface LiveConfig : NSObject

/// 是否开启屏幕翻拍 默认关闭
@property (nonatomic, assign) BOOL isScreenDet;
/// 屏幕翻拍检测阈值[0.0 - 正常活体；1.0 - 翻拍] 默认0.5f
@property (nonatomic, assign) float screenDetThr;
/// 最小人脸尺寸,不小于20像素 默认60
@property (nonatomic, assign) int minFaceSize;
/// 模糊阈值 默认10.0f
@property (nonatomic, assign) float blurThr;
/// 人脸过小阈值 默认0.45f
@property (nonatomic, assign) float smallFaceThr;
/// 人脸过大阈值 默认0.75f
@property (nonatomic, assign) float largeFaceThr;
/// 是否进行人脸遮挡判断 默认NO
@property (nonatomic, assign) BOOL isFaceShelter;
/// 人脸遮挡阈值 值 越大越难判断为遮挡 越小容易判断为遮挡 默认0.95f
@property (nonatomic, assign) float faceShelterThr;
/// 多人脸检测 默认NO
@property (nonatomic, assign) BOOL isMoreFaceDet;
/// 是否检测动作不一致 默认NO
@property (nonatomic, assign) BOOL isDetInconsistentAction;
/// 是否进行光照检测判断 默认NO
@property (nonatomic, assign) BOOL isOpenLightDet;
/// 光照检测欠曝阈值 默认30
@property (nonatomic, assign) float lightMinThr;
/// 光照检测过曝阈值 默认210
@property (nonatomic, assign) float lightMaxThr;
/// MNN能耗 默认正常能耗 FacePower_Normal
@property (nonatomic, assign) ActionPowerMode power;

@end

@interface Actionlive : NSObject

/// 活体检测初始化【双证书校验 debug包 && release包】
/// @param bundleDir Bundle资源路径 eg:[[NSBundle mainBundle] pathForResource:@"xxx" ofType:@"bundle"];
/// @param liveConfig 配置
/// 返回：1 ：初始化成功
///      0 ：初始化失败
///      100 ：授权成功
///      101 ：授权证书读取失败
///      102 ：授权证书校验失败(不匹配)
///      103 ：应用包名错误
///      104 ：应用包名长度错误
///      105 ：设备类型错误
///      106 ：证书未到有效期
///      107 ：证书已过有效期
+ (int)initWithBundleDir:(NSString *)bundleDir
              liveConfig:(LiveConfig *)liveConfig;

/// 活体检测初始化【单证书校验】
/// @param bundleDir Bundle资源路径 eg:[[NSBundle mainBundle] pathForResource:@"xxx" ofType:@"bundle"];
/// @param licenseName 授权证书文件名
/// @param liveConfig 配置
/// 返回：1 ：初始化成功
///      0 ：初始化失败
///      100 ：授权成功
///      101 ：授权证书读取失败
///      102 ：授权证书校验失败(不匹配)
///      103 ：应用包名错误
///      104 ：应用包名长度错误
///      105 ：设备类型错误
///      106 ：证书未到有效期
///      107 ：证书已过有效期
+ (int)initWithBundleDir:(NSString *)bundleDir
             licenseName:(nullable NSString *)licenseName
              liveConfig:(LiveConfig *)liveConfig;

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
 * 活体检测反初始化，释放相关资源
 */
+ (void)unInit;

/** 动作检测方法
 * iamge:       图像数据
 * iFaceBoxX:   检测区域左上角X 坐标
 * iFaceBoxY:   检测区域左上角Y 坐标
 * iFaceBoxW:   检测区域宽度
 * iFaceBoxH:   检测区域高度
 * imotionCode: 动作编号 - 1：眨眼；2：左右摇头；3：点头；4：张嘴；5：正视镜头；6：正视镜头严谨
 * strBestImagePath: 最优图片写入路径
 * complete: fScreenDetScore防翻拍分数，imageData保存的图像数据
 * 返回：
 * 则对应的状态如下：
 * 1:   动作成功
 * 100: 活体动作检测过程中，请继续输入图像数据
 * 101: 活体动作超时未完成
 * 102: 疑似屏幕翻拍
 * 103: 视频抓拍人脸质量不合格
 * 104: 人脸超出引导框
 * 105: 人脸太远,请靠近 [5：正视镜头 || 6：正视镜头严谨]
 * 106: 人脸太近,请远离 [5：正视镜头 || 6：正视镜头严谨]
 * 107: 人脸消失,请重试 [1：眨眼 || 2：左右摇头 || 3：点头 || 4：张嘴 || 6：正视镜头严谨]
 * 108: 人脸图像模糊    [1：眨眼 || 4：张嘴 || 5：正视镜头 || 6：正视镜头严谨]
 * 109: 人脸姿态不正常  [5：正视镜头 || 6：正视镜头严谨]
 * 110: 人脸区域有遮挡  [1：眨眼 || 4：张嘴 || 5：正视镜头 || 6：正视镜头严谨]
 * 111: 非指定动作，请保持与指定动作一致
 * 112: 检测到多个人脸
 * 113: 连续帧检测异常
 * 119: 处理耗时较长，降低图像采样率
 * 201: 有人脸光照过曝，过亮
 * 202: 有人脸光照欠曝，过暗
 * 203: 无人脸光照过曝，过亮
 * 204: 无人脸光照欠曝，过暗
 * -101: SDK未初始化
 * -102: 输入图像数据长度异常
 * -103: 输入数据为空
 * -104: 图像宽或高小于20，无法处理
 * -105: 人脸引导框超出输入图像
 * -106: 线程Loop超时
 */
+ (int)imgInputWithImage:(UIImage *)image
                 faceBoxX:(int)iFaceBoxX
                 faceBoxY:(int)iFaceBoxY
                 faceBoxW:(int)iFaceBoxW
                 faceBoxH:(int)iFaceBoxH
               motionCode:(int)imotionCode
            bestImagePath:(nullable NSString *)strBestImagePath
                 complete:(void (^)(float fScreenDetScore, NSData *imageData))complete;

+ (int)imgInputWithImage:(UIImage *)image
                faceBoxX:(int)iFaceBoxX
                faceBoxY:(int)iFaceBoxY
                faceBoxW:(int)iFaceBoxW
                faceBoxH:(int)iFaceBoxH
              motionCode:(int)imotionCode
                complete:(void (^)(float fScreenDetScore, NSData *imageData))complete;

/**
 * 启动检测线程
 * 0 启动成功 
 */
+ (int)startProcess;

/// 当前版本号
+ (NSString *)currentVersion;

/// 设置是否在console输出算法库的log信息
/// @param bFlag 默认NO(不输出log); 设置为YES, 输出可供调试参考的log信息. 发布产品时必须设置为NO
+ (void)setBaseSDKLogEnabled:(BOOL)bFlag;

/// 设置是否在console输出界面库的log信息
+ (void)setUISDKLogEnabled:(BOOL)bFlag;

/**
 * 生成埋点信息
 * strCallTime         – 当前时间
 * strOrderNum         – 申请单号
 * iActionId           – 提交给app的那张照片对应的动作编号/若活体动作失败，则返回当前活体动作编号
 * strResultFinal      – 最终返给app的结果
 * strSdkPackage       – 包名
 * strDeviceType       – 设备类型
 * strDeviceVersion    – 系统版本
 * strAppVersion       – 应用版本
 * strSdkVersion       – Sdk版本
 */
+ (NSString *)getLogsWithStrCallTime:(NSString *)strCallTime
                           strOrderNum:(NSString *)strOrderNum
                             iActionId:(int)iActionId
                        strResultFinal:(NSString *)strResultFinal
                         strSdkPackage:(NSString *)strSdkPackage
                         strDeviceType:(NSString *)strDeviceType
                      strDeviceVersion:(NSString *)strDeviceVersion
                         strAppVersion:(NSString *)strAppVersion
                         strSdkVersion:(NSString *)strSdkVersion;
@end


NS_ASSUME_NONNULL_END
