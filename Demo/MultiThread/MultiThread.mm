//
//  MultiThread.m
//  Demo
//
//  Created by Zhuo,Chuncai on 2020/1/4.
//  Copyright © 2020 Zhuo,Chuncai. All rights reserved.
//

#import "MultiThread.h"
#import "H2O.hpp"

@implementation MultiThread
- (instancetype)init
{
    self = [super init];
    if (self) {
        [self test_h2o];
    }
    return self;
}

- (void)test_h2o {

}

- (void)test_fooBar {
    //    FooBar foobar =  FooBar(2);
        
    //    FooBar *foobar = new FooBar(2);
    //    foobar->foo(nullptr);
    //    foobar->foo(nullptr);
    //
    //    foobar->bar(nullptr);
    //    foobar->bar(nullptr);
}

@end
