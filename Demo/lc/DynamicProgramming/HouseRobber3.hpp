//
//  HouseRobber3.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/26.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef HouseRobber3_hpp
#define HouseRobber3_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace HouseRobber3 {
/*
 // 下面的思路会超时，需要 剪枝
 1. 选cur， maxSum 转换为maxSum(cur->l->l)+maxSum(cur->l->r)+maxSum(cur->r->l)+maxSum(cur->r->r)
 2. 不选cur，maxSum转换为maxSum(cur->left)+maxSum(cur->right)
 
 // 记忆化搜索： 使用hash表来存之前搜索到的结果
 
 // 增加维度：来记录当前节点选或不选 所能得到的最大值，最后结果为max(root[0], root[1]) root[0]表示不选当前节点的最大值，root[1]表示选当前节点所能达到的最大值
    root[0]: 不选当前节点的最大值，就递归为max(root->left[0], root->left[1]) + max(root->r[0], root->r[1]);
 
    root[1]:选了当前节点左右都不能选 (root->val + root->left[0] + root->right[0])
 */

class Solution {
public:
    vector<int> dfs(TreeNode *root) {
        vector<int> vec(2, 0);
        if (!root) {
            return vec;
        }
        vector<int> lVec = dfs(root->left);
        vector<int> rVec = dfs(root->right);
        
        // 选当前节点，左右子节点都不能选
        vec[1] = root->val + lVec[0] + rVec[0];

        // 不选的时候，转化为 选不选左、右节点的最大值的和
        vec[0] = std::max(lVec[1], lVec[0]) + std::max(rVec[1], rVec[0]);
        return vec;
    }
    int rob(TreeNode *root) {
        vector<int> vec = dfs(root);
        return std::max(vec[0], vec[1]);
    }
};



//class Solution {
//public:
//    unordered_map<TreeNode *, int>map;
//    int dfs(TreeNode *root) {
//        if (!root) {
//            return 0;
//        }
//        if (map.count(root)) {
//            return map[root];
//        }
//        int lMaxSumSelectCur = 0;
//        int rMaxSumSelectCur = 0;
//        // select cur
//        if (root->left) {
//            lMaxSumSelectCur += dfs(root->left->left) + dfs(root->left->right);
//        }
//        if (root->right) {
//            rMaxSumSelectCur += dfs(root->right->left) + dfs(root->right->right);
//        }
//
//        // not select cur
//        int lMaxSum = dfs(root->left);
//        int rMaxSum = dfs(root->right);
//        int maxSum = std::max(root->val + lMaxSumSelectCur + rMaxSumSelectCur, lMaxSum + rMaxSum);
//        map[root] = maxSum;
//        return maxSum;
//    }
//    int rob(TreeNode *root) {
//        map.clear();
//        return dfs(root);
//    }
//};



    
//class Solution {
//public:
//    int dfs(TreeNode *root) {
//        if (!root) {
//            return 0;
//        }
//        int lMaxSumSelectCur = 0;
//        int rMaxSumSelectCur = 0;
//        // select cur
//        if (root->left) {
//            lMaxSumSelectCur += dfs(root->left->left) + dfs(root->left->right);
//        }
//        if (root->right) {
//            rMaxSumSelectCur += dfs(root->right->left) + dfs(root->right->right);
//        }
//
//        // not select cur
//        int lMaxSum = dfs(root->left);
//        int rMaxSum = dfs(root->right);
//        int maxSum = std::max(root->val + lMaxSumSelectCur + rMaxSumSelectCur, lMaxSum + rMaxSum);
//        return maxSum;
//    }
//    int rob(TreeNode *root) {
//        return dfs(root);
//    }
//};

}

#endif /* HouseRobber3_hpp */
