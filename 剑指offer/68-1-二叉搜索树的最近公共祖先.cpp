#include"LeetCode.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }

        return dfs(root, p, q);
    }

    TreeNode* dfs(TreeNode *root, const TreeNode *p, const TreeNode *q) {
        if (root == NULL) {
            return NULL;
        }

        // 根据p和q的值与root作比较, 确定向左或向右搜索, 如果一大一小就返回root
        // 比较绕的是 = 的情况, 题干中规定一个结点可以是自己的祖先, 所以 = 的时候直接返回root即可
        if (p->val < root->val && q->val < root->val) {
            return dfs(root->left, p, q);
        } else if (p->val > root->val && q->val > root->val) {
            return dfs(root->right, p, q);
        } else {
            return root;
        }
    }
};