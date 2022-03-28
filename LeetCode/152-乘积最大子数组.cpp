#include"LeetCode.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int dpMin = nums[0], dpMax = nums[0];
        int ans = nums[0];

        // 尝试以每一位结尾
        for (int i = 1; i < n; i++) {
            // 这里要记录一下初始值, 否则dpMax的更新会被变化过的dpMin影响
            int mx = dpMax, mn = dpMin;

            dpMin = min(nums[i], min(mn * nums[i], mx * nums[i]));
            dpMax = max(nums[i], max(mn * nums[i], mx * nums[i]));

            ans = max(ans, dpMax);
        }

        return ans;
    }
};