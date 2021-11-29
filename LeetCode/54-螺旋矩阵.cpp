#include"LeetCode.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& nums) 
    {
        vector<int> ans;
        int u = 0, d = nums.size() - 1, l = 0, r = nums[0].size() - 1;
        while(true)
        {
            for(int i = l; i <= r; i++)
                ans.push_back(nums[u][i]);
            if(++u > d)
                break;
            for(int i = u; i <= d; ++i) 
                ans.push_back(nums[i][r]); 
            if(--r < l) 
                break; 
            for(int i = r; i >= l; --i) 
                ans.push_back(nums[d][i]); 
            if(--d < u) 
                break;
            for(int i = d; i >= u; --i) 
                ans.push_back(nums[i][l]); 
            if(++l > r) 
                break; 
        }

        return ans;
    }
};
