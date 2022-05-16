#include "LeetCode.h"

class Solution {
public:
  vector<int> getLeastNumbers(vector<int> &arr, int k) {
    if (arr.size() == 0 || k == 0) {
      return {};
    }

    quick_select(arr, 0, arr.size() - 1, k);

    vector<int> ans;
    for (int i = 0; i < k; i++) {
      ans.push_back(arr[i]);
    }

    return ans;
  }

  // 将l到r区间内的前k小的数移到[l, l + k)区间内
  void quick_select(vector<int> &arr, int l, int r, int k) {
    if (l == r) {
      return;
    }

    // 让所有小于等于哨兵结点的数在前面
    // 所有大于等于哨兵结点的数在后面

    int i = l - 1, j = r + 1;
    int flag = arr[(l + r) >> 1];
    while (i < j) {
      while (arr[++i] < flag)
        ;
      while (arr[--j] > flag)
        ;
      // 一定要特判, 防止错误的交换
      if (i < j) {
        swap(arr[i], arr[j]);
      }
    }

    // [l, j]都是小于等于哨兵结点的数, 所以lenL = j - l + 1
    int lenL = j - l + 1;
    if (lenL == k) {
      return;
    } else if (lenL < k) {
      // 不够k个数, 还要在右区间补k - lenL个数
      quick_select(arr, j + 1, r, k - lenL);
    } else if (lenL > k) {
      // 多于k个数, 则进一步筛选
      quick_select(arr, l, j, k);
    }
  }
};