#include "LeetCode.h"

class Solution {
public:
  int countDigitOne(int n) {
    if (n == 0) {
      return 0;
    }

    int ans = 0;

    // 将该数划分为三个部分, high, cur和low
    int low = 0, high = n / 10, cur = n % 10;

    // long long防止溢出
    long long digit = 1;

    // 单独的cur为0或high为0都不能停止计算
    while (cur != 0 || high != 0) {
      // 无论如何, high(0 到 high - 1) * digit个1是肯定有的
      ans += high * digit;

      // 根据cur的值判断当高位等于high时的情况
      if (cur == 1) {
        ans += low + 1;
      } else if (cur > 1) {
        ans += digit;
      }

      // 更新
      low += cur * digit;
      cur = high % 10;
      high /= 10;
      digit *= 10;
    }

    return ans;
  }
};