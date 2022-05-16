#include "LeetCode.h"

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ans;
    stack<TreeNode *> stk;

    while (root != NULL || stk.empty() == false) {
      // 中序遍历吗, 遇到一个结点肯定不能直接用
      // 而是要不断寻找它的左子树, 对于该结点则存到某种容器中
      // 因为中序遍历要先遍历完左子树才能遍历根节点, 所以明显应该使用栈
      while (root != NULL) {
        stk.push(root);
        root = root->left;
      }
      root = stk.top();
      stk.pop();
      ans.push_back(root->val);

      // 左子树为空, 自己又访问结束了, 接下来该访问右子树了
      root = root->right;
    }

    return ans;
  }
};