//
//  MaximumProductSubarray.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/17.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef MaximumProductSubarray_hpp
#define MaximumProductSubarray_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace MaximumProductSubarray {
/*
 1. dp[i] 表示以i为结尾 所能得到的最大乘积 iMax=std::max(iMax*num[i], num[i]);
    由于存在负数 会让之前得到的最大值 变成最小值，最小值变成最大值，所以需要记录iMin
    iMin=std::min(iMin*num[i], num[i]);
 2. 当负数出现的时候需要交换当前的Min和Max，再计算
 
 //badcase      2,-1,1,1

 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int maxProduct = nums[0];
        int iMax = nums[0];
        int iMin = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                std::swap(iMin, iMax);
            }
            iMax = std::max(iMax * nums[i], nums[i]);
            iMin = std::min(iMin * nums[i], nums[i]);
            if (iMax > maxProduct) {
                // 需要保存iMax，因为当出现负数，iMin与iMax交换时，会导致iMax丢失
                maxProduct = iMax;
            }
        }
        return maxProduct;
    }
};
}


#endif /* MaximumProductSubarray_hpp */
