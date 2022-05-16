#include "LeetCode.h"

class Solution {
public:
  string reverseWords(string s) {
    string ans;
    int n = s.size();
    for (int i, j = n - 1;;) {
      while (j >= 0 and s[j] == ' ')
        j--;
      if (j < 0)
        break;
      i = j;
      while (i >= 0 and s[i] != ' ')
        i--;
      ans += s.substr(i + 1, j - i) + " ";
      j = i;
    }

    return ans.substr(0, ans.size() - 1);
  }
};