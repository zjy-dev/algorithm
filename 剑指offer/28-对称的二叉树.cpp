#include"LeetCode.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // 空树是对称的
        if (root == NULL) {
            return true;
        }

        return dfs(root->left, root->right);
    }

    // root要想对称, root的两棵子树必须对称的
    // 此函数用来判断两棵子树是否对称
    bool dfs(TreeNode* A, TreeNode* B) {
        if (A == NULL && B == NULL) {
            return true;
        }

        if (A == NULL || B == NULL || A->val != B->val) {
            return false;
        }

        // A和B要想对称, A的左子树必须和B的右子树对称
        // A的右子树必须和B的左子树对称(可以观察样例)
        return dfs(A->left, B->right) && dfs(A->right, B->left);
    }
};