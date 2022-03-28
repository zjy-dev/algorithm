#include"LeetCode.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode* l, TreeNode* r) {
        int cntNull = (l == NULL) + (r == NULL);

        if (cntNull == 2) {
            return true;
        } else if (cntNull == 1) {
            return false;
        }

        if (l->val != r->val) {
            return false;
        }

        // 轴对称就要这样判断
        return dfs(l->left, r->right) && dfs(l->right, r->left);
    }
};