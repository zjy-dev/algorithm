#include "LeetCode.h"

class Solution {
public:
  int thirdMax(vector<int> &nums) {
    long long a = LONG_LONG_MIN, b = a, c = a;
    for (int val : nums)
      if (val > a)
        c = b, b = a, a = val;
      else if (a > val and val > b)
        c = b, b = val;
      else if (b > val and val > c)
        c = val;

    return c == LONG_LONG_MIN ? a : c;
  }
};
