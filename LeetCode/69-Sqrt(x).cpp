#include "LeetCode.h"

class Solution {
public:
  int mySqrt(int x) {
    long long l = 0, r = x, mid;
    while (l < r) {
      mid = (l + r + 1) >> 1;
      if (mid * mid <= x)
        l = mid;
      else
        r = mid - 1;
    }

    return l;
  }
};