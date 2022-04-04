//
//  SortAnArray.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/22.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef SortAnArray_hpp
#define SortAnArray_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace SortAnArray {
/*
 1. quickSort：基于 随机选取主元 的快速排序时间复杂度为期望 O(nlogn)
    设置一个pivot，然后设置两个index：l,r；分别从左右两侧向另一侧前进；对于从右向左的遍历，找到比pivot小的 并交换；对于从左到右的遍历，找到比pivot大的并交换，迭代处理，直到l>=r
    因左侧的值都是比右侧小的，故只需要 递归处理左右两部分即可
 
 badcase:[5,2,3,1]
 
 2. mergeSort
 */

class Solution {
public:
    void quickSort(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return;
        }
        //随机化选择的pivot
        int randIndex = (rand()%(end - start +1)) + start;
        swap(nums[start], nums[randIndex]);
        
        int pivotIndex = start;
        int pivot = nums[pivotIndex];
        int l = start;
        int r = end;
        while (l < r) {
            while (r > l && nums[r] >= pivot) {
                r--;
            }
            if (r > l) {
                swap(nums[r], nums[pivotIndex]);
                pivotIndex = r;
            }
            
            while (r > l && nums[l] <= pivot) {
                l++;
            }
            if (r > l) {
                swap(nums[l], nums[pivotIndex]);
                pivotIndex = l;
            }
        }
        quickSort(nums, start, l - 1);
        quickSort(nums, r + 1, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0 , (int)nums.size() - 1);
        return nums;
    }
};

//class Solution {
//public:
//    void mergeSort(vector<int>& nums, int start, int end) {
//        if (end == start + 1) {
//            // 大于则交换
//            if (nums[start] > nums[end]) {
//                std::swap(nums[start], nums[end]);
//            }
//            return;
//        } else if (end == start) {
//            return;
//        }
//        int mid = (start + end) / 2;
//        mergeSort(nums, start, mid);
//        mergeSort(nums, mid + 1, end);
//        int index1 = start;
//        int index2 = mid + 1;
//        vector<int> temp;
//
//        while (index1 <= mid && index2 <= end) {
//            if (nums[index1] < nums[index2]) {
//                temp.push_back(nums[index1]);
//                index1++;
//            } else {
//                temp.push_back(nums[index2]);
//                index2++;
//            }
//        }
//        while (index1 <= mid) {
//            temp.push_back(nums[index1]);
//            index1++;
//        }
//        // 轻易拷贝容易出事，手写好一点 下面的end拷贝成了mid
//        while (index2 <= end) {
//            temp.push_back(nums[index2]);
//            index2++;
//        }
//
//        for (int i = start; i <= end; i++) {
//            nums[i] = temp[i - start];
//        }
//    }
//
//    vector<int> sortArray(vector<int>& nums) {
//        mergeSort(nums, 0 , (int)nums.size() - 1);
//        return nums;
//    }
//};

}

#endif /* SortAnArray_hpp */
