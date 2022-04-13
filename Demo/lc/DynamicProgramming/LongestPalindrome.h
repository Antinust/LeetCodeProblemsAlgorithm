//
//  LongestPalindrome.h
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/12.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef LongestPalindrome_h
#define LongestPalindrome_h
#include "PublicCommon.h"

namespace LongestPalindrome {
/*
 1. 定义dp[i][j] 为从i到j是否为回文子串，则有下面递推式
 dp[i][j] = dp[i+1][j-1] && s[i]==s[j]      i+1 < j
        = s[i][j]                           i+1 == j
        = true                              i == j
 注意因为递推式中i依赖i+1先求出，故i需要降序遍历；而j依赖j-1 故j升序遍历
 
 2. 拓展中心算法
    枚举所有的「回文中心」并尝试「扩展」，直到无法扩展为止，此时的回文串长度即为此「回文中心」下的最长回文串长度。我们对所有的长度求出最大值，即可得到最终的答案
 
   长度为 1 和 2 的回文中心分别有 n 和 n−1 个，每个回文中心最多会向外扩展O(n) 次
 
 */


//class Solution {
//public:
//    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
//        while (left >= 0 && right < s.size() && s[left] == s[right]) {
//            --left;
//            ++right;
//        }
//        return {left + 1, right - 1};
//    }
//
//    string longestPalindrome(string s) {
//        int start = 0, end = 0;
//        for (int i = 0; i < s.size(); ++i) {
//            auto [left1, right1] = expandAroundCenter(s, i, i);
//            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
//            if (right1 - left1 > end - start) {
//                start = left1;
//                end = right1;
//            }
//            if (right2 - left2 > end - start) {
//                start = left2;
//                end = right2;
//            }
//        }
//        return s.substr(start, end - start + 1);
//    }
//};

//class Solution {
//public:
//    string longestPalindrome(string s) {
//        int maxLen = 1;
//        int len = s.length();
//
//        int left = 0;
//        int right = 0;
//        vector<vector<bool>> dp(len, vector<bool>(len, 0));
//        for (int i = 0; i < len; i++) {
//            dp[i][i] = true;
//        }
//        for (int i = 1; i < len; i++) {
//            dp[i-1][i] = s[i-1] == s[i];
//            // 这里也需要记录left,right
//            if (dp[i-1][i]) {
//                left = i - 1;
//                right = i;
//            }
//        }
//        for (int i = len - 3; i >= 0; i--) {
//            for (int j = i + 2; j < len; j++) {
//                // 因为表达式是先需要知道i+1, j-1，故i降序，j升序遍历
//                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
//                if (dp[i][j]) {
//                    int val = j - i + 1;
//                    if (val > maxLen) {
//                        maxLen = val;
//                        left = i;
//                        right = j;
//                    }
//                    // printf("i:%d j:%d val:%d\r\n", i, j, val);
//                }
//            }
//        }
//
//        return s.substr(left, right - left + 1);
//    }
//};

}

#endif /* LongestPalindrome_h */
