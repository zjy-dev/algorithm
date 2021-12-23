#include"LeetCode.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == '0')
                    continue;
                if(!i or !j)
                {
                    dp[i][j] = 1;
                    ans = max(ans, dp[i][j]);
                    continue;
                }

                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                ans = max(ans, dp[i][j]);
            }
        
        return ans * ans;
    }
};