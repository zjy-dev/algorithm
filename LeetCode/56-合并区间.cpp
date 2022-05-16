#include "LeetCode.h"

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    int l = intervals[0][0], r = intervals[0][1];
    vector<vector<int>> ans;

    // 以左端点为依据排序, 方便贪心
    sort(intervals.begin(), intervals.end());

    for (const auto &val : intervals) {
      // 如果当前区间左端点大于r, 则不存在任何其他区间左端点小于等于r
      // 所以此时可以更新答案, 并更新l
      if (val[0] > r) {
        ans.push_back({l, r});
        l = val[0];
      }

      // r无论如何都要更新
      r = max(r, val[1]);
    }

    return ans;
  }
};