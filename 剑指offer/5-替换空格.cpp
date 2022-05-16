#include "LeetCode.h"

/**
 * 解法一: 暴力
 * 时间复杂度 -> O(n), 但是会不断的重建和拷贝字符串
 * 空间复杂度 -> O(n), 但是会不断的重建和拷贝字符串
 */
class Solution {
public:
  string replaceSpace(string s) {
    // 根据题目范围, 需要特判
    int n = s.size();
    if (n == 0) {
      return "";
    }

    // 在原串替换不方便, 新建一个字符串ans
    string ans = "";
    for (int i = 0; i < n; i++) {
      if (s[i] == ' ') {
        ans += "%20";
      } else {
        ans += s[i];
      }
    }

    return ans;
  }
};

/**
 * 解法二: 预分配优化
 * 时间复杂度 -> O(n)
 * 空间复杂度 -> O(n)
 */
class Solution {
public:
  string replaceSpace(string s) {
    // 根据题目范围, 需要特判
    int n = s.size();
    if (n == 0) {
      return "";
    }

    // 提前统计空格数量cnt
    int cnt = 0;
    for (const auto &c : s) {
      if (c == ' ') {
        cnt++;
      }
    }

    // ans字符串的长度是cnt * 2 + s.size()
    string ans(cnt * 2 + s.size(), '\0');

    int i = 0;
    for (const auto &c : s) {
      if (c == ' ') {
        ans[i++] = '%', ans[i++] = '2', ans[i++] = '0';
      } else {
        ans[i++] = c;
      }
    }

    return ans;
  }
};