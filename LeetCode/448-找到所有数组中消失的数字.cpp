#include "LeetCode.h"

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    int n = nums.size();

    // 原地修改, 把nums当哈希表用, nums[i] > n 说明 i + 1 出现过
    for (int i = 0; i < n; i++) {
      // 注意nums[i]可能已经加过n了, 取模n可以返还之前的结果
      int t = (nums[i] - 1) % n;

      // nums[i] % n出现过, 要将nums[(nums[i] - 1) % n]变的大于n
      nums[t] += n;
    }

    // 小于等于n的没出现过
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
      if (nums[i - 1] <= n) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};