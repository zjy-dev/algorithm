#include "LeetCode.h"

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    if (n <= 1) {
      return;
    }

    // 从右往左找出一个较小值的位置, 用small记录
    int small = n - 2;
    while (small >= 0 && nums[small] >= nums[small + 1]) {
      small--;
    }

    // 如果small < 0, 说明已经是最大排列了
    if (small >= 0) {
      // small右边现在是递减排列的
      // 为了得到下一个排列, 我们要
      //     1. 将nums[small]和大于nums[small]的最小值交换
      //     2. 将原nums[small]右边改为递增排列, reverse即可

      // 1.1 寻找大于nums[small]的最小值
      int l = small + 1, r = n - 1, mid;
      while (l < r) {
        if (nums[mid = (l + r + 1) >> 1] > nums[small]) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }

      // 1.2 交换
      swap(nums[small], nums[l]);
    }

    // 2. 改为递增序列, 注意如果已经是最大排列了直接reverse全部也复合题干要求
    // max(0, small + 1)不写也行, 只是为了可读性
    reverse(nums.begin() + max(0, small + 1), nums.end());
  }
};