//
//  InorderTraversal.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/5.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef InorderTraversal_hpp
#define InorderTraversal_hpp

#include <stdio.h>


#include "PublicCommon.h"

class Solution1 {
private:
    vector<int> mVec;
    stack<TreeNode *> mStack;
public:
    /*
     1. push curNode into stack
     2. push leftChild into stack iteratively
     3. when pop curNode, if rightChild exist, iterate over step1-2.
     */
    void pushLeftIntoStackIteratively(TreeNode* p) {
        if (!p) {
            return;
        }
        while (p->left) {
            mStack.push(p->left);
            p = p->left;
        }
    }
    
    void iterateTraversal(TreeNode* root) {
        if (!root) {
            return;
        }
        TreeNode *p = root;
        mStack.push(p);
        pushLeftIntoStackIteratively(p);
        do {
            mVec.push_back(mStack.top()->val);
            TreeNode *q = mStack.top();
            mStack.pop();
            if (q->right) {
                mStack.push(q->right);
                pushLeftIntoStackIteratively(q->right);
            }
        } while (!mStack.empty());
    }
    
//    void recursiveTraversal(TreeNode* root) {
//        if (!root) {
//            return;
//        }
//        if (root->left) {
//            recursiveTraversal(root->left);
//        }
//        mVec.push_back(root->val);
//
//        if (root->right) {
//            recursiveTraversal(root->right);
//        }
//    }
    
    vector<int> inorderTraversal(TreeNode* root) {
//        recursiveTraversal(root);
        iterateTraversal(root);
        return mVec;
    }
};

#endif /* InorderTraversal_hpp */
