#include "LeetCode.h"

/**
 * 时间复杂度 => O(n)
 * 空间复杂度 => O(n)
 */
class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    // 模拟压栈, 只要栈顶元素和删除队列相,对应就弹栈
    stack<int> stk;
    int n = pushed.size();
    int i = 0;
    for (const auto &val : pushed) {
      stk.push(val);
      while (!stk.empty() && stk.top() == popped[i]) {
        i++;
        stk.pop();
      }
    }

    // 如果模拟结束后栈刚好弹完, 说明满足题干条件
    return stk.empty();
  }
};