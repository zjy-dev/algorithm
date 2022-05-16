#include "LeetCode.h"

/**
 * 时间复杂度 => O(n)
 * 空间复杂度 => O(n)
 */
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }

    int n = nums.size();

    // dp[i]表示以i结尾的子数组的最大和
    vector<int> dp(n + 1);
    dp[0] = nums[0];
    int ans = dp[0];
    for (int i = 1; i < n; i++) {
      dp[i] = max(nums[i], nums[i] + dp[i - 1]);
      ans = max(ans, dp[i]);
    }

    return ans;
  }
};