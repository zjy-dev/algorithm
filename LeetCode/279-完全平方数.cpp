#include "LeetCode.h"

class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(n + 1);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      dp[i] = i;
      for (int j = 0; j * j <= i; j++)
        dp[i] = min(dp[i], 1 + dp[i - j * j]);
    }

    return dp[n];
  }
};