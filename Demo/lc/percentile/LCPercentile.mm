//
//  LCPercentile.m
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/1.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "LCPercentile.h"
#import "MedianOfTwoSortedArrays.hpp"

@implementation LCPercentile

- (instancetype)init {
    self = [super init];
    if (self) {
        [self testForLC_MedianOfTwoSortedArrays];
    }
    return self;
}

- (void)testForLC_MedianOfTwoSortedArrays {
//    vector<int> a = {1,2,3};
//    vector<int> b = {4,5,6,7,8};
    
//    vector<int> a = {1};
//    vector<int> b = {2,3,4,5,6}; //,7,8
    
    vector<int> a = {1,2,4,5,6};
    vector<int> b = {3}; //,7,8
    MedianOfTwoSortedArrays::Solution *sol = new MedianOfTwoSortedArrays::Solution();
    sol->findMedianSortedArrays(a, b);
}

@end
