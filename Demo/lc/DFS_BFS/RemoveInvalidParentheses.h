//
//  RemoveInvalidParentheses.h
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/8.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef RemoveInvalidParentheses_h
#define RemoveInvalidParentheses_h

#include "PublicCommon.h"
namespace RemoveInvalidParentheses {

/*
 1. calculate the number of '(' and ')' to be removed to make the string become a valid parentheses
 when met '(' lRemove++;
 when met ')' if(lRemove > 0) lRemove--; else if(lRemove == 0) rRemove++
 
 2. iterate over the string by removing the '(' and ')'
 最后结果要去重
 
 递归里面需要使用for循环处理 需不需选取某个元素 index 要更新；
 剪枝：若两个相邻一样的话，处理前一个就行
 */

class Solution {
public:
    bool isValid(string &s) {
        // when rCnt > lCnt return false;
        int i = 0;
        int lCnt = 0;
        int rCnt = 0;
        while (i < s.length()) {
            if (s[i] == '(') {
                lCnt++;
            } else if (s[i] == ')') {
                rCnt++;
                if (rCnt > lCnt) {
                    return false;
                }
            }
            i++;
        }
        return lCnt == rCnt;
    }
    
    void dfs(unordered_set<string> &set, int index, string tempStr, int lRemove, int rRemove) {
        if (lRemove == 0 && rRemove == 0 && isValid(tempStr)) {
            set.insert(tempStr);
            return;
        }
        if (lRemove + rRemove > tempStr.length()) {
            return;
        }
        for (int i = index; i < tempStr.length(); i++) {
            if (i != index && tempStr[i] == tempStr[i - 1]) { // 两个相邻一样的话，处理前一个就行
                continue;
            }
            
            if (lRemove + rRemove > tempStr.length() - i) {
                return;
            }
            if (tempStr[i] == '(' && lRemove > 0) {
                dfs(set, i, tempStr.substr(0, i) + tempStr.substr(i + 1), lRemove-1, rRemove);
            }
            if (tempStr[i] == ')' && rRemove > 0) {
                dfs(set, i, tempStr.substr(0, i) + tempStr.substr(i + 1), lRemove, rRemove-1);
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        vector<string> vec;
        int lRemove = 0;
        int rRemove = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                lRemove++;
            } else if (s[i] == ')') {
                if (lRemove > 0) {
                    lRemove--;
                } else if (lRemove == 0) {
                    rRemove++;
                }
            }
        }
        if (lRemove == 0 && rRemove == 0) {
            return vector<string> {s};
        }
        string tempStr = s;
        unordered_set<string>set;
        dfs(set, 0, tempStr, lRemove, rRemove);
        for (auto it = set.begin(); it != set.end(); it++) {
            vec.push_back(*it);
        }
        return vec;
    }
};

}

#endif /* RemoveInvalidParentheses_h */
