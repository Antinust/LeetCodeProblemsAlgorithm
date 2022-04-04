//
//  DuMediaABTest.m
//  Demo
//
//  Created by Zhuo,Chuncai on 2019/4/11.
//  Copyright © 2019 Zhuo,Chuncai. All rights reserved.
//

#import "DuMediaABTest.h"

@implementation DuMediaABTest

+ (DuMediaABTest *)sharedInstance
{
    static DuMediaABTest *instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[DuMediaABTest alloc] init];
    });
    return instance;
}

- (BOOL)experimentFlagForKey:(NSString *)key defaultValue:(id)value {
    if ([self.experimentProvider respondsToSelector:@selector(experimentBoolValueForKey:defaultValue:)]) {
        return [self.experimentProvider experimentBoolValueForKey:key defaultValue:value];
    }
    return [value boolValue];
}

@end
