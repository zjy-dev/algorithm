#include"LeetCode.h"


class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);

        return ans;
    }

    // 模板题, 选取子集
    void dfs(vector<int>& nums, int idx) {
        int n = nums.size();

        if (idx == n) {
            ans.push_back(temp);
            return;
        }

        // 选该数字
        temp.push_back(nums[idx]);
        dfs(nums, idx + 1);
        temp.pop_back();

        // 不选该数字
        dfs(nums, idx + 1);
    }
};