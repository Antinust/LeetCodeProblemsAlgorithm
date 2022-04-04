//
//  JumpGame2.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/14.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef JumpGame2_hpp
#define JumpGame2_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace JumpGame2 {
/*
 1. 若index+range >= nums.size 则ret cnt；
    0 ~ range-1中遍历j 若有j+range_j > index+range的 cnt++，记录Max_range值
    
    从index+range 遍历到新的Max_range值，重复上一步
 */

class Solution {
    
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int totalCnt = (int)nums.size() - 1;
        int range = nums[0];
        int index = 0;
        int jumpedCnt = 0;
        while (index < totalCnt) {
            jumpedCnt++;
            int maxRangeReachable = index + range;
            for (int i = index + 1; i <= index + range && i <= totalCnt; i++) {
                if (nums[i] + i > maxRangeReachable) {
                    maxRangeReachable = nums[i] + i;
                }
            }
//            if (maxRangeReachable >= totalCnt) {
//                break;
//            }
            index += range;
            range = maxRangeReachable - index;
        }
        return jumpedCnt;
    }
};

}

#endif /* JumpGame2_hpp */
