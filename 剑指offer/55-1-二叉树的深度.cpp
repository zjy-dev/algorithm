#include"LeetCode.h"

class Solution {
public:
    int ans = INT_MIN;
    int maxDepth(TreeNode* root) 
    {
        if(!root)
            return 0;
        dfs(root, 1);
        return ans;
    }
    void dfs(TreeNode* root, int depth)
    {
        if(!root)
            return;
        ans = max(depth, ans);
        dfs(root->left, depth + 1), dfs(root->right, depth + 1);
    }
};