#include "LeetCode.h"

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();

    if (n == 0) {
      return 0;
    }

    int ans = 0;

    // 维护最小股票值
    int minPrice = prices[0];

    // 尝试以每一天作为卖出日
    for (int i = 1; i < n; i++) {
      ans = max(ans, prices[i] - minPrice);
      minPrice = min(minPrice, prices[i]);
    }

    return ans;
  }
};