#include "LeetCode.h"

class CBTInserter {
public:
  queue<TreeNode *> q;
  TreeNode *root;
  CBTInserter(TreeNode *root) {
    this->root = root;

    q.push(root);
    while (q.front()->left and q.front()->right) {
      auto t = q.front();
      q.pop();
      q.push(t->left), q.push(t->right);
    }
  }

  int insert(int val) {
    int ans = q.front()->val;
    if (q.front()->left) {
      q.front()->right = new TreeNode(val);
      q.push(q.front()->left), q.push(q.front()->right);
      q.pop();
    } else
      q.front()->left = new TreeNode(val);

    return ans;
  }

  TreeNode *get_root() { return this->root; }
};
