//
//  LCGreedy.m
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/17.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "LCGreedy.h"
#import "CoinChange.hpp"

@implementation LCGreedy

- (instancetype)init {
    self = [super init];
    if (self) {
        [self testForLC_coinChange];
    }
    return self;
}

- (void)testForLC_coinChange {
    CoinChange::Solution *sol = new CoinChange::Solution();
    vector<int> coins = {186,419,83,408};
    int amount = 6249;
//    vector<int> coins = {1, 2, 5};
//    int amount = 11;
    sol->coinChange(coins, amount);
}


@end
