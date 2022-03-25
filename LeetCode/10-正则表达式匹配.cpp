#include"LeetCode.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        
        s = " " + s, p = " " + p;

        // dp[i][j]表示s[:i]和p[:j]是否匹配
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // dp边界是dp[0][...]和dp[...][0], 当然了, dp[0][0]为true
        dp[0][0] = true;

        // dp[0][1:]要根据'*'来判断
        for (int i = 1; i <= n; i++) {
            dp[0][i] = (p[i] == '*') ? dp[0][i - 2] : false;
        }

        // dp[1:][0]全部是false, 无需初始化

        // dp
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // 以s[i]和p[j]在该位的情况进行讨论
                if (s[i] == p[j] || p[j] == '.') { // 这种情况最简单
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j] == '*') { 
                    // 如果s[i]和p[j - 1]不相等, 那么"x*"起到的作用就是选0次x, 也就是直接忽略p[j - 1]和p[j]
                    if (s[i] != p[j - 1] && p[j - 1] != '.') {
                        dp[i][j] = dp[i][j - 2];
                    } else { // 如果s[i]和p[j - 1]相等, 那么"x*"可以选多次x, 当然也可以选0次
                    // dp[i][j - 2]是选0次
                    // dp[i - 1][j]是选多次(1次或以上)
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
};
