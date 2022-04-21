//
//  GenerateParentheses.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/21.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef GenerateParentheses_hpp
#define GenerateParentheses_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace GenerateParentheses {
/*
 1. 记录当前剩余左括号、右括号的数量，当左、右括号数都为0时，找到一个组合；
    当剩余左括号数> 右括号数时 return；
 2. 当遍历一次完成时，需要回溯 
 */
class Solution {
public:
    void dfs(int leftBracketNum, int rightBracketNum, string &s, vector<string> &vec) {
        if (leftBracketNum == 0 && rightBracketNum == 0) {
            vec.push_back(s);
            return;
        }
        if (leftBracketNum > rightBracketNum) {
            return;
        }
        if (leftBracketNum > 0) {
            s.append("(");
            dfs(leftBracketNum - 1, rightBracketNum, s, vec);
            s.pop_back();
        }
        
        if (rightBracketNum > 0) {
            s.append(")");
            dfs(leftBracketNum, rightBracketNum - 1, s, vec);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        string s;
        dfs(n, n, s, vec);
        return vec;
    }
};

}


#endif /* GenerateParentheses_hpp */
