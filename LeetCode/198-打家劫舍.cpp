#include "LeetCode.h"

class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) {
      return nums[0];
    }

    // dp[i]表示抢劫i最多能获得多少钱
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    int ans = max(dp[0], dp[1]);

    for (int i = 2; i < n; i++) {
      // 不能选相邻
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
      ans = max(ans, dp[i]);
    }

    return ans;
  }
};