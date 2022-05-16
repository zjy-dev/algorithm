#include "LeetCode.h"

class Solution {
public:
  bool canJump(vector<int> &nums) {
    // 不断更新能到达的最远距离
    int maxLen = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      if (i > maxLen) { // 快速失败
        return false;
      } else {
        maxLen = max(maxLen, i + nums[i]);
      }

      if (maxLen >= n - 1) {
        return true;
      }
    }

    return maxLen >= n - 1;
  }
};