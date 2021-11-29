#include"LeetCode.h"

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) 
    {
        dfs(root);
        return root;
    }

    void dfs(TreeNode* root)
    {
        if(!root)
            return;

        swap(root->left, root->right);
        dfs(root->left), dfs(root->right);
    }
};