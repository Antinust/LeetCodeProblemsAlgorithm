//
//  CopyTest.m
//  Demo
//
//  Created by zcc_imac on 2022/4/24.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "CopyTest.h"

@interface CopyTest ()

@property (copy) NSString *testStr;

@end

@implementation CopyTest

- (instancetype)init
{
    self = [super init];
    if (self) {
        
        NSString *str1 = @"str1";
        NSString *str2 = @"str2";
        NSLog(@"str1:%p test2:%p", str1, str2);

        self.testStr = str1;

        NSString *test2 = self.testStr;
        NSLog(@"test1:%p test2:%p", self.testStr, test2);

        self.testStr = str2;
//        test2 = str2;
        NSLog(@"test1:%p test2:%p", self.testStr, test2);
    }
    return self;
}

@end
