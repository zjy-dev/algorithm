#include "LeetCode.h"

class Solution {
public:
  char slowestKey(vector<int> &times, string keys) {
    int n = keys.size();
    char k = keys[0];
    int t = times[0];
    for (int i = 1; i < n; i++) {
      int temp = times[i] - times[i - 1];
      if (temp > t)
        t = temp, k = keys[i];
      else if (temp == t and keys[i] > k)
        k = temp, k = keys[i];
    }

    return k;
  }
};