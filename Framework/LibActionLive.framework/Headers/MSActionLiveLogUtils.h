//
//  MSActionLiveLogUtils.h
//  LibActionLive
//
//  Created by 张杨 on 2022/8/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 隐藏Log
/// UI库专用Log
#define MSFaceLiveSDKLog(format,...) [MSActionLiveLogUtils customLogWithFunction1:__PRETTY_FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__]]
/// 算法库专用Log
#define MSFaceLiveSDKLog2(format,...) [MSActionLiveLogUtils customLogWithFunction2:__PRETTY_FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__]]
/// 常显Log
#define MSLive_Log(format, ...) printf("动作活体:【Method】: %s %s\n" , __PRETTY_FUNCTION__, [[NSString stringWithFormat:(format), ##__VA_ARGS__] UTF8String])

@interface MSActionLiveLogUtils : NSObject

// 设置算法日志输出状态
+ (void)setBaseLogEnable:(BOOL)enable;

// 设置界面库日志输出状态
+ (void)setUILogEnable:(BOOL)enable;

// 日志输出方法
+ (void)customLogWithFunction1:(const char *)function lineNumber:(int)lineNumber formatString:(NSString *)formatString;
+ (void)customLogWithFunction2:(const char *)function lineNumber:(int)lineNumber formatString:(NSString *)formatString;

@end

NS_ASSUME_NONNULL_END
