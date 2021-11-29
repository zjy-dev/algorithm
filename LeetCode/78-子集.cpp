#include"LeetCode.h"

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    int n;
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        n = nums.size();
        dfs(nums, 0);
        return ans;
    }

    void dfs(vector<int>& nums, int pos)
    {
        if(pos == n)
        {
            ans.push_back(temp);
            return;
        }
        //不选pos
        dfs(nums, pos + 1);

        //选pos
        temp.push_back(nums[pos]);
        dfs(nums, pos + 1);
        temp.pop_back();
    }
};