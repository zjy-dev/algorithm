#include "LeetCode.h"

class Solution {
public:
  int reversePairs(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }

    return mergeSort(nums, 0, n - 1);
  }

  // 将[l, r]进行排序, 并返回逆序对数量
  int mergeSort(vector<int> &nums, int l, int r) {
    if (l >= r) {
      return 0;
    }

    int mid = (l + r) >> 1;

    // 先计算左右两个区间内的逆序对数量
    int ans = 0;
    ans += mergeSort(nums, l, mid);
    ans += mergeSort(nums, mid + 1, r);

    vector<int> temp;

    // 对每一个j, 计算一次以它结尾的逆序对数量
    // 也就是左区间中比nums[j]大的数的数量
    // 当nums[i] > nums[j]的时候, 恰好该数量是mid - i + 1
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
      if (nums[i] <= nums[j]) {
        temp.push_back(nums[i++]);
      } else {
        ans += mid - i + 1;
        temp.push_back(nums[j++]);
      }
    }

    while (i <= mid) {
      temp.push_back(nums[i++]);
    }

    while (j <= r) {
      temp.push_back(nums[j++]);
    }

    for (int i = 0; i < temp.size(); i++) {
      nums[l + i] = temp[i];
    }

    return ans;
  }
};