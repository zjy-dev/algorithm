#include "LeetCode.h"

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> ans(m + n);
    int i = 0, j = 0, p = 0;
    while (i < m and j < n)
      if (nums1[i] < nums2[j])
        ans[p++] = nums1[i++];
      else
        ans[p++] = nums2[j++];

    if (i < m)
      for (; i < m; i++)
        ans[p++] = nums1[i];
    else
      for (; j < n; j++)
        ans[p++] = nums2[j];

    for (int i = 0; i < m + n; i++)
      nums1[i] = ans[i];
  }
};