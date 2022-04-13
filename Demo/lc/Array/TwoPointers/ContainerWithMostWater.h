//
//  ContainerWithMostWater.h
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/12.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef ContainerWithMostWater_h
#define ContainerWithMostWater_h
#include "PublicCommon.h"
namespace ContainerWithMostWater {
/*
 1. 移动l, r中较短的那根木棍即可，
    因为移动长的那根的话 高度不变，宽度减小 故一定无更大的面积
 
 */
class Solution {
public:
    int maxArea(vector<int>& h) {
        int len = h.size();
        int l = 0;
        int r = len - 1;
        int maxVal = 0;
        while (l < r) {
            maxVal = max(maxVal, min(h[l], h[r]) * (r - l));
            // printf("max:%d\r\n", maxVal);
            // 移动l,r中较短的那根的长度
            if (h[l] < h[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxVal;
    }
};

}

#endif /* ContainerWithMostWater_h */
