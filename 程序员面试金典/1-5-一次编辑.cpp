#include "LeetCode.h"

class Solution {
public:
  bool oneEditAway(string s1, string s2) {
    int m = s1.size(), n = s2.size();

    if (abs(m - n) > 1) {
      return false;
    }

    // 统计需要编辑的次数
    int cntDiff = 0;
    for (int i = 0, j = 0; i < m && j < n; i++, j++) {
      if (s1[i] == s2[j]) {
        continue;
      }

      cntDiff++;
      // 两处不同一次编辑不可能成功
      if (cntDiff >= 2) {
        return false;
      }

      if (m > n) { // 在s2这边插入一次
        j--;
      } else if (n > m) { // 在s1插入一次
        i--;
      }
    }

    // 1或0个不同是没问题的, 可以一次编辑
    return true;
  }
};