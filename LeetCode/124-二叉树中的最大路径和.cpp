#include"LeetCode.h"

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }

    int dfs(TreeNode* root, int& ans)
    {
        if(!root)
            return NULL;
        
        //l和r代表不能经过父结点的答案
        int l = INT_MIN, r = INT_MIN;

        //ll和rr则可以经过父结点
        int ll = max(0, dfs(root->left, l));
        int rr = max(0, dfs(root->right, r));
        ans = max(l, r);
        ans = max(ll + rr + root->val, ans);

        //由于不能同时经过左右子树和父结点
        //只好退而求其次返回最大的半边
        return max(ll, rr) + root->val;
    }
    
};