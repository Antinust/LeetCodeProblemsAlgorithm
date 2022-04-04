//
//  BTLevelOrderTraversal.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/6.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef BTLevelOrderTraversal_hpp
#define BTLevelOrderTraversal_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace BTLevelOrderTraversal {
/*
 1. 在每次遍历前，记录上一层的节点数，即queue.size()，然后一次遍历完size个节点；进入下一个循环
 
 */

//每次遍历时 记录每一层的节点数，即 QofEveryLeve.size()

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vec;
        vector<vector<int>> reversedVec;

        if (!root) {
            return vec;
        }
        queue<TreeNode*>que;
        que.push(root);
        while (!que.empty()) {
            vector<int>v;
            int everyLevelSize = (int)que.size();
            for (int i = 0; i < everyLevelSize; i++) {
                v.push_back(que.front()->val);
                TreeNode *node = que.front();
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
                que.pop();
            }
            vec.push_back(v);
        }
        for (int i = (int)vec.size() - 1; i >= 0; i--) {
            reversedVec.push_back(vec[i]);
        }
        return vec;
    }
};




//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        vector<vector<int>> vec;
//        if (!root) {
//            return vec;
//        }
//        queue<TreeNode*>que;
//        que.push(root);
//
//        while (!que.empty()) {
//            vector<int>v;
//            queue<TreeNode*> tempQ;
//
//            // 用一个临时Queue 保存每一层在原始Q的元素/节点
//            while (!que.empty()) {
//                if (que.front()->left) {
//                    tempQ.push(que.front()->left);
//                }
//                if (que.front()->right) {
//                    tempQ.push(que.front()->right);
//                }
//                v.push_back(que.front()->val);
//                que.pop();
//            }
//            vec.push_back(v);
//
//            // 把临时Q中的元素，放入元素Q
//            while (!tempQ.empty()) {
//                que.push(tempQ.front());
//                tempQ.pop();
//            }
//        }
//        return vec;
//    }
//};

}

#endif /* BTLevelOrderTraversal_hpp */
