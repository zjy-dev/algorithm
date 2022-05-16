#include "LeetCode.h"

class Solution {
public:
  int countSubstrings(string s) {
    int n = s.size(), ans = 0;

    for (int i = 0; i < n; i++) {
      ans++;
      for (int l = i - 1, r = i + 1; l >= 0 and r < n; l--, r++) {
        if (s[l] != s[r])
          break;
        ans++;
      }
    }

    for (int i = 0; i < n; i++)
      for (int l = i, r = i + 1; l >= 0 and r < n; l--, r++) {
        if (s[l] != s[r])
          break;
        ans++;
      }

    return ans;
  }
};