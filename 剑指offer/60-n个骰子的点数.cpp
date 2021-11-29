#include"LeetCode.h"

class Solution {
public:
    vector<double> dicesProbability(int n) 
    {
        vector<double> ans(6, 1.0 / 6.0);
        for(int i = 2; i <= n; i++)
        {
            vector<double> dp(5 * i + 1);
            for(int j = 0; j < ans.size(); j++)
                for(int k = 0; k < 6; k++)
                    dp[j + k] += ans[j] / 6.0;
            ans = dp;
        }

        return ans;
    }
};