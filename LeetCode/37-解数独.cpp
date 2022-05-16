#include "LeetCode.h"

class Solution {
public:
  bool ok = false;
  bool row[9][10], col[9][10], block[3][3][10];

  void solveSudoku(vector<vector<char>> &arr) {
    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);
    memset(block, 0, sizeof block);

    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++)
        if (arr[i][j] != '.') {
          auto val = arr[i][j] - '0';
          row[i][val] = col[j][val] = block[i / 3][j / 3][val] = true;
        }

    dfs(0, 0, arr);
  }

  void dfs(int r, int c, vector<vector<char>> &arr) {
    if (c > 8)
      r++, c = 0;

    if (r > 8) {
      ok = true;
      return;
    }

    if (arr[r][c] != '.') {
      dfs(r, c + 1, arr);
      return;
    }

    for (int i = 1; i <= 9; i++)
      if (row[r][i] == false and col[c][i] == false and
          block[r / 3][c / 3][i] == false) {
        row[r][i] = col[c][i] = block[r / 3][c / 3][i] = true;
        arr[r][c] = i + '0';

        dfs(r, c + 1, arr);
        if (ok)
          return;

        arr[r][c] = '.';
        row[r][i] = col[c][i] = block[r / 3][c / 3][i] = false;
      }
  }
};