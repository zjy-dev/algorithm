#include "LeetCode.h"

class MinStack {
public:
  stack<int> stk1, stk2;

  MinStack() {}

  void push(int x) {
    stk1.push(x);
    if (stk2.empty() || stk2.top() >= x) {
      stk2.push(x);
    }
  }

  void pop() {
    if (stk1.empty()) {
      return;
    }

    int t = stk1.top();
    if (stk2.top() == t) {
      stk2.pop();
    }

    stk1.pop();
  }

  int top() { return stk1.top(); }

  int getMin() { return stk2.top(); }
};