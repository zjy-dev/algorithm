#include "LeetCode.h"

class Solution {
public:
  // 要求随机返回一个下标, 一次要用vector存储
  unordered_map<int, vector<int>> hash;

  Solution(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      hash[nums[i]].push_back(i);
    }
  }

  int pick(int tar) { return hash[tar].at(rand() % hash[tar].size()); }
};