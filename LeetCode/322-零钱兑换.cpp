#include "LeetCode.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int tar) {
        int n = coins.size();

        // dp[i]是题干的子问题
        // tar + 10的含义: 题干要求最小硬币数, 更新时需要不断用min更新
        // 因此初始化的大一些即可, 且tar最多由tar枚硬币组成, 因此初始化成比tar大即可
        // 当返回结果时, 如果dp[tar] > tar就直接返回-1
        // 因为如果没有方案合法, 那么dp[tar]只会大于等于tar + 10
        vector<int> dp(tar + 1, tar + 10);

        // dp边界, 组成0元无需硬币
        dp[0] = 0;

        // dp
        for (int i = 1; i <= tar; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= coins[j]) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[tar] > tar ? -1 : dp[tar];
    }
};