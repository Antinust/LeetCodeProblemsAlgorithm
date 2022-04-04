//
//  MaxPathSum.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/30.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef MaxPathSum_hpp
#define MaxPathSum_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace MaxPathSum {
/*
 1. 求出每个节点的 左、右子树的路径和最大值，然后再加当前节点，最后记录一个全局的max；
 从每个节点出发所能达到的最大值：max(curVal, curVal + max(lChild, rChild))
 
 2. 不 需要 用hashMap 记录已经遍历过的节点的最大路径和
 
 */
class Solution {
public:
    unordered_map<TreeNode *, int>map;
    int dfs(TreeNode *root, int &maxSum) {
        if (!root) {
            return 0;
        }
//        if (map.count(root)) {
//            return map[root];
//        }
        int lChildMaxSum = 0;
        if (root->left) {
            lChildMaxSum = max(lChildMaxSum, dfs(root->left, maxSum)); //用max过滤负值
        }
        
        int rChildMaxSum = 0;
        if (root->right) {
            rChildMaxSum = max(rChildMaxSum, dfs(root->right, maxSum)); //用max过滤负值
        }
        
        int childMax = max(lChildMaxSum, rChildMaxSum);
//        int curNodeMax = max(root->val, childMax + root->val); //若左右节点路径和为负值，则无需+子节点的
        int curNodeMax = childMax + root->val;
        
        maxSum = max(maxSum, lChildMaxSum + rChildMaxSum + root->val);
//        map[root] = curNodeMax;
        return curNodeMax;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; //max必须初始化为min，min必须初始化为max
//        map.clear();
        dfs(root, maxSum);
        return maxSum;
    }
};

}


#endif /* MaxPathSum_hpp */
