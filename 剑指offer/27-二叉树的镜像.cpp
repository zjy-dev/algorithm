#include"LeetCode.h"

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        dfs(root);
        return root;
    }

    // 递归的去交换左右子树即可
    void dfs(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        swap(root->left, root->right);

        dfs(root->left);
        dfs(root->right);
    }
};