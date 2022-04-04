//
//  ShortestUnsortedContinuousSubarray.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/15.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef ShortestUnsortedContinuousSubarray_hpp
#define ShortestUnsortedContinuousSubarray_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace ShortestUnsortedContinuousSubarray {

/*
 1. sort: 把原数组 拷贝一份后 排序，然后比较两个数组的 不同部分，记录 起始位置 即可
 2. 设左侧和右侧都是 有序的，中间部分是无序，则 min(中间) > 左侧，max(中间) < 右侧；
    从右到左遍历，找到最近比min大的那个
    从左到右遍历，找到最近比max小的那个
 */

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sortedVec = nums;
        int totalCnt = (int)nums.size() - 1;

        int begin = 0;
        int end = -1;
        int min = nums[totalCnt];
        int max = nums[0];
        for (int i = 0; i <= totalCnt; i++) {
            // deal max
            if (nums[i] < max) {
                end = i;
            } else {
                max = nums[i];
            }
            
            // deal min
            if (nums[totalCnt - i] > min) {
                begin = totalCnt - i;
            } else {
                min = nums[totalCnt - i];
            }
        }
        return end - begin + 1;
    }
};

//class Solution {
//public:
//    int findUnsortedSubarray(vector<int>& nums) {
//        vector<int> sortedVec = nums;
//        std::sort(sortedVec.begin(), sortedVec.end());
//        int totalCnt = (int)nums.size() - 1;
//        int begin = 0;
//        int end = totalCnt;
//        while (begin <= totalCnt && nums[begin] == sortedVec[begin]) {
//            begin++;
//        }
//
//        while (end >= 0 && nums[end] == sortedVec[end]) {
//            end--;
//        }
//        return begin > totalCnt ? 0 : end - begin + 1;
//    }
//};

}


#endif /* ShortestUnsortedContinuousSubarray_hpp */
