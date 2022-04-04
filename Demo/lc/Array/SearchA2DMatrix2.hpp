//
//  SearchA2DMatrix2.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/23.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef SearchA2DMatrix2_hpp
#define SearchA2DMatrix2_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace SearchA2DMatrix2 {
/*
 数组从左到右和从上到下都是升序的，如果从右上角出发开始遍历呢？

 会发现每次都是向左数字会变小，向下数字会变大，有点和二分查找树相似。二分查找树的话，是向左数字变小，向右数字变大。

 所以我们可以把 target 和当前值比较。

 如果 target 的值大于当前值，那么就向下走。
 如果 target 的值小于当前值，那么就向左走。
 如果相等的话，直接返回 true
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = 0;
        int numCol = (int)matrix[0].size() - 1;
        int numRow = (int)matrix.size() - 1;
        int y = numCol;
        while (y >= 0 && x <= numRow && matrix[x][y] != target) {
            if (matrix[x][y] < target) {
                x++;
            } else if (matrix[x][y] > target) {
                y--;
            } else {
                break;
            }
        }
        return (y >=0 && x <= numRow && matrix[x][y] == target);
    }
};
}

#endif /* SearchA2DMatrix2_hpp */
