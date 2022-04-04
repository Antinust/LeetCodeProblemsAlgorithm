//
//  FlattenBTToLinkedList.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/21.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef FlattenBTToLinkedList_hpp
#define FlattenBTToLinkedList_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace FlattenBTToLinkedList {
/*
 1. 先把root->rightChild用tempNode保存，把root->right=root->left；递归处理root->left，函数return子树最右侧节点；
    再把之前的temp值赋值给 上个函数返回的子树的最右侧节点的right
    然后递归处理root->right子树；
 */

class Solution {
public:
    TreeNode *dfs(TreeNode *root) {
        if (!root) {
            return NULL;
        }
        if (root->left) {
            TreeNode *temp = root->right;
            root->right = root->left;
            TreeNode *rightestNode = dfs(root->left);
            if (rightestNode) {
                rightestNode->right = temp;
            }
            // 要把leftChild置空，否则leetcode提交报heap use after free?
            root->left = NULL;
        }
        // 右子树也要递归处理
        if (root->right) {
            dfs(root->right);
        }
        TreeNode *rightestNode = root;
        while (rightestNode->right) {
            rightestNode = rightestNode->right;
        }
        return rightestNode;
    }
    
    void flatten(TreeNode* root) {
        dfs(root);
    }
};

}

#endif /* FlattenBTToLinkedList_hpp */
