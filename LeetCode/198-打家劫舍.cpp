#include"LeetCode.h"

class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if(!n)
            return 0;
        int ans = nums[0], dp1 = nums[0], dp0 = 0; 

        for(int i = 1; i < n; i++)
        {
            dp1 = dp0 + nums[i];
            dp0 = max(dp1, dp0) + nums[i];
            ans = max(dp1, dp0);
        }

        return ans;
    }
};  