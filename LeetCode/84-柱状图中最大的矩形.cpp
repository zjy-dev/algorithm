#include "LeetCode.h"

class Solution {
public:
  int largestRectangleArea(vector<int> &nums) {
    // 尝试以每一个柱子为顶, 则我们需要知道柱子k两侧比k矮的第一个柱子的下标
    // 维护一个递增的单调栈, 则可以解决这个问题
    stack<int> stk;
    // 为了一致性, 这里要push一个-1
    stk.push(-1);

    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      // 如果nums[stk.top()] > nums[i]
      // 则stk.top()两侧的比它矮的柱子就都找到了
      while (stk.top() != -1 && nums[stk.top()] > nums[i]) {
        int t = stk.top();
        stk.pop();
        int wid = i - stk.top() - 1, hei = nums[t];
        ans = max(ans, wid * hei);
      }
      stk.push(i);
    }

    // 如果栈还没空, 说明很多柱子右边没有比它矮的柱子了, 我们用n作为边界即可
    while (stk.top() != -1) {
      int t = stk.top();
      stk.pop();
      int wid = n - stk.top() - 1, hei = nums[t];

      ans = max(ans, wid * hei);
    }

    return ans;
  }
};