//
//  FindFirstAndLastPosOfElemInSortedArray.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/13.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef FindFirstAndLastPosOfElemInSortedArray_hpp
#define FindFirstAndLastPosOfElemInSortedArray_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace FindFirstAndLastPosOfElemInSortedArray {

class Solution {
public:
    vector<int> binarySearch(vector<int>& nums, int i, int j, int target) {
        vector<int> vec = {-1,-1};

        int mid = (i + j) / 2;
        while (i < j && nums[mid] != target) {
            if (nums[mid] < target) {
                i = mid + 1;
            } else if (nums[mid] > target) {
                j = mid - 1;
            } else {
                break;
            }
            mid = (i + j) / 2;
        }
        // if not found
        if (nums[mid] != target) {
            return vec;
        }
        int start = mid - 1;
        int end = mid + 1;
        while (start >= 0 && nums[start] == nums[mid]) {
            start--;
        }
        // 注意边界的处理
        while (end < nums.size() && nums[end] == nums[mid]) {
            end++;
        }
        return vector<int> {start + 1, end - 1};
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return vector<int> {-1,-1};
        }
        return binarySearch(nums, 0, (int)nums.size() - 1, target);
        
    }
};


}
#endif /* FindFirstAndLastPosOfElemInSortedArray_hpp */
