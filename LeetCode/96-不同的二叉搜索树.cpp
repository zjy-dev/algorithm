#include"LeetCode.h"

class Solution {
public:
    int numTrees(int n) {
        // dp[k]表示k个节点能组成的二叉搜索树数量
        vector<int> dp(n + 1);

        // 0和1作为dp边界
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            // 对dp[i], 以根的情况讨论进行叠加即可
            for (int root = 1; root <= i; root++) {
                dp[i] += dp[root - 1] * dp[i - root];
            }
        }

        // dp[n]就是答案
        return dp[n];
    }
};