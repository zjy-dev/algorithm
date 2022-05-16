#include "LeetCode.h"

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> s;
    int ans = 0;
    for (const auto &val : nums) {
      s.insert(val);
    }

    for (const auto &val : s) {
      // 只从最小的开始遍历
      if (s.count(val - 1) == 1) {
        continue;
      }

      int len = 1, t = val;
      while (s.count(t + 1) == true) {
        // 加快遍历
        s.erase(t + 1);
        len++, t++;
      }

      ans = max(ans, len);
    }

    return ans;
  }
};