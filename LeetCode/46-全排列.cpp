#include"LeetCode.h"

class Solution {
public:
    int n;
    vector<vector<int>> ans;
    vector<int> nums;
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        sort(nums.begin(), nums.end());
        dfs(0);
        return ans;
    }

    void dfs(int x)
    {
        if(x == n)
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i = x; i < n; i++)
        {
            swap(nums[x], nums[i]);
            dfs(x + 1);
            swap(nums[x], nums[i]);
        }
    }
};