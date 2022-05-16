#include "LeetCode.h"

/**
 * 时间复杂度 => O(n), 每个结点只会被搜索一次
 * 空间复杂度 => O(n), 要维护一个队列用于bfs
 */
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    // 特判空
    if (root == NULL) {
      return {};
    }

    vector<vector<int>> ans;

    // bfs用的队列
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      vector<int> v;

      // 为了取一层的数据, 也就是取q.size()个数据, 要使用循环
      // 且因为q.size()是动态变化的, 所以要读取初始的q.size(), 然后倒着循环
      for (int i = q.size(); i != 0; i--) {
        auto t = q.front();
        q.pop();

        v.push_back(t->val);
        // 空子树就不用放进队列了, 是边界
        if (t->left != NULL) {
          q.push(t->left);
        }
        if (t->right != NULL) {
          q.push(t->right);
        }
      }

      ans.push_back(v);
    }

    return ans;
  }
};