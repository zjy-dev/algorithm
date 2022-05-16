#include "LeetCode.h"

class Solution {
public:
  vector<vector<int>> g;
  vector<int> inDegree;
  bool canFinish(int n, vector<vector<int>> &prerequisites) {
    // 思路是找出拓扑序列, 如果拓扑序列的长度是n, 就没问题
    g.resize(n);
    inDegree.resize(n);

    // 建图和初始化入度
    for (const auto &val : prerequisites) {
      // 有向边是从val[1]指向val[0]的
      g[val[1]].push_back(val[0]);
      inDegree[val[0]]++;
    }

    // 初始化bfs队列
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (inDegree[i] == 0) {
        q.push(i);
      }
    }

    // 记录拓扑序列的长度
    int cnt = 0;

    // bfs求拓扑序列
    while (q.empty() == false) {
      auto t = q.front();
      q.pop();
      cnt++;

      for (const auto &val : g[t]) {
        inDegree[val]--;
        if (inDegree[val] == 0) {
          q.push(val);
        }
      }
    }

    return cnt == n;
  }
};