//
//  KthSmallestInBST.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/5.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef KthSmallestInBST_hpp
#define KthSmallestInBST_hpp

#include <stdio.h>
#include "PublicCommon.h"

//class Solution {
//private:
//    priority_queue<int, vector<int>, greater<int>> mMinQ;
//    vector<int> mVec;
//
//public:
//    void recursiveTraversal(TreeNode *node) {
//        if (!node) {
//            return;
//        }
//        mVec.push_back(node->val);
//        if (node->left) {
//            recursiveTraversal(node->left);
//        }
//        if (node->right) {
//            recursiveTraversal(node->right);
//        }
//    }
//    void setupMinQ() {
//        for (int i = 0; i < mVec.size(); i++) {
//            mMinQ.push(mVec[i]);
//        }
//    }
//
//    int getKthSmallestInMinQueu(int k) {
//        while (k > 1) {
//            mMinQ.pop();
//            k--;
//        }
//        return mMinQ.empty() ? 0 : mMinQ.top();
//    }
//
//    int kthSmallest(TreeNode* root, int k) {
//        recursiveTraversal(root);
//        setupMinQ();
//        return getKthSmallestInMinQueu(k);
//    }
//};

// 二叉搜索树 子节点<当前节点<右节点，按中序遍历之后 就是有序的了
class Solution6 {
private:
    vector<int> mVec;
public:
    void recursiveTraversal(TreeNode *node) {
        if (!node) {
            return;
        }
        if (node->left) {
            recursiveTraversal(node->left);
        }
        mVec.push_back(node->val);
        if (node->right) {
            recursiveTraversal(node->right);
        }
    }
    
    int getKthSmallestInMinQueu(int k) {
        return mVec.empty() ? 0 : mVec[k - 1];
    }
    
    int kthSmallest(TreeNode* root, int k) {
        recursiveTraversal(root);
        return getKthSmallestInMinQueu(k);
    }
};

#endif /* KthSmallestInBST_hpp */
