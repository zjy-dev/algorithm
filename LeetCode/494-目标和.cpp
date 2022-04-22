#include "LeetCode.h"

class Solution {
public:
    int tar;
    int ans = 0;
    int findTargetSumWays(vector<int>& nums, int tar) {
        this->tar = tar;
        dfs(nums, 0, 0);

        return ans;
    }

    void dfs(vector<int>& nums, int pos, int cur) {
        // 递归边界
        if (pos == nums.size()) {
            if (cur == tar) {
                ans++;
            }
            return;
        }

        // 枚举正负号
        dfs(nums, pos + 1, cur + nums[pos]);
        dfs(nums, pos + 1, cur - nums[pos]);
    }
};