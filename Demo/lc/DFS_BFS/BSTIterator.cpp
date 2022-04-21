//
//  BSTIterator.cpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/2/12.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#include "BSTIterator.hpp"
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
    TreeNode *curNode;
    std::vector<int> myvec;
    int index;
public:
    BSTIterator(TreeNode* root) {
        curNode = root;
        myvec.clear();
        index = 0;
        inOrderIterate(root);
    }
    
    void inOrderIterate(TreeNode* root) {
        if (!root) {
            return;
        }
        
        inOrderIterate(root->left);
        myvec.push_back(root->val);
        inOrderIterate(root->right);
    }
    
    int next() {
        return myvec[index++];
    }
    
    bool hasNext() {
        return index < myvec.size();
    }
};

