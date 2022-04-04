//
//  NextPermutation.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/25.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef NextPermutation_hpp
#define NextPermutation_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace NextPermutation {
/*
 1. 从右向左 找到一个相邻的升序序列i，j，满足num[i] < num[j]，若找不到，则说明nextPermutation就是排序后的最小值
    找到i,j后，再从[j, end)中从后往前 找到最小的比num[i]大的元素，并交换；
    然后把j以后的元素 都按升序排序
 
 [1,3,2]
 [4,2,0,2,3,2,0]
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int totalCnt = (int)nums.size();
        if (totalCnt == 1) {
            return;
        }
        int j = totalCnt - 1;
        bool foundK = false;
        while (j >= 0) {
            // 每次循环i重新赋值
            int i = j - 1;
            if (i >= 0 && nums[i] < nums[j]) {
                for (int k = totalCnt - 1; k >= j; k--) {
                    if (nums[k] > nums[i]) {
                        std::swap(nums[k], nums[i]);
                        std::sort(nums.begin() + i + 1, nums.end());
                        foundK = true;
                        break;
                    }
                }
            }
            if (foundK) {
                break;
            }
            j--;
        }
        if (j < 0) {
            std::sort(nums.begin(), nums.end());
        }
    }
};

}

#endif /* NextPermutation_hpp */
