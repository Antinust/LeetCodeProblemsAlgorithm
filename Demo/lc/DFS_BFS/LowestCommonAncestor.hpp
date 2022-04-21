//
//  LowestCommonAncestor.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/5.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef LowestCommonAncestor_hpp
#define LowestCommonAncestor_hpp

#include <stdio.h>
#include "PublicCommon.h"

//
/*
 1. 若p、q两个节点 分别分布在当前节点的左右子树上，则当前节点肯定是lca
 2. 若p/q == root，则当前节点是lca
 3. 若p、q两个节点在 当前节点的左或右子树，则递归遍历左、右子树， 返回其值则可
 4. 其他返回null
 
 */

class Solution {
public:
    TreeNode* lcaTravel(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return nullptr;
        }
        TreeNode *left = nullptr;
        if (root->left) {
            left = lcaTravel(root->left, p, q);
        }
        TreeNode *right = nullptr;
        if (root->right) {
            right = lcaTravel(root->right, p, q);
        }
        if ((left && right)
            || ( (!left || !right) && (p == root || q == root) ) ) {
            return root;
        }
        if (!left) {
            return right;
        }
        if (!right) {
            return left;
        }
        return NULL;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q) {
            return root;
        }
        return lcaTravel(root, p, q);
    }
};


//class Solution2 {
//public:
//    TreeNode* lcaTravel(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (!root) {
//            return NULL;
//        }
//        if (root == p || root == q) {
//            return root;
//        }
//
//        if ((root->left == p && root->right == q)
//            ||(root->left == q && root->right == p) ) {
//            return root;
//        }
//        TreeNode *leftChild = lcaTravel(root->left, p, q);
//        TreeNode *rightChild = lcaTravel(root->right, p, q);
//
//        if (leftChild == NULL) {
//            return rightChild;
//        }
//        if (rightChild == NULL) {
//            return leftChild;
//        }
//
//        if ((leftChild == p && rightChild == q)
//            ||(leftChild == q && rightChild == p) ) {
//            return root;
//        }
//        return NULL;
//    }
//
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (root == p || root == q) {
//            return root;
//        }
//
//        return lcaTravel(root, p, q);
//    }
//};


#endif /* LowestCommonAncestor_hpp */
