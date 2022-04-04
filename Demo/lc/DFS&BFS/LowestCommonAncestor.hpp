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
 
 */
class Solution2 {
public:
    TreeNode* lcaTravel(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return NULL;
        }
        if (root == p || root == q) {
            return root;
        }
        
        if ((root->left == p && root->right == q)
            ||(root->left == q && root->right == p) ) {
            return root;
        }
        TreeNode *leftChild = lcaTravel(root->left, p, q);
        TreeNode *rightChild = lcaTravel(root->right, p, q);
        
        if (leftChild == NULL) {
            return rightChild;
        }
        if (rightChild == NULL) {
            return leftChild;
        }
        
        if ((leftChild == p && rightChild == q)
            ||(leftChild == q && rightChild == p) ) {
            return root;
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


#endif /* LowestCommonAncestor_hpp */
