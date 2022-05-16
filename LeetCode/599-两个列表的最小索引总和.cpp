#include "LeetCode.h"

class Solution {
public:
  vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
    vector<string> ans;

    int m = list1.size(), n = list2.size();

    // 统计l1中的餐厅的索引
    unordered_map<string, int> hash;
    for (int i = 0; i < m; i++) {
      hash[list1[i]] = i;
    }

    int cnt = INT_MAX;
    for (int i = 0; i < n; i++) {
      // l1中没有, 直接跳过
      if (hash.count(list2[i]) == 0) {
        continue;
      }

      // l1中有, 判断一下 当前索引和 和 最小索引和 的关系
      int t = i + hash[list2[i]];
      if (t < cnt) { // 当前的更小, 更新最小索引和, 并清空ans
        cnt = t;
        ans.clear();
        ans.push_back(list2[i]);
      } else if (t == cnt) { // 等于的时候要全部返回
        ans.push_back(list2[i]);
      }
    }

    return ans;
  }
};