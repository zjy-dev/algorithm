#include "LeetCode.h"

const int X[4] = {0, 0, 1, -1}, Y[4] = {1, -1, 0, 0};

class Solution {
public:
  int r, c;
  vector<vector<int>> dp;
  int longestIncreasingPath(vector<vector<int>> &nums) {
    r = nums.size(), c = nums[0].size();
    dp = vector<vector<int>>(r, vector<int>(c, 0));
    int ans = INT_MIN;
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++)
        ans = max(ans, dfs(i, j, nums));

    return ans;
  }

  int dfs(int i, int j, vector<vector<int>> &nums) {
    if (dp[i][j])
      return dp[i][j];

    dp[i][j] = 1;
    for (int t = 0; t < 4; t++) {
      auto x = i + X[t], y = j + Y[t];

      if (x < 0 or x >= r or y < 0 or y >= c or nums[x][y] <= nums[i][j])
        continue;

      dp[i][j] = max(dp[i][j], dfs(x, y, nums) + 1);
    }

    return dp[i][j];
  }
};