//
//  MinStack.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/3.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef MinStack_hpp
#define MinStack_hpp

#include <stdio.h>
#include <stack>
using namespace std;

class MinStack {
private:
    struct Node {
        int val;
        int min;
        Node(int v, int minimum):val(v), min(minimum) {}
    };
    stack<Node> stack;
    int _min;
public:
    MinStack() {
        _min = INT_MAX;
    }
    
    void push(int val) {
        if (val < _min) {
            _min = val;
        }
        stack.push(Node(val, _min));
    }
    
    void pop() {
        stack.pop();
        //        当stack为空时 _min需要恢复初始化的值
        if (stack.empty()) {
            _min = INT_MAX;
        } else {
            _min = stack.top().min;
        }
    }
    
    int top() {
        return stack.top().val;
    }
    
    int getMin() {
        return stack.top().min;
    }
};

#endif /* MinStack_hpp */
