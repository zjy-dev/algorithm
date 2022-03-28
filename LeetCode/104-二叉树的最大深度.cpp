#include "LeetCode.h"

class Solution {
public:
    int ans = 0;
    int maxDepth(TreeNode* root) {
        dfs(root, 1);

        return ans;
    }

    void dfs(TreeNode* root, int depth) {
        if (root == NULL) {
            return;
        }

        // 更新答案
        if (depth > ans) {
            ans = depth;
        }

        // 递归搜索左右子树
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
};