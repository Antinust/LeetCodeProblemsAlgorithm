//
//  MaximalRectangle.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/8.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef MaximalRectangle_hpp
#define MaximalRectangle_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace MaximalRectangle {
/*
 1. 把每一行当做一个Histogram，当新增一行的时候 不需要重新遍历，只需要基于之前的Histogram调整：根据示例可以看出 若新增行的元素为0，则此位置的值为0，否则为上个Histogram对应位置的值+1
 */
class Solution {
    struct Node {
        int val = 0;
        int index = 0;
        Node(int v, int ind):val(v), index(ind) {}
    };
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        } else if (heights.size() == 1) {
            return heights[0];
        }
        
        vector<int> areas;
        stack<Node> stack;
        int maxArea = 0;
        // 插入一个最小值0，保证所有元素可以遍历到
        heights.push_back(0);
        stack.push(Node(heights[0], 0));
        for (int i = 1; i < heights.size(); i++) {
            int height = heights[i];
            // height >= stack.top, can keep stack increasing
            if (stack.empty() || height >= stack.top().val) {
                stack.push(Node(height, i));
            } else {
                int rightIndex = i;
                // iterate until stack.top < curNode
                while (!stack.empty() && stack.top().val > height) {
                    Node nodeTop = stack.top();
                    stack.pop();
                    int leftIndex =  stack.empty() ? -1 : stack.top().index;
                    int tempMax = (rightIndex - leftIndex - 1) * nodeTop.val;
                    if (maxArea < tempMax) {
                        maxArea = tempMax;
                    }
                }
                // 注意别漏了 把当前元素加入栈
                stack.push(Node(height, i));
            }
        }
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int maxArea = -1;
        int nRows = (int)matrix.size();
        int nCols = (int)matrix[0].size();
        vector<int> vec;
        for (int i = 0; i < nCols; i++) {
            vec.push_back(0);
        }
        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                if (matrix[i][j] == '1') {
                    vec[j] += 1;
                } else {
                    vec[j] = 0;
                }
            }
            int maxtemp = largestRectangleArea(vec);
            if (maxArea < maxtemp) {
                maxArea = maxtemp;
            }
        }
        return maxArea;
    }
};
}

#endif /* MaximalRectangle_hpp */
