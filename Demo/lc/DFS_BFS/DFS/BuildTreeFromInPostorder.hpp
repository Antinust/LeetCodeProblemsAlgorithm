//
//  BuildTreeFromInPostorder.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/21.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef BuildTreeFromInPostorder_hpp
#define BuildTreeFromInPostorder_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace BuildTreeFromInPostorder {

/*
 1. 通过后序遍历的最后一个元素 找到根节点的index，然后找到对应的在中序遍历中的位置，然后得到左右子树，再递归处理
 
 */

class Solution {
public:
    unordered_map<int, int> postMap;
    unordered_map<int, int> inMap;
    TreeNode* dfs(vector<int>& inorder, int inStart, int inEnd,
                  vector<int>& postorder, int postStart, int postEnd) {
        TreeNode *node = new TreeNode(postorder[postEnd]);
        int inOrderRootIndex = inMap[postorder[postEnd]];
        int leftChildLen = inOrderRootIndex - inStart;
        int rightChildLen = inEnd - inStart - leftChildLen;
        
        if (leftChildLen > 0) {
            int newPostEnd = postStart + leftChildLen - 1;
            node->left = dfs(inorder, inStart, inOrderRootIndex - 1,
                             postorder, postStart, newPostEnd);
        }
        
        if (rightChildLen > 0) {
            int newPostStart = postStart + leftChildLen;
            node->right = dfs(inorder, inOrderRootIndex + 1, inEnd,
                             postorder, newPostStart, postEnd - 1);
        }
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        inMap.clear();
        postMap.clear();
        for (int i = 0; i < inorder.size(); i++) {
            inMap.insert(make_pair(inorder[i], i));
        }
        for (int i = 0; i < postorder.size(); i++) {
            postMap.insert(make_pair(postorder[i], i));
        }
        return dfs(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};

}

#endif /* BuildTreeFromInPostorder_hpp */
