//
//  FindDisappearedNumbersInArray.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/20.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef FindDisappearedNumbersInArray_hpp
#define FindDisappearedNumbersInArray_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace FindDisappearedNumbersInArray {
/*
 1. 让下标为i的位置，存储值为i+1的，元素， i=[0, n-1]
 2. 遍历数组，当下标为i的位置存储的元素值不为i+1，时，交换num[i] num[num[i]-1]的值，
 直到下标为i的位置存储的元素值为i+1，或者num[i] num[num[i]-1]相等时
 */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>vec;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] - 1 != i && nums[nums[i] - 1] != nums[i]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - 1 != i) {
                vec.push_back(i + 1);
            }
        }
        return vec;
    }
};

}

#endif /* FindDisappearedNumbersInArray_hpp */
