//
//  LCFind.m
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/12.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "LCFind.h"
#import "FindTheDuplicateNumber.hpp"
#import "FirstMissingPositive.hpp"
#import "FindFirstAndLastPosOfElemInSortedArray.hpp"

@implementation LCFind

- (instancetype)init {
    self = [super init];
    if (self) {
        [self testForLC_Find];
//        [self testForLC_FirstMissingPositive];
        [self testForLC_FindFirstAndLastPosOfElemInSortedArray];
    }
    return self;
}

- (void)testForLC_FindFirstAndLastPosOfElemInSortedArray {
    FindFirstAndLastPosOfElemInSortedArray::Solution *sol =
                    new FindFirstAndLastPosOfElemInSortedArray::Solution();
    vector<int> nums = {2,2};
    sol->searchRange(nums, 2);
}

- (void)testForLC_FirstMissingPositive {
    FirstMissingPositive::Solution *sol = new FirstMissingPositive::Solution();
    vector<int> nums = {1,1};
//    [3,4,-1,1]
    sol->firstMissingPositive(nums);
}

- (void)testForLC_Find {
    FindTheDuplicateNumber::Solution *sol = new FindTheDuplicateNumber::Solution();
    vector<int> nums = {1,3,4,2,2};
    sol->findDuplicate(nums);
}


@end
