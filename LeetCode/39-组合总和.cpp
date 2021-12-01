#include"LeetCode.h"

class Solution {
public:
    int n;
    vector<int> nums, temp;
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        n = nums.size();
        this->nums = nums;

        dfs(0, target);
        return ans;
    }

    void dfs(int pos, int x)
    {
        if(!x)
        {
            ans.push_back(temp);
            return;
        }

        if(pos >= n or x < 0)
            return;

        temp.push_back(nums[pos]);
        dfs(pos, x - nums[pos]);
        temp.pop_back();

        dfs(pos + 1, x);
    }
};