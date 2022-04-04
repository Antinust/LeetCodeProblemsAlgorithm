//
//  ProductOfArrayExceptSelf.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/23.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef ProductOfArrayExceptSelf_hpp
#define ProductOfArrayExceptSelf_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace ProductOfArrayExceptSelf {
/*
 1. 分别使用一个数组L存储 当前小于index的所有元素的乘积
    数组R存储 当前大于index的所有元素的乘积
 
 
 2. 空间复杂度为O(1)的做法
    这种方法的唯一变化就是我们没有构造 R 数组。而是用一个遍历来跟踪右边元素的乘积。并更新数组 answer[i]=answer[i]*Ranswer[i]=answer[i]∗R。然后 RR 更新为 R=R*nums[i]R=R∗nums[i]，其中变量 RR 表示的就是索引右侧数字的乘积。

 
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left;
        vector<int> right;

        vector<int> vec;
        left.push_back(1);
        right.push_back(1);
        for (int i = 1; i < nums.size(); i++) {
            left.push_back(left[i - 1] * nums[i - 1]);
            right.push_back(1);
        }
        for (int i = (int)nums.size() - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < nums.size(); i++) {
            vec.push_back(left[i] * right[i]);
        }
        return vec;
    }
};

}

#endif /* ProductOfArrayExceptSelf_hpp */
