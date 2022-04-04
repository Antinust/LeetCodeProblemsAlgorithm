//
//  LCArray.m
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/16.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "LCArray.h"
#import "MoveZeroes.hpp"
#import "MaximumProductSubarray.hpp"
#import "SubarraySumEqualsK.hpp"
#import "ThreeSum.hpp"
#import "NextPermutation.hpp"

@implementation LCArray

- (instancetype)init {
    self = [super init];
    if (self) {
        [self testForLC_MoveZeroes];
        [self testForLC_maxProduct];
        [self testForLC_SubarraySumEqualsK];
        [self testForLC_ThreeSum];
        [self testForLC_NextPermutation];
    }
    return self;
}

- (void)testForLC_NextPermutation {
    NextPermutation::Solution *sol = new NextPermutation::Solution();
    vector<int> nums = {4,2,0,2,3,2,0};
    sol->nextPermutation(nums);
}

- (void)testForLC_ThreeSum {
    ThreeSum::Solution *sol = new ThreeSum::Solution();
    vector<int> nums = {0, 0, 0, 0, 0, 0, 0};
    sol->threeSum(nums);
}

- (void)testForLC_SubarraySumEqualsK {
    SubarraySumEqualsK::Solution *sol = new SubarraySumEqualsK::Solution();
//    int k = 11;
//    vector<int> nums = {3, 4, 7};
    vector<int> nums = {1,-1,0};
    int k = 0;
    sol->subarraySum(nums, k);
}



- (void)testForLC_maxProduct {
    MaximumProductSubarray::Solution *sol = new MaximumProductSubarray::Solution();
    vector<int> nums = {2,3,-2,4};
    sol->maxProduct(nums);
}

- (void)testForLC_MoveZeroes {
    MoveZeroes::Solution *sol = new MoveZeroes::Solution();
//    vector<int> nums = {2,3,1,1,4};
    vector<int> nums = {0,1,0,3,12};
    sol->moveZeroes(nums);
}


@end
