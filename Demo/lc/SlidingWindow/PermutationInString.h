//
//  PermutationInString.h
//  Demo
//
//  Created by zcc_imac on 2022/4/30.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef PermutationInString_h
#define PermutationInString_h
#import "PublicCommon.h"
namespace PermutationInString {
/*
 1. slidingWindow
    若两个字符属于某个字符的全排列，比如abc cba，则必有的一个性质：每个不同字母的个数相同
    维护一个cnt[26]的vector 存储s1[i]-'a'的个数， 维护一个differentLettersCnt的变量，当differentLettersCnt=0时，表示存在
 
    维护一个固定长度为n的window， 窗口右移动的时候，
        移除窗口最左侧的值: if(++dp[s2[i-len1]-'a'] == 1) differentLettersCnt++;
        把新元素加入: if(--dp[s2[i]-'a'] == 0) differentLettersCnt--;
 
    
    
 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if (len1 > len2) {
            return false;
        }
        vector<int> dp(26, 0);
        for (int i = 0; i < len1; i++) {
            dp[s1[i] - 'a']++;
        }
        int differentLettersCnt = 0;
        for (int i = 0; i < 26; i++) {
            if (dp[i] > 0) {
                differentLettersCnt++;
            }
        }

        for (int i = 0; i < len1; i++) {
            if (--dp[s2[i] - 'a'] == 0) {
                differentLettersCnt--;
            }
        }
        if (differentLettersCnt == 0) {
            // printf(" differentLettersCnt = 0 \r\n");
            return true;
        }

        for (int i = len1; i < len2; i++) {
            if (++dp[s2[i - len1] - 'a'] == 1) {
                differentLettersCnt++;
            }
            if (--dp[s2[i] - 'a'] == 0) {
                differentLettersCnt--;
            }
            if (differentLettersCnt == 0) {
                // printf(" i:%d \r\n", i);
                return true;
            }
        }
        return false;
    }
};


}

#endif /* PermutationInString_h */
