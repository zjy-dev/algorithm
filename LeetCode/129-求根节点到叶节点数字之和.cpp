#include"LeetCode.h"

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int path)
    {
        if(!root)
            return 0;
        
        path = path * 10 + root->val;
        if(!root->left and !root->right)
            return path;
        
        return dfs(root->left, path) + dfs(root->right, path);
    }
};