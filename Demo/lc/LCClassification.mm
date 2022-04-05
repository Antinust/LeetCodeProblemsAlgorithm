//
//  LCClassification.m
//  Demo
//
//  Created by zcc_imac on 2022/4/5.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "LCClassification.h"
#import "LCSolutionImpl.h"


@implementation LCClassification

- (instancetype)init
{
    self = [super init];
    if (self) {
        [self test_DP];
    }
    return self;
}


//MARK: - DP
- (void)test_DP {
    [self test_FindNumberOfLIS];
}

- (void)test_FindNumberOfLIS {
//    vector<int> vec = {1,2,4,3,5,4,7,2};
    vector<int> vec = {1,3,2};
    FindNumberOfLIS::Solution *so = new FindNumberOfLIS::Solution();
    int ret = so->findNumberOfLIS(vec);
    NSLog(@"ret:%d", ret);
}



@end
