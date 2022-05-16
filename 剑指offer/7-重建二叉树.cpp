#include "LeetCode.h"

/**
 * 时间复杂度 -> O(n), n次递归建立n个结点
 * 空间复杂度 -> O(n), 哈希表O(n) + 递归O(n),
 * 递归是O(n)的因为每一次递归会建立一个结点
 */
class Solution {
public:
  // 哈希表用来预处理中序序列
  unordered_map<int, int> hash;

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    // 特判空树
    if (preorder.size() == 0) {
      return NULL;
    }

    // 用哈希表预处理中序序列
    int n = preorder.size();
    for (int i = 0; i < n; i++) {
      hash[inorder[i]] = i;
    }

    // dfs
    return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
  }

  TreeNode *dfs(vector<int> &pre, vector<int> &in, int preL, int preR, int inL,
                int inR) {
    // 边界
    if (preL > preR) {
      return NULL;
    }

    // 根结点
    TreeNode *root = new TreeNode(pre[preL]);

    // 从哈希表取出中序序列中根的位置
    int rootPos = hash[root->val];

    // 通过中序序列中根的位置来算出左右子树长度
    int lenL = rootPos - inL, lenR = inR - rootPos;

    // 递归构造左右子树
    root->left = dfs(pre, in, preL + 1, preL + lenL, inL, rootPos - 1);
    root->right = dfs(pre, in, preL + lenL + 1, preR, rootPos + 1, inR);

    return root;
  }
};