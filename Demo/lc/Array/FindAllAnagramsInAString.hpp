//
//  FindAllAnagramsInAString.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/3/27.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef FindAllAnagramsInAString_hpp
#define FindAllAnagramsInAString_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace FindAllAnagramsInAString {
/*
 1. 定义一个数组cnt[26] 表示在字符串p中英文字母a~z出现的次数，遍历p，若cnt[i]>0则a++；
    遍历s 当加入一个字符时 若 --cnt[i] == 0 则b++；当减少一个字符时 若++cnt[i]==1则b--
    当a==b时 加入到数组
    
    
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.length();
        int pLen = p.length();
        vector<int> vec;
        if (sLen < pLen) {
            return vec;
        }
        vector<int> cnt(26, 0);
        int pCntCharFreqGTOne = 0;
        int sCntCharFreqGTOne = 0;
        for (int i = 0; i < pLen; i++) {
            if (++cnt[p[i] - 'a'] == 1) {
                pCntCharFreqGTOne++;
            }
        }
        for (int i = 0; i < pLen; i++) {
            if (--cnt[s[i] - 'a'] == 0) {
                sCntCharFreqGTOne++;
            }
        }
        if (pCntCharFreqGTOne == sCntCharFreqGTOne) {
            vec.push_back(0);
        }
        
        for (int i = pLen; i < sLen; i++) {
            //移除 i-pLen
            if (++cnt[s[i-pLen] - 'a'] == 1) {
                sCntCharFreqGTOne--;
            }
            //添加i的
            if (--cnt[s[i] - 'a'] == 0) {
                sCntCharFreqGTOne++;
            }
            if (sCntCharFreqGTOne == pCntCharFreqGTOne) {
                vec.push_back(i - pLen + 1);
            }
        }
        return vec;
    }
};
}

#endif /* FindAllAnagramsInAString_hpp */
