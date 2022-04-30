//
//  MaximumLengthOfRepeatedSubarray.h
//  Demo
//
//  Created by zcc_imac on 2022/4/30.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef MaximumLengthOfRepeatedSubarray_h
#define MaximumLengthOfRepeatedSubarray_h

namespace MaximumLengthOfRepeatedSubarray {
/*
 子序列默认不连续，子数组默认连续
 1. DP:
    定义dp[i][j]为以a[i] b[j]结尾的最大重复子数组长度，
    dp[i][j] = dp[i-1][j-1] + 1      a[i]==b[j]
                0                    a[i]!=b[j]
 
 2. 滑动窗口
 
 */

class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        int m = a.size();
        int n = b.size();
        int ans = INT_MIN;
        
        vector<vector<int>>dp (m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m ; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};

class Solution2 {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        int m = a.size();
        int n = b.size();
        int ans = INT_MIN;
        
        for (int i = 0; i < m && i < n; i++) {
            int cnt = 0;
            for (int j = i; j < m && j < n ;j++) {
                if (a[j] == b[j]) {
                    cnt++;
                } else {
                    break;
                }
            }
            ans = max(ans, cnt);
            // printf("1 cnt:%d\r\n", ans);
        }

        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < m - i && j < n; j++) {
                // printf("test i:%d j:%d i+j:%d\r\n", i, j, i+j);

                if (a[i+j] == b[j]) {
                    cnt++;
                } else {
                    ans = max(ans, cnt);
                    cnt = 0;
                    // break;
                }
                 ans = max(ans, cnt);
            }
            
            //  printf("2 cnt:%d\r\n", ans);
        }
        for (int i = 0; i < n ; i++) {
            int cnt = 0;
            for (int j = 0; j < n - i && j < m;j++) {
                if (b[i+j] == a[j]) {
                    cnt++;
                } else {
                    ans = max(ans, cnt);
                    cnt = 0;
                    // break;
                }
            }
            ans = max(ans, cnt);
            // printf("3 cnt:%d\r\n", ans);
        }

        return ans == INT_MIN ? 0 : ans;
    }
};

}

#endif /* MaximumLengthOfRepeatedSubarray_h */
