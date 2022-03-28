#include"LeetCode.h"

typedef long long LL;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        LL low = LONG_LONG_MIN, high = LONG_LONG_MAX;
        return dfs(root, low, high);
    }

    // 限定节点的范围在(low, high)
    bool dfs(TreeNode *root, LL low, LL high) {
        if (root == NULL) {
            return true;
        }

        if (root->val <= low || root->val >= high) {
            return false;
        }

        
        return dfs(root->left, low, root->val) && dfs(root->right, root->val, high);
    }
};