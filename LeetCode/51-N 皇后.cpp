#include "LeetCode.h"

class Solution {
public:
  vector<vector<string>> ans;
  vector<string> temp;
  int n;
  vector<bool> row, col, dg, udg;

  void dfs(int i, int j, int cnt) {
    if (j == n)
      i++, j = 0;
    if (i == n) {
      if (cnt == n)
        ans.push_back(temp);
      return;
    }

    dfs(i, j + 1, cnt);

    if (!row[i] and !col[j] and !dg[i - j + n] and !udg[i + j]) {
      row[i] = col[j] = dg[i - j + n] = udg[i + j] = true;
      temp[i][j] = 'Q';
      dfs(i, j + 1, cnt + 1);
      temp[i][j] = '.';
      row[i] = col[j] = dg[i - j + n] = udg[i + j] = false;
    }
  }

  vector<vector<string>> solveNQueens(int n) {
    this->n = n;
    temp = vector<string>(n, string(n, '.'));
    row.resize(n, false);
    col.resize(n, false);
    dg.resize(2 * n, false);
    udg.resize(2 * n, false);

    dfs(0, 0, 0);
    return ans;
  }
};
