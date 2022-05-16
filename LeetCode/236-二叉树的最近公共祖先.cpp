#include "LeetCode.h"

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    return dfs(root, p, q);
  }

  // 返回最近公共祖先
  TreeNode *dfs(TreeNode *root, const TreeNode *p, const TreeNode *q) {
    if (root == NULL) {
      return NULL;
    }

    // 如果 root 和 p 或 q 重合, 就说明root是最近的公共祖先
    if (root->val == p->val || root->val == q->val) {
      return root;
    }

    // 递归寻找最近公共祖先
    auto ansL = dfs(root->left, p, q);
    auto ansR = dfs(root->right, p, q);

    if (ansL == NULL && ansR == NULL) { // 找不到公共祖先
      return NULL;
    } else if (ansL != NULL && ansR != NULL) { // p和q分列两侧
      return root;
    }

    // 返回最近公共祖先
    return ansL == NULL ? ansR : ansL;
  }
};