#include "LeetCode.h"

class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    // 非常简单的层序遍历, 推荐自己写
    if (root == NULL) {
      return {};
    }

    vector<int> ans;

    queue<TreeNode *> q;
    q.push(root);

    // bfs
    while (q.empty() == false) {
      // 先将前面q.size() - 1个元素出队
      int len = q.size() - 1;
      while (len--) {
        auto t = q.front();
        q.pop();
        if (t->left != NULL) {
          q.push(t->left);
        }
        if (t->right != NULL) {
          q.push(t->right);
        }
      }

      // 再将最后一个元素出队
      auto t = q.front();
      q.pop();
      ans.push_back(t->val);
      if (t->left != NULL) {
        q.push(t->left);
      }
      if (t->right != NULL) {
        q.push(t->right);
      }
    }

    return ans;
  }
};