#include "LeetCode.h"

class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    int n = people.size();
    sort(people.begin(), people.end(),
         [](const vector<int> &v1, const vector<int> &v2) {
           return v1[0] < v2[0] || (v1[0] == v2[0] and v1[1] > v2[1]);
         });
    vector<vector<int>> v(n);

    for (int i = 0; i < n; i++) {
      int cnt = people[i][1] + 1;
      for (int j = 0; j < n; j++) {
        if (!v[j].size())
          cnt--;

        if (!cnt) {
          v[j] = people[i];
          break;
        }
      }
    }
    return v;
  }
};