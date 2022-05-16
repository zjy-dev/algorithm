#include "LeetCode.h"

class Solution {
public:
  int findJudge(int n, vector<vector<int>> &arr) {
    if (!arr.size() and n == 1)
      return 1;

    unordered_map<int, int> hash;

    for (const auto &v : arr)
      hash[v[1]]++, hash[v[0]]--;

    for (const auto &p : hash)
      if (p.second == n - 1)
        return p.first;

    return -1;
  }
};