//
//  MajorityElement.h
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/15.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef MajorityElement_h
#define MajorityElement_h

namespace MajorityElement {
/*
 1. 因为数组中元素出现次数 大于n/2，即数组的第n/2+1大的元素 一定是出现次数最多的元素，
    因为无论出现最多次数的元素，是在排序后数组的左端 还是右端，都会跨过(中间位置+1)
    比如 1 1 1 2 2
        1 1 2 2 2
 */

//    int partition(vector<int>& nums, int l, int r) {
//        int pivot = nums[r];
//        int i = l - 1;
//        for (int j = l; j <= r - 1; ++j) {
//            if (nums[j] <= pivot) {
//                i = i + 1;
//                swap(nums[i], nums[j]);
//            }
//        }
//        swap(nums[i + 1], nums[r]);
//        return i + 1;
//    }
//    int randomized_partition(vector<int>& nums, int l, int r) {
//        int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
//        swap(nums[r], nums[i]);
//        return partition(nums, l, r);
//    }


class Solution {
public:
    int majorityElement(vector<int>& a) {
        int count = 0;
        int candidate = 0;
        int len = a.size();
        for (int i = 0; i < len ; i++) {
            if (count == 0) {
                candidate = a[i];
                count++;
            } else {
                count += candidate == a[i] ? 1 : -1;
            }
        }
        return candidate;
    }
};



//class Solution {
//public:
//    int partition(vector<int>& a, int l, int r) {
//        int i = l - 1; //
//        int pivot = a[r];
//        for (int j = l; j < r; j++) {
//            if (a[j] < pivot) {
//                swap(a[++i], a[j]); //
//            }
//        }
//        swap(a[i + 1], a[r]);
//        return i + 1;
//    }
//    int findPos(vector<int>& a, int pos, int start, int end) {
//        if (start >= end) { return a[start]; }
//        int randIndex = rand() % (end - start + 1) + start;
//        swap(a[randIndex], a[end]);
//        int aPos = partition(a, start, end);
//        if (aPos == pos) {
//            return a[aPos];
//        } else if (aPos < pos) {
//            return findPos(a, pos, aPos + 1 , end);
//        } else {
//            return findPos(a, pos, start, aPos - 1);
//        }
//    }
//
//    int majorityElement(vector<int>& a) {
//        int len = a.size();
//        if (len == 1) {
//            return a[0];
//        }
//        return findPos(a, len / 2, 0, len - 1);
//    }
//};


//class Solution {
//public:
//    int findPos(vector<int>& a, int pos, int start, int end) {
//        int l = start;
//        int r = end;
//        int pivot = start;
//        int randIndex = rand() % (end - start + 1) + start;
//        swap(a[randIndex], a[pivot]);
//        while (l < r) {
//            while (l < r && a[r--] >= a[pivot]);
//            if (l < r) {
//                swap(a[r], a[pivot]);
//                pivot = r;
//            }
//            while (l < r && a[l++] <= a[pivot]);
//            if (l < r) {
//                swap(a[l], a[pivot]);
//                pivot = l;
//            }
//        }
//        if (l == pos) {
//            return a[l];
//        } else if (l < pos) {
//            return findPos(a, pos, l + 1 , end);
//        } else {
//            return findPos(a, pos, start , l - 1);
//        }
////        return 0;
//    }
//
//    int majorityElement(vector<int>& a) {
//        int len = a.size();
//        if (len == 1) {
//            return a[0];
//        }
//        return findPos(a, len / 2, 0, len - 1);
//    }
//};

}

#endif /* MajorityElement_h */
