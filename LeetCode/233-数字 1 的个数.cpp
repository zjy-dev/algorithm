#include "LeetCode.h"

class Solution {
public:
  int countDigitOne(int n) {
    int ans = 0;
    int cur = n % 10, high = n / 10, low = 0;
    long long digit = 1;
    while (high or cur) {
      if (!cur)
        ans += high * digit;
      else if (cur == 1)
        ans += high * digit + low + 1;
      else
        ans += (high + 1) * digit;

      low += digit * cur, digit *= 10, cur = high % 10, high /= 10;
    }
    return ans;
  }
};