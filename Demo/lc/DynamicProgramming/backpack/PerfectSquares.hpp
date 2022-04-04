//
//  PerfectSquares.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/25.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef PerfectSquares_hpp
#define PerfectSquares_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace PerfectSquares {
/*
 1. 问题可以转化为 f[i] = 1 + min{f[i-j*j]}   j=[0, sqrt(i)]
 从i-j*j 到i只需要选中index=j的元素即可
 
 */
class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) {
            return 0;
        }
        vector<int> vec(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int sqrtI = sqrt(i);
            int min = n + 1;
            for (int j = 1; j <= sqrtI; j++) {
                min = std::min(min, vec[i-j*j]);
            }
            vec[i] = 1 + min;
        }
        return vec[n];
    }
};

}

#endif /* PerfectSquares_hpp */
