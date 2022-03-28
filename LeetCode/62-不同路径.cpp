#include"LeetCode.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp[r][c]代表到达(r, c)坐标的方法数量
        // dp[r][c] = dp[r - 1][c] + dp[r][c - 1]
        // 这是因为机器人只能从左边或者上边走过来
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // dp边界
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }

        // dp
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};