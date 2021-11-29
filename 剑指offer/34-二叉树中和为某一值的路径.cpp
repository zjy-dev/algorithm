#include"LeetCode.h"

class Solution{
public:
    vector<vector<int>> ans;
    vector<int> v;
    int tar;
    vector<vector<int>> pathSum(TreeNode* root, int target) 
    {
        this->tar = target;
        dfs(root, 0);
        return ans;
    }

    void dfs(TreeNode* root, int num)
    {
        if(!root)
            return;
        
        num += root->val;
        v.push_back(root->val);

        if(num == tar and !root->left and !root->right)
            ans.push_back(v);

        dfs(root->left, num);
        dfs(root->right, num);

        v.pop_back();
    }
};