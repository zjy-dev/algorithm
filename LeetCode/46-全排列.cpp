#include "LeetCode.h"

class Solution {
public:
  vector<vector<int>> ans;

  vector<vector<int>> permute(vector<int> &nums) {
    if (nums.size() == 0) {
      return {};
    }

    dfs(nums, 0);
    return ans;
  }

  // nums[0:idx]是排列好的, nums[idx:]是未排列的
  void dfs(vector<int> &nums, int idx) {
    if (idx == nums.size()) {
      ans.push_back(nums);
    }

    // 对于idx, 循环让每个未排列的数尝试排在idx上(也就是swap)
    // 然后递归下一个位置
    for (int i = idx; i < nums.size(); i++) {
      swap(nums[i], nums[idx]);
      dfs(nums, idx + 1);
      swap(nums[i], nums[idx]);
    }
  }
};