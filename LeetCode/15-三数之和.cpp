#include "LeetCode.h"

class Solution {
public:
  // 由于答案要去重, 且排序双指针是去重神器, 所以排序双指针即可
  vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> ans;

    // 排序双指针
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {
      // 去重
      if (i != 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int tar = -nums[i];

      int l = i + 1, r = n - 1;
      while (l < r) {
        // 去重, 注意当左右都重的时候才去重
        if (l != i + 1 && r != n - 1 && nums[l] == nums[l - 1] &&
            nums[r] == nums[r + 1]) {
          l++, r--;
          continue;
        }

        // 经典双指针
        if (nums[l] + nums[r] < tar) {
          l++;
        } else if (nums[l] + nums[r] > tar) {
          r--;
        } else {
          ans.push_back({nums[i], nums[l], nums[r]});
          l++, r--;
        }
      }
    }

    return ans;
  }
};