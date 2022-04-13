//
//  TrappingRainWater.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/8.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef TrappingRainWater_hpp
#define TrappingRainWater_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace TrappingRainWater {
/*
 1. 按列求出 每一列可以装多少水，根据木桶效应(最短的一块 决定可以装多少水)， 找出左右两边连续的最大值即可
 
 2. 按行求，利用单调栈，设置一个单调递减栈(bottom to top)，当当前元素大于栈顶元素时，由栈顶元素的前一个、栈顶元素、当前元素组成的一个凹块，就可以接水了；
    若栈顶元素的下一个与栈顶 元素有相同的值，则需要继续pop出栈，直到栈顶的下个元素大于栈顶 或者栈空
 
    雨水的高度的确定：min(nextTop, curVal) - top
 
    算出一个值后，把栈顶元素出栈；递归前面一个步骤，直到栈顶元素大于当前元素，或者栈为空；压栈当前元素
 */

// 下面的代码(算法)较简单 快速
class Solution {
public:
    int trap(vector<int>& h) {
        int len = h.size();
        if (h.size() == 1) {
            return 0;
        }
        // h.push_back(0);
        stack<int>sta; //store index of array
        sta.push(0);
        int sum = 0;
        for (int i = 1; i < len; i++) {
            //如果栈不空并且当前指向的高度大于栈顶高度就一直循环
            while (!sta.empty() && h[sta.top()] < h[i]) {
                int topIndex = sta.top();
                sta.pop();
                if (sta.empty()) {
                    break;
                }
                // int cnt = 1; 无需cnt，宽通过index的差值即可求出
                // 相等情况，因为leftIndex==topIndex，故高度为0，sum+=0
                // while(!sta.empty() && h[sta.top()] == h[topIndex]) {
                //     sta.pop();
                // }
                // 注意宽度的正确值
                sum += (i - sta.top() - 1) * (min(h[i], h[sta.top()]) - h[topIndex]) ; //无需 * cnt
            }
            sta.push(i);

        }
        return sum;
    }
};

//class Solution {
//    struct Node {
//        int val = 0;
//        int index = 0;
//        Node(int v, int ind):val(v), index(ind) {}
//    };
//public:
//    int trap(vector<int>& height) {
//        if (height.size() <= 2) {
//            return 0;
//        }
//        int totalSum = 0;
//        stack<Node> stack;
//        stack.push(Node(height[0], 0));
//        int totalCnt = (int)height.size();
//        for (int i = 1; i < totalCnt; i++) {
//            if (stack.empty() || stack.top().val >= height[i]) {
//                stack.push(Node(height[i], i));
//            } else {
//                if (stack.size() <= 1) {
//                    stack.pop();
//                    stack.push(Node(height[i], i));
//                    continue;
//                } else {
//                    // 循环遍历 栈 直到栈顶元素 大于当前元素
//                    while (!stack.empty() && height[i] > stack.top().val) {
//                        Node topNode = stack.top();
//                        stack.pop();
//                        while (!stack.empty() && stack.top().val == topNode.val) {
//                            stack.pop();
//                        }
//                        // if stack.empty, means can't find nextTop > top
//                        if (stack.empty()) {
//                            stack.push(Node(height[i], i));
//                            continue;
//                        }
//
//                        int rectHeight = std::min(stack.top().val, height[i]) - topNode.val;
//                        int area = rectHeight * (i - stack.top().index - 1);
//                        totalSum += area;
//                    }
//
//                    stack.push(Node(height[i], i));
//                }
//            }
//        }
//        return totalSum;
//    }
//};

//MARK: - concise writting style
// stack 记录index 即可，不需要记录整个Node
//class Solution {
//public:
//    int trap(vector<int>& height) {
//        if (height.size() <= 2) {
//            return 0;
//        }
//        int totalSum = 0;
//        stack<int> stack;
//        stack.push(0);
//        int totalCnt = (int)height.size();
//        for (int i = 1; i < totalCnt; i++) {
//            while (!stack.empty() && height[i] > height[stack.top()]) {
//                int topVal = height[stack.top()];
//                stack.pop();
//
//                // 若栈顶元素相同，则pop只剩下一个
//                while (!stack.empty() && topVal == height[stack.top()]) {
//                    stack.pop();
//                }
//
//                if (!stack.empty()) {
//                    int stackTop = stack.top();
//                    int rectHeight = std::min(height[stackTop], height[i]) - topVal;
//                    int area = rectHeight * (i - stackTop - 1);
//                    totalSum += area;
//                }
//            }
//            stack.push(i);
//        }
//        return totalSum;
//    }
//};
}

#endif /* TrappingRainWater_hpp */
