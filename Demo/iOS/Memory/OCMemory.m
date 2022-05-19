//
//  OCMemory.m
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/5/17.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "OCMemory.h"
#import <objc/runtime.h>

extern void _objc_autoreleasePoolPrint();

@implementation OCMemory
- (instancetype)init {
    self = [super init];
    if (self) {
        [self testAutoreleasePool];
    }
    return self;
}

- (void)testAutoreleasePool {
    NSLog(@"testAutoreleasePool begin\r\n");
    //pool1，里面添加1个自动释放对象
    @autoreleasepool {

        NSObject *obj = [[NSObject alloc] autorelease];

        //pool2，里面添加3个自动释放对象
        @autoreleasepool {

            NSInteger count = 3;
            for(NSInteger i=0; i<count; i++){

                NSObject *obj = [[NSObject alloc] autorelease];
            }

            //pool3，里面添加2个自动释放对象
            @autoreleasepool {

                NSInteger count = 2;
                for(NSInteger i=0; i<count; i++){

                    NSObject *obj = [[NSObject alloc] autorelease];
                }

                //创建完三个pool后打印
                _objc_autoreleasePoolPrint();
            }
            
            //超出pool3的作用域时打印
            _objc_autoreleasePoolPrint();
        }
        
        //超出pool2的作用域时打印
        _objc_autoreleasePoolPrint();
    }
    //超出pool1作用域打印
    _objc_autoreleasePoolPrint();
    
    NSLog(@"\r\n");
    NSLog(@"testAutoreleasePool end");

}

@end
