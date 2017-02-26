//
//  XMGRemotePlayer.h
//  播放器
//
//  Created by 小码哥 on 2017/1/14.
//  Copyright © 2017年 xmg. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 播放器的状态
 * 因为UI界面需要加载状态显示, 所以需要提供加载状态
 - XMGRemotePlayerStateUnknown: 未知(比如都没有开始播放音乐)
 - XMGRemotePlayerStateLoading: 正在加载()
 - XMGRemotePlayerStatePlaying: 正在播放
 - XMGRemotePlayerStateStopped: 停止
 - XMGRemotePlayerStatePause:   暂停
 - XMGRemotePlayerStateFailed:  失败(比如没有网络缓存失败, 地址找不到)
 */
typedef NS_ENUM(NSInteger, XMGRemotePlayerState) {
    XMGRemotePlayerStateUnknown = 0,
    XMGRemotePlayerStateLoading   = 1,
    XMGRemotePlayerStatePlaying   = 2,
    XMGRemotePlayerStateStopped   = 3,
    XMGRemotePlayerStatePause     = 4,
    XMGRemotePlayerStateFailed    = 5
};



@interface XMGRemotePlayer : NSObject

/** 单例对象 */
+ (instancetype)shareInstance;

/**
 根据一个url地址, 播放相关的远程音频资源

 @param url url地址
 @param isCache 是否需要缓存
 */
- (void)playWithURL:(NSURL *)url isCache:(BOOL)isCache;

/**
 暂停当前播放的音频资源
 */
- (void)pause;

/**
 继续播放音频资源
 */
- (void)resume;

/**
 停止播放音频资源
 */
- (void)stop;

/**
 快进/快退

 @param timeDiffer 跳跃的时间段
 */
- (void)seekWithTimeDiffer:(NSTimeInterval)timeDiffer;

/**
 播放指定的进度

 @param progress 进度信息
 */
- (void)seekWithProgress:(float)progress;



#pragma mark - 数据提供

/** 是否静音, 可以反向设置数据 */
@property (nonatomic, assign) BOOL muted;
/** 音量大小 */
@property (nonatomic, assign) float volume;
/** 当前播放速率 */
@property (nonatomic, assign) float rate;


/** 总时长 */
@property (nonatomic, assign, readonly) NSTimeInterval totalTime;
/** 总时长(格式化后的) */
@property (nonatomic, copy, readonly) NSString *totalTimeFormat;
/** 已经播放时长 */
@property (nonatomic, assign, readonly) NSTimeInterval currentTime;
/** 已经播放时长(格式化后的) */
@property (nonatomic, copy, readonly) NSString *currentTimeFormat;
/** 播放进度 */
@property (nonatomic, assign, readonly) float progress;
/** 当前播放的url地址 */
@property (nonatomic, strong, readonly) NSURL *url;
/** 加载进度 */
@property (nonatomic, assign, readonly) float loadDataProgress;
/** 播放状态 */
@property (nonatomic, assign, readonly) XMGRemotePlayerState state;

@end
