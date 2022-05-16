#include "LeetCode.h"

class Solution {
public:
  int hammingDistance(int x, int y) {
    int ans = 0;

    // 异或一下就知道不同的位了
    x ^= y;

    // 统计二进制中1的个数
    int t = 1;
    for (int i = 0; i < 31; i++) {
      if (t & x) {
        ans++;
      }

      t <<= 1;
    }

    return ans;
  }
};