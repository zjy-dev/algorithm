#include "LeetCode.h"

class Solution {
public:
  vector<TreeNode *> v;
  void flatten(TreeNode *root) {
    if (root == NULL) {
      return;
    }

    // 先序遍历
    dfs(root);

    // 然后串起来
    for (int i = 0; i < v.size() - 1; i++) {
      cout << i << " " << v.size() - 1;
      v[i]->left = NULL;
      v[i]->right = v[i + 1];
    }
  }

  void dfs(TreeNode *root) {
    if (root == NULL) {
      return;
    }

    v.push_back(root);
    dfs(root->left);
    dfs(root->right);
  }
};