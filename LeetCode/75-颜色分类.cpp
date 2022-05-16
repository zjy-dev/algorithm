#include "LeetCode.h"

class Solution {
public:
  void sortColors(vector<int> &nums) {
    int n = nums.size();
    int l = 0, r = n - 1;

    // 将0都交换到最前面
    int p = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        swap(nums[i], nums[p++]);
      }
    }

    // 在0后面的部分中, 将1交换到前面
    for (int i = p; i < n; i++) {
      if (nums[i] == 1) {
        swap(nums[i], nums[p++]);
      }
    }
  }
};