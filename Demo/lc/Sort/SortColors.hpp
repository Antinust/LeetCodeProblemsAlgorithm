//
//  SortColors.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/13.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef SortColors_hpp
#define SortColors_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace SortColors {

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroCnt = 0;
        int oneCnt = 0;
        int twoCnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroCnt++;
            } else if (nums[i] == 1) {
                oneCnt++;
            } else {
                twoCnt++;
            }
        }
        int index = 0;
        for (; index < zeroCnt; index++) {
            nums[index] = 0;
        }
        
        for (; index < zeroCnt + oneCnt; index++) {
            nums[index] = 1;
        }
        for (; index < nums.size(); index++) {
            nums[index] = 2;
        }
    }
};

}


#endif /* SortColors_hpp */
