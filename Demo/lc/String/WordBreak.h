//
//  WordBreak.h
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/7.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef WordBreak_h
#define WordBreak_h
#include "PublicCommon.h"
namespace WordBreak {
/*
 1. build trie
 2. search
 
 设定dp[i]为0~i的字符串是否可以在wordDict中找到，状态转移方程如下：
 dp[i]= dp[j] && checkExist(j, i-1)     其中j区间为 [0, i-1]
 
 使用动态规划+hashMap较快
 
 使用递归DFS较慢：
 // for循环里面 i的起始值是startIndex，而非0，因为要随递归而转移(第一次是0，但第二次就是之前的0+strLen)，切记

badcase:
     "aaaaaaa"
     ["aaaa","aaa"]
 
 badcase:
     "aebbbbs"
     ["a","aeb","ebbbb","s","eb"]
 
 */

//class Solution1 {
//public:
//    bool wordBreak(string s, vector<string>& wordDict) {
//        int sLen = s.length();
//        unordered_set<string>set;
//        for (int i = 0; i < wordDict.size(); i++) {
//            set.insert(wordDict[i]);
//        }
//        vector<int>dp (sLen + 1, 0);
//        dp[0] = 1;
//        for (int i = 1; i <= sLen; i++) {
//            bool found = false;
//            for (int j = 0; j < i; j++) {
//                found = dp[j] && set.count(s.substr(j, i - j));
//                if (found) {
//                    break;
//                }
//            }
//            dp[i] = found;
//        }
//        return dp[sLen];
//    }
//};

class Solution {
public:
    bool dfs(string s, unordered_set<string> &set, vector<int> &memo, int staIndex) {
        int sLen = s.length();
        if (staIndex >= sLen) {
            return true;
        }
        if (memo[staIndex] != -1) {
            return memo[staIndex];
        }
        // for循环里面 i的起始值是startIndex，而非0，因为要随递归而转移，切记
        for (int i = staIndex; i < sLen; i++) {
            string str = s.substr(staIndex, i - staIndex + 1);
            if (set.count(str) && dfs(s, set, memo, i + 1)) {
                memo[staIndex] = 1;
                return true;
            }
        }
        memo[staIndex] = 0;
        return memo[staIndex];
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int sLen = s.length();
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<int> memo (sLen + 1, -1);
//        for (int i = 0; i < wordDict.size(); i++) {
//            set.insert(wordDict[i]);
//        }
        return dfs(s, set, memo, 0);
    }
};

//class Solution {
//public:
//    struct Node {
//        int val;
//        bool isEndNode;
//        vector<Node*> next;
//        Node(int v, bool isEnd):val(v), isEndNode(isEnd), next(vector<Node*>(26, NULL)) {}
//    };
//
//    bool hasPrefix(Node *node, string str) {
//        if (!node) {
//            return false;
//        }
//        Node *tempNode = node;
//        for (int j = 0; j < str.length(); j++) {
//            int value = str[j]-'a';
//            if (!tempNode->next[value]) {
//                return false;
//            }
//            if (j == str.length() - 1) {
//                return tempNode->next[value]->isEndNode;
//            }
//            tempNode = tempNode->next[value];
//        }
//        return true;
//    }
//
//    bool wordBreak(string s, vector<string>& wordDict) {
//        int sLen = s.length();
//        Node *node = new Node(0, 0);
//        for (int i = 0; i < wordDict.size(); i++) {
//            string str = wordDict[i];
//            Node *tempNode = node;
//            for (int j = 0; j < str.length(); j++) {
//                int value = str[j]-'a';
//                if (!tempNode->next[value]) {
//                    tempNode->next[value] = new Node(value, 0);
//                }
//                if (j == str.length() - 1) {
//                    tempNode->next[value]->isEndNode = true;
//                }
//                tempNode = tempNode->next[value];
//            }
//        }
//        vector<int>dp (sLen + 1, 0);
//        dp[0] = 1;
//        for (int i = 1; i <= sLen; i++) {
//            bool found = false;
//            for (int j = 0; j < i; j++) {
//                found = dp[j] && hasPrefix(node, s.substr(j, i - j));
//                if (found) {
//                    break;
//                }
//            }
//            dp[i] = found;
//        }
//        return dp[sLen];
//    }
//};
}

#endif /* WordBreak_h */
