#include "LeetCode.h"

class Solution {
public:
  // 答案
  int ans;

  int kthLargest(TreeNode *root, int k) {
    if (root == NULL) {
      return 0;
    }

    dfs(root, k);
    return ans;
  }

  // 搜索第cnt大的数
  void dfs(TreeNode *root, int &cnt) {
    if (root == NULL) {
      return;
    }

    // 因为是第cnt大的数, 所以要从右子树开始搜索
    dfs(root->right, cnt);

    // 如果在右子树, 就直接return, 剪枝
    if (cnt == 0) {
      return;
    }

    // 遍历当前结点
    cnt--;

    // 如果当前结点是答案, 就更新并返回
    if (cnt == 0) {
      this->ans = root->val;
      return;
    }

    // 递归搜索左子树
    dfs(root->left, cnt);
  }
};