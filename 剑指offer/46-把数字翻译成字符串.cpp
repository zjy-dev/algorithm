#include"LeetCode.h"

// 最淳朴的二维dp
// 时空都是O(n)
class Solution {
public:
    int translateNum(int num) {
 
        string str = " " + to_string(num);
        int n = str.size() - 1;

        // dp[k]表示以k结尾的字符串最多的表示次数
        vector<int> dp(n + 1, 0);

        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            string temp = str.substr(i - 1, 2);
            if (temp >= "10" && temp <= "25") {
                dp[i] = dp[i - 2];
            }
            dp[i] += dp[i - 1];
        }

        return dp[n];
    }
};

// 滚动数组优化后空间降到O(1)
class Solution {
public:
    int translateNum(int num) {
        
        string str = " " + to_string(num);
        int n = str.size() - 1;

        // ans最小也只能表示dp[2]
        // dp[1]只能特判掉
        if (n == 1) {
            return 1;
        }

        // p -> dp[n - 2]
        // q -> dp[n - 1]
        // ans -> dp[n]
        int p = 1, q = 1, ans = 0; 

        for (int i = 2; i <= n; i++) {
            // ans代表的dp[n]在循环开始是0
            ans = 0;
            string temp = str.substr(i - 1, 2);
            if (temp >= "10" && temp <= "25") {
                ans = p;
            }
            ans += q;

            // p, q 向后滚动
            p = q, q = ans;
        }

        // return dp[n]
        return ans;
    }
};