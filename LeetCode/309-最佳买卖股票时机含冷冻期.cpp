#include "LeetCode.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;

        // dp[i][0]: 手上持有股票的最大收益
        // dp[i][1]: 手上不持有股票，并且i + 1处于冷冻期中的累计最大收益
        // dp[i][2]: 手上不持有股票，并且i + 1不在冷冻期中的累计最大收益
        // 我们可以用滚动数组, a b c去代替dp[i][*]
        int a = 0, b = 0, c = 0;

        // dp边界, 第0天只能买入股票
        a = -prices[0];

        // dp, 逻辑很简单, 仔细体会即可
        for (int i = 1; i < n; i++) {
            int ta = a, tb = b, tc = c;
            a = max(ta, tc - prices[i]);
            b = ta + prices[i];
            c = max(tc, tb);
        }

        return max(b, c);
    }
};