//
//  IntegerBreak.h
//  Demo
//
//  Created by Zhuo,Chuncai on 2022/4/29.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef IntegerBreak_h
#define IntegerBreak_h
#include "PublicCommon.h"
namespace IntegerBreak {
/*
 根据递推式，寻找规律
 dp[n] = max(dp[i] *(n-i), i*(n-i))   i in [1, n - 1]
 */
class Soluton {
public:
    int integerBreak(int n) {
        vector<int>dp (n + 1, 1);
        for (int i = 3; i <= n; i++) {
            int maxV = 1;
            for (int j = 1; j < i; j++) {
                maxV = max(maxV, dp[j] * (i - j));
                maxV = max(maxV, j * (i - j));
            }
            dp[i] = maxV;
        }
        return dp[n];
    }
};

}

#endif /* IntegerBreak_h */
