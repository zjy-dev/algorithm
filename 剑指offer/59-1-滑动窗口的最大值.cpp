#include "LeetCode.h"

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int n = nums.size();
    if (!n)
      return {};
    deque<int> q;
    vector<int> ans;

    for (int i = 0; i < k; i++) {
      while (!q.empty() and q.back() < nums[i])
        q.pop_back();
      q.push_back(nums[i]);
    }
    ans.push_back(q.front());

    for (int i = k; i < n; i++) {
      if (nums[i - k] == q.front())
        q.pop_front();
      while (!q.empty() and q.back() < nums[i])
        q.pop_back();
      q.push_back(nums[i]);
      ans.push_back(q.front());
    }

    return ans;
  }
};