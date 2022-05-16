#include "LeetCode.h"

class StackOfPlates {
public:
  const int cap_;
  vector<stack<int>> v_;
  StackOfPlates(int cap) : cap_(cap) {}

  void push(int val) {
    if (cap_ == 0) {
      return;
    }

    if (v_.empty() || v_.back().size() == cap_) {
      v_.push_back(stack<int>());
      return push(val);
    }

    v_.back().push(val);
  }

  // 像一个正常的栈一样删除
  int pop() {
    if (cap_ == 0) {
      return -1;
    }

    if (v_.empty()) {
      return -1;
    }

    auto ret = v_.back().top();
    v_.back().pop();

    shrink();
    return ret;
  }

  int popAt(int idx) {
    if (cap_ == 0) {
      return -1;
    }
    if (idx < 0 || idx >= v_.size()) {
      return -1;
    }

    auto ret = v_[idx].top();
    v_[idx].pop();
    if (v_[idx].empty()) {
      v_.erase(v_.begin() + idx);
    }

    return ret;
  }

  void shrink() {
    while (v_.size() && v_.back().empty()) {
      v_.pop_back();
    }
  }
};
