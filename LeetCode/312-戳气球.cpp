#include "LeetCode.h"

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        // 避免特判, 在nums的前后加两个1
        vector<int> val(n + 2);
        val[0] = val[n + 1] = 1;
        for (int i = 1; i <= n; i++) {
            val[i] = nums[i - 1];
        }
        n += 2;

        // dp[i][j]表示戳完开区间(i, j)内的气球所能获得的最大金币数
        vector<vector<int>> dp(n + 10, vector<int>(n + 10, 0));

        // 枚举长度dp, 因为是开区间, 所以len从3开始才有效
        for (int len = 3; len <= n; len++) {
            for (int st = 0; st + len - 1 < n; st++) {
                // (st, ed)就是开区间
                int ed = st + len - 1;
                
                // dp, 枚举最后一个戳爆的气球
                for (int k = st + 1; k < ed; k++) {
                    // 对于最后一个戳爆的气球, 它的左右是st和ed
                    int t = val[k] * val[st] * val[ed];
                    t += dp[st][k] + dp[k][ed];
                    dp[st][ed] = max(dp[st][ed], t);
                }
            }
        }

        return dp[0][n - 1];
    }
};