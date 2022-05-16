#include "LeetCode.h"

class Solution {
public:
  vector<int> shortestToChar(string s, char c) {
    int n = s.size();
    vector<int> ans(n, INT_MAX);

    // 第一次从左到右遍历
    // 记录离左边最近的c的距离
    int pos = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == c) {
        ans[i] = 0;
        pos = i;
        continue;
      }

      if (pos != -1) {
        ans[i] = min(ans[i], i - pos);
      }
    }

    // 从右边再来一遍
    pos = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == c) {
        pos = i;
        continue;
      }

      if (pos != -1) {
        ans[i] = min(ans[i], pos - i);
      }
    }

    return ans;
  }
};