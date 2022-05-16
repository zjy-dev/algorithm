#include "LeetCode.h"

class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> dp(n + 1, 0);

    // 题干说第一个丑数是1
    dp[1] = 1;

    // 维护三个指针, 不断往前滚动
    int p2 = 1, p3 = 1, p5 = 1;
    for (int i = 2; i <= n; i++) {
      // 相应的指针乘相应的因数
      // 别怀疑, 丑数 * (2 | 3 | 5)才能是丑数, 所以这样是正确的
      int t2 = dp[p2] * 2, t3 = dp[p3] * 3, t5 = dp[p5] * 5;
      dp[i] = min(t2, min(t3, t5));

      // 这里一定不能用else if!!!
      // 这是因为丑数不能重复, 而t2、t3、t5可能重复
      // 例如2 * 3和3 * 2
      // 因此一定要用if分别判断
      if (dp[i] == t2) {
        p2++;
      }
      if (dp[i] == t3) {
        p3++;
      }
      if (dp[i] == t5) {
        p5++;
      }
    }

    return dp[n];
  }
};