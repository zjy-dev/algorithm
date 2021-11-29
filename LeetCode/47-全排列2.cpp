#include"LeetCode.h"

class Solution {
public:
    int n;
    vector<vector<int>> ans;
    vector<int> nums;
    vector<int> temp;
    vector<bool> vis;
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        this->nums = nums;
        n = nums.size();
        vis.resize(n, false);

        sort(this->nums.begin(), this->nums.end());
        dfs(0);
        return ans;
    }

    void dfs(int x)
    {
        if(x == n)
        {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < n; i++)
        {
            // !vis[i - 1] : 如果前面重复的数已经填过了, 那么即使重复也可以继续填
            if(vis[i] or (i >= 1 and nums[i] == nums[i - 1] and !vis[i - 1]))
                continue;

            vis[i] = true, temp.push_back(nums[i]);
            dfs(x + 1);
            vis[i] = false, temp.pop_back();
        }
    }
};