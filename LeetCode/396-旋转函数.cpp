#include "LeetCode.h"

class Solution {
public:
  int maxRotateFunction(vector<int> &nums) {
    int n = nums.size();
    // 记sum(nums)为t

    // F(0) = 0 × nums[0] + 1 × nums[1] + ... + (n-2) × nums[n-2] + (n−1) ×
    // nums[n−1] F(1) = 1 × nums[0] + 2 × nums[1] + ... + (n-1) × nums[n-2] + 0
    // × nums[n−1] F(2) = 2 × nums[0] + 3 × nums[1] + ... + 0 × nums[n-2] + 1 ×
    // nums[n−1]

    // 观察得到
    // F(1) = F(0) + t - n × nums[n - 1]
    // F(2) = F(1) + t - n × nums[n - 2]
    // F(k) = F(k - 1) + t - n × nums[n - k], 只和前一项有关

    // 计算初始的F(0)和t
    int f0 = 0, t = 0;
    for (int i = 0; i < n; i++) {
      f0 += i * nums[i];
      t += nums[i];
    }

    // 记录最大值
    int ans = f0;

    // 不断迭代更新f0, f1即可
    // 毕竟F(k)只和F(k - 1)有关
    for (int i = 1; i < n; i++) {
      int f1 = f0 + t - n * nums[n - i];
      ans = max(ans, f1);

      f0 = f1;
    }

    return ans;
  }
};