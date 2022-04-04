//
//  LargestRectangleInHistogram.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/8.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef LargestRectangleInHistogram_hpp
#define LargestRectangleInHistogram_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace LargestRectangleInHistogram {
/*
 1. use monotonic(increasing) stack to find the nearest element less than curNode from left and right direction;
 2. if curVal > stack.top , then curVal is the rightBorderOfARectangle of stack.top, stack.top->next is the leftBorder of stack.top.
 */
class Solution {
    struct Node {
        int val = 0;
        int index = 0;
        Node(int v, int ind):val(v), index(ind) {}
    };
    const static int MAX_LENGHT = 100001;
    int maxAreas[MAX_LENGHT];
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
                    maxAreas[nodeTop.index] = (rightIndex - leftIndex - 1) * nodeTop.val;
                    if (maxArea < maxAreas[nodeTop.index]) {
                        maxArea = maxAreas[nodeTop.index];
                    }
                }
                // 注意别漏了 把当前元素加入栈
                stack.push(Node(height, i));
            }
        }
        return maxArea;
    }
};
}
#endif /* LargestRectangleInHistogram_hpp */
