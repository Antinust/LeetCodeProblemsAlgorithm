//
//  CountingBits.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/14.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef CountingBits_hpp
#define CountingBits_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace CountingBits {

/*
 1. dp: 通过计算示例 可以找到迭代的规律， 奇数的1的个数比它小1的偶数的个数 多1
    偶数的1的个数 为偶数/2的1的个数  偶数/2 为奇数或偶数，若为偶数则可以继续/2，若为奇数在上一轮已经求出

 */


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> vec;
        vec.push_back(0);
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                vec.push_back(vec[i - 1] + 1);
            } else {
                vec.push_back(vec[i / 2]);
            }
        }
        return vec;
    }
};

}

#endif /* CountingBits_hpp */
