#include "LeetCode.h"

class Solution {
public:
  int maxDepth(string s) {
    int ans = 0, cnt = 0;
    for (const auto &c : s)
      if (c == '(')
        cnt++, ans = max(ans, cnt);
      else if (c == ')')
        cnt--;

    return ans;
  }
};