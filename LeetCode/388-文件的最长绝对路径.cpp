#include "LeetCode.h"

class Solution {
public:
  int lengthLongestPath(string s) {
    int n = s.size();

    int pos = 0, ans = 0;

    // 用栈记录之前的目录长度
    // 不用担心同级文件夹的问题, 会自动覆盖掉的
    // 栈的size就是深度, 根文件夹的深度是1
    stack<int> stk;

    while (pos < n) {
      // 统计当前文件/文件夹的深度
      int depth = 0;
      while (pos < n && s[pos] == '\t') {
        pos++, depth++;
      }

      // 统计当前文件/文件夹的长度, 以及判断是否是文件
      bool isFile = false;
      int curLen = 0;
      while (pos < n && s[pos] != '\n') {
        if (s[pos] == '.') {
          isFile = true;
        }
        pos++, curLen++;
      }

      // 跳过 '\n'
      pos++;

      // 删除深度大于等于自己的文件夹, 然后覆盖同级的文件夹
      // size_t是unsigned LL, 会连带着depth一起触发强转变为uLL
      // -1如果按照unsigned来理解会很大, 就会触发空栈删除异常
      while ((int)stk.size() - 1 >= depth) {
        stk.pop();
      }

      // 栈非空, 更新当前长度
      if (stk.empty() == false) {
        // + 1是因为 '/'
        curLen += stk.top() + 1;
      }

      // 是文件, 更新答案
      if (isFile == true) {
        ans = max(ans, curLen);
      } else { // 不是文件, 入栈
        stk.push(curLen);
      }
    }

    return ans;
  }
};