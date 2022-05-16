#include "LeetCode.h"

class Solution {
public:
  int jump(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) {
      return 0;
    }

    int ans = 0;

    // 起跳范围是[st, ed]
    int st = 0, ed = 0;
    while (true) {

      // 在起跳范围中寻找能跳到的最远距离 maxPos
      int maxPos = 0;
      for (int i = st; i <= ed; i++) {
        maxPos = max(maxPos, i + nums[i]);
      }

      // 跳
      ans++;

      // 这一跳能不能跳到终点
      if (maxPos >= n - 1) {
        break;
      }

      // 更新st, ed
      // 因为题干保证能跳到终点, 因此st必然等于ed + 1
      st = ed + 1, ed = maxPos;
    }

    return ans;
  }
};