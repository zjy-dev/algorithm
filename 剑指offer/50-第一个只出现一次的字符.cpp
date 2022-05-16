#include "LeetCode.h"

class Solution {
public:
  char firstUniqChar(string s) {
    int n = s.size();
    unordered_map<char, int> hash;
    for (int i = 0; i < n; i++) {
      hash[s[i]]++;
    }

    for (int i = 0; i < n; i++) {
      if (hash[s[i]] == 1) {
        return s[i];
      }
    }

    return ' ';
  }
};