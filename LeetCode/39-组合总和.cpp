#include"LeetCode.h"

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<vector<int>> combinationSum(vector<int>& nums, int tar) {
        if (nums.size() == 0) {
            return {};
        }

        dfs(nums, tar, 0);
        return ans;
    }

    // 以选和不选为依据来dfs
    void dfs(vector<int>& nums, int val, int idx) {
        if (val == 0) {
            ans.push_back(temp);
            return;
        }

        if (idx == nums.size() || val < 0) {
            return;
        }

        // 选idx
        temp.push_back(nums[idx]);
        dfs(nums, val - nums[idx], idx);
        temp.pop_back();

        // 不选idx
        dfs(nums, val, idx + 1);
    }
};