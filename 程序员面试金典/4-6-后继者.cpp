#include "LeetCode.h"

class Solution {
public:
  TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
    // p的右子树非空的时候
    // 后继结点就是右子树中最小的那个, 比较简单
    if (p->right) {
      p = p->right;
      while (p->left) {
        p = p->left;
      }

      return p;
    }

    // p的右子树为空的时候
    // 后继结点是p所在子树的祖先
    TreeNode *t = root, *ans = nullptr;
    while (t) {
      // 当t大于p, t可能是答案, 也可能答案在t的左子树中
      if (t->val > p->val) {
        ans = t;
        t = t->left;
      } else {
        // 当t小于p, 答案只可能在右子树中
        // 如果没有答案, 最终t会等于p, 然后变为nullptr
        t = t->right;
      }
    }

    return ans;
  }
};