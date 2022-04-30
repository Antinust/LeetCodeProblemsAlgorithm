//
//  LargestPerimeter.h
//  Demo
//
//  Created by zcc_imac on 2022/4/30.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef LargestPerimeter_h
#define LargestPerimeter_h
namespace LargestPerimeter {
/*
 1. 先排序
 2. 排序之后，倒序找到满足条件的 三角形 返回即可；因为前面的肯定不存在更大的，因为前面的三个值 都小于当前的三个值
 */

class Solution {
public:
    //倒序枚举
    int largestPerimeter(vector<int>& a) {
        int len = a.size();
        sort(a.begin(), a.end());
        for (int i = len - 1; i >=  2; i++) {
            if (a[i-2] + a[i-1] < a[i]) {
                return a[i-2] + a[i-1] + a[i];
            }
        }
        return 0;
    }
};

class Solution1 {
public:
    //正常
    int largestPerimeter(vector<int>& a) {
        int len = a.size();
        sort(a.begin(), a.end());
        int maxV = (a[0] + a[1] <= a[2]) ? 0 : a[0] + a[1] + a[2];
        for (int i = 1; i < len - 2; i++) {
            int perimeter = (a[i] + a[i+1] <= a[i+2]) ? 0 : a[i] + a[i+1] + a[i+2];
            maxV = max(maxV, perimeter);
        }
        return maxV;
    }
};

}

#endif /* LargestPerimeter_h */
