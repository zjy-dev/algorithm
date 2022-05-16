#include "LeetCode.h"

class Solution {
public:
  bool isStraight(vector<int> &nums) {
    // 不能有重复, 有重复直接g, 所以排序很方便去重
    sort(nums.begin(), nums.end());

    // t记录第一个非0位置
    int t = 0;
    for (int i = 0; i < 4; i++) {
      if (nums[i] == 0) {
        t = i + 1;
      } else if (nums[i] == nums[i + 1]) {
        return false;
      }
    }

    // 接下来, 只要nums[4](也就是最大的数)和nums[t]之间的差距小于等于4即可
    return nums[4] - nums[t] <= 4;
  }
};