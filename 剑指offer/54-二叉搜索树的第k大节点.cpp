#include"LeetCode.h"

class Solution{
public:
    int cnt, ans;
    int kthLargest(TreeNode* root, int k) 
    {   
        this->cnt = k;
        dfs(root);
        return ans;
    }

    void dfs(TreeNode* root)
    {
        if(!root)
            return;
        
        dfs(root->right);
        cnt--;
        if(!cnt)
        {
            ans = root->val;
            return;
        }
        dfs(root->left);
    }
};