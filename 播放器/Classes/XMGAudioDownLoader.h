//
//  XMGAudioDownLoader.h
//  播放器
//
//  Created by 小码哥 on 2017/1/15.
//  Copyright © 2017年 xmg. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol XMGAudioDownLoaderDelegate <NSObject>

- (void)downLoading;

@end


@interface XMGAudioDownLoader : NSObject


@property (nonatomic, weak) id<XMGAudioDownLoaderDelegate> delegate;

@property (nonatomic, assign) long long totalSize;
@property (nonatomic, assign) long long loadedSize;
@property (nonatomic, assign) long long offset;
@property (nonatomic, strong) NSString *mimeType;


- (void)downLoadWithURL:(NSURL *)url offset:(long long)offset;


@end
