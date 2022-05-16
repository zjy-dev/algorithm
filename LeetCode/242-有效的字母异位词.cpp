#include "LeetCode.h"

class Solution {
public:
  bool isAnagram(string s, string t) {
    int hash[26];
    memset(hash, 0, sizeof hash);

    for (const char &c : s)
      hash[c - 'a']++;

    for (const char &c : t)
      hash[c - 'a']--;

    for (int i = 0; i < 26; i++)
      if (hash[i])
        return false;

    return true;
  }
};