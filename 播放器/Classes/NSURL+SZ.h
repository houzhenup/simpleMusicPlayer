//
//  NSURL+SZ.h
//  播放器
//


#import <Foundation/Foundation.h>

@interface NSURL (SZ)


/**
 获取streaming协议的url地址
 */
- (NSURL *)streamingURL;


- (NSURL *)httpURL;

@end
