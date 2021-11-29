#include"LeetCode.h"

class Solution {
public:
    int maxValue(vector<vector<int>>& nums) 
    {
        if(!nums.size())
            return 0;
        int r = nums.size(), c = nums[0].size();
        vector<vector<int>> dp(r, vector<int>(c, 0));
        dp[0][0] = nums[0][0];
        for(int i = 1; i < r; i++)
            dp[i][0] = dp[i - 1][0] + nums[i][0];
        for(int j = 1; j < c; j++)
            dp[0][j] = dp[0][j - 1] + nums[0][j];
        for(int i = 1; i < r; i++)
            for(int j = 1; j < c; j++)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + nums[i][j];
        
        return dp[r - 1][c - 1];
    }
};