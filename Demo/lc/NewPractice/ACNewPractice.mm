//
//  ACNewPractice.m
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/28.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "ACNewPractice.h"
#import "SpiralOrder.hpp"

@implementation ACNewPractice
- (instancetype)init {
    self = [super init];
    if (self) {
        [self testForLC_SpiralOrder];
    }
    return self;
}

- (void)testForLC_SpiralOrder {
    SpiralOrder::Solution *sol = new SpiralOrder::Solution();
//    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    sol->spiralOrder(matrix);
}

@end
