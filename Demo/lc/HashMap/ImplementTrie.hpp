//
//  ImplementTrie.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/24.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef ImplementTrie_hpp
#define ImplementTrie_hpp

#include <stdio.h>
#include "PublicCommon.h"

namespace ImplementTrie {
/*
 1. 题目限制输入的字符串全为小写，且在a-z直接，可以映射到数组0-25
 
 */

class Trie {
    const static int MAX_NODE_NUM = 26;
    struct TrieNode {
        bool isEndingNode;
//        vector<TrieNode *>next(26, nullptr); 直接这样初始化不行，需要放到initializationList当中
        vector<TrieNode *>next;
        TrieNode(bool isEnding, int maxNodeNum):isEndingNode(isEnding), next(maxNodeNum, NULL) {
        }
    };
public:
    TrieNode *pNode = NULL;
    Trie() {
        pNode = new TrieNode(false, MAX_NODE_NUM);
    }
    
    void insert(string word) {
        TrieNode *node = pNode;
        int totalCnt = word.length();
        for (int i = 0; i < totalCnt; i++) {
            int index = word[i] - 'a';
            if (!node->next[index]) {
                bool isEnding = i == totalCnt - 1;
                node->next[index] = new TrieNode(isEnding, MAX_NODE_NUM);
                // 创建完node->next之后 要让node指向next
            } else {
                //之前已经存在，若为word的最后一个字符也要标记为ending
                if (i == totalCnt - 1) {
                    node->next[index]->isEndingNode = true;
                }
            }
            node = node->next[index];
        }
    }
    
    bool search(string word) {
        TrieNode *node = pNode;
        int totalCnt = word.length();
        for (int i = 0; i < totalCnt; i++) {
            int index = word[i] - 'a';
            if (!node->next[index]) {
                return false;
            } else {
                if (i == totalCnt - 1 && node->next[index]->isEndingNode) {
                    return true;
                }
                node = node->next[index];
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = pNode;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->next[prefix[i] - 'a']) {
                return false;
            } else {
                node = node->next[prefix[i] - 'a'];
            }
        }
        return true;
    }
};


//class Trie {
//    struct TrieNode {
//        string key;
//        bool isEndingNode = false;
//        unordered_map<string, TrieNode*> map;
//        TrieNode(string s):key(s) { map.clear(); }
//    };
//    unordered_map<string, TrieNode*>map;
//public:
//    Trie() {
//        map.clear();
//    }
//
//    void insert(string word) {
//        if (word.length() < 1) {
//            return;
//        }
//        int index = 1;
//        string key = string(1, word[0]);
//        if (map.count(key) == 0) {
//            std::pair<string, TrieNode*>pair = make_pair(key, new TrieNode(key));
//            map.insert(pair);
//            if (word.length() == 1) {
//                pair.second->isEndingNode = true;
//            }
//            TrieNode *previousNode = pair.second;
//            while (index < word.length()) {
//                string tempKey = string(1, word[index]);
//                std::pair<string, TrieNode*>tempPair = make_pair(tempKey, new TrieNode(tempKey));
//                if (index == word.length() - 1) {
//                    tempPair.second->isEndingNode = true;
//                }
//                previousNode->map.insert(tempPair);
//                index++;
//                previousNode = tempPair.second;
//            }
//
//        } else {
//            int newIndex = 1;
//            TrieNode *node = map[key];
//            while (newIndex < word.length() ) {
//                string newkey = string(1, word[newIndex]);
//                if (node->map.count(newkey) == 0) {
//                    std::pair<string, TrieNode*>tempPair = make_pair(newkey, new TrieNode(newkey));
//                    node->map.insert(tempPair);
//                    node = tempPair.second;
//                } else {
//                    node = node->map[newkey];
//                }
//                if (newIndex == word.length() - 1) {
//                    node->isEndingNode = true;
//                }
//                newIndex++;
//            }
//        }
//    }
//
//    bool search(string word) {
//        if (word.length() < 1) {
//            return false;
//        }
//        int index = 0;
//        unordered_map<string, TrieNode*>tempMap = map;
//        while (index < word.length()) {
//            string key = string(1, word[index]);
//            if (tempMap.count(key) == 0) {
//                return false;
//            } else {
//                if (index == word.length() - 1 && tempMap[key]->isEndingNode) {
//                    return true;
//                }
//                tempMap = tempMap[key]->map;
//
//            }
//            index++;
//        }
//        return false;
//    }
//
//    bool startsWith(string prefix) {
//        if (prefix.length() < 1) {
//            return false;
//        }
//        int index = 0;
//        unordered_map<string, TrieNode*>tempMap = map;
//        while (index < prefix.length()) {
//            string key = string(1, prefix[index]);
//            if (tempMap.count(key) == 0) {
//                return false;
//            } else {
//                tempMap = tempMap[key]->map;
//            }
//            index++;
//        }
//        return index >= prefix.length();
//    }
//};

}

#endif /* ImplementTrie_hpp */
