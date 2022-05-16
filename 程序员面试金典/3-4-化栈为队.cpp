#include "LeetCode.h"

class MyQueue {
public:
  stack<int> stk1, stk2;
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) { stk1.push(x); }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    if (stk2.size()) {
      auto t = stk2.top();
      stk2.pop();
      return t;
    }

    while (stk1.size()) {
      stk2.push(stk1.top());
      stk1.pop();
    }

    return pop();
  }

  /** Get the front element. */
  int peek() {
    if (stk2.size()) {
      return stk2.top();
    }

    while (stk1.size()) {
      stk2.push(stk1.top());
      stk1.pop();
    }

    return peek();
  }

  /** Returns whether the queue is empty. */
  bool empty() { return stk1.empty() && stk2.empty(); }
};
