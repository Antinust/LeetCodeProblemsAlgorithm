//
//  SymmetricTree.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/20.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef SymmetricTree_hpp
#define SymmetricTree_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace SymmetricTree {
/*

 new_sol:
    1. 递归遍历判断是否为对称树即可：lc_101
 
 // 下面这种方法不行，
    有badcase：[5,4,1,null,1,null,4,2,null,2,null]
        1. 中序遍历后，然后看数组是否为回文即可
        2. 当左/右子树为空时，插入一个-INT_MIN；用于判断为空的节点是否对称
 */

//    vector<int> mVec;
//    void recursiveTraversal(TreeNode* root, vector<int> &vec) {
//        if (!root) {
//            return;
//        }
//        if (root->left) {
//            recursiveTraversal(root->left, vec);
//        } else if (root->right) {
//            vec.push_back(INT_MIN);
//        }
//
//        vec.push_back(root->val);
//
//        if (root->right) {
//            recursiveTraversal(root->right, vec);
//        } else if (root->left) {
//            vec.push_back(INT_MIN);
//        }
//    }

class Solution {
public:
    bool isTwoTreeSymmetric(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        } else if ((!p && q) ||(p && !q)) {
            return false;
        }
        
        if (p->val != q->val) {
            return false;
        }
        bool isFirstPartSymmetric = isTwoTreeSymmetric(p->left, q->right);
        bool isSecondPartSymmetric = isTwoTreeSymmetric(p->right, q->left);

        return isFirstPartSymmetric && isSecondPartSymmetric;
    }
    bool isSymmetric(TreeNode* root) {
        if ((!root) ||(!root->left && !root->right)) {
            return true;
        }
        return isTwoTreeSymmetric(root->left, root->right);
    }
};

}

#endif /* SymmetricTree_hpp */
