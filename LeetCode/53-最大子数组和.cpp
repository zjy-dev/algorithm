#include "LeetCode.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];

        // dp[k]是以k结尾的连续子数组的最大和
        vector<int> dp(n + 1, 0);

        // dp边界
        dp[0] = nums[0];

        // dp
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};