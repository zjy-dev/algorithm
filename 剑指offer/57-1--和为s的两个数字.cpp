#include "LeetCode.h"

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    int n = nums.size();
    if (n == 0) {
      return {};
    }

    // 最简单的双指针
    int l = 0, r = n - 1;
    while (l < r) {
      if (nums[l] + nums[r] > target) {
        r--;
      } else if (nums[l] + nums[r] < target) {
        l++;
      } else {
        return {nums[l], nums[r]};
      }
    }

    return {};
  }
};