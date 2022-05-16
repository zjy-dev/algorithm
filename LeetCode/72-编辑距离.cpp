#include "LeetCode.h"

class Solution {
public:
  int minDistance(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    s1 = " " + s1;
    s2 = " " + s2;

    // dp[i][j]表示i和j之间的最短编辑距离
    // 注意 s1变成s2 和 s2变成s1 本质上没有区别
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // dp边界, 空字符串变成str的操作数是固定的len(str)
    for (int i = 0; i <= m; i++) {
      dp[i][0] = i;
    }
    for (int i = 0; i <= n; i++) {
      dp[0][i] = i;
    }

    // dp
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        // 考虑最后一步的操作类型

        // 1.插入, 删除
        dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1;

        // 2.替换
        if (s1[i] == s2[j]) { // 末尾相等则无需替换
          dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
        } else { // 末尾不等则需要替换
          dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }
      }
    }

    return dp[m][n];
  }
};