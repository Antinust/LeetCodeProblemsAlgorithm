//
//  FindNumberOfLIS.h
//  Demo
//
//  Created by zcc_imac on 2022/4/5.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef FindNumberOfLIS_h
#define FindNumberOfLIS_h
#import "PublicCommon.h"

namespace FindNumberOfLIS {
/*
 dp[i] 表示以i结尾的最长子序列的长度
 cnt[i] 表示以i结尾的最长子序列的个数
 
 当num[i]>num[j]时，
    若dp[j]+1 > dp[i]则说明首次出现了j比之前记录的dp[i]值都大，故cnt[i]=cnt[j]
    若dp[j]+1 == dp[i] 则说明之前出现过dp[i]的最大值，故cnt[i]+=cnt[j]
 
    注意编码过程中tempMax与dp[j]的比较处理？
 
    LIS可能存在多个，需要都加上，比如[1,3,2]
 
 badcase: [1,2,4,3,5,4,7,2]
 
 
 */
lc/LCSolutionImpl.h
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(), 1);
        vector<int>cnt(nums.size(), 1);

        int lis = 1;
        for (int i = 1; i < nums.size(); i++) {
            int tempMax = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] > tempMax) {
                        cnt[i] = cnt[j];
                    } else if (dp[j] == tempMax){
                        cnt[i] += cnt[j];
                    }
                    tempMax = max(tempMax, dp[j]);
                }
            }
            dp[i] = tempMax + 1;
            if (dp[i] > lis) {
                lis = dp[i];
            }
        }
        
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (dp[i] == lis){
                result += cnt[i];
            }
        }
        
        return result;
    }
};

}

#endif /* FindNumberOfLIS_h */
