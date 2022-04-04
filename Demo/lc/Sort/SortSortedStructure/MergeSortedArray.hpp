//
//  MergeSortedArray.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/9.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef MergeSortedArray_hpp
#define MergeSortedArray_hpp

#include <stdio.h>

#include "PublicCommon.h"
namespace MergeSortedArray {

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> vec;
        int nums1Cnt = 0;
        int nums2Cnt = 0;
        int mergedNums = 0;
        // 注意判断临界条件，<= 还是<
        while (nums1Cnt < m && nums2Cnt < n) {
            if (nums1[nums1Cnt] <= nums2[nums2Cnt]) {
                vec.push_back(nums1[nums1Cnt++]);
            } else {
                vec.push_back(nums2[nums2Cnt++]);
            }
            mergedNums++;
        }
        // 注意判断临界条件，> 还是>=
        if (nums1Cnt >= m) {
            for (int i = nums2Cnt; i < n; i++) {
                vec.push_back(nums2[i]);
            }
        }
        
        // 注意判断临界条件，> 还是>=
        if (nums2Cnt >= n) {
            for (int i = nums1Cnt; i < m; i++) {
                vec.push_back(nums1[i]);
            }
        }
        
        //copy back to nums1
        for (int i = 0; i < vec.size() && i < nums1.size(); i++) {
            nums1[i] = vec[i];
        }
    }
};

}
#endif /* MergeSortedArray_hpp */
