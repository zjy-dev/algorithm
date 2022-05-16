#include "LeetCode.h"

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int ans = 0;
    // a ^ a = 0
    for (const auto &val : nums) {
      ans ^= val;
    }

    return ans;
  }
};