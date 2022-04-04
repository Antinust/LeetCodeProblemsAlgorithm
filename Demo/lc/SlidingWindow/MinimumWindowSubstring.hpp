//
//  MinimumWindowSubstring.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/31.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef MinimumWindowSubstring_hpp
#define MinimumWindowSubstring_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace MinimumWindowSubstring {
/*
 1. slidingWindow+hashTable
 使用两个指针/下标 指向s中的滑动窗口的两侧，r++直到窗口包含t，l++直到窗口不包含t，l++的同时记录最小的窗口大小
 比较滑动窗口是否包含t时，可以借助hashMap和needCnt，hashMap记录每个字母出现的次数，记录t中字母出现次数大于1的个数为needCnt
 
 当needCnt==0时表示滑动窗口中找到了一个子串包含t，当--map[str[i]] == 0时表示 找到了t中一个字母needCnt--
 当++map[str[i]]==1时，即滑动窗口左边界右移时，needCnt++;
 
 */

class Solution {
public:
    string minWindow(string s, string t) {
        const int sLen = s.length();
        const int tLen = t.length();
        if (sLen < tLen) {
            return "";
        }
        int needCnt = 0;
        unordered_map<int, int>map;
        string resultStr = "";
        for (int i = 0; i < tLen; i++) {
            map[t[i]]++;
        }
        needCnt = map.size();
        int minLen = INT_MAX;
        int lInd = 0;  //lIndex
        int rInd = 0;  //rIndex
        
        while (rInd < sLen) {
            if (--map[s[rInd]] == 0) {
                needCnt--;
            }
            while (needCnt == 0 && lInd < sLen) {
                int winLen = rInd - lInd + 1;
                if (winLen < minLen) {
                    minLen = winLen;
                    resultStr = s.substr(lInd, winLen);
                }
                if (++map[s[lInd]] == 1) {
                    needCnt++;
                }
                lInd++;
            }
            rInd++;
        }
        return resultStr;
    }
};

}

#endif /* MinimumWindowSubstring_hpp */
