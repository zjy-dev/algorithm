#include "LeetCode.h"

class Solution {
public:
  int findNthDigit(int n) {
    if (!n)
      return 0;
    int digit = 1, st = 1;
    long long count = 9;
    while (n > count) {
      n -= count;
      st *= 10, digit++;
      count = (long long)9 * st * digit;
    }

    int num = st + (n - 1) / digit;
    return to_string(num)[(n - 1) % digit] - '0';
  }
};