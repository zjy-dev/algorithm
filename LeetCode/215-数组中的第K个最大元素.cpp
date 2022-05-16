#include "LeetCode.h"

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    quick_select(nums, 0, nums.size() - 1, k);
    return nums[k - 1];
  }

  void quick_select(vector<int> &nums, int l, int r, int k) {
    if (l >= r)
      return;
    int i = l - 1, j = r + 1, flag = nums[(l + r) >> 1];
    while (i < j) {
      while (nums[++i] > flag)
        ;
      while (nums[--j] < flag)
        ;
      if (i < j)
        swap(nums[i], nums[j]);
    }

    int lenL = j - l + 1;
    if (k <= lenL)
      return quick_select(nums, l, j, k);

    quick_select(nums, j + 1, r, k - lenL);
  }
};