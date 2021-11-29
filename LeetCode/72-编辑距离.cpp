#include"LeetCode.h"

class Solution {
public:
    int minDistance(string s1, string s2) 
    {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i = 0; i <= m; i++)
            dp[i][0] = i;
        for(int i = 0; i <= n; i++)
            dp[0][i] = i;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                int t = s1[i - 1] == s2[j - 1] ? 0 : 1;
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + t);
            }
        
        return dp[m][n];
    }
};