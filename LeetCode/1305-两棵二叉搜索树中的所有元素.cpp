#include "LeetCode.h"

class Solution {
public:
  vector<int> v1, v2;

  vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    inOrder(root1, v1);
    inOrder(root2, v2);
    vector<int> ans;
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {
      ans.push_back(v1[i] < v2[j] ? v1[i++] : v2[j++]);
    }

    while (i < v1.size()) {
      ans.push_back(v1[i++]);
    }
    while (j < v2.size()) {
      ans.push_back(v2[j++]);
    }
    return ans;
  }

  void inOrder(TreeNode *root, vector<int> &v) {
    stack<TreeNode *> stk;

    while (!stk.empty() || root) {
      while (root) {
        stk.push(root);
        root = root->left;
      }

      root = stk.top();
      stk.pop();
      v.push_back(root->val);
      root = root->right;
    }
  }
};