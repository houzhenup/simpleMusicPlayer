//
//  ViewController.m
//  播放器
//
//  Created by 小码哥 on 2017/1/14.
//  Copyright © 2017年 xmg. All rights reserved.
//

#import "ViewController.h"
#import "XMGRemotePlayer.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UILabel *playTimeLabel;
@property (weak, nonatomic) IBOutlet UILabel *totalTimeLabel;

@property (weak, nonatomic) IBOutlet UIProgressView *loadPV;

@property (nonatomic, weak) NSTimer *timer;
@property (weak, nonatomic) IBOutlet UISlider *playSlider;

@property (weak, nonatomic) IBOutlet UIButton *mutedBtn;
@property (weak, nonatomic) IBOutlet UISlider *volumeSlider;


@end

@implementation ViewController

- (NSTimer *)timer {
    if (!_timer) {
        NSTimer *timer = [NSTimer timerWithTimeInterval:1 target:self selector:@selector(update) userInfo:nil repeats:YES];
        [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSRunLoopCommonModes];
        _timer = timer;
    }
    return _timer;
}


- (void)viewDidLoad {
    [super viewDidLoad];
    [self timer];
}


- (void)update {
    
//    NSLog(@"--%zd", [XMGRemotePlayer shareInstance].state);
    // 68
    // 01:08
    // 设计数据模型的
    // 弱业务逻辑存放位置的问题
    self.playTimeLabel.text =  [XMGRemotePlayer shareInstance].currentTimeFormat;
    self.totalTimeLabel.text = [XMGRemotePlayer shareInstance].totalTimeFormat;
    
    self.playSlider.value = [XMGRemotePlayer shareInstance].progress;
    
    self.volumeSlider.value = [XMGRemotePlayer shareInstance].volume;
    
    self.loadPV.progress = [XMGRemotePlayer shareInstance].loadDataProgress;
    
    self.mutedBtn.selected = [XMGRemotePlayer shareInstance].muted;

}


- (IBAction)play:(id)sender {
    
    // http://120.25.226.186:32812/resources/videos/minion_01.mp4
    NSURL *url = [NSURL URLWithString:@"http://120.25.226.186:32812/resources/videos/minion_01.mp4"];
    [[XMGRemotePlayer shareInstance] playWithURL:url isCache:YES];
    
}
- (IBAction)pause:(id)sender {
    [[XMGRemotePlayer shareInstance] pause];
}

- (IBAction)resume:(id)sender {
    [[XMGRemotePlayer shareInstance] resume];
}
- (IBAction)kuaijin:(id)sender {
    [[XMGRemotePlayer shareInstance] seekWithTimeDiffer:15];
}
- (IBAction)progress:(UISlider *)sender {
    [[XMGRemotePlayer shareInstance] seekWithProgress:sender.value];
}
- (IBAction)rate:(id)sender {
    [[XMGRemotePlayer shareInstance] setRate:2];
}
- (IBAction)muted:(UIButton *)sender {
    sender.selected = !sender.selected;
    [[XMGRemotePlayer shareInstance] setMuted:sender.selected];
}
- (IBAction)volume:(UISlider *)sender {
    [[XMGRemotePlayer shareInstance] setVolume:sender.value];
}

@end
