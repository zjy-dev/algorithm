#include"LeetCode.h"

class Solution {
public:
    int cuttingRope(int n) 
    {
        if(n < 2)
            return 0;
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        
        vector<int> dp(n + 1, 0);
        dp[1] = 1, dp[2] = 2, dp[3] = 3;
        for(int i = 3; i <= n; i++)
            for(int j = 1; j <= i >> 1; j++)
                dp[i] = max(dp[i], dp[j] * dp[i - j]);
            
        return dp[n];
    }
};