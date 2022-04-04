//
//  MaximalSquare.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/17.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef MaximalSquare_hpp
#define MaximalSquare_hpp

#include <stdio.h>

#include "PublicCommon.h"
namespace MaximalSquare {
/*
 1. findMaxRect
 {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}}
 
 2. 类似于找 largestRectangleArea，利用单调栈，不过求的是 正方形面积，而非长方形
 
 */
class Solution {
    struct Node {
        int val;
        int index;
        Node(int v, int ind):val(v), index(ind) { }
    };
public:
    int findMaxRect(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        else if (nums.size() == 1) {
            return nums[0];
        }
        int totalCnt = (int)nums.size();
        stack<Node> stack;
        stack.push(Node(nums[0], 0));
        int index = 1;
        int maxArea = 0;
        while (index < totalCnt) {
            if (stack.empty()) {
                stack.push(Node(nums[index], index));
            }
            else if (stack.top().val <= nums[index]) {
                stack.push(Node(nums[index], index));
            } else {
                // 遍历直到栈顶元素 < 当前元素 或栈为空
                while (!stack.empty() && stack.top().val > nums[index]) {
                    Node node = stack.top();
                    int leftIndex = node.index;
                    stack.pop();
                    while (!stack.empty() && stack.top().val == node.val) {
                        leftIndex = node.index;
                        stack.pop();
                    }
                    if (!stack.empty()) {
                        leftIndex= stack.top().index;
                    } else {
                        leftIndex = -1;
                    }
                    int width = (index - leftIndex - 1);
                    int len = std::min(width, node.val);
                    maxArea = std::max(len * len, maxArea);
                }
                
                // remember to push Node with index when deal special case or else
                stack.push(Node(nums[index], index));
            }
            index++;
        }
        return maxArea;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int Max = 0;
        // vector后面多加个0，保证全部元素可以出栈
        vector<int> mVec(matrix[0].size() + 1, 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '0') {
                    mVec[j] = 0;
                } else {
                    mVec[j] += 1;
                }
            }
            Max = std::max(Max, findMaxRect(mVec));
        }
        return Max;
    }
};

}

#endif /* MaximalSquare_hpp */
