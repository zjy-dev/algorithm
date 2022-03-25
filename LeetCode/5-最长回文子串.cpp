#include"LeetCode.h"

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        // dp[i][j]表示[i, j]的子串是不是回文串
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

        // 长度为1, 当然是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        

        // 记录答案
        int start = 0, length = 1;

        // 枚举长度dp, 从2开始枚举即可
        for (int len = 2; len <= n; len++) {
            for (int st = 0; st + len - 1 < n; st++) {
                int ed = st + len - 1;

                // 特判一下长度为2的情况
                if (len == 2) {
                    dp[st][ed] = (s[st] == s[ed]);
                } else {
                    dp[st][ed] = (s[st] == s[ed] && dp[st + 1][ed - 1]); 
                }

                if (dp[st][ed] == true && len > length) {
                    start = st;
                    length = len;
                }
            }
        }

        return s.substr(start, length);
    }
};