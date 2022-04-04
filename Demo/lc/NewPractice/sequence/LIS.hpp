//
//  LIS.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/28.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef LIS_hpp
#define LIS_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace LIS {

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int totalCnt = (int)nums.size();
        // 区分vec() vs vec{}，一个是批量赋值，一个是逐个赋值
        vector<int>maxL (totalCnt, 1);
        int maxLength = 1;
        for (int i = 1; i < totalCnt; i++) {
            int max = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    max = std::max(max, maxL[j] + 1);
                }
            }
            maxL[i] = max;
            maxLength = std::max(max, maxLength);
        }
        return maxLength;
    }
};

}

#endif /* LIS_hpp */
