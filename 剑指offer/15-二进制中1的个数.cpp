#include "LeetCode.h"

/**
 * 时间复杂度 -> O(logn), 只和数的二进制长度有关
 * 空间复杂度 -> O(1)
 */
class Solution {
public:
  int hammingWeight(uint32_t n) {
    int ans = 0;

    while (n != 0) {
      // 消除n的二进制表示中的最后一个1
      n &= (n - 1);
      ans++;
    }

    return ans;
  }
};
