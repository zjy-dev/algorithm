#include "LeetCode.h"

class Solution {
public:
  // 加快在中序序列中寻找root的速度
  unordered_map<int, int> hash;
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size();
    if (n == 0) {
      return NULL;
    }

    for (int i = 0; i < n; i++) {
      hash[inorder[i]] = i;
    }
    return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
  }

  // 逐步划分前序和中序序列的边界, 递归的构造树
  TreeNode *dfs(vector<int> &pre, vector<int> &in, int preL, int preR, int inL,
                int inR) {
    if (preL > preR) {
      return NULL;
    }
    TreeNode *root = new TreeNode(pre[preL]);

    // 左子树的长度
    int lenL = hash[root->val] - inL;

    // 仔细一些即可
    root->left = dfs(pre, in, preL + 1, preL + lenL, inL, hash[root->val] - 1);
    root->right = dfs(pre, in, preL + lenL + 1, preR, hash[root->val] + 1, inR);
    return root;
  }
};