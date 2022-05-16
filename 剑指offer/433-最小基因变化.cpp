#include "LeetCode.h"

class Solution {
public:
  string ed_;
  int ans_ = INT_MAX;
  unordered_set<string> vis_;

  int minMutation(string st, string ed, vector<string> &bank) {
    ed_ = ed;

    dfs(st, 0, bank);
    return ans_ == INT_MAX ? -1 : ans_;
  }

  void dfs(string s, int cnt, vector<string> &bank) {
    if (s == ed_) {
      ans_ = min(ans_, cnt);
      return;
    }

    // 站在bank的角度出发即可
    // 因为中间结果只能是bank中的内容
    for (const auto &str : bank) {
      // s和str的差别不能超过1
      int diff = 0;
      for (int i = 0; i < 8; i++) {
        str[i] == s[i] ? NULL : diff++;
      }

      // vis_防止反复横跳
      if (diff > 1 || vis_.count(str)) {
        continue;
      }

      // 回溯
      vis_.insert(str);
      // 这里要加diff, 不是加1
      dfs(str, cnt + diff, bank);
      vis_.erase(str);
    }
  }
};