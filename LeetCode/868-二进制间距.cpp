#include "LeetCode.h"

class Solution {
public:
  int binaryGap(int n) {
    // l初始化为-1可以用于标识l是否代表一个二进制1
    int l(-1), r(-1), ans(0);

    for (int i = 31; i >= 0; i--) {
      if ((n >> i) & 1) {
        // 第一位是32 - 31
        // 所以第i位是32 - i
        r = 32 - i;

        if (l != -1) {
          ans = max(ans, r - l);
        }

        l = 32 - i;
      }
    }

    return ans;
  }
};