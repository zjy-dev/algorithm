#include "LeetCode.h"

class Solution {
public:
  void quick_sort(vector<int> &nums, int l, int r) {
    if (l >= r) {
      return;
    }

    int i = l - 1, j = r + 1, flag = nums[(l + r) >> 1];

    while (i < j) {
      while (nums[++i] < flag)
        ;
      while (nums[--j] > flag)
        ;

      if (i < j) {
        swap(nums[i], nums[j]);
      }
    }

    // 递归排序
    quick_sort(nums, l, j);
    quick_sort(nums, j + 1, r);
  }

  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();

    quick_sort(nums, 0, n - 1);

    return nums;
  }
};