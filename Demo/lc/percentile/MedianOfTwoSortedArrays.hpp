//
//  MedianOfTwoSortedArrays.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/1.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef MedianOfTwoSortedArrays_hpp
#define MedianOfTwoSortedArrays_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace MedianOfTwoSortedArrays {
/*
编码经验：若一个子函数里面 有多处需要判断奇偶，可以把这个判断奇偶操作 提取到父函数；

 1. 根据中位数性质：将一个集合划分为 左右两部份个数完全相等的子集合
    问题可以转换为 在数组A中位置 i 划分，数组B中的位置j划分，使得A、B左部分的元素个数和 = 右部分的元素个数和
    设A的元素个数为m，B的元素个数为n，当m+n为奇数时，划分A、B使得左边元素个数比右边多1；当m+n为偶数时，划分使得左右两侧元素个数相等。
    i+j=(m+n+1)/2，
    通过二分查找i，使得max(A[i-1], B[j-1]) < min(A[i], B[j])；若A[i-1]>B[j]，则i往左边走；若B[j-1]>A[i], 则i往右走；
                                    会不会出现A[i-1]>B[j]&&B[j-1]>A[i]，不会；因为 A[i-1]>B[j]=> A[i]>A[i-1]>B[j]>B[j-1] =>A[i]>B[j-1]
 
    设定A[-1]=B[-1]=负无穷  A[m]=B[n]=正无穷
 2. 设定k=(m+n+1)/2，问题转换为找到第K大的元素，每次比较前k/2个元素，若A[k/2-1] < B[k/2-1]，则可以断定A[k/2-1]及之前的元素不含第K大的元素
    k=k-2/k，继续比较A[k/2]、B[0]后面的元素，直到k=1，就找到了
    
    注意：若A[k/2-1]或B[k/2-1]越界，则减少的元素个数不是k/2，而是实际的个数
    编码时：针对m+n为奇数情况，直接求第(m+n+1)/2小的元素，偶数情况，直接求第(m+n)/2、(m+n)/2+1小的平均值
 [2]
 []
 
 [1,2,4,5,6]
 [3]
 
 [3]
 [1,2,4,5,6]
 
 */


class Solution {
public:
    double findKthElem(vector<int> &a, vector<int> &b, int k) {
        int i = 0;
        int j = 0;
        int m = a.size();
        int n = b.size();
        while (true) {
            if (i >= m) {
                return b[j + k - 1];
            }
            if (j >= n) {
                return a[i + k - 1];
            }
            if (k == 1) {
                return min(a[i], b[j]);
            }
            int indexI = min(i + k / 2 - 1, m - 1);
            int indexJ = min(j + k / 2 - 1, n - 1);
            if (a[indexI] < b[indexJ]) {
                k -= indexI - i + 1;
                i = indexI + 1;
            } else {
                k -= indexJ - j + 1;
                j = indexJ + 1;
            }
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int> &a, vector<int> &b) {
        int totalLen = (int)(a.size() + b.size());
        if ((totalLen) % 2 == 1) {
            return findKthElem(a, b, (totalLen + 1) / 2);
        } else {
            return (findKthElem(a, b, totalLen / 2) + findKthElem(a, b, totalLen / 2 + 1)) / 2.0;
        }
    }
};




//iterate

//class Solution {
//public:
//    double findKthElem(vector<int> &a, vector<int> &b, int k) {
//        int i = 0;
//        int j = 0;
//        int m = a.size();
//        int n = b.size();
//        while (true) {
//            if (i >= m) {
//                return b[j + k - 1];
//            }
//            if (j >= n) {
//                return a[i + k - 1];
//            }
//            if (k == 1) {
//                return min(a[i], b[j]);
//            }
//            int indexI = min(i + k / 2 - 1, m - 1);
//            int indexJ = min(j + k / 2 - 1, n - 1);
//            if (a[indexI] < b[indexJ]) {
//                k -= indexI - i + 1;
//                i = indexI + 1;
//            } else {
//                k -= indexJ - j + 1;
//                j = indexJ + 1;
//            }
//        }
//        return 0;
//    }
//    double findMedianSortedArrays(vector<int> &a, vector<int> &b) {
//        int totalLen = (int)(a.size() + b.size());
//        if ((totalLen) % 2 == 1) {
//            return findKthElem(a, b, (totalLen + 1) / 2);
//        } else {
//            return (findKthElem(a, b, totalLen / 2) + findKthElem(a, b, totalLen / 2 + 1)) / 2.0;
//        }
//    }
//};


// recursion

//class Solution {
//public:
//    double findKthElem(vector<int>& nums1, vector<int>& nums2, int k, int i, int j) {
//        if (i >= nums1.size()) {
//            return nums2[j + k - 1];
//        }
//        if (j >= nums2.size()) {
//            return nums1[i + k - 1];
//        }
//        if (k == 1) {
//            return min(nums1[i], nums2[j]);
//        }
//
//        int indexI = i + k / 2 - 1;
//        bool iBeyondBorder = false;
//        if (indexI >  nums1.size() - 1) {
//            indexI = nums1.size() - 1;
//            iBeyondBorder = true;
//        }
//
//        int indexJ = j + k / 2 - 1;
//        bool jBeyondBorder = false;
//        if (indexJ >  nums2.size() - 1) {
//            indexJ = nums2.size() - 1;
//            jBeyondBorder = true;
//        }
//
//        if (nums1[indexI] < nums2[indexJ]) {
//            if (iBeyondBorder) {
//                k -= indexI - i + 1;
//            } else {
//                k -= k / 2;
//            }
//            return findKthElem(nums1, nums2, k, indexI + 1, j);
//        } else {
//            if (jBeyondBorder) {
//                k -= indexJ - j + 1;
//            }  else {
//                k -= k / 2;
//            }
//            return findKthElem(nums1, nums2, k, i, indexJ + 1);
//        }
//    }
//
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        unsigned long m = nums1.size();
//        unsigned long n = nums2.size();
//        if ((m + n) % 2 == 1) {
//            return findKthElem(nums1, nums2, (m + n + 1) / 2, 0, 0);
//        } else {
//            return (findKthElem(nums1, nums2, (m + n) / 2, 0, 0) + findKthElem(nums1, nums2, (m + n) / 2  + 1, 0, 0)) /2;
//        }
//    }
//};







//class Solution {
//public:
//    double iterateFindMedian(vector<int>& nums1, vector<int>& nums2, int k, int i, int j) {
//        if (i >= nums1.size()) {
//            if ((nums1.size() + nums2.size()) % 2 == 1) {
//                return nums2[j + k - 1];
//            } else {
//                return (nums2[j + k - 1] + nums2[j + k]) / 2.0;
//            }
//        }
//        if (j >= nums2.size()) {
//            if ((nums1.size() + nums2.size()) % 2 == 1) {
//                return nums1[i + k - 1];
//            } else {
//                return (nums1[i + k - 1] + nums1[i + k]) / 2.0;
//            }
//        }
//        if (k == 1) {
//            if ((nums1.size() + nums2.size()) % 2 == 1) {
//                return min(nums1[i], nums2[j]);
//            } else {
//                return (nums1[i] + nums2[j]) / 2.0;
//            }
//        }
//
//        int indexI = i + k / 2 - 1;
//        if (indexI >  nums1.size() - 1) {
//            indexI = nums1.size() - 1;
//        }
//        int indexJ = j + k / 2 - 1;
//        if (indexJ >  nums2.size() - 1) {
//            j = nums2.size() - 1;
//        }
//
//        k = k - k / 2;
//        if (nums1[indexI] < nums2[indexJ]) {
//            return iterateFindMedian(nums1, nums2, k, indexI + 1, j);
//        } else {
//            return iterateFindMedian(nums1, nums2, k, i, indexJ + 1);
//        }
//        return 0;
//    }
//
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        int m = nums1.size();
//        int n = nums2.size();
//        if (m == 0 && n == 0) {
//            return 0;
//        } else if (m == 0) {
//            return n % 2 == 1 ? nums2[(n - 1) / 2] : (nums2[(n - 1) / 2] + nums2[(n - 1) / 2 + 1]) / 2.0;
//        } else if (n == 0) {
//            return m % 2 == 1 ? nums1[(m - 1) / 2] : (nums1[(m - 1) / 2] + nums1[(m - 1) / 2 + 1]) / 2.0;
//        }
//
//        int k = (m + n + 1) / 2;
//        return iterateFindMedian(nums1, nums2, k, 0, 0);
//    }
//};

}

#endif /* MedianOfTwoSortedArrays_hpp */
