#include "LeetCode.h"

class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    // 看看数据范围, nums[i]的数全部大于等于1
    if (k <= 1) {
      return 0;
    }

    const int n = nums.size();
    int ans = 0;

    // 题干保证全是正数
    uint64_t val = 1;

    // 每次强制以ed结尾
    for (int st = 0, ed = 0; ed < n; ed++) {
      val *= nums[ed];
      while (val >= k) {
        val /= nums[st++];
      }
      ans += (ed - st + 1);
    }

    return ans;
  }
};