#include"LeetCode.h"

class Solution {
public:
    int ans = INT_MIN;
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        dfs(root, 0);
        return ans;
    }

    // 最简单的dfs, 逐渐往下搜, 遇到空树就更新答案
    void dfs(TreeNode* root, int depth) {
        if (root == NULL) {
            ans = max(ans, depth);
            return;
        }

        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
};