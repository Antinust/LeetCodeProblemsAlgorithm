//
//  Permutations.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/19.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef Permutations_hpp
#define Permutations_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace Permutations {
/*
 1. 思路理清之后 慢慢调试：选一个数加入数组之后，回溯时再不选这个数
 
 */

class Solution {
public:
    void recursiveTraversal(vector<vector<int>> &vec, vector<int>& nums, vector<int>& visited,
                            int depth, vector<int>& tempVec) {
        if (depth >= nums.size()) {
            vec.push_back(tempVec);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] == 0) {
                tempVec.push_back(nums[i]);
                visited[i] = 1;
                recursiveTraversal(vec, nums, visited, depth + 1, tempVec);
                visited[i] = 0;
                tempVec.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vec;
        vector<int> visited(nums.size(), 0);
        vector<int> tempVec;
        recursiveTraversal(vec, nums, visited, 0, tempVec);
        return vec;
    }
};

}

#endif /* Permutations_hpp */
