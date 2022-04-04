//
//  LCBacktracking.m
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/19.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "LCBacktracking.h"
#import "Permutations.hpp"

@implementation LCBacktracking

- (instancetype)init {
    self = [super init];
    if (self) {
        [self testForLC_Permutations];
    }
    return self;
}

- (void)testForLC_Permutations {
    Permutations::Solution *sol = new Permutations::Solution();
    vector<int> nums = {1,2,3,4};
    sol->permute(nums);
}
@end
