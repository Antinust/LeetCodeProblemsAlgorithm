//
//  MinimumSizeSubarraySum.h
//  Demo
//
//  Created by zcc_imac on 2022/4/30.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef MinimumSizeSubarraySum_h
#define MinimumSizeSubarraySum_h
#import "PublicCommon.h"
namespace MinimumSizeSubarraySum {
/*
求长度最小的子数组，满足和>= target
 1. sliding window
    设置两个index：l, r，初始时指向起始位置，r++，直到子数组和>=target，记录此时的长度；然后l++，若仍然满足子数组和>=target则记录此时的长度。
 不够熟练，需要多练习双指针之类的
 */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& a) {
        int ans = INT_MAX;
        int l = 0;
        int r = 0;
        int sum = 0;
        int len = a.size();
        while (r < len) {
            if (a[r] >= target) {
                return 1;
            }
            sum += a[r];
            while(sum < target && ++r < len) {
                sum += a[r];
            }

            while (sum >= target && r >= l) {
                // printf("sum:%d l:%d r:%d\r\n", sum, l, r);
                ans = min(ans, r - l + 1);
                sum -= a[l];
                l++;
            }
            r++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};


}

#endif /* MinimumSizeSubarraySum_h */
