//
//  BurstBalloons.h
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/7.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef BurstBalloons_h
#define BurstBalloons_h
#include "PublicCommon.h"

namespace  BurstBalloons {
/*
 1. 思路对了，就可以1A
 定义dp[i][j]为 以i, j 为开区间内所能得到的最大的硬币数，k为最后刺破气球的位置，则有如下转移方程式
 
 dp[i][j]= max(dp[i][k] + dp[k][j] + v[i]*v[k]*v[j])
 
 最后结果为dp[0][len+1]，给v数组前后插入一个元素1；遍历的时候i需要从大到小遍历[len-1, 0]，j为i+2到len+1，k为[i+1, j)
 
 */
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        }
        vector<int> v;
        v.push_back(1);
        for (int i = 0; i < nums.size(); i++) {
            v.push_back(nums[i]);
        }
        v.push_back(1);
        
        vector<vector<int>> dp(v.size(), vector<int>(v.size(), 0));
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 2; j < len + 2; j++) {
                int tempMax = INT_MIN;
                for (int k = i + 1; k < j; k++) {
                    tempMax = max(tempMax, dp[i][k] + dp[k][j] + v[i]*v[k]*v[j]);
                }
                dp[i][j] = tempMax;
            }
        }
        return dp[0][len + 1];
    }
};

}

#endif /* BurstBalloons_h */
