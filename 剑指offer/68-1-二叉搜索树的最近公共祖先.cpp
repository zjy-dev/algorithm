#include"LeetCode.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        return dfs(root, p, q);
    }
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        const auto val = root->val;
        if(p->val > val and q->val > val)
            return dfs(root->right, p, q);
        else if(p->val < val and q->val < val)
            return dfs(root->left, p, q);
        else
            return root;
    }
};