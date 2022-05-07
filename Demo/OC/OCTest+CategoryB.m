//
//  OCTest+CategoryB.m
//  Demo
//
//  Created by zcc_imac on 2022/5/7.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "OCTest+CategoryB.h"

@implementation OCTest (CategoryB)

+ (void)load {
    NSLog(@"%s %@", __func__, self);
}

+ (void)initialize {
    NSLog(@"%s %@", __func__, self);
}

+ (void)printClassName {
    NSLog(@"%s %s", __func__, object_getClassName(self));
}

@end
