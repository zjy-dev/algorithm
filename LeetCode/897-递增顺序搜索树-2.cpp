#include "LeetCode.h"

class Solution {
public:
  TreeNode *increasingBST(TreeNode *root) {
    stack<TreeNode *> stk;
    TreeNode *ans = NULL, *prev = NULL;
    auto p = root;
    while (p or !stk.empty()) {
      while (p) {
        stk.push(p);
        p = p->left;
      }

      p = stk.top(), stk.pop();

      if (prev)
        prev->right = p;
      else
        ans = p;

      prev = p;
      p->left = NULL;

      p = p->right;
    }

    return ans;
  }
};