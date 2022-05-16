#include "LeetCode.h"

class Solution {
public:
  int nthUglyNumber(int n) {
    int a = 1, b = 1, c = 1;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      int n2 = dp[a] * 2, n3 = dp[b] * 3, n4 = dp[c] * 5;
      dp[i] = min(n2, min(n3, n4));
      if (dp[i] == n2)
        a++;
      if (dp[i] == n3)
        b++;
      if (dp[i] == n4)
        c++;
    }
    return dp[n];
  }
};