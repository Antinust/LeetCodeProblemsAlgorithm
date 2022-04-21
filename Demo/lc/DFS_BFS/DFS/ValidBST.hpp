//
//  ValidBST.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/9.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef ValidBST_hpp
#define ValidBST_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace ValidBST {
class Solution {
public:
//    中序遍历后，判断数组是否有序即可
    void dfs(TreeNode* root, vector<int>& vec) {
        if (!root) {
            return;
        }
        if (root->left) {
            dfs(root->left, vec);
        }
        vec.push_back(root->val);
        if (root->right) {
            dfs(root->right, vec);
        }
    }
    
    bool isVecAscending(vector<int>& vec) {
        if (vec.size() <= 1) {
            return true;
        }
        // 注意判断临界条件：比如是需要遍历到最后一个，还是倒数第二个
        // 注意题目要求是>，不能含有等于，等于也是非BST
        for (int i = 0; i < vec.size() - 1; i++) {
            if (vec[i] >= vec[i + 1]) {
                return false;
            }
        }
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        if (!root || (!root->left && !root->right)) {
            return true;
        }
        vector<int> vec;
        dfs(root, vec);
        
        return isVecAscending(vec);
    }
};

}

#endif /* ValidBST_hpp */
