#include "LeetCode.h"

class Solution {
public:
  bool isBalanced(TreeNode *root) {
    if (dfs(root) < 0) {
      return false;
    }

    return true;
  }

  // 返回负数说明该树不平衡
  // 0或正数是该树的深度, 同时说明该树平衡
  int dfs(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }

    int depthL = dfs(root->left);

    // 在这里处理depthL是为了剪枝, 很重要的优化
    // 左子树不平衡当然root也不平衡, 返回负数
    if (depthL < 0) {
      return INT_MIN;
    }

    int depthR = dfs(root->right);

    if (depthR < 0 || abs(depthL - depthR) > 1) {
      return INT_MIN;
    }

    // 别忘了 + 1
    return max(depthL, depthR) + 1;
  }
};