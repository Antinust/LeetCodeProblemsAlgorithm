//
//  LongestValidParentheses.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/31.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef LongestValidParentheses_hpp
#define LongestValidParentheses_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace LongestValidParentheses {
/*
 1. dp: 定义dp[i]为以i结尾的最长有效括号长度 从dp[i]往前推，
    1.1 若s[i]=='('，则dp[i]=0
    1.2 若s[i]==')'
        若s[i-1]=='(' 则dp[i]=dp[i-1]+2
        若s[i-1]==')'
            若s[i-dp[i-1]-1]=='('
                若dp[i-dp[i-1]-2]存在     则dp[i]=2+dp[i-1]+dp[i-dp[i-1]-2]
                若dp[i-dp[i-1]-2]不存在     则dp[i]=2+dp[i-1]
            若s[i-dp[i-1]-1]==')'或不存在 则dp[i]=0
 
 2. 栈：寻找以当前右括号结尾 所能达到的最大长度。
    栈底部始终存储当前已遍历元素中最近 未匹配的右括号
    遍历string，若遇到'('直接入栈；遇到')' 若栈不为空，则先把栈顶元素出栈，得出匹配长度=i-stack.top(); 若栈为空，则把当前元素入栈
    为了处理已开始就是'('，保持 栈底部始终存储当前已遍历元素中最近未匹配的右括号的这个特性，最开始把-1压入栈
 
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>stack;
        stack.push(-1);
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    maxLen = max(maxLen, i - stack.top());
                }
            }
        }
        return maxLen;
    }
};

}

#endif /* LongestValidParentheses_hpp */
