//
//  CombinationSum.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/23.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef CombinationSum_hpp
#define CombinationSum_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace CombinationSum {
/*
 1. 每次递归 可以通过 选/不选 当前的index 递归，直到index >= totalCnt ||  target<nums[index]
 
 */

class Solution {
public:
    void dfs(vector<int>& candidates, int index, int target,
             vector<int>& tempVec, vector<vector<int>> &vec) {
        if (index >= candidates.size()) {
            return;
        }
        if (target == 0) {
            vec.push_back(tempVec);
            return;
        }
//        if (target == candidates[index]) {
//            // 这里 push的话 没有pop 导致vector里面多一个元素
//            tempVec.push_back(candidates[index]);
//            vec.push_back(tempVec);
//            return;
//        }
        
        if (target < candidates[index]) {
            return;
        }
        // use index
        tempVec.push_back(candidates[index]);
        dfs(candidates, index, target - candidates[index], tempVec, vec);
        tempVec.pop_back();
        
        // not use index
        dfs(candidates, index + 1, target, tempVec, vec);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> vec;
        std::sort(candidates.begin(), candidates.end());
        vector<int>tempVec;
        dfs(candidates, 0, target, tempVec, vec);
        return vec;
    }
};


//class Solution {
//public:
//    void dfs(vector<int>& candidates, int index, int target,
//             vector<int>& tempVec, vector<vector<int>> &vec) {
//        if (index >= candidates.size()) {
//            return;
//        }
//
//        if (target == 0) {
//            vec.push_back(tempVec);
//            return;
//        }
////        if (target == candidates[index]) {
////            // 这里 push的话 没有pop 导致vector里面多一个元素
////            tempVec.push_back(candidates[index]);
////            vec.push_back(tempVec);
////            return;
////        }
//
//        if (target >= candidates[index]) {
//            // use index
//            tempVec.push_back(candidates[index]);
//            dfs(candidates, index, target - candidates[index], tempVec, vec);
//            tempVec.pop_back();
//        }
//
//        // not use index
//        dfs(candidates, index + 1, target, tempVec, vec);
//    }
//
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        vector<vector<int>> vec;
//        std::sort(candidates.begin(), candidates.end());
//        vector<int>tempVec;
//        dfs(candidates, 0, target, tempVec, vec);
//        return vec;
//    }
//};


//class Solution {
//public:
//    void dfs(vector<int>& candidates, int index, int target,
//             vector<int>& tempVec, vector<vector<int>> &vec) {
//        if (index >= candidates.size()) {
//            return;
//        }
//        if (target < candidates[index]) {
//            return;
//        }
//        if (target == candidates[index]) {
//            // 这里 push的话 没有pop 导致vector里面多一个元素
//            tempVec.push_back(candidates[index]);
//            vec.push_back(tempVec);
//            return;
//        }
//
//        // use index
//        tempVec.push_back(candidates[index]);
//        dfs(candidates, index, target - candidates[index], tempVec, vec);
//        tempVec.pop_back();
//
//        // not use index
//        dfs(candidates, index + 1, target, tempVec, vec);
//    }
//
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        vector<vector<int>> vec;
//        std::sort(candidates.begin(), candidates.end());
//        vector<int>tempVec;
//        dfs(candidates, 0, target, tempVec, vec);
//        return vec;
//    }
//};

}

#endif /* CombinationSum_hpp */
