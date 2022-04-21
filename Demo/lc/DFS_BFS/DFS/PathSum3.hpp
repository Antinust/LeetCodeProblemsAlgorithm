//
//  PathSum3.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/26.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef PathSum3_hpp
#define PathSum3_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace PathSum3 {
/*
 1. 求i~j的和，可以利用前缀和；即prefixSum[j] - prefixSum[i-1]，若存在prefixSum[j]-target=prefixSum[i-1]；
    则必有sum[i~j]=target
    prefixSum[0] = 0
 
 badcase:
 [0,1,1]
 1
 */
class Solution {
public:
    unordered_map<int, int>prefixSumMap;
    int _pathSum = 0;
    int dfs(TreeNode* root, int targetSum, int &prefixSum) {
        if (!root) {
            return 0;
        }
        prefixSum += root->val;
        if (prefixSumMap.count(prefixSum - targetSum)) {
            _pathSum += prefixSumMap[prefixSum - targetSum];
        }
        prefixSumMap[prefixSum]++;
        
        if (root->left) {
            dfs(root->left, targetSum, prefixSum);
        }
        if (root->right) {
            dfs(root->right, targetSum, prefixSum);
        }
        
        prefixSumMap[prefixSum]--;
        prefixSum -= root->val;
        return 0;
    }
    int pathSum(TreeNode* root, int targetSum) {
        prefixSumMap.clear();
        prefixSumMap[0] = 1; // targetSum路径和 = 当前节点到根节点和的情况
        int prefixSum = 0;
        _pathSum = 0;
        dfs(root, targetSum, prefixSum);
        return _pathSum;
    }
};

}

#endif /* PathSum3_hpp */
