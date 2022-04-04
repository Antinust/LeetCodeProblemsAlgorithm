//
//  FirstMissingPositive.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/12.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef FirstMissingPositive_hpp
#define FirstMissingPositive_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace FirstMissingPositive {
/*
 1. 将数组视为哈希表
 若n为数组元素个数，缺失的最小正的元素，一定在1 ~ n+1中间，因为n个元素最多只能填满1到n+1里面的n个元素，必定缺少一个元素。
 
 建立一个数组元素到下标的映射，比如元素值为1，则应该放到下标为0的位置(n->n-1)，若元素值不在1~n+1，则不交换
 
 因每次交换都让一个元素处于正确位置上，故最多需要交换n次，因此时间复杂度=O(n);元素全部交换完成后，第一个下标与元素值不匹配的即为最小缺失的
 
 */
class Solution {
public:
    
    int firstMissingPositive(vector<int>& nums) {
        int totalCnt = (int)nums.size();
        
        for (int i = 0; i < totalCnt; i++) {
            // badcase [1, 1]，需要判断，若相等需要退出循环
            while ((nums[i] >= 1 && nums[i] <= totalCnt)
                   && nums[i] != i + 1
                   && nums[i] != nums[nums[i] - 1]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        for (int i = 0; i < totalCnt; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return totalCnt + 1;
    }
};

}

#endif /* FirstMissingPositive_hpp */
