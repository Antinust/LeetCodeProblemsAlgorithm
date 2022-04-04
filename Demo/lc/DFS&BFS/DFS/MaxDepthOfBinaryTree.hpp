//
//  MaxDepthOfBinaryTree.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/14.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef MaxDepthOfBinaryTree_hpp
#define MaxDepthOfBinaryTree_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace MaxDepthOfBinaryTree {

class Solution {
public:
    int recursiveTraversal(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftDepth = 0;
        if (root->left) {
            leftDepth = recursiveTraversal(root->left);
        }
        int rightDepth = 0;
        if (root->right) {
            rightDepth = recursiveTraversal(root->right);
        }
        return std::max(leftDepth, rightDepth) + 1;
    }
    
    int maxDepth(TreeNode* root) {
        vector<int> mVec;
        return recursiveTraversal(root);
    }
};

}

#endif /* MaxDepthOfBinaryTree_hpp */
