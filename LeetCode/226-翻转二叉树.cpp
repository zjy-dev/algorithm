#include"LeetCode.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        dfs(root);
    }

    void dfs(TreeNode* root)
    {
        if(!root)
            return;
        swap(root->left, root->right);
        dfs(root->left), dfs(root->right);
    }
};