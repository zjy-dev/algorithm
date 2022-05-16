#include "LeetCode.h"

class Solution {
public:
  string reverseWords(string s) {
    int n = s.size();
    if (n == 0) {
      return "";
    }

    string ans;

    int st, ed = n - 1;
    while (true) {
      // 定位最后一个字符串的末尾位置
      while (ed >= 0 && s[ed] == ' ') {
        ed--;
      }

      // 如果ed < 0说明全是空格, 返回即可
      if (ed < 0) {
        break;
      }

      // 定位最后一个字符串的开头位置
      st = ed;
      while (st >= 0 && s[st] != ' ') {
        st--;
      }

      // 注意要从st + 1开始, 因为根据上面一个循环, st不是小于0就是s[st] == ' '
      for (int k = st + 1; k <= ed; k++) {
        ans += s[k];
      }

      ans += ' ';

      ed = st;
    }

    // 去掉末尾的一个空格
    return ans.substr(0, ans.size() - 1);
  }
};