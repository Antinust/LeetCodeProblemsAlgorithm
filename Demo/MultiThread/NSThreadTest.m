//
//  NSThreadTest.m
//  Demo
//
//  Created by zcc_imac on 2022/5/10.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "NSThreadTest.h"
#import <UIKit/UIKit.h>

@interface NSThreadTest () {
    
}

@property NSThread *mThread;
@property bool keepRunning;
@property dispatch_queue_t queue;
@end

@implementation NSThreadTest

- (instancetype)init
{
    self = [super init];
    if (self) {
        _keepRunning = true;
        [self testGCD_once];
        [self testDispatchMain];
        [self testMainQueueAndMainThread];
        [self asyncAndGlobalQueue];
        _queue = dispatch_queue_create("gcd_test_serial_q", DISPATCH_QUEUE_SERIAL);
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

//MARK: - test GCD
- (void)testGCD_once {
    NSLog(@"once:%lu %lu", ((uintptr_t)0), (~(uintptr_t)0));
    NSLog(@"test");
}

- (void)testGCD_serialQueue {
    NSLog(@"1");
    dispatch_async(self.queue, ^{
        NSLog(@"2");
        dispatch_sync(self.queue, ^{
            NSLog(@"3");
        });
        NSLog(@"4");
    });
    NSLog(@"5");
}

- (void)asyncAndGlobalQueue {
    NSLog(@"begin --- main:%d",[NSThread isMainThread]);
    
    dispatch_queue_t globalQueue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    for (NSInteger index = 0; index < 10 ;index ++) {
        //dispatch_sync，本应该让block里面的内容在globalQueue执行的，却在主线程执行了
        dispatch_sync(globalQueue, ^{
            NSLog(@"index:%ld --- %@ main:%d", index, [NSThread currentThread], [NSThread isMainThread]);
        });
    }
    NSLog(@"end --- main:%d",[NSThread isMainThread]);
}

- (void)testMainQueueAndMainThread {
    // dispatch_queue_t queue = dispatch_queue_create(dispatch_queue_get_label(dispatch_get_main_queue()), nil);  //这种方式会导致label相同
    dispatch_queue_t queue = dispatch_queue_create("com.apple.main-thread", nil);
    NSLog(@"main_q:%s", dispatch_queue_get_label(dispatch_get_main_queue()));
    
    dispatch_sync(queue, ^{
        // 当前代码,在主线程,而不在主队列
        NSLog(@"isMainThread:%d isMainQ:%d", [NSThread isMainThread], dispatch_queue_get_label(DISPATCH_CURRENT_QUEUE_LABEL) == dispatch_queue_get_label(dispatch_get_main_queue()));
//        if ([NSThread isMainThread]) {
//            [self addRedView]; // 执行这行, 会崩溃
//        } else {
//            dispatch_async(dispatch_get_main_queue(), ^{
//                [self addRedView];
//            });
//        }
 
        if (dispatch_queue_get_label(DISPATCH_CURRENT_QUEUE_LABEL) == dispatch_queue_get_label(dispatch_get_main_queue())) {
            [self addRedView];
        } else {
            dispatch_async(dispatch_get_main_queue(), ^{
                [self addRedView]; // 执行这行, 不会崩溃
            });
        }
 
    });
 
}
// 假设这个方法是系统的某个方法, 要求必须在主线程 && 必须是主队列, 否则触发crash
- (void)addRedView {
 
    if ([NSThread isMainThread]) {
 
    } else {
        NSLog(@"不是主线程");
        NSAssert(NO, @"不是主线程");
    }
    if (dispatch_queue_get_label(DISPATCH_CURRENT_QUEUE_LABEL) == dispatch_queue_get_label(dispatch_get_main_queue())) {
 
    } else {
        NSLog(@"不是主队列");
        NSAssert(NO, @"不是主队列");
    }
    UIView *redView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 100, 40)];
    redView.backgroundColor = [UIColor redColor];
//    [self.view addSubview:redView];
}

- (void)testDispatchMain {
    //异步加入到全局并发队列中
     dispatch_async(dispatch_get_global_queue(0, 0), ^{
    //异步加入到主队列中
        dispatch_async(dispatch_get_main_queue(), ^{
            NSLog(@"main thread: %d", [NSThread isMainThread]);
            NSLog(@"%@",[NSThread currentThread]);
            // 判断是否是主队列
//            void *value = dispatch_get_specific(key);//返回与当前分派队列关联的键的值。
            NSLog(@"main queue: %d", dispatch_queue_get_label(DISPATCH_CURRENT_QUEUE_LABEL) == dispatch_queue_get_label(dispatch_get_main_queue()));
        });
    });
    NSLog(@"dispatch_main会堵塞主线程");
//    dispatch_main();
    NSLog(@"查看是否堵塞主线程");
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
