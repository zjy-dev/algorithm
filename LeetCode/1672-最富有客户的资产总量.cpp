#include "LeetCode.h"

class Solution {
public:
  int maximumWealth(vector<vector<int>> &nums) {
    // 简单题
    int row = nums.size(), col = nums[0].size();
    int ans = 0;
    for (int i = 0; i < row; i++) {
      int t = 0;
      for (int j = 0; j < col; j++) {
        t += nums[i][j];
      }

      ans = max(ans, t);
    }

    return ans;
  }
};