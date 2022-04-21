//
//  SerializeAndDeserializeBinaryTree.h
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/8.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef SerializeAndDeserializeBinaryTree_h
#define SerializeAndDeserializeBinaryTree_h
#include "PublicCommon.h"
namespace SerializeAndDeserializeBinaryTree {
/*
 1. dfs:
    deserialize, 反序列化的时候 也是递归，先处理根节点，再处理递归处理左、右子树
    serialize 序列化的时候 需要存储分割符，否则无法解析val对应的字符1000，
 
 2. bfs:
 
 判断queue是不为空，使用 !que.empty()， que.empty()为空返回true
 
 badcase
 [1,2,3,null,null,4,5,6,7]
 
 */

//class Codec {
//public:
//    void bfs(TreeNode* root, string &str) {
//        if (!root) {
//            return;
//        }
//        queue<TreeNode*>que;
//        que.push(root);
//        while (!que.empty()) {
//            TreeNode *node = que.front();
//            que.pop();
//            if (node->val != INT_MIN) {
//                str.append("," + to_string(node->val));
//                if (node->left) {
//                    que.push(node->left);
//                } else {
//                    que.push(new TreeNode(INT_MIN));
//                }
//                if (node->right) {
//                    que.push(node->right);
//                } else {
//                    que.push(new TreeNode(INT_MIN));
//                }
//            } else {
//                delete node;
//                str.append(",X");
//            }
//        }
//    }
//
//    TreeNode *deserializeBFS(vector<int> &vec) {
//        if (vec.empty()) {
//            return NULL;
//        }
//        TreeNode *node = new TreeNode(vec[0]);
//        queue<TreeNode*>que;
//        que.push(node);
//        int index = 1;
//        while (!que.empty() && index < vec.size() - 1) {
//            TreeNode *tempNode = que.front();
//            if (tempNode->val != INT_MIN) {
//                TreeNode *left = new TreeNode(vec[index]);
//                TreeNode *right = new TreeNode(vec[index + 1]);
//                que.pop();
//                if (left->val != INT_MIN) {
//                    tempNode->left = left;
//                }
//                que.push(left);
//                if (right->val != INT_MIN) {
//                    tempNode->right = right;
//                }
//                que.push(right);
//                index += 2;
//            } else {
//                que.pop();
//                delete tempNode;
////                index++; // 空节点，index不用++
//            }
//        }
//        return node;
//    }
//
//    // Encodes a tree to a single string.
//    string serialize(TreeNode* root) {
//        string str;
//        bfs(root, str);
//        return str;
//    }
//
//    // Decodes your encoded data to tree.
//    TreeNode* deserialize(string data) {
//        if (data.length() < 1) {
//            return NULL;
//        }
//        vector<int> v;
//
//        string str;
//        istringstream strStream(data);
//        while (getline(strStream, str, ',')) {
//            if (str.compare("X") == 0) {
//                v.push_back(INT_MIN);
//            } else if(str.length() > 0) {
//                v.push_back(stoi(str));
//            }
//        }
//        return deserializeBFS(v);
//    }
//};


class Codec {
public:
    void dfs(TreeNode* root, string &str) {
        if (!root) {
            return;
        }
        str.append("," + to_string(root->val));
        if (root->left) {
            dfs(root->left, str);
        } else {
            str.append(",X");
        }
        if (root->right) {
            dfs(root->right, str);
        } else {
            str.append(",X");
        }
    }

    TreeNode* deserializeDFS(vector<int> &v, int &index) {
        if (v.empty() || index >= v.size()) {
            return NULL;
        }
        TreeNode *node = NULL;
        int val = v[index];
        if (val != INT_MIN) {
            node = new TreeNode(val);
            node->left = deserializeDFS(v, ++index);
            node->right = deserializeDFS(v, ++index);
        } else {
//            index++;    // 这里 不需要index++，因为上面👆的操作已经++了index
        }
        return node;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        dfs(root, str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() < 1) {
            return NULL;
        }
        vector<int> v;
        string str;
        istringstream strStream(data);
        while (getline(strStream, str, ',')) {
            if (str.compare("X") == 0) {
                v.push_back(INT_MIN);
            } else if(str.length() > 0) {
                v.push_back(stoi(str));
            }
        }
        int index = 0;
        return deserializeDFS(v, index);
    }
};

}

#endif /* SerializeAndDeserializeBinaryTree_h */
