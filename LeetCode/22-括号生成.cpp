#include "LeetCode.h"

class Solution {
public:
  vector<string> ans;
  vector<string> generateParenthesis(int n) {
    if (n == 0) {
      return {};
    }

    dfs("", n, 0, 0);

    return ans;
  }

  // 用cntL和cntR来维护左右括号的数量
  void dfs(string temp, const int &n, int cntL, int cntR) {
    if (cntL + cntR == (n << 1)) {
      ans.push_back(temp);
      return;
    }

    // 左括号和右括号数量一样的话, 只能放左括号, return
    if (cntL == cntR) {
      dfs(temp + '(', n, cntL + 1, cntR);
      return;
    }

    // 左括号多, 一定可以放右括号
    dfs(temp + ')', n, cntL, cntR + 1);

    // 但是不一定可以再放左括号, 要判断一下是否已经有n个了
    if (cntL < n) {
      dfs(temp + '(', n, cntL + 1, cntR);
    }
  }
};