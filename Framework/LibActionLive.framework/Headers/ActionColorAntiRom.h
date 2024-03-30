//
//  ActionColorAntiRom.h
//  LibActionLive
//
//  Created by 张杨 on 2022/12/3.
//  炫彩Rom攻击检测工具

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 炫彩Rom攻击检测工具
 * 使用方式：
 * 1.炫彩开始时调用start方法，开始检测，注意一次识别只可调用一次
 * 2.炫彩阶段实时调用inputWithImage方法输入图像帧数据。
 * 3.炫彩结束后，调用getResult方法获取检测结果
 *
 */

@interface ActionColorAntiRom : NSObject

/// 开始检测
+ (void)start;

/// 输入图像数据
/// - Parameters:
///   - image: 图像数据
///   - colorSequence: 颜色序列编号
+ (void)inputWithImage:(UIImage *)image
         colorSequence:(int)colorSequence;

/// 获取检测结果
+ (double)getResult;

@end

NS_ASSUME_NONNULL_END
