#include"LeetCode.h"

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if(!root1 or !root2)
            return root1 ? root1 : root2;
            
        dfs(root1, root2);
        return root1;
    }

    void dfs(TreeNode* root1, TreeNode* root2)
    {
        root1->val += root2->val;
        if(root1->left and root2->left)
            dfs(root1->left, root2->left);
        else if(!root1->left and root2->left)
            root1->left = root2->left;

        if(root1->right and root2->right)
            dfs(root1->right, root2->right);
        else if(!root1->right and root2->right)
            root1->right = root2->right;
    }
};