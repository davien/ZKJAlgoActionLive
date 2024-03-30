//
//  Facexdet.h
//  LibFaceRecognition
//
//  Created by 张杨 on 2020/11/11.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface FaceState : NSObject

/// 人脸上半部是否遮挡
@property (nonatomic, assign) BOOL isFaceUpShelter;
/// 人脸下半部是否遮挡
@property (nonatomic, assign) BOOL isFaceDownShelter;
/// 人脸轮廓是否遮挡
@property (nonatomic, assign) BOOL isFaceOutLineShelter;
/// 是否张嘴
@property (nonatomic, assign) BOOL isOpenMouth;
/// 是否抬头
@property (nonatomic, assign) BOOL isFaceUp;
/// 是否低头
@property (nonatomic, assign) BOOL isFaceDown;
/// 是否左转
@property (nonatomic, assign) BOOL isFaceLeft;
/// 是否右转
@property (nonatomic, assign) BOOL isFaceRight;
/// 是否闭眼
@property (nonatomic, assign) BOOL isCloseEyes;
/// 人脸是否是大角度 (侧脸之类，有时左转右转判断不准确)
@property (nonatomic, assign) BOOL isFaceBigPose;
/// 人脸旋转角度 -180° 至 180°
@property (nonatomic, assign) int faceAngle;
/// 是否过爆
@property (nonatomic, assign) BOOL isTooLight;
/// 是否欠曝
@property (nonatomic, assign) BOOL isTooDark;
/// 是否模糊
@property (nonatomic, assign) BOOL isBlur;
/// 是否翻拍
@property (nonatomic, assign) BOOL isRemake;

@end

/// **************结果类**************
@interface FaceRecognizeResult : NSObject

/// RECT
@property (nonatomic, assign) int x;
@property (nonatomic, assign) int y;
@property (nonatomic, assign) int width;
@property (nonatomic, assign) int height;
/// Token
@property (nonatomic, copy) NSString *token;
/// 人脸检测分数
@property (nonatomic, assign) float faceScore;
/// 人脸坐标98点 CGPoint数组
@property (nonatomic, strong) NSMutableArray<NSValue *> *faceLmd98;
/// 人脸状态
@property (nonatomic, strong) FaceState *faceState;

@end



/// **************配置类**************

typedef enum {
    FacePower_Normal = 0,
    FacePower_High,
    FacePower_Low
} FacePowerMode;

@interface FaceQualityConfig : NSObject

/// 人脸遮挡判断开关 默认NO
@property (nonatomic, assign) BOOL faceShelterSwitch;
/// 人脸遮挡阈值 遮挡的概率值 越大越难判断为遮挡  越小容易判断为遮挡 默认0.5f
@property (nonatomic, assign) float faceShelterThr;
/// 光照检测 默认NO
@property (nonatomic, assign) BOOL isOpenLightDet;
/// 人脸模糊阈值 默认18
@property (nonatomic, assign) float faceBlurThr;
/// 屏幕翻拍检测开关 默认NO
@property (nonatomic, assign) BOOL isScreenDet;
/// 幕翻拍检测阈值 默认0.5f
@property (nonatomic, assign) float screenDetThr;
/// MNN能耗 默认正常能耗 FacePower_Normal
@property (nonatomic, assign) FacePowerMode power;

@end

@interface Facexdet : NSObject

/// 当前算法版本
+ (NSString *)currentVersion;

/// 人脸检测初始化 【双证书校验 debug包 && release包】
/// @param bundleDir Bundle资源路径 eg:[[NSBundle mainBundle] pathForResource:@"xxx" ofType:@"bundle"];
/// @brief faceQualityConfig 配置类
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
+ (int)initWithBundleDir:(NSString *)bundleDir;
+ (int)initWithBundleDir:(NSString *)bundleDir
       faceQualityConfig:(nullable FaceQualityConfig *)faceQualityConfig;


/// 人脸检测初始化【单证书校验】
/// @param bundleDir Bundle资源路径 eg:[[NSBundle mainBundle] pathForResource:@"xxx" ofType:@"bundle"];
/// @param licenseName 授权证书名称 eg:facex_record_ios
/// @brief faceQualityConfig 配置类
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
             licenseName:(NSString *)licenseName;
+ (int)initWithBundleDir:(NSString *)bundleDir
             licenseName:(nullable NSString *)licenseName
       faceQualityConfig:(nullable FaceQualityConfig *)faceQualityConfig;

/// 校验授权证书有效性
/// @param licenseName 授权证书名称 eg:facex_record_ios
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

/// 人脸检测反初始化,释放相关资源
+ (void)unInit;

/// 人脸检测-自动矫正图片
/// @param image 图片 - RGBA或RGB格式
/// @param completion 回调结果Result数组
+ (void)faceDetectWithImage:(UIImage *)image
                completion:(void (^)(NSArray<FaceRecognizeResult*> *results))completion;

/// 人脸检测
/// @param image 图片 - RGBA或RGB格式
/// @param correctImage 是否矫正图片 YES-不返回faceLmd98 NO-返回faceLmd98
/// @param completion 回调结果Result数组
+ (void)faceDetectWithImage:(UIImage *)image
               correctImage:(BOOL)correctImage
                 completion:(void (^)(NSArray<FaceRecognizeResult*> *results))completion;

/// 人脸1:1比对
/// @param featureTokenOne 人脸特征Token
/// @param featureTokenTwo 人脸特征Token
/// return 比对分数
+ (double)comparisonFace:(NSString *)featureTokenOne
            faceTokenTwo:(NSString *)featureTokenTwo;

/// 人脸1:N比对
/// @param featureTokenOne 人脸特征Token
/// @param featureOther 人脸特征Token数组
/// @param completion 回调结果Result数组
+ (void)recognizeFaces:(NSString *)featureTokenOne
          featureOther:(NSArray<NSString*> *)featureOther
            completion:(void (^)(NSArray<FaceRecognizeResult*> *results))completion;

/// 人脸纠正
/// @param image 待纠正图片 - RGBA或RGB格式
/// @param bestImagePath 转正图片存储路径
+ (void)getFrontFaceWithImage:(UIImage *)image
                bestImagePath:(NSString *)bestImagePath;

@end

NS_ASSUME_NONNULL_END
