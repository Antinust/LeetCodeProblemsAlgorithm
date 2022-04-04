//
//  DiameterOfBinaryTree.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/20.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef DiameterOfBinaryTree_hpp
#define DiameterOfBinaryTree_hpp

#include <stdio.h>
#include "PublicCommon.h"


namespace DiameterOfBinaryTree {

/*
 1. 最长路径 一定以某个节点 为根节点，找出所有节点的最大左子树、右子树之和，然后遍历所有节点，找出其最大值即可
 
 */

class Solution {
public:
    
    int recursiveTraversal(TreeNode* root, int &maxLen) {
        if (!root) {
            return 0;
        }
        int leftChildLen = -1;
        if (root->left) {
            leftChildLen = recursiveTraversal(root->left, maxLen);
        }
        
        int rightChildLen = -1;
        if (root->right) {
            rightChildLen = recursiveTraversal(root->right, maxLen);
        }
        int totalLen = leftChildLen + rightChildLen + 2;
        if (totalLen > maxLen) {
            maxLen = totalLen;
        }
        return std::max(leftChildLen, rightChildLen) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxLen = 0;
        recursiveTraversal(root, maxLen);
        return maxLen;
    }
};


}

#endif /* DiameterOfBinaryTree_hpp */
