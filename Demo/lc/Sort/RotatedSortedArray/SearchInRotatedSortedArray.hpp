//
//  SearchInRotatedSortedArray.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/10.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef SearchInRotatedSortedArray_hpp
#define SearchInRotatedSortedArray_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace SearchInRotatedSortedArray {
/*
 1. find mid: 1) left < Cur > right  2) left > cur < right
 2. leftBorder > max(right_side_nums) 左侧边界的最小值 大于右边所有数的最大值。
 所以当leftBorder< mid时，说明mid还在left side， leftBorder=mid; mid go right；
    当mid < leftBorder时，说明mid在right side， mid go left; rightBorder=mid;
    当leftBorder/rightBorder=mid, find min/max
 3. if in left side go right
 
 */

class Solution {
public:
    int valueIndexInSortedArray(vector<int>& num, int leftIndex, int rightIndex, int target) {
        int mid = (leftIndex + rightIndex) / 2;
        while (leftIndex < rightIndex) {
            // 注意这里需要加上=，且等于单独判断；若不确定就 多加代码或复杂度

            if (target == num[mid] ) {
                return mid;
            } else if (target < num[mid]) {
                rightIndex = mid -1;
            } else {
                leftIndex = mid + 1;
            }
            mid = (leftIndex + rightIndex) / 2;
        }
        return target == num[leftIndex] ? leftIndex : -1;
    }
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int totalCnt = (int)nums.size();
        int leftBorder = 0;
        int rightBorder = totalCnt - 1;

        int indexInUnRotatedArray = valueIndexInSortedArray(nums, 0, rightBorder, target);
        if (indexInUnRotatedArray != -1) {
            return indexInUnRotatedArray;
        }

        int mid = (leftBorder + rightBorder) / 2;
        while (mid != leftBorder && mid != rightBorder) {
            if (nums[leftBorder] < nums[mid]) {
                leftBorder = mid;
            } else {
                rightBorder = mid;
            }
            mid = (leftBorder + rightBorder) / 2;
        }
//        printf("left_max:%d right_min:%d\r\n", leftBorder, rightBorder);

        if (target > nums[leftBorder] || target < nums[rightBorder]) {
            return -1;
        }
        if (target >= nums[0] && target <= nums[leftBorder]) {
            return valueIndexInSortedArray(nums, 0, leftBorder, target);
        }
        if (target >= nums[rightBorder] && target <= nums[totalCnt - 1]) {
            return valueIndexInSortedArray(nums, rightBorder, totalCnt - 1, target);
        }
        return -1;
    }
};

}


#endif /* SearchInRotatedSortedArray_hpp */
