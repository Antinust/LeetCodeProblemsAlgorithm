//
//  BalanceBST.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/5.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef BalanceBST_hpp
#define BalanceBST_hpp

#include <stdio.h>
#include "PublicCommon.h"

class Solution5 {
    
public:
    vector<int> mVec;
    void recursiveTraversal(TreeNode* root) {
        if (!root) {
            return;
        }
        if (root->left) {
            recursiveTraversal(root->left);
        }
        mVec.push_back(root->val);

        if (root->right) {
            recursiveTraversal(root->right);
        }
    }
    
    TreeNode* createBalancedBST(int lIndex, int rIndex) {
        if (lIndex > rIndex) {
            return NULL;
        }
        int mid = (lIndex + rIndex) / 2;
        TreeNode* root = new TreeNode(mVec[mid]);
        root->left = createBalancedBST(lIndex, mid -1);
        root->right = createBalancedBST(mid + 1, rIndex);
        if (lIndex == rIndex) {
            return root;
        }
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        recursiveTraversal(root);
//        for (int i = 0; i < mVec.size(); i++) {
//            printf(" %d\r\n ", mVec[i]);
//        }
        return createBalancedBST(0, (int)mVec.size() - 1);
    }
};


#endif /* BalanceBST_hpp */
