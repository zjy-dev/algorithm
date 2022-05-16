#include "LeetCode.h"

class Solution {
public:
  int tar, ans = 0;
  unordered_map<int, int> hash;
  int pathSum(TreeNode *root, int targetSum) {
    hash[0] = 1;
    this->tar = targetSum;
    return dfs(root, 0);
  }

  int dfs(TreeNode *root, int path) {
    if (!root)
      return 0;
    path += root->val;

    int count = hash[path - tar];

    hash[path]++;

    count += dfs(root->left, path);
    count += dfs(root->right, path);

    hash[path]--;

    return count;
  }
};