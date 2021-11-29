#include"LeetCode.h"

class Solution{
public:
    vector<int> levelOrder(TreeNode* root) 
    {
        if(!root)
            return {};
        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);
        while(q.size())
        {
            auto t = q.front();
            q.pop();
            ans.push_back(t->val);
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }

        return ans;
    }
};