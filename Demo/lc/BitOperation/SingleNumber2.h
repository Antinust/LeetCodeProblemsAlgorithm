//
//  SingleNumber2.h
//  Demo
//
//  Created by zcc_imac on 2022/4/30.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef SingleNumber2_h
#define SingleNumber2_h

namespace SingleNumber2 {
/*
 1. 统计负数的digit位数时，需要加上第31位，即dp[31]++，注意对于INT_MIN不需要处理
 2. 最后若最高位的个数%3==1，若之前累加的和为0，说明结果为INT_MIN直接返回INT_MIN，否则返回-ans
 
 */

class Solution {
public:
    int singleNumber(vector<int>& a) {

        vector<int> dp (sizeof(int) * 8, 0);
        int len = dp.size();

        for (int num : a) {
            // printf("num =%d\r\n", num );
            if (num < 0) {
                dp[len - 1]++;
            }
            int cnt = 0;
            // INT_MIN 需要特殊处理
            if (num != INT_MIN) {
                while (num) {
                    if (num & 1) {
                        dp[cnt]++;
                    }
                    num /= 2;
                    cnt++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < len; i++) {
            // printf("dp[%d]=%d\r\n", i , dp[i]);
            int kthDigitNum = dp[i] % 3;
            if (i == len - 1) {
                if (kthDigitNum == 1) {
                    // printf("ans=%d\r\n", ans);
                    return ans == 0 ? INT_MIN : -ans;
                }
            } else {
                ans += pow(2, i) * (kthDigitNum);
            }
        }
        return ans;
    }
};

}


#endif /* SingleNumber2_h */
