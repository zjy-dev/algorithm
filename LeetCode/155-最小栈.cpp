#include "LeetCode.h"

class MinStack {
public:
  // stk1维护正常的栈, stk2维护最小值
  stack<int> stk1, stk2;
  MinStack() {}

  void push(int val) {
    stk1.push(val);
    if (stk2.empty() == true || stk2.top() >= val) {
      stk2.push(val);
    }
  }

  void pop() {
    int t = stk1.top();
    stk1.pop();

    if (stk2.empty() == false && stk2.top() == t) {
      stk2.pop();
    }
  }

  int top() { return stk1.top(); }

  int getMin() { return stk2.top(); }
};
