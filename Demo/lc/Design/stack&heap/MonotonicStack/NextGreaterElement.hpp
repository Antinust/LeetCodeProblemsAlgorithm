//
//  NextGreaterElement.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/8.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef NextGreaterElement_hpp
#define NextGreaterElement_hpp

#include <stdio.h>
#include "PublicCommon.h"
/*
 对于数组中的每个元素，往右遍历，找到下个比自己大的元素需要走多少步；没有找到则返回-1
 input: 5,3,1,2,4
 return: -1 3 1 1 -1
 */
namespace NextGreaterElement {

class Solution {
private:
    struct Node {
        int val = 0;
        int index = 0;
        Node(int v, int ind):val(v), index(ind) {}
    };
    
public:
    
    // 更新index的差值即为 距离值
    vector<int> nextExceed(vector<int> &input) {
        vector<int>result;
        
        
        return result;
    }
};
}

#endif /* NextGreaterElement_hpp */
