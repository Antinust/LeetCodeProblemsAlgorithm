//
//  LongestIncreasingSubsequence.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/15.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef LongestIncreasingSubsequence_hpp
#define LongestIncreasingSubsequence_hpp

#include <stdio.h>

#include "PublicCommon.h"

namespace LongestIncreasingSubsequence {
/*
 1. dp:
 定义dp[i]为 已i结尾的最大子序列长度
 dp[i] = max(dp[j]) + 1 ；  0 <= j < i
 
 不分 num[i] > or < num[j];  在第二层循环中判断，因为 num[i] > num[i-1]，不一定表示从i-1到i这条路径得到的值最大，可能从i-2到的更大
 
 result = max(dp[i])
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }
        int dp[2501] = {0};
        int maxLen = 1;
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j <= i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            maxLen = std::max(maxLen, dp[i]);
        }
        return maxLen;
    }
};

}


#endif /* LongestIncreasingSubsequence_hpp */
