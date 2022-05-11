//
//  NSThreadTest.m
//  Demo
//
//  Created by zcc_imac on 2022/5/10.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "NSThreadTest.h"

@interface NSThreadTest () {
    
}

@property NSThread *mThread;
@property bool keepRunning;
@end

@implementation NSThreadTest

- (instancetype)init
{
    self = [super init];
    if (self) {
        _keepRunning = true;
        dispatch_async(dispatch_get_global_queue(0, 0), ^{
            [self initThread];
        });
        [self initThread];
    }
    return self;
}

+ (id)sharedInstance {
    static dispatch_once_t token;
    static NSThreadTest * instance;
    dispatch_once(&token, ^{
        instance = [[NSThreadTest alloc] init];
    });
    return instance;
}

- (void)repeat {
    static int cnt = 0;
    NSLog(@"repeat_cnt:%d", cnt++);
    if (cnt > 10) {
        _keepRunning = false;
    }
}

- (void)initThread {
    self.mThread = [[NSThread alloc] initWithTarget:self selector:@selector(repeat) object:nil];
    [self.mThread start];
    while (_keepRunning) {
        [[NSRunLoop currentRunLoop] addPort:[NSMachPort port] forMode:NSDefaultRunLoopMode];

        [[NSRunLoop currentRunLoop] runMode:NSDefaultRunLoopMode beforeDate:[NSDate distantFuture]];
        NSLog(@"keep_running");
//        [NSThread sleepForTimeInterval:0.01];
    }
}

- (void)stopRunning {
    
}

//MARK: - AFN2.0
+ (NSThread *)networkRequestThread {
    static NSThread *_networkRequestThread = nil;
    static dispatch_once_t oncePredicate;
    dispatch_once(&oncePredicate, ^{
        _networkRequestThread = [[NSThread alloc] initWithTarget:self selector:@selector(networkRequestThreadEntryPoint:) object:nil];
        [_networkRequestThread start];
    });

    return _networkRequestThread;
}

+ (void)networkRequestThreadEntryPoint:(id)__unused object {
    @autoreleasepool {
        [[NSThread currentThread] setName:@"AFNetworking"];

        NSRunLoop *runLoop = [NSRunLoop currentRunLoop];
        [runLoop addPort:[NSMachPort port] forMode:NSDefaultRunLoopMode];
        [runLoop run];
    }
}

@end
