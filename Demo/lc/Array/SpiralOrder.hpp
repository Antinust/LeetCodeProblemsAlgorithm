//
//  SpiralOrder.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/28.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef SpiralOrder_hpp
#define SpiralOrder_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace SpiralOrder {
/*
 1. m行n列矩阵；i,j 从0，0开始，遍历，直到(m-1)/2, (n-1)/2；注意每次的边界处理
    1.1 i, j++
    1.2 i++, j
    1.3 i, j--
    1.4 i--, j
 2. 当vec.size >= m*n 时 return
 
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> vec;
        if (matrix.size() < 1) {
            return vec;
        }
        int rowNum = (int)matrix.size();
        int colNum = (int)matrix[0].size();
        
        int i = 0;
        int j = 0;
        int maxSize = rowNum *colNum;
        for (; i <= (rowNum -1 ) / 2 && j <= (colNum -1) / 2; i++, j++) {
            int indexI = i;
            int indexJ = j;
            while (indexJ < colNum - j && vec.size() < maxSize) {
                vec.push_back(matrix[indexI][indexJ]);
                indexJ++;
            }
            indexJ = colNum - j - 1;
            
            while (++indexI < rowNum - i && vec.size() < maxSize) {
                vec.push_back(matrix[indexI][indexJ]);
//                indexI++;
            }
            indexI = rowNum - i - 1;
            
            while (--indexJ >= j && vec.size() < maxSize) {
                vec.push_back(matrix[indexI][indexJ]);
//                indexJ--;
            }
            indexJ = j;
            
            while (--indexI > i && vec.size() < maxSize) {
                vec.push_back(matrix[indexI][indexJ]);
//                indexI--;
            }
        }
        return vec;
    }
};

}

#endif /* SpiralOrder_hpp */
