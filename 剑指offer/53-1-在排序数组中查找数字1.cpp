#include "LeetCode.h"

class Solution {
public:
  int search(vector<int> &nums, int tar) {
    // 判空
    if (nums.size() == 0) {
      return 0;
    }

    int n = nums.size();

    // 从左往右寻找第一个大于等于tar的数
    int l = 0, r = n - 1, mid;
    while (l < r) {
      if (nums[mid = (l + r) >> 1] >= tar) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    // 特判数组中没有该元素的情况
    if (nums[l] != tar) {
      return 0;
    }

    // 记录左区间
    int ansL = l;

    // 从右往左寻找第一个小于等于tar的数
    l = 0, r = n - 1;
    while (l < r) {
      if (nums[mid = (l + r + 1) >> 1] <= tar) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }

    // 记录右端点
    int ansR = l;
    return ansR - ansL + 1;
  }
};