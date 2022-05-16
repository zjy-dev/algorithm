#include "LeetCode.h"

class Solution {
public:
  void setZeroes(vector<vector<int>> &nums) {
    // 统计一下出现了0的行列
    unordered_set<int> rows, cols;
    int row = nums.size(), col = nums[0].size();
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (nums[i][j] == 0) {
          rows.insert(i);
          cols.insert(j);
        }
      }
    }

    // 置0
    for (const auto &r : rows) {
      for (int i = 0; i < col; i++) {
        nums[r][i] = 0;
      }
    }

    for (const auto &c : cols) {
      for (int i = 0; i < row; i++) {
        nums[i][c] = 0;
      }
    }
  }
};