#include "LeetCode.h"

class Solution {
public:
  int findMin(vector<int> &nums) {
    int l = 0, r = nums.size() - 1, mid;
    while (l < r) {
      if (nums[mid = (l + r) >> 1] > nums[r])
        l = mid + 1;
      else if (nums[mid] < nums[r])
        r = mid;
      else
        r--;
    }

    return nums[l];
  }
};