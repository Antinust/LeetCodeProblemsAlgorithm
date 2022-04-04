//
//  LongestConsecutiveSequence.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/16.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef LongestConsecutiveSequence_hpp
#define LongestConsecutiveSequence_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace LongestConsecutiveSequence {
/*
 1. 注意查找的时候 剪枝，不要重复计算
 
 */

//class Solution {
//public:
//    int longestConsecutive(vector<int>& nums) {
//        unordered_set<int> num_set;
//        for (const int& num : nums) {
//            num_set.insert(num);
//        }
//        int longestStreak = 0;
//        for (const int& num : num_set) {
//            if (!num_set.count(num - 1)) {
//                int currentNum = num;
//                int currentStreak = 1;
//                while (num_set.count(currentNum + 1)) {
//                    currentNum += 1;
//                    currentStreak += 1;
//                }
//                longestStreak = max(longestStreak, currentStreak);
//            }
//        }
//        return longestStreak;
//    }
//};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set;
        for (int i = 0; i < nums.size(); i++) {
            set.insert(nums[i]);
        }
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            // target - 1 存在则不遍历，不存在则去遍历
            if (!set.count(nums[i] - 1)) {
                int tempCnt = 1;
                int target = nums[i] + 1;
                // 从连续的最小值开始遍历，一直到连续的最大的
                while (set.count(target++)) {
                    tempCnt++;
                }
                max = std::max(max, tempCnt);
            }
        }
        return max;
    }
};

}

#endif /* LongestConsecutiveSequence_hpp */
