#include "LeetCode.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        
        // 维护遍历到的日期前的最低价
        int minPrice = prices[0];

        for (int i = 1; i < n; i++) {
            // 假设今天卖, 前面最低的时候买
            ans = max(ans, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        return ans;
    }
};