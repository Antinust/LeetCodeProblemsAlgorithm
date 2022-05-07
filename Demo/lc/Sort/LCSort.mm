//
//  LCSort.m
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/10.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#import "LCSort.h"
#include "MergeSortedArray.hpp"
#include "SearchInRotatedSortedArray.hpp"
#include "FindMinimumInRotatedSortedArray.hpp"
#include "FindMinInRotatedSortedArray2.hpp"
#include "MergeIntervals.hpp"
#import "ShortestUnsortedContinuousSubarray.hpp"

@implementation LCSort

- (instancetype)init {
    self = [super init];
    if (self) {
        [self testForLC];
    }
    return self;
}
//MARK: - QuickSort
void qSort(vector<int> & a) {
    int len = a.size();
    int i = -1;
    int j = 0;
    int pivotIndex = len - 1;
    
    while (j < pivotIndex) {
        if (a[j] < a[pivotIndex]) {
            swap(a[++i], a[j]);
        }
        j++;
    }
    swap(a[i + 1], a[pivotIndex]);
}

- (void)testForSortedArray {
    SearchInRotatedSortedArray::Solution *sol = new SearchInRotatedSortedArray::Solution();
//    vector<int> vec = {4,5,6,7,0,1,2};
//    sol->search(vec, 0);
    
    vector<int> vec = {1, 3};
    sol->search(vec, 2);
}

- (void)testForFindMinInRotatedSortedArray {
    FindMinimumInRotatedSortedArray::Solution *sol = new FindMinimumInRotatedSortedArray::Solution();
//    vector<int> vec = {3,3,1,3};
    vector<int> vec = {10,1,10,10,10};

    
//    sol->search(vec, 0);
    sol->findMin(vec);
}

//
- (void)testForFindMinInRotatedSortedArray2 {
    FindMinInRotatedSortedArray2::Solution *sol = new FindMinInRotatedSortedArray2::Solution();
//    vector<int> vec = {3,3,1,3};
    vector<int> vec = {2,2,2,0,1};
//    sol->search(vec, 0);
    sol->findMin(vec);
}

- (void)testForMergeSort {
    //    MergeSortedArray::Solution *sol = new MergeSortedArray::Solution();
    ////    vector<int> nums1 = {1,2,3,0,0,0};
    ////    int m = 3;
    ////    vector<int> nums2 = {2,5,6};
    ////    int n = 3;
    //
    //    vector<int> nums1 = {2,0};
    //    int m = 1;
    //    vector<int> nums2 = {1};
    //    int n = 1;
    //
    //    sol->merge(nums1, m, nums2, n);
}

- (void)testForLC_MergeIntervals {
    MergeIntervals::Solution *sol = new MergeIntervals::Solution();
//    vector<vector<int>> vec = {{1,3},{2,6},{8,10},{15,18}};
   vector<vector<int>> vec =  {{1,4},{0,2},{3,5}};
    sol->merge(vec);
    
}

- (void)testForLC_findUnsortedSubarray {
    ShortestUnsortedContinuousSubarray::Solution *sol = new ShortestUnsortedContinuousSubarray::Solution();
//    vector<vector<int>> vec = {{1,3},{2,6},{8,10},{15,18}};
   vector<int> vec =  {2,6,4,8,10,9,15};
    sol->findUnsortedSubarray(vec);
}


- (void)testForLC {
    [self testForLC_findUnsortedSubarray];
}

@end
