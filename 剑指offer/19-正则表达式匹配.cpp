#include"LeetCode.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        s = " " + s, p = " " + p;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++)
            dp[0][i] = p[i] == '*' ? dp[0][i - 2] : false;

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                if(s[i] == p[j] or p[j] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else if(p[j] == '*')
                    if(p[j - 1] != s[i] and p[j - 1] != '.')
                        dp[i][j] = dp[i][j - 2];
                    else
                        dp[i][j] = dp[i - 1][j] or dp[i][j - 2] or dp[i][j - 1];


        return dp[m][n];
    }
};