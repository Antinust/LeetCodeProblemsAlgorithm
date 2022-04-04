//
//  DailyTemperatures.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/24.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef DailyTemperatures_hpp
#define DailyTemperatures_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace DailyTemperatures {
/*
 1. 保存单调递减栈，记录Node(key,下标值)，当栈顶元素小于当前元素时，循环pop栈顶元素，直到大于当前元素或栈空
 
 2. 方法二，单调栈只存index即可，因为没有用到key，key可以通过nums[index]找到
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int totalSize = (int)temperatures.size();
        vector<int> vec(totalSize, 0); //比for循环赋值 效率高了一点
        stack<int>stack;
        for (int i = 0; i < totalSize; i++) {
            while (!stack.empty() && temperatures[stack.top()] < temperatures[i]) {
                // 注意更新的是当前栈顶元素的index对应的值
                int topIndex = stack.top();
                vec[topIndex] = i - topIndex;
                stack.pop();
            }
            stack.push(i);
        }
        return vec;
    }
};


//class Solution {
//    struct Node {
//        int key;
//        int index;
//        Node(int k, int ind):key(k), index(ind)  {}
//    };
//public:
//    vector<int> dailyTemperatures(vector<int>& temperatures) {
//        int totalSize = (int)temperatures.size();
//        vector<int> vec(totalSize, 0); //比for循环赋值 效率高了一点
//        stack<Node>stack;
//        for (int i = 0; i < totalSize; i++) {
//            while (!stack.empty() && stack.top().key < temperatures[i]) {
//                // 注意更新的是当前栈顶元素的index对应的值
//                vec[stack.top().index] = i - stack.top().index;
//                stack.pop();
//            }
//            stack.push(Node(temperatures[i], i));
//        }
//        return vec;
//    }
//};
}




#endif /* DailyTemperatures_hpp */
