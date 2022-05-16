#include "LeetCode.h"

class Solution {
public:
  int tar;
  vector<vector<int>> ans;
  vector<int> v;
  vector<vector<int>> pathSum(TreeNode *root, int target) {
    this->tar = target;
    dfs(root, 0);

    return ans;
  }

  void dfs(TreeNode *root, int num) {
    if (!root)
      return;

    v.push_back(root->val);
    if (!root->left and !root->right and num + root->val == tar)
      ans.push_back(v);
    dfs(root->left, num + root->val);
    dfs(root->right, num + root->val);
    v.pop_back();
  }
};