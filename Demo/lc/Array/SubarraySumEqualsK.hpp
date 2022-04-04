//
//  SubarraySumEqualsK.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/19.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef SubarraySumEqualsK_hpp
#define SubarraySumEqualsK_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace SubarraySumEqualsK {
/*
 1. 定义前缀和数组： pre[i] 为从0开始以i结尾的所有元素的和
 则 pre[i] = pre[i-1] + nums[i]
 则[j..i]这个子数组和为k, 这个条件我们可以转化为 k = pre[i] - pre[j-1]  => pre[j-1] = pre[i] - k
 
 所以我们考虑以i结尾的和为k的连续子数组个数时只要统计有多少个前缀和为 pre[i]-k 的 pre[j] 即可

 用hashMap记录 多少个pre[j]即可，求出所有的值即可
 

 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];
            if (mp.find(pre - k) != mp.end()) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};


}

#endif /* SubarraySumEqualsK_hpp */
