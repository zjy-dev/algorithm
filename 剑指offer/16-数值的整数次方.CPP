#include "LeetCode.h"

/**
 * 时间复杂度 -> O(logn), 经典快速幂
 * 空间复杂度 -> O(1)
 */
class Solution {
public:
  double myPow(double x, int n) {
    // 防止后面除0, 特判掉0
    if (x == 0) {
      return 0;
    }

    // 题干指出n能取到int下限, 因此-n会溢出, 使用long long k替换掉n即可
    long long k = n;

    // 举个栗子, 5 ^ (-3) 可以表示为 (1 / 5) ^ 3
    // 也就是说, x取倒数, k取相反数
    if (k < 0) {
      x = (1 / x);
      k = -k;
    }

    // 快速幂
    double t = x, ans = 1;
    while (k != 0) {
      if (k & 1 == 1) {
        ans *= t;
      }

      t *= t;
      k >>= 1;
    }

    return ans;
  }
};
