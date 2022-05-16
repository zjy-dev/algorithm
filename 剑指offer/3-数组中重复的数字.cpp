#include "LeetCode.h"

/**
 * 时间复杂度 -> O(n), 因为每一次交换都会归位一个数字, n次交换之内必然得到结果
 * 空间复杂度 -> O(1)
 */
class Solution {
public:
  int findRepeatNumber(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      // 每个数字都应该是唯一的, 我们每一次交换都会将一个数字归位
      while (nums[i] != i) {
        // 如果nums[nums[i]]已经正确归位了,我们就会得到冗余的nums[i], return即可
        if (nums[i] == nums[nums[i]]) {
          return nums[i];
        }

        // 将nums[i]送到正确的位置
        swap(nums[i], nums[nums[i]]);
      }
    }

    // 答案一定存在, 随便return即可
    return 0;
  }
};