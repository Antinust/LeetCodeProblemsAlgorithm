//
//  RegularExpressionMatching.h
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/9.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef RegularExpressionMatching_h
#define RegularExpressionMatching_h
#include "PublicCommon.h"

namespace RegularExpressionMatching {
/*
 https://leetcode-cn.com/problems/regular-expression-matching/solution/shou-hui-tu-jie-wo-tai-nan-liao-by-hyj8/
 1. s[i]==p[j]||p[j]=='.' => dp[i][j]=dp[i-1][j-1]
    
 2. p[j]=='*'
    若p[j-1]=='.'|| s[i]==p[j-1]
        去掉前面一个元素    dp[i][j]=dp[i][j-2]
        匹配前面一个元素    dp[i][j]=dp[i-1][j-2]
        匹配前面>=2个元素   dp[i][j]=dp[i-1][j]
    若s[i]==p[j-2]
        dp[i][j]=d[i][j-2]
 因为题目里面保证了 出现*的时候，必定有一个前缀，故当p[j-1]=='*'时，j>1及j-2存在
 因为要满足递推式，故dp[0][0]需为true，注意base case；dp[0][j]的处理
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp (m + 1, vector<bool>(n + 1, 0));
        // base case
        dp[0][0] = true;
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*'){
                    if (p[j - 2] == '.' || s[i - 1] == p[j - 2]) {
                        dp[i][j] = dp[i][j - 2] | dp[i - 1][j - 2] | dp[i - 1][j];
                    } else {
                        dp[i][j] = dp[i][j-2];
                    }
                }
            }
        }
        return dp[m][n];
    }
};

}


#endif /* RegularExpressionMatching_h */
