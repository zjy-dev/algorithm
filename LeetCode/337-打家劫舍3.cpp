#include "LeetCode.h"

class Solution {
public:
    // 记忆化搜索
    unordered_map<TreeNode*, int> hash;

    int rob(TreeNode* root) {
        return dfs(root);
    }

    int dfs(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        // 记忆化剪枝
        if (hash.count(root) == 1) {
            return hash[root];
        }

        // 抢劫root
        int robRoot = root->val;
        if (root->left != NULL) { // 抢劫root的孙子结点们
            robRoot += dfs(root->left->left) + dfs(root->left->right);
        }
        if (root->right != NULL) {
            robRoot += dfs(root->right->left) + dfs(root->right->right);
        }

        // 不抢劫root, 那就可以从儿子结点开始抢
        int notRobRoot = dfs(root->left) + dfs(root->right);

        hash[root] = max(robRoot, notRobRoot);
        return max(robRoot, notRobRoot);
    }
};