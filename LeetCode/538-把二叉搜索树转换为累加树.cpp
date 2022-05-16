#include "LeetCode.h"

class Solution {
public:
  int cnt = 0;
  TreeNode *convertBST(TreeNode *root) {
    dfs(root);

    return root;
  }

  // 按照从大到小的顺序遍历一遍, 记录总和, 每遍历到一个新结点就更新即可
  // 也就是说, 反向中序遍历
  void dfs(TreeNode *root) {
    if (root == NULL) {
      return;
    }

    // 反向中序遍历
    dfs(root->right);

    // 更新root的val
    cnt += root->val;
    root->val = cnt;

    dfs(root->left);
  }
};