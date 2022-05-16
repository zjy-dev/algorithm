#include "LeetCode.h"

class Solution {
public:
  string addBinary(string a, string b) {
    if (a.size() > b.size())
      return addBinary(b, a);
    int m = a.size(), n = b.size();
    int i = m - 1, j = n - 1, temp = 0;
    for (; i >= 0; i--, j--) {
      auto cnt = temp + (a[i] == '1') + (b[j] == '1');
      b[j] = cnt % 2 + '0';
      temp = cnt / 2;
    }
    for (; j >= 0; j--) {
      auto cnt = (b[j] == '1') + temp;
      b[j] = cnt % 2 + '0';
      temp = cnt / 2;
    }
    return temp ? "1" + b : b;
  }
};