#include"LeetCode.h"

class Solution {
public:
    void flatten(TreeNode* root) 
    {
        dfs(root);
    }

    void dfs(TreeNode* root)
    {
        if(!root)
            return;
        if(!root->left)
        {
            dfs(root->right);
            return;
        }
        
        auto tailL = root->left;
        while(tailL->right)
            tailL = tailL->right;
        tailL->right = root->right;

        root->right = root->left;
        root->left = NULL;
        
        dfs(root->right);
    }
};
