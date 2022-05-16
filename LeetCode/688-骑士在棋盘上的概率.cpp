#include "LeetCode.h"

/**
 * 时间复杂度 -> O(n^2 * k), 三重循环
 * 空间复杂度 -> O(n^2 * k)
 */
class Solution {
public:
  // 偏移量数组, 话说这棋的走法真怪啊
  int X[8] = {1, 1, 2, 2, -1, -1, -2, -2};
  int Y[8] = {2, -2, 1, -1, 2, -2, 1, -1};

  double knightProbability(int n, int k, int row, int col) {

    // dp[step][x][y]表示从(x, y)出发, 跳跃step次后留在棋盘上的概率
    // 也就是说, 答案就是dp[k][row][col]
    vector<vector<vector<double>>> dp(
        k + 1, vector<vector<double>>(n, vector<double>(n)));

    // dp边界, 从棋盘任何一点出发, 不跳跃, 必然留在棋盘上, 概率为1
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dp[0][i][j] = 1;
      }
    }

    // 自底向上递推
    // dp[step][x][y]就等于sum(dp[step - 1][x + biasX][y + biasY] / 8)
    // 这是因为方向有8个
    for (int step = 1; step <= k; step++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          for (int x = 0; x < 8; x++) {
            int tx = i + X[x], ty = j + Y[x];
            if (tx < 0 || tx >= n || ty < 0 || ty >= n) {
              continue;
            }
            dp[step][i][j] += (dp[step - 1][tx][ty] / 8);
          }
        }
      }
    }

    // 返回答案
    return dp[k][row][col];
  }
};