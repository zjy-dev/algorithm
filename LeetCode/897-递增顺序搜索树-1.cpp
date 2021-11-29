#include"LeetCode.h"

class Solution {
public:
    vector<int> v;
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ans = new TreeNode();
        auto p = ans;
        dfs(root);
        for(int i = 0; i < v.size(); i++)
            p->right = new TreeNode(int(v[i])), p = p->right;

        return ans->right;
    }

    void dfs(TreeNode* root)
    {
        if(!root)
            return;

        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }
};