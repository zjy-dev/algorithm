#include "LeetCode.h"

class Solution {
public:
  bool isSubStructure(TreeNode *A, TreeNode *B) {
    // 根据题干约定, 空树不是任意树的子结构
    // 而根据常识, 任意非空树也不是空树的子结构
    if (A == NULL || B == NULL) {
      return false;
    }

    // 这里也要递归的原因是
    // A的子树的根节点和B的根节点对齐也是可以的
    return dfs(A, B) || isSubStructure(A->left, B) ||
           isSubStructure(A->right, B);
  }

  // 判断b是否是a的子结构(a和b的根节点对齐)
  bool dfs(TreeNode *a, TreeNode *b) {
    // 注意此时b为空是要return true的
    // 因为我们已经明确了B不是空树
    // b为空反而是我们最想看到的情况, 它代表dfs的边界
    if (b == NULL) {
      return true;
    }

    // a空b不空 或 a,b的值不相等
    // 返回false
    if (a == NULL || a->val != b->val) {
      return false;
    }

    return dfs(a->left, b->left) && dfs(a->right, b->right);
  }
};