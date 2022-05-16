#include "LeetCode.h"

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int n = digits.size();
    digits[n - 1]++;
    for (int i = n - 1; i >= 1; i--) {
      if (digits[i] < 10)
        return digits;
      digits[i - 1]++;
      digits[i] = 0;
    }

    if (digits[0] == 10) {
      digits[0] = 0;
      digits.insert(digits.begin(), 1);
      return digits;
    }

    return digits;
  }
};