#include"LeetCode.h"

typedef long long LL;

class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        return dfs(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
    
    bool dfs(TreeNode* root, LL low, LL high)
    {
        if(!root)
            return true;
        
        if(root->val <= low or root->val >= high)
            return false;

        return dfs(root->left, low, root->val) and dfs(root->right, root->val, high);
    }   
};