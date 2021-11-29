#include"LeetCode.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(!root)
            return true;
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode* l, TreeNode* r)
    {
        if(!l and !r)
            return true;
        if(!l or !r)
            return false;
        if(l->val != r->val)
            return false;
        return dfs(l->left, r->right) and dfs(l->right, r->left);
    }
};