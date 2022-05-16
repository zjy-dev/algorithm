#include "LeetCode.h"

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    int n = s.size();
    s = " " + s;

    // dp[k]表示s[:k]能不能满足题干条件
    // 所以答案就是dp[n]
    vector<bool> dp(n + 1, false);

    // 快速判断某个字符串有没有在dict中出现
    unordered_set<string> hash;
    for (const auto &val : wordDict) {
      hash.insert(val);
    }

    // dp边界
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
      // 以j为分界点, 如果dp[j]满足, 则尝试使用dict中的单词匹配
      for (int j = 0; j < i; j++) {
        if (dp[j] && hash.count(s.substr(j + 1, i - j))) {
          dp[i] = true;

          // 有一种方案匹配成功了就可以
          break;
        }
      }
    }

    return dp[n];
  }
};