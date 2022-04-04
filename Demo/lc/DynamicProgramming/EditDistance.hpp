//
//  EditDistance.hpp
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/2.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef EditDistance_hpp
#define EditDistance_hpp

#include <stdio.h>
#include "PublicCommon.h"
namespace EditDistance {
/*
 1. 定义dp[i][j] 表示单词a[i]到单词b[j] 之间的编辑距离；对于边界条件 则有dp[i][0]=i dp[0][j]=j
    dp[i][j]=dp[i-1][j-1]    when a[i]==b[j]
    dp[i][j]=min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1   when a[i]!=b[j]
    以单词horse到ros的转换举例：
    当dp[i][j]=d[i-1][j-1]+1，此时表示替换，用单词hors匹配ro，最后的e用s替换
    当dp[i][j]=dp[i-1][j]+1， 此时表示删除，用单词hors匹配ros，删除e
    当dp[i][j]=dp[i][j-1]+1,  此时表示增加，用单词horse匹配ro，最后在结尾添加s
 */

class Solution {
public:
    int minDistance(string a, string b) {
        int m = a.length();
        int n = b.length();
        vector<vector<int>> dp;
        for (int i = 0; i <= m; i++) {
            dp.push_back(vector<int>(n+1, 0));
        }
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]) + 1;
                }
            }
        }
        return dp[m][n];
    }
};


//class Solution {
//public:
//    int minDistance(string a, string b) {
//        int m = a.length();
//        int n = b.length();
//        if (m * n == 0) {
//            return m + n;
//        }
//        vector<vector<int>> dp(m+1, vector<int>(n+1)); //注意定义初始化 二维vector的方法
//        for (int i = 0; i <= m; i++) {
//            dp[i][0] = i;
//        }
//        for (int j = 0; j <= n; j++) {
//            dp[0][j] = j;
//        }
//        for (int i = 1; i <= m; i++) {
//            for (int j = 1; j <= n; j++) {
//                if (a[i-1] == b[j-1]) { // 注意这里的映射string(0,m-1) => dp[1,m]
//                    dp[i][j] = dp[i-1][j-1];
//                } else {
////                    int tempMin = min(dp[i-1][j-1], dp[i][j-1]);
////                    tempMin = min(tempMin, dp[i-1][j]);
////                    dp[i][j] = tempMin + 1;
//                    dp[i][j] = min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]) + 1; //min可以嵌套
//                }
//            }
//        }
//        return dp[m][n];
//    }
//};

}

#endif /* EditDistance_hpp */
