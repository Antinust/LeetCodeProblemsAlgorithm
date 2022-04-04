//
//  FindMinimumInRotatedSortedArray.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/10.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef FindMinimumInRotatedSortedArray_hpp
#define FindMinimumInRotatedSortedArray_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace FindMinimumInRotatedSortedArray {

/*
 1. 如果旋转了元素个数的n倍的话：必有 nums[leftBorder] < nums[mid] < nums[rightBorder]，需要先递归判断当前vec是否为sorted有序数组
 
 2. 否则，处理旋转逻辑：
    leftBorder > max(right_side_nums) 左侧边界的最小值 大于右边所有数的最大值。
 所以当leftBorder< mid时，说明mid还在left side， leftBorder=mid; mid go right；
    当mid < leftBorder时，说明mid在right side， mid go left; rightBorder=mid;
    当leftBorder/rightBorder=mid, find min/max
 3. if in left side go right
 
 */


class Solution {
public:
    bool isVectSorted(vector<int>& nums, int left, int right) {
        if (left == right) {
            return true;
        } else if (left + 1 == right) {
            return nums[left] <= nums[right];
        }
        
        int mid = (left + right) / 2;
        if (nums[mid] < nums[left] || nums[mid] > nums[right]) {
            return false;
        }
        bool isLeftSorted = isVectSorted(nums, left, mid);
        if (!isLeftSorted) {
            return false;
        }
        bool isRightSorted = isVectSorted(nums, mid, right);
        if (!isRightSorted) {
            return false;
        }
        return true;
    }
    
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return std::min(nums[0], nums[1]);
        }
        
        int totalCnt = (int)nums.size();
        int leftBorder = 0;
        int rightBorder = totalCnt - 1;
        int mid = (leftBorder + rightBorder) / 2;
        if (isVectSorted(nums, leftBorder, rightBorder)) {
            return nums[leftBorder];
        }
        
        while (mid != leftBorder && mid != rightBorder && leftBorder < rightBorder) {
            // 相等时，不能使用二分了，因为无法确定nums[min]在nums[mid]的左侧还是右侧，导致丧失了二段性
            // 相等时 rightBorder--是OK的，但是 left++不OK
            if (nums[leftBorder] == nums[mid]) {
                // 相等情况分两种：  3 3 3 1 3
                //                3 1 3 3 3
                while (leftBorder + 1 <= rightBorder && nums[leftBorder] ==  nums[leftBorder + 1]) {
                    leftBorder++;
                }
            } else if (nums[leftBorder] < nums[mid]) {
                leftBorder = mid;
            } else {
                rightBorder = mid;
            }
            mid = (leftBorder + rightBorder) / 2;
        }
        return std::min(nums[leftBorder], nums[rightBorder]);
    }
};



}


#endif /* FindMinimumInRotatedSortedArray_hpp */
