//
//  BestTimeToBuyAndSellStockWithCooldown.h
//  Demo
//
//  Created by zcc_imac on 2022/4/6.
//  Copyright © 2022 Zhuo,Chuncai. All rights reserved.
//

#ifndef BestTimeToBuyAndSellStockWithCooldown_h
#define BestTimeToBuyAndSellStockWithCooldown_h

#import "PublicCommon.h"

namespace BestTimeToBuyAndSellStockWithCooldown {

/*
 参考 https://leetcode-cn.com/circle/article/qiAgHn/
 
 定义t[i][k] 为第i天进行k次操作所能得到的最大值，
 t[i][k][0] 为第i天进行k次操作 持有0份股票所能得到的最大值
 t[i][k][1] 为第i天进行k次操作 持有1份股票所能得到的最大值
 通用状态转义表达式如下：
 t[i][k][0]= max(t[i-1][k][0], t[i-1][k][1]+price[i])   t[i-1][k][1]+price[i]表示第i-1天有股票，第i天操作卖掉
 t[i][k][1]= max(t[i-1][k][1], t[i-1][k][0]-price[i])   t[i-1][k][0]-price[i]表示第i-1天没有股票，第i天操作买入
 
 包含冷却期的表达式如下：
 t[i][k][0]= max(t[i-1][k][0], t[i-1][k][1]+price[i])   t[i-1][k][1]+price[i]表示第i-1天有股票，第i天操作卖掉
 t[i][k][1]= max(t[i-1][k][1], t[i-2][k][0]-price[i])   因为第i天要买入，故第i-1天不能操作，只能在第i-2天卖到或不操作 t[i-1][k][0]-price[i]替换为t[i-2][k][0]-price[i]
 
 注意dp[0][1]及dp[i-2]的处理
 最终结果为t[n-1][k][0]
 
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) {
            return 0;
        }
        vector<vector<int>>dp(len, vector<int>(2, 0));
        dp[0][1] = -prices[0]; //第0天买入后的最大值为-prices[0]
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], (i >= 2 ? dp[i-2][0] : 0) - prices[i]);
        }
        return dp[len-1][0];
    }
};

}

namespace BestTimeToTradeStock {
/*
 1、使用imin 记录已经遍历过的 数组的 最小值；用若a[i]>imin, 用dp数组存储当前元素与imin的差值
 2、找到dp数组中的最大值
 */
class Solution {
public:
    int maxProfit(vector<int>& a) {
        int len = a.size();
        int imin = a[0];
        vector<int> dp (len, 0);
        for (int i = 1; i < len; i++) {
            if (a[i] > imin) {
                dp[i] = a[i] - imin;
            }
            imin = min(a[i], imin);
        }
        int ans = 0;
        for (int j = 0; j < len; j++) {
            ans = max(ans, dp[j]);
        }
        return ans;
    }
};
}

#endif /* BestTimeToBuyAndSellStockWithCooldown_h */
