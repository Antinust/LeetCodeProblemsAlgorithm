//
//  LCDP.m
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/14.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "LCDP.h"
#import "JumpGame.hpp"
#import "PerfectSquares.hpp"

@implementation LCDP

- (instancetype)init {
    self = [super init];
    if (self) {
        [self testForLC_JumpGame];
        [self testForLC_PerfectSquares];
    }
    return self;
}

- (void)testForLC_PerfectSquares {
    PerfectSquares::Solution *sol = new PerfectSquares::Solution();
    int n = 12;
    sol->numSquares(n);
}

- (void)testForLC_JumpGame {
    JumpGame::Solution *sol = new JumpGame::Solution();
//    vector<int> nums = {2,3,1,1,4};
    vector<int> nums = {3,2,1,0,4};
    sol->canJump(nums);
}


@end
