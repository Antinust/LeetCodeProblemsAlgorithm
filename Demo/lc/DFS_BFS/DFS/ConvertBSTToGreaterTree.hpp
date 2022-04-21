//
//  ConvertBSTToGreaterTree.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/23.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef ConvertBSTToGreaterTree_hpp
#define ConvertBSTToGreaterTree_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace ConvertBSTToGreaterTree {
/*
 1. 中 序遍历即可 得到所有节点的值的和；当前节点的值+=accumulatedSum
 注意递归条件
 */
class Solution {
public:
    TreeNode* dfs(TreeNode *root, int &sum) {
        if (!root) {
            return root;
        }
        if (root->right) {
            dfs(root->right, sum);
        }
        root->val += sum;
        sum = root->val;
        if (root->left) {
            dfs(root->left, sum);
        }
        return root;
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        return dfs(root, sum);
    }
};

}

#endif /* ConvertBSTToGreaterTree_hpp */
