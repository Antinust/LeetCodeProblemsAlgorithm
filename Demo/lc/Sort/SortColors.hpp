//
//  SortColors.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/13.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef SortColors_hpp
#define SortColors_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace SortColors {

class Solution {
public:
    void sortColors(vector<int>& a) {
        int len = a.size();
        if (len < 2) {
            return;
        }
        int zero = -1;
        int two = len;
        int i = 0;
        while (i < two) {
            if (a[i] == 0) {
                swap(a[++zero], a[i]);
                i++;
            } else if (a[i] == 1) {
                i++;
            } else {
                swap(a[--two], a[i]);
            }
        }
    }
};


//class Solution {
//public:
//    void sortColors(vector<int>& nums) {
//        int zeroCnt = 0;
//        int oneCnt = 0;
//        int twoCnt = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] == 0) {
//                zeroCnt++;
//            } else if (nums[i] == 1) {
//                oneCnt++;
//            } else {
//                twoCnt++;
//            }
//        }
//        int index = 0;
//        for (; index < zeroCnt; index++) {
//            nums[index] = 0;
//        }
//
//        for (; index < zeroCnt + oneCnt; index++) {
//            nums[index] = 1;
//        }
//        for (; index < nums.size(); index++) {
//            nums[index] = 2;
//        }
//    }
//};

//[1,2,0]
//[2,0,2,1,1,0]
class Solution2 {
public:
    void sortColors(vector<int>& a) {
        int len = a.size();
        int zeroIndex = -1;
        int twoIndex = len;
        int index = 0;
        while (index < twoIndex) {
            if (a[index] == 2) {
                swap(a[--twoIndex], a[index]);
            } else if (a[index] == 0) {
                swap(a[++zeroIndex], a[index]);
                index++;
            } else {
                index++;
            }
        }
    }
};

}


#endif /* SortColors_hpp */
