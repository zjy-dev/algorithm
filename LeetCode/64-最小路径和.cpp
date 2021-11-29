#include"LeetCode.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& arr) 
    {
        int m = arr.size(), n = arr[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = arr[0][0];
        for(int i = 1; i < n; i++)
            dp[0][i] = dp[0][i - 1] + arr[0][i];
        for(int i = 1; i < m; i++)
            dp[i][0] = dp[i - 1][0] + arr[i][0];
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
        return dp[m][n];
    }
};
