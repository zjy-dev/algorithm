#include"LeetCode.h"

/**
 * 时间复杂度 -> O(n * n), 双重循环
 * 空间复杂度 -> O(n)
 */
class Solution {
public:
    int cuttingRope(int n) {
        // 题干要求必须拆至少两段, 但实际上2和3不拆比拆更长
        // 也就是说, 2和3是dp的边界条件
        // 所以对于长度小于等于3的绳子, 不需要dp, 也就需要特判
        if (n == 2) {
            return 1;
        } else if (n == 3) {
            return 2;
        }

        vector<int> dp(n + 1, 0);
        // 题干要求必须拆至少两段, 但实际上2和3不拆比拆更长, 作为边界
        dp[1] = 1, dp[2] = 2, dp[3] = 3;

        for (int i = 4; i <= n; i++) {
            for (int j = 1; j <= (i >> 1); j++) {
                dp[i] = max(dp[i], dp[j] * dp[i - j]);
            }
        }

        return dp[n];
    }
};