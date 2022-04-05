//
//  PartitionEqualSubsetSum.h
//  Demo
//
//  Created by zcc_imac on 2022/4/5.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef PartitionEqualSubsetSum_h
#define PartitionEqualSubsetSum_h



namespace PartitionEqualSubsetSum {
/*
 从数组中选取一些元素 == 整个数组元素和的一半；定义dp[i][j] 为从0~i区间选取一定元素 满足和为j 是否存在
 则dp[i][j] = dp[i-1][j]                 当a[i]>j时 不选取a[i]
             true                       当a[i]=j时
        dp[i - 1][j] |dp[i-1][j-a[i]]    选取a[i]<j
 
 
 
 注意i/j == 0时的处理
 badcase: [2,2,3,5]
 [1,5,11,5]
 
 if (maxNum > target) {return false;}
 
 可以用状态压缩降到一维
 
 */


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = 0, maxNum = 0;
        for (auto& num : nums) {
            sum += num;
            maxNum = max(maxNum, num);
        }
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target) {
            return false;
        }
        vector<int> dp(target + 1, 0);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int j = target; j >= num; --j) {
                dp[j] |= dp[j - num];
            }
        }
        return dp[target];
    }
};


//class Solution {
//public:
//    bool canPartition(vector<int>& a) {
//        int num = a.size();
//        if (num <= 1) {
//            return false;
//        }
//        int sum = 0;
//        int maxNum = 0;
//        for (int i = 0; i < num; i++) {
//            sum += a[i];
//            maxNum = max(maxNum, a[i]);
//        }
//        if (sum % 2 == 1) {
//            return false;
//        }
//        sum /= 2;
//        if (maxNum > sum) {
//            return false;
//        }
//        vector<vector<bool>> dp(num, vector<bool>(sum + 1, 0));
//        for (int i = 0; i < num; i++) {
//            dp[i][0] = true;
//        }
//
//        dp[0][a[0]] = true; // prune
//        for (int i = 1; i < num; i++) {
//            for (int j = 1; j <= sum; j++) {
//                if (a[i] <= j) {
//                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - a[i]];
//                } else {
//                    dp[i][j] = dp[i-1][j];
//                }
//            }
//        }
//        return dp[num - 1][sum];
//    }
//};

}
#endif /* PartitionEqualSubsetSum_h */
