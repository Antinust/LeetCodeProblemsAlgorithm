//
//  BuildTreeFromPreInorder.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/21.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef BuildTreeFromPreInorder_hpp
#define BuildTreeFromPreInorder_hpp

#include <stdio.h>
#include "PublicCommon.h"

//    struct Node {
//        int val;
//        int index;
//        Node(int v, int ind):val(v), index(ind){}
//    };

namespace BuildTreeFromPreInorder {
/*
    1. 先序遍历的第一个元素一定是根元素，然后在中序遍历中找到根元素 所在的index2，减去先序遍历中所在的index1 即为左子树长度；
    右子树长度为 totalLen - index2
    2. 重复 步骤1
    
 用hashMap保存 元素及index下标 方便存储
    若pre、in的起始index一致，=> 根据len(leftChild) + 1 = 1 + len(leftChild) 可以得出先序、中序遍历 右子树的起始位置一致

 */
class Solution {
public:
    unordered_map<int, int> preMap;
    unordered_map<int, int> inMap;
    
    TreeNode *dfs(vector<int>& preorder, int preStart, int preEnd,
                  vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd
            || preEnd >= preorder.size() || inEnd >= inorder.size()
            || preStart < 0 || inStart < 0) {
            return NULL;
        }
        TreeNode *node = new TreeNode(preorder[preStart]);
        
        int rootIndexInOrder = inMap[preorder[preStart]];
        
        int leftChildLen = rootIndexInOrder - inStart;
        int rightChildLen = inEnd - inStart - leftChildLen;
        
        if (leftChildLen > 0) {
            int InStarLeft = inStart;
            int InEndLeft = rootIndexInOrder - 1;
            
            int preStartLeft = preStart + 1;
            int preEndLeft = preStartLeft + leftChildLen - 1;

            node->left = dfs(preorder, preStartLeft, preEndLeft,
                             inorder, InStarLeft, InEndLeft);
        }
//
        if (rightChildLen > 0) {
            int inStartRight = rootIndexInOrder + 1;
            int inEndRight = inEnd;
            
            int preStartRight = preStart + 1 + leftChildLen;
            int preEndRight = preEnd;
            
            node->right = dfs(preorder, preStartRight, preEndRight,
                             inorder, inStartRight, inEndRight);
        }
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preMap.clear();
        inMap.clear();
        for (int i = 0; i < preorder.size(); i++) {
            preMap.insert(std::make_pair(preorder[i], i));
        }
        for (int i = 0; i < inorder.size(); i++) {
            inMap.insert(std::make_pair(inorder[i], i));
        }
        return dfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};

}


#endif /* BuildTreeFromPreInorder_hpp */
