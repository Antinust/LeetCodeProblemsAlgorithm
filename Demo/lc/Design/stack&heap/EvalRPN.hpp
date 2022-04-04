//
//  EvalRPN.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/7.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef EvalRPN_hpp
#define EvalRPN_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace EvalRPN {

class Solution {
    stack<string> stack;
public:
    bool isOperator(string &str) {
        if (str.compare("+") == 0
            ||str.compare("-") == 0
            ||str.compare("*") == 0
            ||str.compare("/") == 0) {
            return true;
        }
        return false;
    }
    int getOperationResult(string &str, int a, int b) {
        if (str.compare("+") == 0) {
            return a + b;
        } else if (str.compare("-") == 0) {
            return a - b;
        } else if (str.compare("*") == 0) {
            return a * b;
        } else if (str.compare("/") == 0) {
            return a / b;
        }
        return 0;
    }
    
    int evalRPN(vector<string>& tokens) {
        for (int i = 0; i < tokens.size(); i++) {
            if (isOperator(tokens[i])) {
                // 操作数，a, b顺序别搞反了 先出来的是b，后出来的是a
                int b = stoi(stack.top());
                stack.pop();
                int a = stoi(stack.top());
                stack.pop();
                stack.push(to_string(getOperationResult(tokens[i], a, b)));
            } else {
                stack.push(tokens[i]);
            }
        }
//        return 0;
        return stack.empty() ? 0 : stoi(stack.top());
    }
};

}
#endif /* EvalRPN_hpp */
