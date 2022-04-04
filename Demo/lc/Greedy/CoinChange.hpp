//
//  CoinChange.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/17.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef CoinChange_hpp
#define CoinChange_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace CoinChange {
/*
 1. 利用dp + dfs: dp[i]表示容量为i所需要的最小硬币数
 dp[i] = min(dp[i-coins[j]] + 1, dp[i]);
 */

class Solution {
public:
    int recursiveTraversal(vector<int>& coins, vector<int>& dp, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return -1;
        }
        if (dp[amount] != -2) {
            return dp[amount];
        }
        int64_t minValue = LONG_LONG_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int subAmount = amount - coins[i];
            if (subAmount >= 0) {
                if (dp[subAmount] == -2) {
                    int64_t nums = recursiveTraversal(coins, dp, subAmount);
                    if (nums >= 0) {
                        minValue = std::min(nums + 1, minValue);
                    } else {
                        dp[subAmount] = (int)nums;
                    }
                } else if (dp[subAmount] != -1) {
                    minValue = std::min((int64_t)(dp[subAmount] + 1), minValue);
                }
            }
        }
        dp[amount] = (int)minValue;
        return (int)minValue;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp;
        for (int i = 0; i <= amount; i++) {
            dp.push_back(-2);
        }
        dp[0] = 0;
        return recursiveTraversal(coins, dp, amount);
    }
};

}



#endif /* CoinChange_hpp */
