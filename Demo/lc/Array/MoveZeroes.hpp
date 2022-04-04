//
//  MoveZeroes.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/16.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef MoveZeroes_hpp
#define MoveZeroes_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace MoveZeroes {
/*
 1. 记录到当前位置为止，前面已经出现的0的个数n，然后向前移动n位即可
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCnt = 0;
        int totalCnt = (int)nums.size() - 1;
        for (int i = 0; i <= totalCnt; i++) {
            if (nums[i] == 0) {
                zeroCnt++;
            } else {
                nums[i - zeroCnt] = nums[i];
            }
        }
        for (int i = totalCnt; i > totalCnt - zeroCnt ; i--) {
            nums[i] = 0;
        }
    }
};
}

#endif /* MoveZeroes_hpp */
