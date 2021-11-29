#include"LeetCode.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root)
            return NULL;
        if(root == p or root == q)
            return root;
        
        auto l = lowestCommonAncestor(root->left, p, q);
        auto r = lowestCommonAncestor(root->right, p, q);
        if(!l and !r)
            return NULL;
        else if(l and r)
            return root;

        return l ? l : r;
    }
};