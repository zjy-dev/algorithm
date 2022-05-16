#include "LeetCode.h"

class Solution {
public:
  int countSquares(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));
    int ans = 0;

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (!matrix[i][j])
          continue;

        if (!i or !j) {
          ans++;
          dp[i][j] = 1;
          continue;
        }

        dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
        ans += dp[i][j];
      }

    return ans;
  }
};