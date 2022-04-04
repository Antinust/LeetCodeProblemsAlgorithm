//
//  DuMediaABTest.h
//  Demo
//
//  Created by Zhuo,Chuncai on 2019/4/11.
//  Copyright © 2019 Zhuo,Chuncai. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DMABTestProviderProtocol <NSObject>

- (BOOL)experimentBoolValueForKey:(NSString *)key defaultValue:(id)value;

- (id)experimentIDValueForKey:(NSString *)key defaultValue:(id)value;

@end

@interface DuMediaABTest : NSObject

@property (nonatomic, weak) id<DMABTestProviderProtocol> experimentProvider;

+ (DuMediaABTest *)sharedInstance;

- (BOOL)experimentFlagForKey:(NSString *)key defaultValue:(id)value;

@end

NS_ASSUME_NONNULL_END
