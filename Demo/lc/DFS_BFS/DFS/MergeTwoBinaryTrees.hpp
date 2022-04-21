//
//  MergeTwoBinaryTrees.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/20.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef MergeTwoBinaryTrees_hpp
#define MergeTwoBinaryTrees_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace MergeTwoBinaryTrees {

class Solution {
public:
    
    void recursiveTraversal(TreeNode* root1, TreeNode* root2) {
        // 左、右子树有一个为空，则不再递归，直接赋值，否则递归
        root1->val += root2->val; // 这一行与 root1->left->val += root2->left->val 重复
        if (!root1->left) {
            root1->left = root2->left;
        } else if (root2->left) {
//            root1->left->val += root2->left->val;
            recursiveTraversal(root1->left, root2->left);
        }
        
        if (!root1->right) {
            root1->right = root2->right;
        } else if (root2->right) {
//            root1->right->val += root2->right->val;
            recursiveTraversal(root1->right, root2->right);
        }
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) {
            return root2;
        }
        if (!root2) {
            return root1;
        }
        recursiveTraversal(root1, root2);
        return root1;
    }
};
      
//class Solution {
//public:
//    void recursiveTraversal(TreeNode* root, TreeNode* root1, TreeNode* root2) {
//        if (!root) {
//            return;
//        }
//        if (!root1) {
//            root = root2;
//            return;
//        } else if (!root2) {
//            root = root1;
//            return;
//        }
//
//        int leftChildVal = INT_MIN;
//        int rightChildVal = INT_MIN;
//        if (root1->left && root2->left) {
//            leftChildVal = root1->left->val + root2->left->val;
//        } else if (root1->left) {
//            leftChildVal = root1->left->val;
//        } else if (root2->left) {
//            leftChildVal = root2->left->val;
//        }
//
//        if (root1->right && root2->right) {
//            rightChildVal = root1->right->val + root2->right->val;
//        } else if (root1->right) {
//            rightChildVal = root1->right->val;
//        } else if (root2->right) {
//            rightChildVal = root2->right->val;
//        }
//        if (leftChildVal != INT_MIN) {
//            root->left = new TreeNode(leftChildVal);
//        }
//        if (rightChildVal != INT_MIN) {
//            root->right = new TreeNode(rightChildVal);
//        }
//        recursiveTraversal(root->left, root1->left, root2->left);
//        recursiveTraversal(root->right, root1->right, root2->right);
//    }
//    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
//        if (!root1) {
//            return root2;
//        }
//        if (!root2) {
//            return root1;
//        }
//
//        TreeNode *root = new TreeNode(root1->val + root2->val);
//        recursiveTraversal(root, root1, root2);
//        return root;
//    }
//};

}

#endif /* MergeTwoBinaryTrees_hpp */
