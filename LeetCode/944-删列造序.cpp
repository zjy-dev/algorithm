#include "LeetCode.h"

class Solution {
public:
  int minDeletionSize(vector<string> &strs) {
    if (strs.size() == 0) {
      return 0;
    }

    int ans = 0;
    int row = strs.size(), col = strs[0].size();
    for (int c = 0; c < col; c++) {
      int t = strs[0][c] - 'a';
      for (int r = 1; r < row; r++) {
        if (strs[r][c] - 'a' < t) {
          ans++;
          break;
        }
        t = strs[r][c] - 'a';
      }
    }

    return ans;
  }
};