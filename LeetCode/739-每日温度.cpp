#include "LeetCode.h"

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &nums) {
    int n = nums.size();
    stack<int> stk;
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {
      while (!stk.empty() and nums[i] > nums[stk.top()])
        ans[stk.top()] = i - stk.top(), stk.pop();

      stk.push(i);
    }

    return ans;
  }
};