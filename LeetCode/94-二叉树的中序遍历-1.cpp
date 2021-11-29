#include"LeetCode.h"

class Solution{
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode* p)
    {
        if(!p)
            return;

        dfs(p->left);
        ans.push_back(p->val);
        dfs(p->right);
    }
};