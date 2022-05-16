#include "LeetCode.h"

class Solution {
public:
  vector<int> ans;
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    ans.resize(n);

    ans[0] = nums[0];
    for (int i = 1; i < n; i++)
      ans[i] = ans[i - 1] * nums[i];

    int r = 1;
    for (int i = n - 1; i >= 1; i--) {
      ans[i] = ans[i - 1] * r;
      r *= nums[i];
    }
    ans[0] = r;
    return ans;
  }
};