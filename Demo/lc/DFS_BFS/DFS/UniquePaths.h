//
//  UniquePaths.h
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/13.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef UniquePaths_h
#define UniquePaths_h
namespace UniquePaths {
/*
 1. dp[i][j] = dp[i-1][j] + dp[i][j-1]
 初始化 dp[i][0]=dp[0][j]=1，因为只能向右、下移动，故上边界及左边界的值都为1
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

}

#endif /* UniquePaths_h */
