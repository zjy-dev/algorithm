#include "LeetCode.h"

class Solution {
public:
  int minPathSum(vector<vector<int>> &nums) {
    int row = nums.size(), col = nums[0].size();

    // dp[r][c]表示到达(r, c)的最小路径和
    // dp[r][c] = min(dp[r - 1][c], dp[r][c - 1]) + nums[r][c]
    vector<vector<int>> dp(row + 1, vector<int>(col + 1));
    dp[0][0] = nums[0][0];

    // dp边界
    // 第0行和第0列的走法是唯一的
    for (int i = 1; i < row; i++) {
      dp[i][0] = dp[i - 1][0] + nums[i][0];
    }
    for (int i = 1; i < col; i++) {
      dp[0][i] = dp[0][i - 1] + nums[0][i];
    }

    // dp
    for (int r = 1; r < row; r++) {
      for (int c = 1; c < col; c++) {
        dp[r][c] = min(dp[r - 1][c], dp[r][c - 1]) + nums[r][c];
      }
    }

    return dp[row - 1][col - 1];
  }
};