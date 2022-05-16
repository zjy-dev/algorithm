#include "LeetCode.h"

class Solution {
public:
  vector<int> ans;
  vector<int> lexicalOrder(int n) {
    for (int i = 1; i <= 9; i++) {
      dfs(i, n);
    }

    return ans;
  }

  void dfs(int val, const int &n) {
    if (val > n) {
      return;
    }

    // 从小往大枚举就是字典序
    ans.push_back(val);
    for (int i = 0; i <= 9; i++) {
      dfs(val * 10 + i, n);
    }
  }
};